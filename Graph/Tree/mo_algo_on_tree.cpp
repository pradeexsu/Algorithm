#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio (0); cin.tie (0);
#define pb push_back
using namespace std;
const int N = 1e5+5;
vector<int>edj[N];
int FT[2*N], start[N], finish[N], col[N];
short nodeF[N];
int freq[N], FF[N], bit[N+1], ans[N];
int timer = 1;
int num;
int blk_siz = 700;
struct query{
	int l;
	int r;
	int idx;
	int k;
	
	bool operator<(const query &b) const{
		if (l/blk_siz != b.l/blk_siz)
			return l/blk_siz < b.l/blk_siz;

		if ((l/blk_siz)&1)
			return r > b.r;
		return r < b.r;
	}

} q[N];


void bfs(int cur, int par)
{
	start[cur] = timer;
	FT[timer] = cur;
	timer++;
	for (int i: edj[cur])
	{
		if(i==par)
			continue;
		bfs(i, cur);
	}
	finish[cur] = timer;
	FT[timer] = cur;
	timer++;
}

/*		
			1
		   / \
    	  /   \
	     2	   3    
    	/ \
       /   \
      4	    5
5 0
1 2
1 3
2 4
2 5
*/

void add_bit(int i){
	
	while(i<=num){
		bit[i]+=1;
		i += i&(-1);
	}
}

void del_bit(int i){
	
	while(i<=num){
		bit[i]-=1;
		i += i&(-1);
	}
}

int get_bit(int i){
	
	int res = 0;
	while(i>0){
		res += bit[i];
		i -= i&(-i);
	}
	return res;
}

void add(int idx){
	int node = FT[idx];
	int c;
	nodeF[node]++;
	if(nodeF[node]==2)
	{
		c = col[node];
		freq[c]++;
		FF[freq[c]]++;
		add_bit(freq[c]);
		del_bit(freq[c]-1);
	}
} 

void remove(int idx){
	int node = FT[idx];
	int c;
	nodeF[node]--;
	if(nodeF[node]==1)
	{
		c = col[node];
		freq[c]--;
		FF[freq[c]]++;
		add_bit(freq[c]);
		FF[freq[c]+1]--;
		del_bit(freq[c]+1);
	}
}

int main(){
	//fast
	int n, u, v, qr;
	cin >> n >> qr ;
	for (int i=1; i<=n; i++)
		cin >> col[i];
	for (int i=1; i<n; i++)
		cin >> u >> v, edj[u].pb(v), edj[v].pb(u);
	int x,k;
	bfs(1, -1);

	for (int i=0; i<qr; i++){
		cin >> x >> k;
		 q[i].l = start[x];
		 q[i].r = finish[x];
		 q[i].k = k;
		 q[i].idx = i;
	}
	num = n;
	sort(q,q+qr);
	int L, R, idx, ML = 1, MR = 0;
	
	for (int i=0; i<qr; i++)
	{
		L = q[i].l, R = q[i].r;
		k = q[i].k;
		idx = q[i].idx;
		while (MR<R)
			MR++,add(MR);
		while (ML>L)
			ML--, add(ML);
		while (MR>R)
			remove(MR), MR--;
		while (ML>L)
			remove(ML), ML++;
		ans[idx] = get_bit(num)-get_bit(k-1);
	}	
	
	for (int i=0; i<qr; i++)
		cout<<ans[i]<<'\n';
	return 0;
}
/*
8 5
1 2 2 3 3 2 3 3
1 2
1 5
2 3
2 4
5 6
5 7
5 8
1 2
1 3
1 4
2 3
5 3
*/
