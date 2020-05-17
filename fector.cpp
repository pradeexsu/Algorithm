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

struct _type;
vector<int> fectorize(int n){
    vector<int> f;
    f.reserve(10);
    while(1 != n){
        f.push_back(prime[n]);
        n /= prime[n];
    }
    return f;
}

void merg(_type &s1, _type &s2, _type &d);

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

    _type operator*(_type &n)
    {
        _type aux;
        merg(*this,n,aux);
        return aux;
    }

    _type operator/(_type &n)
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

void merg(_type &s1, _type &s2, _type &d){
    auto p1 = s1.p.begin();
    auto e1 = s1.p.end();
    auto p2 = s2.p.begin();
    auto e2 = s2.p.end();
    while(p1!=e1 and p2!=e2){
        if(p1->first == p2->first){
            d.p.push_back({p1->first, p1->second + p2->second});
            p1++;
            p2++;
        }
        else if(p1->first < p2->first){
            d.p.push_back({p1->first, p1->second});
            p1++;
        }
        else{
            d.p.push_back({p2->first, p2->second});
            p2++;
        }

    }
    while(p1!=e1){
        d.p.push_back({p1->first, p1->second});
        p1++;
        return;
    }
    while(p2!=e2){
        d.p.push_back({p2->first, p2->second});
        p2++;
    }
}

int main() {
    sive();
    _type n1(3245),n2(98976);
    n1.print();
    cout<<"\n";
    n2.print();
    cout<<"\n";
    (n1*n2).print();
    _type n3(32);
    (n2/n3).print();

    return 0;
}
