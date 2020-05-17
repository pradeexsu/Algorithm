#include <bits/stdc++.h>
#include <algorithm>

struct Graph{
    int v;
    std::set<int> *edj_list;
    Graph(int n){
        int v = n+1;
        edj_list = new std::set<int>[n+1];

    }
    void add_edj(int v, int u){
        edj_list[v].insert(u);
        edj_list[u].insert(v);
    }

    void remove_edj(int u, int v){
        edj_list[v].erase(u);
        edj_list[u].erase(v);
    }

    void eular_path(int u){
        if(edj_list[u].empty()){
            std::cout<<u<<" :";
            return;
        }
        int v = *edj_list[u].begin();
        std::cout << u <<" -> ";
        remove_edj(v,u);
        eular_path(v);
    }

    void eular_path2(int u){
        std::stack<int> s;
        s.push(u);

        while(!s.empty()) {
            u = s.top();
            s.pop();
            if (edj_list[u].empty()){
                std::cout << u << " :\n";
                break;
            }
            int v = *edj_list[u].begin();
            s.push(v);
            std::cout << u <<" -> ";
            remove_edj(v,u);
        }
    }


};

long long gcd(long long a, long long b, long long &x, long long &y){
   if(a==0){
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

void func(){
    Graph graph(4);
    graph.add_edj(1,2);
    graph.add_edj(1,4);
    graph.add_edj(2,4);
    graph.add_edj(2,3);
    graph.add_edj(3,4);
    graph.eular_path2(2);
    long long x,y;
    std::cout << gcd(77,31, x, y)<<"\n";
    std::cout<<(x+31)%31<<"\n";

}

class CRT{
    long long pro;
    long long ans;
public:
    CRT(std::vector<long long> a, std::vector<long long> m){
        int n = a.size();
        long long x;
        std::vector<long long> M(n);
        std::vector<long long> y(n);

        pro = 1ll;
        ans = 0ll;

        for(int i = 0 ; i < n; i++){
            pro *= m[i];
        }

        for(int i = 0 ; i < n; i++){
            M[i] = pro/m[i];
            y[i] = pow(M[i], m[i]-2, m[i]);
            ans = ans%pro +  (M[i]*y[i]*a[i]) % pro;
            ans %= pro;
        }

    }

    long long pow(long long a, long long b, long long mod){
        long long ans = 1ll;
        while(b){
            if(b&1){
                ans *= a;
                ans %= mod;
            }
            a *= a;
            a %= mod;
            b >>= 1;
        }
        return ans;
    }

    long long getAns(){
        return ans;
    }
};

int run(int x){
    std::queue<int> que;
    que.push(3);
    que.push(7);


    int a, count = 0;
    while(que.front() <= x){
        count++;
        a = que.front();
        que.pop();
        que.push(a*10+3);
        que.push(a*10+7);
    }
    return count;
}

int main() {

//    CRT crt({2, 3, 2},{3, 5, 7});

//    std::cout<< crt.getAns()<<"\n";
    std::cout<< run(773);
    return 0;
}
