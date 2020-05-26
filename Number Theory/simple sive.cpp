#include <iostream>
#include<vector>
using namespace std;
#define ll long long
int  p[10002];
vector<int> prime;
void primeSieve(int n){
    p[0] = p[1] = 1;
    for (int i=3; i<=n; i +=2)
        if (!p[i]){
            prime.push_back(i);
            for (ll j = i*(ll)i; j<=n; j += 2*i)
                p[j]=1;
        }
}

vector<int> fectorize(int n){
    int i = 0;
    vector<int> fectors;
    int p = prime[i];
    while(p*p<=n){
        while(n%p==0){
            n /= p;
            fectors.push_back(p);    
        }
        i++;
        p = prime[i];
    }
    if(n != 1)
        fectors.push_back(n);
    return fectors;
}

int main() {
    primeSieve(10000);
    for (auto i: prime)
        cout<<i<<" ";
    int n;
    cin>>n;
    cout<<'\n';
    vector<int> v = fectorize(n);
}

