#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long 
using namespace std;
const int total = 1e3+1;
typedef tuple<int,int,int> ti3;
int parent[total];
int ranks[total];
ti3 edges[total*total/2];

void init(int n){
	for (int i=0; i< n; i++){
		parent[i] = i;
		ranks[i] = 0;
	}
}
int find(int v){
	if(parent[v]==v)
		return v;
	return parent[v] = find(parent[v]);
}

void union_set(int a, int b){
	a = find(a);
	b = find(b);
	if(a!=b){
		if(ranks[a]<ranks[b]){
			swap(a, b);
		}
		parent[b] = a;
		if(ranks[a]==ranks[b])
		ranks[a]++;
	}
}

int kruskal(int n){
	
	int mst = 0, w, x, y;
	sort(edges, edges+n);
	for (int i=0;i<n;i++){
		tie(w,x,y) = edges[i];
		x = find(x);
		y = find(y);
		
		if(x != y){
			mst += w;
			union_set(x, y);
		}
	}
	return mst;
}

int main(){
	int n, e, w, x, y;
	cin>>n>>e;
	init(n);

	for(int i=0; i<e; i++){
		cin>>w>>x>>y;
		edges[i] = tie(w, x, y);
	}
	cout<<kruskal(e)<<'\n';
	
	return 0;
}
