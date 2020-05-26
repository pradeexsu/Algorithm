#include<bits/stdc++.h>
using namespace std;
#define N 1000
/*
set<int>
vector<int>
list<int>
forward_list<int>
unordered_set<int>
deque<int>
*/
class Graph{
	public:
	int V;
	set<int> *edj;
	Graph(int v){
		edj = new set<int>[v+1];
		V = v+1;
	}
	// copy constructor give transpos
	Graph(const Graph &G){
		V = G.V;
		edj = new set<int>[V];
		for (int i=1; i<V; i++){
			for(auto edge:G.edj[i]){
				edj[i].insert(edge);
			}
		}
	}
	
	Graph(const Graph &G, bool transpose){
		V = G.V;
		edj = new set<int>[V];
		for (int i=1; i<V; i++){
			for(auto edge:G.edj[i]){
				edj[edge].insert(i);
			}
		}
	}
	
	void add_edj(int u, int v, bool bidir = false){
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
	template <size_t bitsetsize>
	void dfs_aux(int v, bitset<bitsetsize> &visited, stack<int> &s){
		visited[v] = 1;
		for (auto u: edj[v]){
			if(not visited[u])
				dfs_aux(u, visited, s);
		}
		s.push(v);
	}
	template <size_t bitsetsize>	
	void dfs_t(int v, bitset<bitsetsize> &visited,vector<list<int>> &g_comp){
		visited[v] = 1;
		g_comp.back().push_back(v);
		for (auto u: edj[v]){
			if(not visited[u])
				dfs_t(u, visited, g_comp);
		}
		
	}
	
	void connected_component(){
		bitset<N> visited;
		stack<int> stk;
		for(int i=1;i<V;i++){
			if(not visited[i])
				dfs_aux(i,visited, stk);
		}
		Graph T(*this, true);
		bitset<N> revisited;
		vector<list<int>> ans;
		while (not stk.empty()){
			int u=stk.top();
			stk.pop();
			if(not revisited[u]){
				ans.push_back(list<int>());
				T.dfs_t(u, revisited, ans);
			}
		
		}
		for (auto &l: ans){
			for(auto &i: l)
				printf("%d ->", i);
			printf("\n");
		}
		
	}
	
};

int main(){
	Graph g(7);
	g.add_edj(2,1);
	g.add_edj(1,7);
	g.add_edj(6,1);
	g.add_edj(2,7);
	g.add_edj(2,5);
	g.add_edj(3,2);
	g.add_edj(7,4);
	g.add_edj(4,3);
	//g.print();
	//printf("\n");
	//Graph T(g,true);
	//T.print();
	g.connected_component();
	
	
}
