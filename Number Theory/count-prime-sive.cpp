// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


void printKAlmostPrimes(int k, int n);

int main() {
	// your code goes herei
int t;
cin>>t;
while(t--){
	int n,k;
	cin>>n>>k;
    printKAlmostPrimes(n,k);
    cout<<endl;
}


	return 0;
}// } Driver Code Ends

// ios_base::sync_with_stdio(0);
// cin.tie(0);
// cout.tie(0);
int  p[100002];
            //  100002
const int nn=100000;

void sive(){
    memset(p,0, sizeof(p));
    for (int i=2; i<=nn; i++){
        if(not p[i]){
            for (int j=i; j<=nn; j += i){
                int tmp = j;
                while(tmp%i==0){
                    p[j]++;
                }
            }
        }
    }
}

// bool is_prim(int n){
// 	if(n<4)
// 		return true;
// 	if(n%2==0 and n%3==0)
// 		return false;
// 	for (long long i=5; i*i<=n; i+=6)
// 		if(n%i==0 or n%(i-2)==0)
// 			return false;
// 	return true;
// }

// 10000*100 =
bool flag=true;

void printKAlmostPrimes(int k, int n)
{
    if(flag){
        flag = false;
        sive();
    }
    int x=2;
    int count=0;
    while(count<n){
        if(p[x]==k)
            count++, printf("%d ",x);
        x++;
    }
}
