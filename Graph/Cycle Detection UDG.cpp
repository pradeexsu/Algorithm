
#include<bits/stdc++.h>
using namespace std;
#define N 1000

class Graph{
	public:
	int V;
	set<int> *edj;

	Graph(int v){
		edj = new set<int>[v+1];
		V = v+1;
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
	
	void dfs_h(int v, int *par, int *visited, vector<vector<int> > &comp){
		visited[v] = 1;
		for (auto u: edj[v]){
			if(u != par[v] and 2 > visited[u]){
				
			if(not visited[u]){
				par[u] = v;
				dfs_h(u, par, visited, comp);
			}
			else{
				int s = v;
				vector<int> path;
				path.push_back(s);
				while(s!=u){
					s = par[s];
					path.push_back(s);
				}
				comp.emplace_back(path);
			}
			}
		}
		visited[v]=2;
	}

	void dfs(){
		int *vis = new int[V];
		int *par = new int[V];
		for (int i=0;i<V;i++)
			vis[i]=0;
		vector<vector<int>> cycles;
		par[1]=1;
		dfs_h(1, par, vis, cycles);
		for (auto &cycle: cycles){
			for (auto &c: cycle){
				cout<<c<<" ";
			}
			cout<<'\n';
		}
		
	}
};

void test_case_1(){
//test case 1:
	Graph g(5);
	g.add_edj(1,2);
	g.add_edj(1,4);
	g.add_edj(4,2);
	g.add_edj(4,5);
	g.add_edj(4,3);
	g.add_edj(5,3);
//1 2 4
//3 4 5
	g.dfs();
	cout<<'\n';
}

void test_case_2(){
//test case 2:
	Graph g(8);
   g.add_edj(1, 2);
   g.add_edj(2, 3);
   g.add_edj(3, 4);
   g.add_edj(4, 5);
   g.add_edj(5, 2);
   g.add_edj(5, 6);
   g.add_edj(6, 7);
   g.add_edj(7, 8);
   g.add_edj(6, 8);
//5 4 3 2
//8 7 6
	g.dfs();	
}

int main(){
	
	test_case_1();
	test_case_2();

}
