#include<stdio.h>
// #include <iostream>
// #include<bits/stdc++.h>
// #include <cmath>
// #define fast ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
using namespace std;
#define nl                    printf("\n");
#define ll                    long long
#define all(p)                p.begin(),p.end()
#define pb                    push_back
#define eb                    emplace_back
#define abs(a)                (a<0)? (-1*a) : a
#define clr(x)                x.clear()
#define vi                    vector<int>
#define vvi                   vector<vi>
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>
#define max(x,y)              (x>y)?x:y
#define min(x,y)              (x<y)?x:y
#define mid(s,e)              (s+(e-s)/2)
#define mod                   int(1e9)+7
#define pc                    putchar_unlocked
#define gc                    getchar_unlocked

// template<typename... T>
// void read(T&... args){
//     ((cin >> args), ...);
// }

// template<typename... T>
// void write(T&&... args){
//     ((cout << args << " "), ...);
// }
inline void input(int&);
inline void input(ll&);
// inline void print(int);
// inline void print(ll);
int main() {
    ll n;
    int t;
    input(t);
    while(t--)
    {
        input(n);
        // printf("%d",t);
        // nl;
        printf("%lld",n);
        nl
    }
	return 0;
}


inline void input(int &n) { n=0; char c=gc(); while(c<'0' or c>'9') c=gc(); while(c>='0' and c<='9') { n=(n<<3)+(n<<1)+c-'0'; c=gc(); }}
inline void input(ll &n) { n=0; char c=gc(); while(c<'0' or c>'9') c=gc(); while(c>='0' and c<='9') { n=(n<<3)+(n<<1)+c-'0'; c=gc(); }}
// inline void print(int a) { char s[20]; int i=0; do { s[i++]=a%10+'0'; a/=10; } while(a); i--; while(i>=0) pc(s[i--]); /*pc('\n');*/ }
// inline void print(ll a) { char s[20]; int i=0; do { s[i++]=a%10+'0'; a/=10; } while(a); i--; while(i>=0) pc(s[i--]); /*pc('\n');*/ }
