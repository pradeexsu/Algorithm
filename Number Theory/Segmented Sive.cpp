#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
const int n = (int)1e5+5;
bitset<n> p;
vector<int> primes;

void sive(){
    primes.reserve(9999);
    for (int i=2; i<n; i++){
        if(!p[i]){
            primes.push_back(i);
            for (long long j = i*(long long )i; j<n; j += i)
                p[j] = 1;
        }
    }
}

void segmented(int m, int nn){
    bool *seg = new bool[nn-m+2]();
    for (auto x: primes){
        if(x*x>nn){
            break;
        }
        
        int start = (m/x)*x;

        if(x>=m && x<=nn){
            start = 2*x;
        }
        else if(start<m){
            start += x;
        }

        for (int i = start; i<=nn; i+=x){
            seg[i-m] = 1;
        }

    }
    for (int i=m; i<=nn; i++){
        if(!seg[i-m] && i!=1 )
            cout<< i << '\n';
    }

    delete [] seg;
}

int main() {
    int t;
    int m, nn;
    sive();
    cin>>t;

    while(t--){
        cin>>m>>nn;
        segmented(m,nn);
        cout<<'\n';
    }
    return 0;
}
