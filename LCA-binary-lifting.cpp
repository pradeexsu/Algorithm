#include <bits/stdc++.h>
#define N 100000
#define logn 17
using namespace std;
vector<int> adj[N];
int pa[N][logn];
int depth[N], sub_size[N];

int chain_id[N], id = 0, chain_lead[N];
int chain_ptr[N], ptr = 0;
int arr[N], base_array[N];
int tree[4*N];

int lca( int u, int v){
    if(depth[v]>depth[u])
    {
        int temp = u;
        u = v;
        v = temp;
    }

    int diff = depth[u] - depth[v];
    for(int i=0;i<logn; i++)
    {
        if((diff>>i)&1)
        {
            u = pa[ u ][i];
        }
    }
    if(u==v)
        return v;

    for (int i=logn-1;i>=0;i--)
    {
        if (pa[u][i] != pa[v][i])
        {
            u = pa[u][i];
            v = pa[v][i];
        }
    }
    return pa[u][0];
}

void dfs(int v, int prev = -1, int level=0){
    pa[v][0] = prev;
    depth[v] = level;
    sub_size[v] = 1;

    for(int i=0; i<adj[v].size(); i++){
        if(adj[v][i] != prev){
            dfs( adj[v][i], v, level + 1);
            sub_size[v]+= sub_size[ adj[v][i]];
        }
    }

}

void hld(int v, int prev ){
    if(chain_lead[id] == -1){
        chain_lead[id] = v;
    }

    chain_id[v] = id;
    chain_ptr[v] = ptr;

    base_array[ ptr++ ] = arr[ v ];

    int mi = -1, mv = -1;
    for (int i=0; i<adj[v].size(); i++){
        if(adj[v][i] != prev and mv < sub_size[ adj[v][i] ]){
            mi = i;
            mv = sub_size[ adj[v][i] ];
        }
    }

    if(mi >= 0){
        hld( adj[v][mi], v);
    }

    for (int i=0; i < adj[v].size(); i++){
        if(mi!=i and adj[v][i] != prev){
            id++;
            hld( adj[v][i], v);
        }
    }

}


void build(int v, int tl, int tr ){
    if(tl==tr){
        tree[v] = base_array[tl];
        return ;
    }

    int tm = (tl + tr)>>1, c = v<<1;
    build(c, tl, tm);
    build(c|1, tm+1, tr);
    tree[v] =  tree[c]+ tree[c|1];
}

int query_tree(int v, int tl, int tr, int ql, int qr){
   if(tl>qr or tr< ql or tl > tr){
       return 0;
   }
   if(tl>= ql and tr <=qr){
       return tree[v];
   }

   int sum = 0,c = v<<1, tm = (tl+tr)>>1;
    sum += query_tree(c, tl, tm, ql, qr);
    sum += query_tree(c|1, tm+1, tr, ql, qr);
  return sum;
}

int query_up(int u, int v){
    if(u==v){
        return arr[u];
    }
    int uchain, vchian = chain_id[v], sum = 0;
    while(true){
        uchain = chain_id[u];
        if(uchain==vchian){
            if(u==v){
                sum += arr[u];
                break;
            }
            sum += query_tree(1, 0, ptr - 1, chain_ptr[v], chain_ptr[u]);
            break;
        }
            sum += query_tree(1, 0, ptr - 1, chain_ptr[chain_lead[uchain]], chain_ptr[u]);
            u = chain_lead[chain_id[u]];
            u = pa[u][0];
    }
    return sum;
}

int query(int u, int v){
    if(u==v){
        return arr[v];
    }

    int lca_ = lca(u,v);
    int sum = query_up(u, lca_);
    sum += query_up(v, lca_);
    sum -= arr[lca_];
    return sum;
}

int main() {
    int u, v;
    int n, q;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[v - 1].push_back(u - 1);
        adj[u - 1].push_back(v - 1);
    }

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    memset(chain_lead, -1, sizeof(chain_lead));
    dfs(0);

    hld(0, -1);
    build(1, 0, ptr - 1);

    if(false){
        for (int i = 0; i < n; i++) {
            cout << "depth[" << i << "] : " << depth[i] << "\n";
        }

        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << "subSize[" << i << "] : " << sub_size[i] << "\n";
        }
        cout << "\n";

        for (int i = 0; i < n; i++) {
            cout << "chain_id[" << i << "] : " << chain_id[i] << "\n";
        }
        cout << "\n";
        for (int i = 0; i <= id; i++)
            cout << "chin_lead[" << i << "] : " << chain_lead[i] << "\n";
        cout << "\n";

        for (int i = 0; i < n; i++) {
            cout << "chain_ptr[" << i << "] : " << chain_ptr[i] << "\n";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << base_array[i] << " ";
        }
    }

    for(int j = 1; j<logn;j++){
        for(int i=0; i<n; i++){
            if(pa[i][j-1] != -1)
                pa[i][j] = pa[ pa[i][j-1] ][j-1];
        }
    }

    cin>>q;
    while(q--){
        cin>>u>>v;
        cout<<query(u-1,v-1)<<"\n";
    }

    return 0;
}
