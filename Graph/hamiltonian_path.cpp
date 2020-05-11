#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
bitset<10002> visited;

struct Graph
{
	set<int> *edj_list;
	int n;
	Graph(int v)
	{
		this->n = v;
		edj_list = new set<int>[v+1];
	}
	
	void add_edj(int u, int v, bool bidir=true)
	{
		edj_list[u].insert(v);
		if (bidir)
			edj_list[v].insert(u);
	}
	
	void permute_path(int v, vector<int> &path, vector<vector<int>> &ans)
	{
		for (auto edj: edj_list[v])
		{
			if (not visited[edj])
			{
				visited[edj] = 1;
				path.push_back(edj);
				if (path.size() == (size_t)n)
					ans.push_back(path);
				else
					permute_path(edj,path,ans);
				path.pop_back();				
				visited[edj] = 0;
			}
		}
	}

	vector<vector<int>> hemiltonian_path()
	{
		vector<vector<int> > ans;
		vector<int> path;
		visited.reset();
		for (int i=1; i<=n; i++){
			visited[i] = 1;
			path.push_back(i);
			permute_path(i, path, ans);
			path.pop_back();
			visited[i] = 0;
		}
		return ans;
	}

};
void run()
{
	Graph g(4);
	/*		
	    1
     	    |
	    2
	   / \
	  /   \
	 3 ~~~ 4    

	*/
//	posibal distinct hamiltonian path

//	output :
//	1 2 3 4 
//	1 2 4 3 
//	3 4 2 1 
//	4 3 2 1

	g.add_edj(1,2);
	g.add_edj(2,3);
	g.add_edj(2,4);
	g.add_edj(3,4);
	
	auto ans = g.hemiltonian_path();
	for (auto &i: ans){
		for (int j: i)
			cout<<j<<" ";
		cout<<"\n";
	}
}
int main(){
	fast
	run();	
	return 0;
}
