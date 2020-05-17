#include "bits/stdc++.h"
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

struct node{
    char ch;
    bool terminal;
    int ccount;
    unordered_map<char,node*> child;
    node(char c);
};

node::node(char c) {
    ch = c;
    ccount = 1;
    terminal = false;
}

class Trie{
    node *root;
    int count;
public:
    Trie(){
        root = new node('\0');
        count = 0;
    }

    void add_word(string str){
        auto temp = root;
        for(char ch : str){
            if(temp->child.count(ch)){
                temp->ccount++;
                temp = temp->child[ch];
            }
            else{
                node *nod = new node(ch);
                temp->child[ch] = nod;
                temp = nod;
            }
        }
        temp->ccount++;
        temp->terminal = true;
    }

    int search_word(string str){
        auto temp = root;
        for(char ch : str){
            if(temp->child.count(ch)){
                temp = temp->child[ch];
            }
            else{
                return 0;
            }
        }
        return temp->ccount;
    }
};

int main() {

    fast
    Trie tree;
    int q;
    string type,s;
    cin>>q;
    while(q--){
        cin>>type>>s;
        if(type[0]=='a')
            tree.add_word(s);
        else
            cout<<tree.search_word(s)<<"\n";
    }
    return 0;
}

