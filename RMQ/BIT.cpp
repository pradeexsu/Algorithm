#include <iostream>
using namespace std;
int MaxIdx = 20;
int tree[101];

void update(int idx, int val){
    while (idx <= MaxIdx){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int readSingle(int idx){
    int sum = tree[idx]; // this sum will be decreased
    if (idx > 0){ // the special caseint 
        int z = idx - (idx & -idx);
        idx--; // idx is not important anymore, so instead y, you can use idx
        while (idx != z){ // at some iteration idx (y) will become z
            sum -= tree[idx]; 
                        // substruct tree frequency which is between y and "the same path"
            idx -= (idx & -idx);
        }
    }
    return sum;
}

void scale(int c){
    for (int i = 1 ; i <= MaxIdx ; i++)
        tree[i] = tree[i] / c;
}

int main() {
    
    update(1,6);
    scale(3);
    update(2,3);
    update(4,2);
    update(7,1);
    update(9,10);
    cout<<read(7)<<"\n";
    cout<<"->";
    cout<<readSingle(1)<<"\n";
    cout<<readSingle(8)<<"\n";
    cout<<readSingle(9)<<"\n";
    cout<<readSingle(7)<<"\n";
    return 0;
}
