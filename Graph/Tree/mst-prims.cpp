#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
using namespace std;

const int total = 1e4+2;
typedef pair<int,int> pi2;
int parent[total];
set<pi2>edjList[total];

bitset<total> marked;

void init(int n){
		for (int i=0; i< n; i++){
		parent[i] = i;
	}
}

int prims(){
	
	int mst = 0, w, x;
	marked.reset();
	priority_queue< pi2, vector<pi2>, greater<pi2> > edgeQ;
	edgeQ.push({0,1});
	while(not edgeQ.empty()){
		tie(w, x) = edgeQ.top();
		edgeQ.pop();
		if(marked[x])
			continue;
		mst+= w;
		marked[x] = true;
		for(auto node: edjList[x]){
			if(not marked[node.second])
				edgeQ.push(node);
		}
	}
	return mst;
}

int main(){
	int n, w;
//	cin>>n>>e;
	n = 40;
//	init(n);
	int sum = 0;
	for(int i=0;i<n;i++){
		for (int j=0;j<n;j++){			
			cin>>w;
			sum+=w;
			if(w!=0)
				edjList[i+1].insert({w, j+1});
		}
	}
	sum/=2;

	
/*	for(int i=0; i<e; i++){
		cin>>x>>y>>w;
		edjList[x].push_back({w, y});
		edjList[y].push_back({w, x});
	}
*/

	int ans = prims();
	cout<< sum-ans <<'\n';
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
