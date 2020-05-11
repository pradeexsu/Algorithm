#include<bits/stdc++.h>
#include <bitset>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
const int total = 3e3+2;
bitset<total> marked;
typedef pair<int,int> pi2;
set<pi2>edjList[total];

int prims(int src)
{
    int mst_cost = 0, w, x;
    priority_queue< pi2, vector<pi2>, greater<pi2> > edgeQ;
    edgeQ.push({0,src});
    while (not edgeQ.empty())
    {
        tie(w, x) = edgeQ.top();
        edgeQ.pop();
        if (marked[x])
            continue;
        mst_cost += w;
        marked[x] = true;
        for (auto node: edjList[x])
        {
            if (not marked[node.second])
                edgeQ.push(node);
        }
    }
    return mst_cost;
}

int main()
{
    int n, w, x, y, e;
    cin >> n >> e;
 
    for (int i=0; i<e; i++)
    {
        cin>>x>>y>>w;
        edjList[x].insert({w, y});
        edjList[y].insert({w, x});
    }
    int root;
    cin >> root;
    int mst_cost = prims(root);
    cout << mst_cost;
    return 0;
}
