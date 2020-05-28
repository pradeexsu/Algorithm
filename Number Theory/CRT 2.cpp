#include<bits/stdc++.h> 
#define int long long
using namespace std; 

int inv(int a, int m) 
{ 
	int m0 = m, t, q; 
	int x0 = 0, x1 = 1; 

	if (m == 1) 
	    return 0; 
	while (a > 1) 
	{ 
		// q is quotient 
		q = a / m; 

		t = m; 

		m = a % m, a = t; 
		t = x0; 
		x0 = x1 - q * x0; 
		x1 = t; 
	} 

	if (x1 < 0) 
		x1 += m0;
	return x1; 
} 

// k is size of num[] and rem[]. Returns the smallest 
// number x such that: 
// x % num[0] = rem[0], 
// x % num[1] = rem[1], 
// .................. 
// x % num[k-2] = rem[k-1] 
// Assumption: Numbers in num[] are pairwise coprime 
// (gcd for every pair is 1) 
int findMinX(int *num, int *rem, size_t k, int prod=1) 
{ 
	// Compute product of all numbers 
	// int prod = 1; 
	// for (size_t i = 0; i < k; i++) 
	// 	prod *= num[i]; 

	// Initialize result 
	int result = 0; 

	// Apply above formula 
	for (size_t i = 0; i < k; i++) 
	{ 
		int pp = prod / num[i]; 
		result += ((rem[i] * inv(pp, num[i]))%prod * pp)%prod; 
		result %= prod;
	}
	return result; 
} 

// Driver method 
signed main() 
{ 
	size_t n;
	cin>>n;
	int *a = new int[n]; 
	int *r = new int[n];
	int prod = 1;
	for (size_t i=0; i<n; i++){
		scanf("%lld",i+a);
		prod*=a[i];
	}
	for (size_t i=0; i<n; i++)
		scanf("%lld",i+r);
	
	printf("%lld",findMinX(a, r, n, prod)); 
	return 0; 
} 

