#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
long long inf = 1e18;

ll dist[701][701];
list<pair<pii,int>> graph[701][701];

ll dijkstra(int n) {

    dist[0][0] = 0;

    set<pair<ll, pair<int,int> > > Q;

    Q.insert({ dist[0][0],{0, 0}});

    int i,j,x,y;
    while(!Q.empty()){
        auto top = Q.begin();
        auto u = top->second;
        Q.erase(top);
        tie(i,j) = u;
        for(auto next: graph[i][j])    {
            tie(x,y) = next.first;
            ll weight = next.second;

            if( dist[i][j] + weight < dist[x][y] ) {
                if(Q.find( {dist[x][y],{x,y}})!=Q.end())

                    Q.erase(Q.find( {dist[x][y], {x,y}} ));
                dist[x][y] = dist[i][j] + weight;
                Q.insert( {dist[x][y], {x,y}} );
            }
        }
    }
    return dist[n-1][n-1] + graph[n-1][n-1].begin()->second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>x;
            if(j!=n-1)
                graph[i][j].push_back({{i,j+1},x});
            if(i!=n-1)
                graph[i][j].push_back({{i+1,j},x});
            if(i!=0)
                graph[i][j].push_back({{i-1,j},x});                    
            if(j!=0)
                graph[i][j].push_back({{i,j-1},x});                    
            dist[i][j] = inf;
        }
    }
    cout<<dijkstra(n);
    return 0;
}
