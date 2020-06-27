#include<bits/stdc++.h>

using namespace std;
pair<int,int> get_inter(set<pair<int,int>> &p, int n)  {
    set<pair<int,int>>::iterator it = p.upper_bound({n+1, INT_MAX});
    it--;
    return *it;
}
tuple<int, string, int> getData(int n)  {
    if(n&1)
        return {7, "pradeep",8};
    return make_tuple(4, "suthar",5);
}


int main(){
    set<pair<int,int > > s{{10,12},{13,17},{6,6},{6,8},{6,7},{70,100}};
    
    for(const pair<int,int> &i:s){
        cout <<"{ "<< i.first<<", "<< i.second<<" },  ";
    }
    cout<<endl;
    // for(const pair<int,int> &i:s){
    //     cout <<"{ "<< i.first<<", "<< i.second<<" },  ";
    // }
    
    // cout<<"hi"<<endl;
    // is any intervel contain number ...
    // int n;
    // cin>>n;
    // auto geted = get_inter(s,n);
    // cout<<endl<< "{"<<geted.first<<","<<geted.second<<"}";
    vector<int>v{1, 2, 3, 4, 5};
    int init = 2;
    int ac = accumulate(v.begin(), v.end(), 1, [](int x,int y){ return 2*x + y ;});
    cout << endl << ac<<endl;
    int result[5];
    partial_sum(v.begin(), v.end(), result, std::multiplies<int>());
    for(int i:result){
        cout<< i<< " ";
        }
        cout<<endl;

    partial_sum(v.begin(), v.end(), result, [](int x,int y){ return 2*x+2*y ; });
    for(int i:result){
        cout<< i<< " ";
        }
        cout<<endl;
    partial_sum(v.begin(), v.end(), result, [](int x,int y){ return 2*y ; });
    for(int i:result){
        cout<< i<< " ";
        }
        cout<<endl;
    int age;
    int rol;
    string name; 
    tie(rol, name, age) = getData(1);
    cout<<rol<<" "<<name<<" "<<age<<endl;
    tie(rol, name, age) = getData(2);
    cout<<rol<<" "<<name<<" "<<age<<endl;
    // tuples are comparable....
    tuple<int,int,int> time1={1,2,3},time2={1,3,2};
    if(time1>time2)
        cout<<"yes\n";
    else
        cout<<"no\n";
    // tuple are used as multi valued key
    map<tuple<int, string, float>,string> m;
    m[make_tuple(77424,"key",17746)] = "pradeep's mobail number ";
    cout<<m[{77424,"key",17746}] <<endl;
    cout<< (rand()%3)<<endl;
    return 0;
}