#include<bits/stdc++.h>
#define ll long long
#include <queue>
//#define prime 119
using namespace std;
int reset[1000];
int go(int n){
	queue<ll>q;
	ll x;
	q.push(9);
	while(true){
		x = q.front();
			q.pop(); 
		if(x%n==0)
			return x;
		q.push(x*10);
		q.push(x*10 + 9);
	}
	return x;
}

void KMPpreporocess(string patt){
	int i = 0, j = 1;
	reset[0] = - 1;
	while(i<patt.size()){
		// check for resetting
		while(j >= 0 and patt[i]!=patt[j]){
			j = reset[j];
		}
		j++;
		i++;
		reset[i] = j;
	}
}
void KMPsearch(string str, string patt){
	KMPpreporocess(patt);
	int i = 0, j = 0;
	while(i<str.size()){
		while(j>0 and str[i]!=patt[j]){
			j = reset[j];
		}
		j++;
		i++;
		if(j==patt.size()){
			cout<<"Pattern is found at : "<<i-j<<endl;
			j=reset[j];
		}
	}
}

int main(int argc, char const *argv[]){
	string str = "ababcabdab";
	string pat = "abd";
	// int n=260;
	// bool f=0;
	// cout<<go(n)<<endl;
	memset(reset,-1,4000);
	KMPsearch(str,pat);
	return 0;
	}