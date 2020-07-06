#include<iostream>
#include<vector>
#define logN 11
using namespace std;

vector<int> adj[1000];
int parent[1000][logN];
int level[1000];

void dfs(int u, int p){
	level[u] = level[p]+1;
	parent[u][0] = p;
	for (int i=1; i<logN; i++)
		parent[u][i] = parent[parent[u][i-1] ][i-1];
///		parent[u][i] = parent[parent[u][i-1] ][i-1];
	
	for (size_t i=0; i < adj[u].size(); ++i){
		int v = adj[u][i];
		if(v==p) continue;
		dfs(v, u);
	}
}

int lca(int u, int v){
	if(level[u]< level[v])
		swap(u, v);
	int diff = level[u] - level[v];

	for (int i=0; i<logN; ++i){
		if ((1<<i)&diff)
			u = parent[u][i];
	}
	if(u==v)
		return u;
	for (int i=logN-1; i>=0; --i){
		if (parent[u][i] != parent[v][i]){
			u = parent[u][i];
			v = parent[v][i];
		}
	}
	return parent[u][0];
}

int main(){

	int n,x,y;
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>x>>y,adj[x].push_back(y),adj[y].push_back(x);
	int q;
	level[1] = 0;
	dfs(1, 1);
	cin>>q;
	while(q--){
		cin >> x >> y;
		cout << lca(x, y) <<" ("<<x<<","<<y<<")\n";
		
	}
	return 0;
}
