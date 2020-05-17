#include <bits/stdc++.h>
#include <algorithm>

long long gcd(long long a, long long b, long long &x, long long &y)
{
   if(a==0)
   {
       x = 0;
       y = 1;
       return b;
   }
   long long x1, y1;
   long long d = gcd(b%a, a, x1, y1);
   x = y1 - (b/a)*x1;
   y = x1;
   return d;
}

class CRT
{
    long long pro;
    long long ans;
public:
    
    CRT(std::vector<long long> a, std::vector<long long> m)
    {
        int n = a.size();
        long long x;
        std::vector<long long> M(n);
        std::vector<long long> y(n);

        pro = 1ll;
        ans = 0ll;

        for(int i = 0 ; i < n; i++)
        {
            pro *= m[i];
        }

        for(int i = 0 ; i < n; i++)
        {
            M[i] = pro/m[i];
            y[i] = pow(M[i], m[i]-2, m[i]);
            ans = ans%pro +  (M[i]*y[i]*a[i]) % pro;
            ans %= pro;
        }

    }

    long long pow(long long a, long long b, long long mod)
    {
        long long ans = 1ll;
        while(b)
        {
            if(b&1)
            {
                ans *= a;
                ans %= mod;
            }
            a *= a;
            a %= mod;
            b >>= 1;
        }
        return ans;
    }

    long long getAns()
    {
        return ans;
    }
};

int run(int x)
{
    std::queue<int> que;
    que.push(3);
    que.push(7);


    int a, count = 0;
    while(que.front() <= x)
    {
        count++;
        a = que.front();
        que.pop();
        que.push(a*10+3);
        que.push(a*10+7);
    }
    return count;
}

int main()
{

    CRT crt({2, 3, 2},{3, 5, 7});

    std::cout<< crt.getAns()<<"\n";
//    std::cout<< run(773);
    return 0;
}
