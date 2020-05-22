 
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

int fector_count(int n){
  int cnt = 0;
  int ans = 1;
  int num = prime[n];

    while(1 != n){
        cnt = 0;
        while (prime[n]==num){
            cnt++;
            n /= prime[n];
        }
        ans *= (cnt+1);
        num = prime[n];
    }
    return ans;
}

int main() {
    sive();
    int n;
    cin>>n;
    cout<<fector_count(n);    
    return 0;
}
