#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define inf 0xffffffff
using namespace std;
#define unordered_map unordered_map

template<typename T>
struct Graph
{
	unordered_map<T, list<pair<T, int> > > edj_list;
	
	void add_edge(T u, T v, int dist, bool bidir = true){
		edj_list[u].push_back({v, dist});
		if(bidir)
			edj_list[v].push_back({u, dist});
	}
	
	void dijkastra(T src){
		unordered_map<T, int> dist;
		for (auto &i:edj_list){
			dist[i.first] = inf;
		}
		
		set<pair<int, T> > Que;
		
		dist[src] = 0;
		Que.insert({0, src});
		int w;
		T node;
		while(not Que.empty()){
			tie(w, node) = *Que.begin();
			Que.erase(Que.begin());
			
			for (auto &nbr: edj_list[node]){
				
				if( dist[nbr.first] > dist[node] + nbr.second){
					auto iter = Que.find( {dist[node], nbr.first} );
					if(iter != Que.end())
						Que.erase(iter);
					dist[nbr.first] = dist[node] + nbr.second;
					
					Que.insert({dist[nbr.first], nbr.first});
				}
			}
		}
		for (auto i: dist){
			cout << i.first << " : " << i.second << '\n';
		}
	}

};


int main()
{
	int n, w, x, y, e;
	Graph<int> *g = new Graph<int>(); 
	cout << "input: ";
	cin >> n >> e;
	for (int i=0; i<e; i++)
	{
		cin >> x >> y >> w;
		g->add_edge(x, y, w);
	}
	cout << "output: \n";
	g->dijkastra(1);
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
*/
