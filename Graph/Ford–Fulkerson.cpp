#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int> >& v)
{
    for (auto& i : v) {
        for (auto& j : i) {
            cout << j << ", ";
        }
        cout << endl;
    }
}
bool bfs(int** residual_capacity, int n, int source, int sink, int parent[])
{
    queue<int> q;
    q.push(source);
    bool visited[n];
    visited[source] = 1;
    while (not q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) {
            if (not visited[v] and residual_capacity[u][v] > 0) {
                parent[v] = u;
                visited[v] = true;
                q.push(v);
                if (v == sink) {
                    return true;
                }
            }
        }
    }
    return false;
}

int max_flowing(int** capacity, int s, int t, int n)
{
    int max_flow = 0;
    vector<vector<int> > aug_paths;
    int** residual_capacity = new int*[n];
    for (int i = 0; i < n; i++) {
        residual_capacity[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            residual_capacity[i][j] = capacity[i][j];
        }
    }
    int parent[n];

    while (bfs(residual_capacity, n, s, t, parent)) {
        int flow = INT_MAX;
        vector<int> current_augmented_path;
        int v = t;
        while (v != s) {
            current_augmented_path.push_back(v);
            int u = parent[v];
            if (flow > residual_capacity[u][v]) {
                flow = residual_capacity[u][v];
            }
            v = u;
        }
        current_augmented_path.push_back(s);
        std::reverse(current_augmented_path.begin(), current_augmented_path.end());
        aug_paths.push_back(current_augmented_path);
        max_flow += flow;
        v = t;
        while (v != s) {
            int u = parent[v];
            residual_capacity[u][v] -= flow;
            residual_capacity[v][u] += flow;
            v = u;
        }
    }
    print(aug_paths);
    return max_flow;
}
int main()
{
    int n, e;
    cin >> n >> e;
    int** capacity = new int*[n];
    for (int i = 0; i < n; i++) {
        capacity[i] = new int[n];
        memset(capacity[i], 0, sizeof(capacity[i]));
    }
    int u, v, c;
    for (int i = 0; i < e; i++) {
        cin >> u >> v >> c;
        capacity[u][v] = c;
    }
    int s, t;
    cin >> s >> t;
    int max_flow = max_flowing(capacity, s, t, n);
    cout << max_flow << endl;
}
