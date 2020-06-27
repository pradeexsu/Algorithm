#include<iostream>
using namespace std;

bool ratInMaze( char maze[1000][1000], int sol[1000][1000], int i, int j, int m, int n){
	// base case ...
	if( i==m && j== n){
		sol[m][n] = 1;
		// print path 
		for(int u=0; u<=m;u++){
			for(int k=0;k<=n;k++){
				cout<<sol[u][k]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return true;
	}
	// Rat should be inside grid.
	if( i>m || j>n){
		return false;
	}
	if( maze[i][j] == 'X'){
		return false;
	}
	// Assume solution exists through current cell
	sol[i][j] = 1;
	bool rightSuccess = ratInMaze( maze, sol, i, j+1, m, n);
	if(rightSuccess)
		return true;
	bool leftSuccess = ratInMaze( maze, sol, i+1, j, m, n);
	if(leftSuccess)
		return true;
	// Back tracking 
	sol[i][j] = 0; 
//	if(rightSuccess || leftSuccess){
//		return true;
//	}
		return false;
}


int main(){
	char maze[1000][1000];
	int board[1000][1000]={0};
	int m,n;
	cin>>m>>n;
	for( int i=0; i<m; i++){
		for(int j=0; j<n; j++)
			cin>>maze[i][j];
	}
	bool path = ratInMaze(maze, board, 0, 0, m-1, n-1);
	if(!path)
		cout<<"-1";
	
	return 0;
}
