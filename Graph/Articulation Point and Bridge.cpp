
#include<bits/stdc++.h>
using namespace std;
#define N 1000

class Graph{
	public:
	int V;
	set<int> *edj;
	int *disc;
	int *low;
	set<int> *a_point;
	set<pair<int, int>> *bridges;
	int timet;
	Graph(int v){
		V = v+1;
		edj = new set<int>[V];
		disc = new int[V]{0};
		low = new int[V];
		a_point = new set<int>();
		bridges = new set<pair<int,int>>();
		timet=1;
		
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
	
	void dfs(int cur, int pa){
		int no_child=0;
		disc[cur]=low[cur]=timet++;
		
		for (auto child: edj[cur]){
			
				if(not disc[child]){
					dfs(child, cur);
					no_child++;
					low[cur] = min(low[cur], low[child]);
					//art point
					if (low[child] >= disc[cur]){
						a_point->insert(cur);
					}
					// bridge
					if(low[child] > disc[cur]){
						bridges->insert({cur, child});
					}
				}
				else if(child!=pa){
					// backedge
					//cycle found
					low[cur] = min(low[cur], disc[child]);
					
				}
			
		}
		// separate case for root to be art point.
		if(pa==0 and no_child >= 2)
			a_point->insert(cur);
		return ;
	}

	void dfs(){
		dfs(1, 0);
		for (auto &i: *a_point)
			cout<<i<<" ";
		cout<<"\n";
		for (auto &i: *bridges)
			cout<<"("<<i.first<<", "<<i.second<<")\n";
		
	}
	~Graph(){
		delete[] edj;
		delete[] disc;
		delete[] low;
		delete a_point;
		delete bridges;
		
		
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
