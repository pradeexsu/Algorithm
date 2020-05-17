#include <bits/stdc++.h>
#define N 100002
#define logn 17
#define fast std::ios_base::sync_with_stdio(0);std::cin.tie(0);
#define endl "\n"
#define mod (int)(1e9+7)
#define Nx 1000002
using namespace std;
struct _type;
int prime[Nx+2];
vector<int> adj[N];
int pa[N][logn];
int depth[N], sub_size[N];

int chain_id[N], id = 0, chain_lead[N];
int chain_ptr[N], ptr = 0;
_type merg(_type &s1, _type &s2);

vector<int> fectorize(int n){
    vector<int> f;
    f.reserve(7);
    while(1 != n){
        f.push_back(prime[n]);
        n /= prime[n];
    }
    return f;
}

struct _type{
    _type(){}

    list<pair<int, int>> p;

    _type(int n){
        vector<int> v = fectorize(n);
        pair<int,int> a;
        auto it = v.begin();
        auto uit = upper_bound(v.begin(), v.end(),*it);
        while(it!=v.end()){
            a = {*it, uit - it};
            p.push_back(a);
            it = uit;
            uit = upper_bound(v.begin(), v.end(),*it);
        }
    }

    _type operator*(_type n)
    {
        return merg(*this,n);
    }

    _type operator/(_type n)
    {
        auto it1 = n.p.begin();
        auto it2 = p.begin();
        auto e1 = n.p.end();
        while(it1 !=e1 and it2 != p.end()){
            if(it1->first == it2->first){
                it2->second -= it1->second;
                if(it2->second==0){
                    auto temp = it2;
                    it2++;
                    it1++;
                    p.erase(temp);
                    continue;
                }
                it1++;
                it2++;
            }
            else{
                it2++;
            }
        }
        return *this;
    }

    void print()
    {
        for(auto i:p)
            cout<<i.first<<" "<<i.second <<"\n";
    }
};

_type base_array[N];
_type tree[4*N];

int arr[N];

void sive(){
    prime[1] = 1;
    for(int i=2;i<=Nx; i++){
        if(!prime[i]){
            for(int j = i ;j <= Nx; j += i){
                if(!prime[j])
                    prime[j]=i;
            }
        }
    }
    return ;
}

_type merg(_type &s1, _type &s2){
    _type aux;
    auto p1 = s1.p.begin();
    auto e1 = s1.p.end();
    auto p2 = s2.p.begin();
    auto e2 = s2.p.end();
    if(p1==e1)
        return s2;
    else if(p2==e2)
        return s1;

    while(p1!=e1 and p2!=e2){
        if(p1->first == p2->first){
            aux.p.push_back({p1->first, p1->second + p2->second});
            p1++;
            p2++;
        }
        else if(p1->first < p2->first){
            aux.p.push_back({p1->first, p1->second});
            p1++;
        }
        else{
            aux.p.push_back({p2->first, p2->second});
            p2++;
        }

    }

    while(p1!=e1){
        aux.p.push_back({p1->first, p1->second});
        p1++;
        return aux;
    }
    while(p2!=e2){
        aux.p.push_back({p2->first, p2->second});
        p2++;
    }
    return aux;
}

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

    base_array[ ptr++ ] = _type(arr[v]);

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
    tree[v] =  tree[c]*tree[c|1];
}

_type query_tree(int v, int tl, int tr, int ql, int qr){
    if(tl > tr or tl>qr or tr< ql){
        return _type();
    }
    if(tl>= ql and tr <=qr){
        return tree[v];
    }

    int c = v<<1, tm = (tl+tr)>>1;

    _type b = query_tree(c, tl, tm, ql, qr);
    _type a = query_tree(c|1, tm+1, tr, ql, qr);
    return a*b;
}

_type query_up(int u, int v){
    if(u==v){
        return _type();
    }
    int uchain, vchian = chain_id[v];
    _type ans, a;

    while(true){
        uchain = chain_id[u];
        if(uchain == vchian){
            if(u == v){
                break;
            }
            a = query_tree(1, 0, ptr - 1, chain_ptr[v]+1, chain_ptr[u]);
            ans = ans*a;
            break;
        }
        a = query_tree(1, 0, ptr - 1, chain_ptr[chain_lead[uchain]], chain_ptr[u]);
        ans = ans*a;
        u = chain_lead[uchain];
        u = pa[u][0];
    }

    return ans;
}

_type query(int u, int v){
    if(u==v){
        return base_array[chain_ptr[v]];
    }

    int lca_ = lca(u,v);
    _type a = query_up(u, lca_);
    _type b = query_up(v, lca_);
    _type d = a*b;
    return d*base_array[chain_ptr[lca_]];
}

int main() {
    fast
    sive();
    int u, v;
    int n, q, t;
    cin>>t;
    while(t--) {
        cin >> n;
        fill(tree, tree + 4 * n, _type());
        fill(base_array, base_array + n, _type());
        memset(chain_lead, -1, sizeof(int)*n);

        ptr = 0;
        id = 0;

        for(int i=0;i<n;i++){
            adj[i].clear();
        }

        for (int i = 0; i < n - 1; i++) {
            cin >> u >> v;
            adj[v - 1].push_back(u - 1);
            adj[u - 1].push_back(v - 1);
        }

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        dfs(0);

        hld(0, -1);
        build(1, 0, ptr - 1);
        for (int j = 1; j < logn; j++) {
            for (int i = 0; i < n; i++) {
                if (pa[i][j - 1] != -1)
                    pa[i][j] = pa[pa[i][j - 1]][j - 1];
            }
        }

        cin >> q;
        while (q--) {
            cin >> u >> v;
            long long ans = 1;
            _type a = query(u - 1, v - 1);
//            a.print();
//            cout<<endl;
            for (pair<int, int> i:a.p) {
                ans *= (i.second + 1);
                ans %= mod;
            }
            cout << ans << endl;
        }
    }
    return 0;
}

