

#include<bits/stdc++.h>
using namespace std;
#define N 1000

class Graph{
	public:
	int V;
	set<int> *edj;
	bool is_bipartite;
	Graph(int v){
		V = v+1;
		edj = new set<int>[V];
		is_bipartite = true;
	}
	
	void add_edj(int u, int v, bool bidir = true){
		edj[u].insert(v);
		if(bidir)
			edj[v].insert(u);
	}
	
	void print(){
		for (int i=1;i<V;i++){
			printf("%d ->",i);
			for (auto edge: edj[i])
				printf("%d ", edge);
			printf("\n");
		}
	}
	template<size_t t,size_t k>
	void dfs(int cur, bitset<t> &vis, bitset<k> &col, bool c){
		if(not is_bipartite)
			return;
		vis[cur] = 1;
		col[cur] = c;
		for (auto child: edj[cur]){
			
				if(not vis[child]){
					dfs(child, vis, col, not c);
				}
				else if(col[child] == c){
					is_bipartite = 0;
					return;
				}
		}
		
	}
	bool bipartite(){
		bitset<1000> vis;
		bitset<1010> col;
		dfs(1,vis, col, 1);
		return is_bipartite;
	}
	
	~Graph(){
		delete[] edj;
	}
};

int main(){
	Graph *g = new Graph(5);
	g->add_edj(1,2);
	g->add_edj(3,2);
	g->add_edj(4,3);
	g->add_edj(1,4);
	g->add_edj(1,5);
	g->add_edj(5,3);
	
	if(g->bipartite())
		cout<<"biparitite";
	else
		cout<<"not a bipartite";
	return 0;
}
