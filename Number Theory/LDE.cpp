
#include <iostream>
using namespace std;

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void print_first_n_solution(int a, int b, int c, int x0, int y0, int g, int n){
    for (int i=0;i<n; i++){
        int xi = x0+(b/g)*i;
        int yi = y0 - (a/g)*i;
        if(a*(xi)+ b*yi == c){
            cout<<i<<"th solution is : "<<a<<"*"<<xi<<" + "<<b<<"*"<<yi<<" = "<<c<<endl;
        }
    }
}

int main() {
    int x, y,a,b,c,g;
    while(cin>>a>>b>>c){
        // int g = ext_euclid(a,b,x,y);
        // cout<<g <<" ="<<a<<"*"<<x<<"+"<<b<<"*"<<y<<endl;
        if(find_any_solution(a, b, c, x , y, g)){
            cout<<"solution exist \n";
            // cout<<a<<"*"<<x<<"+"<<b<<"*"<<y<<" = "<<c<<endl;
            print_first_n_solution(a, b, c, x, y, g, 5);
        }
        else{
            cout<<"no solution exist\n";
        }

    }
}
