#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#define int long long

using namespace std;

int modular_multiplication(int a, int b, int n)
{
	int res = 0;
	while (b){
		if (b&1ll) res += a;
		a *= 2;
		b /= 2;
		res %= n;
		a %= n;
	}
	return res;
}
int modular_exponantiation(int a, int b, int n){
	int res = 1;
	while(b){
		if(b&1ll){
			res = modular_multiplication(res, a, n);
			res %= n;
		}
		a = modular_multiplication(a, a, n);
		a %= n;
		b /= 2;
	}
	return res;
}
bool miller_robin(int n){
	if (n==2) return 1;
	if (n%2==0 or n==1) return 0;
	// n id odd
	//n-1 is even
	int d = n-1, s = 0;
	while(d%2==0){
		s++;
		d /= 2;
	}
	// n-1 = d*pow(2,s);
	// d is odd number..
	vector<int> a({2, 3, 5, 7, 11, 13, 17, 19, 23});
	
	for (size_t i=0; i < a.size(); i++){
		if(a[i]>n-2) continue;
		// a[i] ^d %n
		int ad = modular_exponantiation(a[i], d, n);
		if (ad%n==1) continue;
		bool prime = false;
		for (int r = 0; r<= s-1; r++){
			// (2^r)%n
			 int rr = modular_exponantiation(2, r, n);
			 // (a^(d*2*i))%n
			 int ard = modular_exponantiation(ad, rr, n);
			 if (ard %n ==n-1){
				prime = true;
				break;
			 }
		}
		if(not prime)
			return false;
	}
	return true;
}

signed main() {
    int t;
    scanf("%lld",&t);
	int n;
    while(t--){
		scanf("%lld", &n);
		if (miller_robin(n))
			cout<<"prime \n";
		else
			cout<<"not prime \n";
    }
	return 0;
}
