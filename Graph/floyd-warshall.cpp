                        //directed edges
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define inf 0xfffffff
using namespace std;

void floyd_warshall(int G[][400], int &n){
    for(int k=0; k<n; k++)  {
       for(int i=0; i<n; i++)  {
          for(int j=0; j<n; j++)  {
             G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
          }
        }
    }

}

int main(){
    int n,w,x,y,e;
    // cout<<"input: ";
    cin>>n>>e;

    int G[n][400];
    for(int i=0; i<n; i++){
        fill_n(G[i],n,inf);
        G[i][i] = 0;
    }
    for (int i=0; i<e; i++){
        cin>>x>>y>>w;
        G[x-1][y-1] = w;
    }
    int q;
    
    cin>>q;
    // cout<<"output: \n";
    floyd_warshall(G,n);
    for (int i=0; i<q; i++){
        cin>>x>>y;
        if(G[x-1][y-1]==inf)
            cout<<"-1\n";
        else
            cout<<G[x-1][y-1]<<'\n';
    }
    return 0;
}
