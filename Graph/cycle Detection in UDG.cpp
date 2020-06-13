#include<bits/stdc++.h>
using namespace std;

struct dsu{
	int *p;
	int size;
	dsu(int n){
		size = n;
		p = new int[n];
		init();
	}
	
	void init(){
		iota(p,p+size,0);
	}

	int find(int v){
		if( p[v] == v)
			return v;
		else
			return p[v] = find(p[v]);
	}
	bool is_disjoint(int u, int v){
		return (find(u)!=find(v));
	}
	bool take_union(int u, int v){
		int a = find(u);
		int b = find(v);
		if(a!=b){
			p[a] = p[b];	
			return true;		
		}
		else
			return false;
	}

};


struct graph{
	set<set<int>> *edge_list;
	
	graph(){
		edge_list = new set<set<int>>();
	}
	
	void add_edj(const initializer_list<int> e){
		edge_list->insert(e);
	}
	
	size_t size(){
		return edge_list->size();
	}
	
	bool has_cycle(){
		dsu select(1000);
		for(auto &i:*edge_list){
			set<int>::iterator it = i.begin();
			int a = *it;
			int b = *(++it);
			if(select.take_union(a, b));
			else return true;
		}
		return false;
	}
	
};

int main(){
	int n, a, b;
	cin >> n;
	graph g;
	for (int i=0;i<n;i++)
		cin >> a >> b,g.add_edj({a,b});
	if(g.has_cycle())
		cout<<"cycle detected";
	else
		cout<<"no cycle";
		
	return 0;
}
