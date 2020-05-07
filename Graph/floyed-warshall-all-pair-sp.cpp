#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define inf 0xfffffff
const int V = 5;
using namespace std;

struct Graph{
	unordered_map<int, list<pair<int,int> > > edj_list;
	int **graph;
	int **parent;
	
	Graph(int n){
		graph = new int*[n];
		parent = new int*[n];
		for (int i=0; i<V; i++){
			graph[i] = new int[V];
			parent[i] = new int[V];
		}
	}
	
	void add_edj(int u, int v, int w, bool bidir = false){
		edj_list[u].push_back({v, w});
		if(bidir)
			edj_list[v].push_back({u, w});
	}
	
	void print_list(){
		for (auto &i: edj_list){
			cout<<i.first<<" : ";
			for (auto &j: i.second){
				cout<<"("<<j.first<<","<<j.second<<"),";
			}
			cout<<'\n';
		}
	}
	
	void matrix_form(int u, int v, int w){
		graph[u-1][v-1] = w;
		parent[u-1][v-1] = u;
		return;
	}
	
	void matrix_form2(){
		for (int i=0; i<V; i++){
			for (int j=0; j<V; j++){
				if(i==j){
					graph[i][j] = 0;
					parent[i][j] = 0;
				}
				else{
					graph[i][j] = inf;
					parent[i][j] = 0;
				}
			}
		}
		return;
	}
	
	void print_matrix(){
		for (int i=0;i<V; i++){
			for (int j=0; j<V; j++){
				if(graph[i][j] == inf)
					cout<<"inf ";
				else
					cout<<graph[i][j]<<"  ";
			}
			cout<<'\n';
		}
	}
	
	void print_pi(int p[][V]){
		cout<<"parent matrix : \n";
		for (int i=0; i<V; i++){
			for (int j=0; j<V; j++){
				if(p[i][j] != 0)
					cout<<p[i][j]<<"   ";
				else
					cout<<"nil   ";
			}
			cout<<'\n';
		}
	}
	
	void print_solution(int dist[][V]){
		cout<<"all pair shortest path : \n";
		for (int i=0;i<V; i++){
			for (int j=0; j<V; j++){
				if(dist[i][j] == inf)
					cout<<"inf ";
				else
					cout<<dist[i][j]<<"  ";
			}
			cout<<'\n';
		}		
	}
	
	void print_path(int p[][V], int d[][V]){
		for (int i=0;i<V; i++){
			for (int j=0; j<V; j++){
				if(i!=j){	
					cout<<"shortest path from "<<i+1<<" to "<<j+1<<" is : \n";
					cout<<"total distance : "<<d[i][j]<<"\n path : ( ";
					int k = j;
					int l = 0;
					int a[V];
					a[l++] = j+1;
					
					while(p[i][k]!=i+1){
						a[l++] = p[i][k];
						k = p[i][k]-1;
					}
					a[l] = i+1;
					
					for (int r=l; r>0; r--){
						cout <<a[r]<<" --> ";
					}
					cout<<a[0]<<" )\n";
					
				}
			}
		}
	}

	void floyd_warshall(){
		int dist[V][V], i, j, k;
		int parent2[V][V];
		for (i=0; i<V; i++){
			for (j=0; j<V; j++){
				dist[i][j] = graph[i][j];
			}
		}
		
		for (i=0; i<V; i++){
			for (j=0; j<V; j++){
				parent2[i][j] = parent[i][j];
			}
		}
		
		for(k=0; k<V; k++)  {
			for(i=0; i<V; i++)  {
				for(j=0; j<V; j++)  {
					
					if(dist[i][j]> dist[i][k] + dist[k][j]){
						dist[i][j] = dist[i][k] + dist[k][j];
						parent2[i][j] = parent2[k][j];
				  }
			  }
			}
		}
		print_solution(dist);
		cout<<"\n\n";
		print_pi(parent2);
		cout<<"\n\n";
		print_path(parent2, dist);
		cout<<"\n\n";		
	}
	
};

int main(){
	cout<<"input: ";
	Graph g(5);
	g.matrix_form2();
	g.add_edj(1,2,3);
	g.matrix_form(1,2,3);

	g.add_edj(1,3,8);
	g.matrix_form(1,3,8);

	g.add_edj(1,5,-4);
	g.matrix_form(1,5,-4);

	g.add_edj(2,4,1);
	g.matrix_form(2,4,1);

	g.add_edj(2,5,7);
	g.matrix_form(2,5,7);

	g.add_edj(3,2,4);
	g.matrix_form(3,2,4);
	
	g.add_edj(4,3,-5);
	g.matrix_form(4,3,-5);
	
	g.add_edj(4,1,2);
	g.matrix_form(4,1,2);
	
	g.add_edj(5,4,6);
	g.matrix_form(5,4,6);
	g.print_list();
	cout<<"\n\n";
	g.print_matrix();
	cout<<"\n\n";
	g.floyd_warshall();
	return 0;
}


