#include <stdio.h>
#include <bitset>
#include <vector>
using namespace std;
const int n = int(87000010);
bitset<n> p;
int primes[int(5e6+1000)];
// large prime 
void sive(){
    int k=1;
    for (int i=2; i<n; i++){
        if(!p[i]){
            primes[k++] = i;
            for (long long j = i*(long long )i; j<n; j += i)
                p[j] = 1;
        }
    }
}

int main() {
    int t, nn;
    sive();
    scanf("%d",&t);
    while(t--){
        scanf("%d", &nn);
        printf("%d\n",primes[nn]);
    }
    return 0;
}
