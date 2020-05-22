#include <bits/stdc++.h>
#define Nx 1000002
using namespace std;
int prime[Nx+1];

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

vector<int> fectorize(int n){
    vector<int> f;
    f.reserve(10);
    while(1 != n){
        f.push_back(prime[n]);
        n /= prime[n];
    }
    return f;
}

list<pair<int,int>>  fect(int n){
        list<pair<int,int>> p;
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
    return p;    
}

int main() {
    sive();
    int n;
    cin>>n;
    auto fec = fect(n);
    for (auto i: fec)
        cout<<i.first<<", "<<i.second<<'\n';
    
    return 0;
}
