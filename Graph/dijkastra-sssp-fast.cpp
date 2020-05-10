#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n,int source, vector<pair<int, int> > G[]) 
{
    int INF = (int)1e9;
    vector<int> D(n, INF);
    D[source] = 0;
    set<pair<int, int> > Q;
    Q.insert({0, source});
    
    while (not Q.empty())   
    {
        auto top = Q.begin();
        int u = top->second;
        Q.erase(top);
        for (auto next: G[u])    
        {
            int v = next.first, weight = next.second;
            if (D[u]+weight < D[v] ) 
            {
                if (Q.find( {D[v], v}) != Q.end())
                    Q.erase(Q.find( {D[v], v} ));
                D[v] = D[u]+weight;
                Q.insert({D[v], v});
            }
        }
    }
    return D;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,s,x,y,z,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m; 
        vector<pair<int,int> > *G=new vector<pair<int,int> >[n+1];
        vector<int>ans;
        for(int i=0;i<m;i++){
            cin>>x>>y>>z;
            G[x].push_back(make_pair(y,z));
            G[y].push_back(make_pair(x,z));
        }
        cin>>s;
        ans = dijkstra(n+1,s,G);
        for(int i=1;i<=n;i++){
            if(i==s)
                continue;
            else if(ans[i]==1e9)
                cout<<"-1 ";
            else
                cout<<ans[i]<<" ";
        }
        delete[] G;
        cout<<'\n';
    }
}
