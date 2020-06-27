#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
struct point{
int x,y;
    point(int a=0, int b=0):x(a), y(b) {}
    void print(){
        cout<<this->x <<", "<< this->y <<"   ";
    }
    int mod(){
        return x*x + y*y;
    }
};

int main(){
    vector<int> v1{0, 1, 2, 3, 4, 5};
    vector<int> v2{3, 4, 5, 6, 7};

    vector<int> result(10,-1);
    cout<< "Set union : ";
    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
    set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
    // set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), result, greater<int>());
    
    for(int i:result){
        if(i==-1)
            break;
        cout <<  i << " ";
    }
    cout<<endl;
    vector<int> result1(10,-1);
    set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), result1.begin());
    cout<< "Set differ v1 - v2 : ";

    for(int i:result1){
        if(i==-1)
            break;
        cout <<  i << " ";
    }

    cout<<endl;
    cout<< "Set differ v2 - v1 : ";

    vector<int> result2(10,-1);
    set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), result2.begin());
    for(int i:result2){
        if(i==-1)
            break;
        cout <<  i << " ";
    }
    cout<<endl<< "set symetric differnce : ";
    vector<int> result3(10,-1);
    set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), result3.begin());
    for(int i:result3){
        if(i==-1)
            break;
        cout <<  i << " ";
    }

    cout<<endl<< "set intersection : ";
    vector<int> result4(10,-1);
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), result4.begin());
    for(int i:result4){
        if(i==-1)
            break;
        cout <<  i << " ";
    }
    
    cout<<endl<< "merge : ";
    vector<int> result5(15,-1);
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), result5.begin());
    for(int i:result5){
        if(i==-1)
            break;
        cout <<  i << " ";
    }
    cout << endl;
    vector<point> cod{{1,2}, {2,3}, {4,3}, {1,-6},{4,7},{0,2},{1,1}};

    for(auto i:cod)
        i.print();
    cout<<endl;
    sort(cod.begin(), cod.end(),[](point &a, point &b){ return a.mod() < b.mod(); });
    for(auto i:cod)
        i.print();
    cout<<endl;
    
    vector<point> p1{{1,2}, {2,3}, {4,3}, {1,1}};
    vector<point> p2{{1,2}, {1,-6}, {4,7}, {0,2}};
    vector<point> new_re(10,{0, 0});
    sort(p1.begin(), p1.end(), [](point &a, point &b){ return a.mod() < b.mod(); });
    sort(p2.begin(), p2.end(), [](point &a, point &b){ return a.mod() < b.mod(); });
    set_intersection(p1.begin(), p1.end(),
                   p2.begin(), p2.end(), new_re.begin(),
                   [](point &a, point &b){ return a.mod() < b.mod(); }
                    );
    cout << endl;
    for(point &p: new_re){
        if( p.mod() == 0)
            break;
        p.print();
    }
    
    return 0;
}
