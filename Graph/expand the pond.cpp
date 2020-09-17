#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
vector<pair<int,int>> xy={{0,1},{1,0},{0,-1},{-1,0}};

void floo_fill(int i,int j , int m, int n, vector<vector<int>> &pond, int comp){
    if(i>=m or j>=n or i<0 or j<0 or pond[i][j]!=1)
        return;
    pond[i][j] = comp;
    for(auto pr: xy){
        floo_fill(i+pr.x, j+pr.y, m,n, pond, comp);
    }
}

int main(){
	int m,n;
	cin>>m>>n;
	vector<vector<int>> p(m, vector<int>(n));
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i=0;i<m;i++ ){
		for (int j=0; j<n; j++)
			cin>>p[i][j];
	}
    int comp = 1;
    unordered_map<int,int> size;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if(p[i][j]==1){
                floo_fill( i, j, m, n, p, ++comp);
            }
            if(p[i][j]!=0)
                size[p[i][j]]++;
        }
    }
    
    int max_ = 1;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if(p[i][j]==0){
                set<int> comps;
                for (auto pr: xy){
                    int xx = pr.x +i;
                    int yy = pr.y +j;
                    if(xx>=m or yy>=n or xx<0 or yy<0 or p[xx][yy]==0)
                        continue;
                    comps.insert(p[xx][yy]);
                }
                int ans = 1;
                for (auto types: comps)
                    ans += size[types];
                max_ = max(max_, ans);
            }
        }
    }
    cout<<max_<<endl;
        // for (int i=0; i<m; i++){
    //     for (int j=0; j<n; j++){
    //         cout<<p[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // for (int i=0; i<m; i++){
    //     for (int j=0; j<n; j++){
    //         cout<<size[p[i][j]]<<" ";
    //     }
    //     cout<<endl;
    // }
	return 0;
}