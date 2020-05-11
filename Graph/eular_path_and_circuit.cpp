#include <bits/stdc++.h>
#include <algorithm>

struct Graph
{
    int v;
    std::set<int> *edj_list;
    
    Graph(int n)
    {
        int v = n+1;
        edj_list = new std::set<int>[n+1];

    }
    void add_edj(int v, int u)
    {
        edj_list[v].insert(u);
        edj_list[u].insert(v);
    }

    void remove_edj(int u, int v)
    {
        edj_list[v].erase(u);
        edj_list[u].erase(v);
    }

    void eular_path(int u)
    {
        if(edj_list[u].empty())
        {
            std::cout<<u<<" :";
            return;
        }
        int v = *edj_list[u].begin();
        std::cout << u <<" -> ";
        remove_edj(v,u);
        eular_path(v);
    }

    bool eular_path2(int u)
    {
        int first = u, last;
        while(true){
            if (edj_list[u].empty())
            {
                std::cout << u << " :\n";
                last = u;
                break;
            }
            int v = *edj_list[u].begin();
            std::cout << u <<" -> ";
            remove_edj(v,u);
            u = v;
        }
        return first==last;
    }


};

void func()
{
    Graph graph(5);
    graph.add_edj(1,2);
    graph.add_edj(1,3);
    graph.add_edj(2,3);
    graph.add_edj(3,5);
    graph.add_edj(3,4);
    graph.add_edj(4,5);
    /*
     
      1     4
      | \ / |
      |  3  |   
      | / \ |
      2     5
    
    */   
    // this function return true if eular circuit is exist else false
    bool eular_circuit_exist = graph.eular_path2(2); 
    std::cout<<'\n';
    if (eular_circuit_exist)
        std::cout<<"eular circuit exist\n";
    else
        std::cout<<"eular circuit not exist\n";
        
    
}

void func2()
{
    Graph graph(4);
    /*
     1--------2
      \     /  \
        \  /    \
         4--------3
    */

    graph.add_edj(1,2);
    graph.add_edj(1,4);
    graph.add_edj(2,4);
    graph.add_edj(2,3);
    graph.add_edj(3,4);
    graph.eular_path2(2); 

}

int main() 
{

    func();
    func2();
    return 0;
}

//     output :
// 2 -> 1 -> 3 -> 2 :

// eular circuit exist
// 2 -> 1 -> 4 -> 2 -> 3 -> 4 :
