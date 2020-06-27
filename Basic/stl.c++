#include<string>
#include<set>
#include<unordered_set>
#include<list>
#include<deque>
#include<algorithm>
#include<tuple>
#include<vector>
#include<iostream>
using namespace std;

template<typename temp>
void print(temp &x){
        for(auto &i:x)
            cout << i<< " ";
    cout<<endl;
}
namespace str{
    void string_demo(){
        string s1;
        s1= "hello";
        string s2(s1,3,2);  //   string (string obj, starting index, char count );
        string s ("this is stl",7);     //string (char const , char count );
        cout << s << endl;
        string ss(5,'-');  // string (reapte times, char);
        cout << ss <<endl;
        auto sx = string(s1.begin(), s1.end()-2);  // string (iter to first , iter to last );
        // append(string)  it add's at end and return also ...
        cout << sx <<endl;
        cout << sx.append("xxx") << endl;
        cout << sx << endl;
        sx.clear();
        cout<< sx<<"---\n";

        cout << string("this").compare("thzsi")<<endl;
        cout<< ("this" > "thsi")<<endl;
        cout<< ("this" < "thsi")<<endl;
        char cpy[20];
        string str;
        size_t sz = string("algorithm").copy(cpy, 4,2);     //  string.copy( char *, len, pos );  only copid into char* ...
        cpy[4] = '\0';
        cout<<"size : "<<sz <<" > " << cpy<<endl;
        // copy algoritm ...
        int arr[]{1,2,3,4,5};
        int ar[4];
        copy(arr,arr+4,ar);
        for(int &i: ar)
            cout<< i<< " ";
        cout<<endl<< str.empty()<<endl;
        cout<<string("algorithms").erase(4,5); // earse( pos , number of chars )    ;
        cout<< string("algo").find("go")<<endl;

        if(string("algo").find("go",3) == string::npos) 
            cout<< "string go not found !"<< endl;
        auto x = string("algo");
        cout << x.insert(4," this ")<<endl;
        cout<<(x.length()== x.size()) <<endl;
        cout<<x.substr(2,2)<<endl;  // string.substr(start pos, char count );

        return ;
    }
}
namespace linear{
    
    void vector_demo(){
        vector<int> p{1,5,7,-1};

        for(auto &i:p)
        cout << i<< " ";
        auto &x = p;
        cout<<endl<< (x.at(3)+= 5);
        // x.clear();
        cout<<endl;
        x.erase(x.end()-1);
        print(x);
        x.push_back(3);
        print(x);
        x.pop_back();
        print(x);
        // x.insert(2,1);
        x.insert(x.end(),x.begin(),x.end());
        x.insert(x.end()-3,100000);
        print(x);
        x.insert(x.end(), 999999);
        print(x);
        x.resize(6);
        print(x);
        x.reserve(15);
        cout<<"size : "<<x.size()<<endl;
        cout<<"capacity : "<<x.capacity()<<endl;
        x.shrink_to_fit();
        cout<<"size : "<<x.size()<<endl;
        cout<<"capacity : "<<x.capacity()<<endl;

        print(x);

        

        return ;
    }

    void list_demo(){
        list<int> l1(4,-1);
        list<int> l2(5,100);
        list<int> l3(l1.rbegin(),l1.rend());      // only forward iterator...
        print(l1);
        print(l2);
        cout<<l1.empty()<<endl;
        l3.assign(l2.begin(),l2.end());     // renew th e list...
        print(l3);
        auto iter = l3.begin();
        *iter = 1;
        iter++;
        *iter = 2;
        auto iter2 = iter;
        iter++;
        *iter = 3;
        iter++;
        l3.erase(iter2);
        print(l3);
        l3.erase(iter,l3.end());
        print(l3);
        cout<<"front : "<<l3.front() << ", back : "<<l3.back()<<endl;
        l3.push_back(11);
        for(int i=0;i<5;i++)
            l3.push_back(10);   

        l3.push_front(-1);
        l3.pop_back();
        l3.pop_front();
        print(l3);
        l3.remove(10);
        print(l3);
        l3.reverse();
        print(l3);
        cout<<l3.size();
        iter = l3.begin();
        iter++;
        iter++;
        auto its = l2.end();
        its--;
        l3.insert(iter, l2.begin(), its);
        l3.insert(iter, 7);
        l3.insert(iter, 7);
        print(l3);
        return ;
    }

