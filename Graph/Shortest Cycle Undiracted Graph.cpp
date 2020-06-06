


#include<bits/stdc++.h>
using namespace std;
#define N 1000

class Graph{
	public:
	int V;
	set<int> *edj;

	Graph(int v){
		V = v+1;
		edj = new set<int>[V];
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
	
	bool shortest_cycle(int &ans){

		int *dist = new int[V];
		fill_n(dist, V, INT_MAX);
		ans = INT_MAX;		
		queue<int> que;
		que.push(1);
		int u;
		dist[1] = 0;
		while(not que.empty()){
			u = que.front();
			que.pop();

			for (auto &i: edj[u]){
				if(dist[i]==INT_MAX){
					que.push(i);
					dist[i] = dist[u]+1;
				}
				else if(dist[i] >= dist[u]){		//			>=		
					ans = min(ans, dist[i]+dist[u]+1);
				}
			}
		}

		return ans!=INT_MAX;
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
	g->add_edj(5,2);
	int cycle;
	if(g->shortest_cycle(cycle))
		cout<<"smallest cycle is of size : "<<cycle<<'\n';
	else
		cout<<"no cycle";
	return 0;
}
