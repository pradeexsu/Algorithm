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

void func(){
    Graph graph(4);
    graph.add_edj(1,2);
    graph.add_edj(1,4);
    graph.add_edj(2,4);
    graph.add_edj(2,3);
    graph.add_edj(3,4);
    graph.eular_path2(2);

}



int main() {

    func();
    return 0;
}
