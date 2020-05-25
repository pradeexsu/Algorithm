#include<iostream>
#define MAX 1000102
unsigned long long phi[MAX + 7];
	//Complexity : Sqrt(N)
int phi(int n) {
	int result = n;
	
	for (int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			while(n % i == 0)
				n /= i;
			result -= result / i;
			}
	}
	if(n > 1)
		result -= result / n;

	return result;
}
	//Complexity : O(N*loglongN)

/**
 * It took 0.902 secs to generate up to 1e7.
**/
void get(){
    phi[1] = 1;
	for (int i = 2; i <= MAX; i++) {
        if(!phi[i]) {
            phi[i] = i-1;
            for (int j = 2*i; j <= MAX; j += i) {
                if (!phi[j])
			phi[j] = j;
				
                phi[j] = (phi[j] * (i-1)) / i;
            }
        }
    }

}
int main() {
	int q, n;
	scanf("%d",&q);
	get();
	while(q--){
		scanf("%d",&n);
		printf("%llu\n",phi[n]);
	}
	return 0;
}
