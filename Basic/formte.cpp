#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
//#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<stdio.h>
// #include <iostream>
// #include<bits/stdc++.h>
// #define fast ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
using namespace std;

#define abs(a)                (a<0)? (-1*a) : a
#define all(p)                p.begin(),p.end()
#define clr(x)                x.clear()
#define eb                    emplace_back
#define gc                    getchar_unlocked
#define ll                    long long
#define max(x,y)              (x>y)?x:y
#define mid(s,e)              (s+(e-s)/2)
#define min(x,y)              (x<y)?x:y
#define mod                   int(1e9)+7
#define nl                    pc('\n');
#define pb                    push_back
#define pc                    putchar_unlocked
#define pii                   pair<int,int>
#define pll                   pair<ll,ll>
#define vi                    vector<int>
#define vvi                   vector<vi>
inline void                   input(int&);
inline void                   input(ll&);
inline void                   print(int);
inline void                   print(ll);
int main() {
    ll n;
    int t;
    input(t);
    while(t--)
    {
        input(n);
         //printf("%d",t);
        // nl;
        printf("%lld",n);
        nl
    }
	return 0;
}
// ll extgcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extgcd(b,a%b,y,x);y-=a/b*x;return g;}}
// ll modpow(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}


//              fast io
inline void input(int &n) { n=0; char c=gc(); while(c<'0' or c>'9') c=gc(); while(c>='0' and c<='9') { n=(n<<3)+(n<<1)+c-'0'; c=gc(); }}
inline void input(ll &n) { n=0; char c=gc(); while(c<'0' or c>'9') c=gc(); while(c>='0' and c<='9') { n=(n<<3)+(n<<1)+c-'0'; c=gc(); }}
inline void print(int a) { char s[20]; int i=0; do { s[i++]=a%10+'0'; a/=10; } while(a); i--; while(i>=0) pc(s[i--]); /*pc('\n');*/ }
inline void print(ll a) { char s[20]; int i=0; do { s[i++]=a%10+'0'; a/=10; } while(a); i--; while(i>=0) pc(s[i--]); /*pc('\n');*/ }
