//                      maximum value of x, such that, n! % kx = 0     
//                      hackerblock *A Factorial Problem*

#include<iostream>
#define int long long
#define inf (long long)1e9
using namespace std;
signed main() {
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		int ans = inf;
		int occ = 0;
		for (int i=2; i*i<=k; i++){
			if(k%i==0){
				occ = 0;
				while(k%i==0){
					occ++;
					k/=i;
				}
				int tmp = 0, cnt=0;
				int p = i;
				while(p<=n){
					cnt += n/p;
					p *= i;
				}
				ans = min(cnt/occ, ans);
			}
		}
		if(k>1){
			int p = k;
			int cnt=0;
			while(p<=n){
				cnt += n/p;
				p *= k;
			}
			ans = min(ans, cnt);
		}
		if(ans==inf)
			cout<<0<<'\n';
		else
			cout<<ans<<'\n';
	}

	return 0;
}
