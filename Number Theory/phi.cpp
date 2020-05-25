#include <iostream>

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

void computeTotient(int n) 
{ 
	long long phi[n+1]; 
	for (int i=1; i<=n; i++) 
		phi[i] = i;

	for (int p=2; p<=n; p++) 
	{ 
		// If phi[p] is not computed already, 
		// then number p is prime 
		if (phi[p] == p) 
		{
			// Phi of a prime number p is 
			// always equal to p-1. 
			phi[p] = p-1; 
			// Update phi values of all 
			// multiples of p 
			for (int i = 2*p; i<=n; i += p) 
			{ 
			// Add contribution of p to its 
			// multiple i by multiplying with 
			// (1 - 1/p) 
			phi[i] = (phi[i]/p) * (p-1); 
			} 
		} 
	} 

	for (int i=1; i<=n; i++) 
		std::cout << "Totient of " << i << " is " << phi[i] << '\n'; 
} 
int main(){
	//std::cout<<phi(18);
	computeTotient(18);
	return 0;
}
