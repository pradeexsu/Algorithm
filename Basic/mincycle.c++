#include<bits/stdc++.h> 
#define INF INT_MAX 
using namespace std; 

struct Edge{ 
	int u; 
	int v; 
	int weight; 
}; 

class Graph{ 
	int V;
	list < pair <int, int > >*adj; 

	vector <Edge> edge;

public:
	Graph( int V ) { 
		this->V = V ; 
		adj = new list < pair <int, int > >[V]; 
	} 

	void add_edge ( int u, int v, int w ); 
	void remove_edge( int u, int v, int w ); 
	int dijkastra_sp (int u, int v ); 
	int find_min_cost(); 

}; 


void Graph :: add_edge ( int u, int v, int w ){ 

	adj[u].push_back( {v, w} ); 
	adj[v].push_back( {u, w} ); 

	Edge e { u, v, w }; 
	edge.push_back ( e ); 
} 

void Graph :: remove_edge ( int u, int v, int w ){
	adj[u].remove({v, w}); 
	adj[v].remove({u, w}); 
} 

int Graph :: dijkastra_sp ( int u, int v ){ 
	set< pair<int, int> > setds; 
	vector<int> dist(V, INF); 

	setds.insert(make_pair(0, u)); 
	dist[u] = 0;

	while (!setds.empty()){ 
		pair<int, int> tmp = *(setds.begin()); 
		setds.erase(setds.begin()); 
		int u = tmp.second; 


		list< pair<int, int> >::iterator i; 
		for (i = adj[u].begin(); 	; ++i) 
		{ 
			int v = (*i).first; 
			int weight = (*i).second; 

			if (dist[v] > dist[u] + weight) 
			{ 
				if (dist[v] != INF) 
					setds.erase(setds.find(make_pair(dist[v], v))); 

				dist[v] = dist[u] + weight; 
				setds.insert(make_pair(dist[v], v)); 
			} 
		} 
	} 

	return dist[v] ; 
} 


int Graph :: find_min_cost(){ 
	int min_cycle = INT_MAX; 
	int E = edge.size(); 
	for ( int i = 0 ; i < E ; i++ ){ 
		Edge e = edge[i]; 
		// current Edge information 

		// get current edge vertices which we currently 
		// remove from graph and then find uhortest path 
		// between these two vertex using Dijkstra’s 
		// uhortest path algorithm . 
		remove_edge( e.u, e.v, e.weight ) ; 

		// minimum vistance between these two vertices 
		int vistance = dijkastra_sp( e.u, e.v ); 

		// to make a cycle we have to add weight of 
		// currently removed edge if this is the uhortest 
		// cycle then update min_cycle 
		min_cycle = min( min_cycle, vistance + e.weight ); 

		add_edge( e.u, e.v, e.weight ); 
	} 

	return min_cycle ; 
} 

int main() 
{ 
	int V = 301; 
	Graph g(V);
	int n, x, y, w;
	cin>>n;
  	for(int i=0;i<n;i++){
          cin>>x>>y>>w;
        g.add_edge(x, y, w);
      } 
	cout << g.find_min_cost() << endl; 
	return 0; 
} 