    void pair_demo(){
        vector<pair<char, int>> p{ {'a', 2}, {'b', 3}, {'c', 7} };
        p.push_back({'t', 9});
        p.push_back(make_pair('t', 20));
        p.push_back(make_pair('O', 2));
        sort(p.begin(), p.end());
        p[0].swap(p[1]);
        char chr = get<0>(p[0]) + get<1>(p[0]);
        cout<< chr <<endl;
        for(auto i:p){
            cout << i.first <<" : "<< i.second << ", ";
        }
            cout<<"\b\b ";
            cout<<endl;
        return ;
    }
    void forward_list_demo(){

    } 
}

namespace associative{
    template<typename T>
    T merg(T &t1, T &t2){
        t1.insert(t2.begin(), t2.end());
        return t1;
    }
    void set_demo(){        //multiset ...
        string arr[]={"pradeep","divya","love","school","love","crush","crush"};
        set<string> str(arr, arr+7);
        print(str);
        str.clear();
        cout << str.empty()<<endl;
        auto feedback = str.insert("life");
        cout<<*feedback.first <<", "<< feedback.second ;
        str.insert({"love","crush","love"});
        str.insert(arr,arr+3);
        auto iter = str.begin();
        iter++;
        iter = str.insert(iter++,"fu*k");
        cout<<endl<< *iter;
        cout<<endl;
        print(str);
        auto iterat = str.end();
        iterat--;
        str.erase(iter,iterat);
        print(str);
        cout<<endl;
        
        return ;
    }
    void unorderd_set_demo(){
        unordered_set<string> s1;
        unordered_set<string> s2{"one", "two", "three"};
        unordered_set<string> s3{"four", "five", "six"};
        unordered_set<string> s4( merg(s2, s3 ) );
        for(const std::string&i: s4)
            cout<<i<<" ";
        
        
        return ;

    }
    void map_demo(){        // multimap ...

        return ;
    }

}

namespace indexed_sequance_container{
    //  deque ...
    /*
        1.  fast insertion at both the ends
    */
   void deque_demo(){
       {
           std::deque<int> dq{2, 3, 4};
           dq.push_front(1);
           dq.push_back(5);
           print(dq);
       }

        {
           std::deque<int> dq(4,1000);
           dq.pop_front();
           dq.pop_back();
           dq.push_back(7);
           dq.push_back(7);
           cout<<*dq.begin() << " "<< dq.front() << " " << dq.back();
           print(dq);
            cout<< (dq.at(3) += 3 )<<endl;
            print(dq);
        }

   }
    void spoj_deque(){
        int n, k,i;
        cin>>n;
        int *arr = new int[n];
        for(i=0;i<n;i++)
            scanf("%d",arr+i);
        cin>>k;
        deque<int>Q(k);
        
        for(i=0 ; i < k ; i++){
            while(!Q.empty() and  arr[ i ]>= arr[ Q.back() ])
                Q.pop_back();
            Q.push_back(i);
            
        }
        
        
        for(;i<n;i++){
            printf("%d ",arr[Q.front()]);
            while(!Q.empty() and Q.front() <= i-k)
                Q.pop_front();
            while(!Q.empty() and arr[i] >= arr[Q.back()])
                Q.pop_back();
            Q.push_back(i);
        }
        printf("%d\n",arr[Q.front()]);

    }
}

int main(){
    // str::string_demo();
    // linear::vector_demo();

    // linear::list_demo();
    // linear::pair_demo();

    // associative::set_demo();
    // indexed_sequance_container::deque_demo();
    // associative::map_demo();
    // indexed_sequance_container::spoj_deque();

    // set<int> a{1,2,3};
    // cout<<a.erase(5);
    associative::unorderd_set_demo();
    return 0;
}