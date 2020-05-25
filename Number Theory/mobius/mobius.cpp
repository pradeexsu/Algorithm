
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#define int long long
#define N 100004
using namespace std;
int a[N], prime_count[N], mobius[N];

void mobius_sive(){
	int i, j;
	for (i=1; i<N; i++){
		a[i] = 1;
	}
	for (i=2; i<N; i++){
		if(prime_count[i]) continue;
		for (j=0; j<N; j+=i){
			prime_count[j]++;
			a[j] *= i;
		}
	}
	for (i = 1; i<N; i++){
		if(a[i] == i){
			if(prime_count[i]%2 ==1) mobius[i] = -1;
			else mobius[i] = 1;
		}
		else{
			mobius[i] = 0;
		}
	}
	
}

signed main() {
	mobius_sive();
	for (int i=0; i<30; i++){
		cout<< mobius[i]<<" ";
	}
			
	return 0;
}
