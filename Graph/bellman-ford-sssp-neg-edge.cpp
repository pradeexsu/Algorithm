						//directed edges
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define inf 0xfffffff
using namespace std;

vector<int> bellman_ford(int src, vector<pair<int,int> > G[], int n)
{
	vector<int> dist(n+1, inf);
	dist[src] = 0;
	int v, w;
	for (int i=0; i<n-1; i++)
	{
		for (int u=1; u<=n; u++)
		{
			if (dist[u] == inf)
				continue;				
			for (auto edge: G[u])
			{
				tie(v, w) = edge;
				dist[v] = min(dist[v], dist[u]+w);
			}
		}
	}
	//for detecting negetive cycle in graph  *optional
	for (int u=1; u<=n; u++)
	{
		if (dist[u] == inf)
				continue;				
		for (auto edge: G[u]){
			tie(v, w) = edge;
			if (dist[v] > dist[u]+w){
				//Negetive cycle detected !!
				dist.clear();
// 				assert(0);
			}
		}
	}
	return dist;
}

int main(){
	int n, w, x, y, e, s;
	cout<<"input: ";
	cin>>n>>e;
	vector<pair<int,int> > *g = new vector<pair<int,int> >[n+1]; 

	for(int i=0; i<e; i++){
		cin>>x>>y>>w;
		g[x].push_back({y, w});
		g[y].push_back({x, w});
	}
	cin>>s;
	cout<<"output: \n";
	auto dist = bellman_ford(s,g,n);
	for (int i=1;i<n;i++)
		cout<<dist[i]<<' ';
	delete[] g;
	return 0;
}

/*
7 7
1 2 1
1 3 1
2 3 2
3 4 3
4 5 2
4 6 1
5 6 1
1
*/
