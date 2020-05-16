#include <vector>

class SparseTable
{
public:
    SparseTable(std::vector<int> v)
    {
        log_table.assign(v.size() + 1, 0);
        for (auto i = 2UL; i < log_table.size(); i++)
            log_table[i] = log_table[i / 2] + 1;

        sparse_table.assign(log_table.back() + 1, std::vector<int>(v.size()));
        sparse_table[0] = v;
        for (auto row = 1UL; row < sparse_table.size(); row++) {
            for (auto i = 0UL; i + (1 << row) <= v.size(); i++) {
                sparse_table[row][i] =
                    std::min(sparse_table[row - 1][i],
                             sparse_table[row - 1][i + (1 << (row - 1))]);
            }
        }
    }

    int minimum(int l, int r)
    {
        int log = log_table[r - l];
        return std::min(sparse_table[log][l],
                        sparse_table[log][r - (1 << log)]);
    }

private:
    std::vector<int> log_table;
    std::vector<std::vector<int>> sparse_table;
};

class LCA
{
public:
    LCA(std::vector<std::vector<int>> adj) : adj(adj) {
        int nodes = adj.size();
        first_encounter.resize(nodes);
        dfs_euler_tour(0, -1);
        st = new SparseTable(euler_tour);
    }

    ~LCA() {
        delete st;
    }

    int query(int u, int v) {
        int fe1 = first_encounter[u];
        int fe2 = first_encounter[v];
        if (fe1 > fe2)
            std::swap(fe1, fe2);
        int LCA_new_index = st->minimum(fe1, fe2+1);
        int LCA_old_index = new_to_old[LCA_new_index];
        return LCA_old_index;
    }

private:
    void dfs_euler_tour(int v, int p) {
        int new_index = new_to_old.size();
        new_to_old.push_back(v);
        first_encounter[v] = euler_tour.size();
        euler_tour.push_back(new_index);

        for (int u : adj[v]) {
            if (u == p)
                continue;

            dfs_euler_tour(u, v);
            euler_tour.push_back(new_index);
        }
    }

    std::vector<std::vector<int>> adj;
    std::vector<int> euler_tour;
    std::vector<int> first_encounter;
    std::vector<int> new_to_old;
    SparseTable* st;
};
