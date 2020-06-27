#include <iostream>
#include<deque>
using namespace std;

int main() {
    int n, k;
    int *a;
    scanf("%d", &n);
    a = new int[n];

    for(int i=0; i<n; i++){
        scanf("%d", a+i);
    }
    scanf("%d", &k);    
    //We have to process first k elements separtely
    deque<int> Q(k);
    int i;
    for(i=0; i<k; i++){
        while (!Q.empty() &&a[i]>a[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i);
        
    }
    //Process the remaining elements 
    for (; i<n; i++){
        printf("%d ", a[Q.front()] );        
        //1. Remove the elements which are not the part of the window(Contraction)
        while ((!Q.empty() && (Q.front()<=i-k))){
            Q.pop_front();
        }
        
        //2. Remove the elements which are not useful and are in window
        while (!Q.empty() && a[i]>=a[Q.back()]){
            Q.pop_back();   
        }
        //3. Add the new elements(Expansion)
        Q.push_back(i);
    }
    
    printf("%d", a[Q.front()]);
    
    
    return 0;
}
