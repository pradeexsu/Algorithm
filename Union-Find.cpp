#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long 
using namespace std;
const int total = 1e3+1;

int parent[total];
int ranks[total];

void init(int n)
{
	for (int i=0; i< n; i++)
	{
		parent[i] = i;
		ranks[i] = 0;
	}
}

int find(int v)
{
	if(parent[v]==v)
		return v;
	return parent[v] = find(parent[v]);
}

void union_set(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a!=b)
	{
		if (ranks[a]<ranks[b])
		{
			swap(a, b);
		}
		parent[b] = a;
		if (ranks[a]==ranks[b])
			ranks[a]++;
	}
}
bool is_union(int u, int v)
{
	return find(u)==find(v);
}
