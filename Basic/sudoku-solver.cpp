#include <iostream>
#include <cmath>
using namespace std;

bool canPlace( int sudko[][9], int i, int j, int n, int number){
	
	for(int x=0;x<n;x++){
		// row and colm chek
		if(sudko[x][j]==number||sudko[i][x]==number){
			return false;
		}
	 }
	
	int rn =sqrt(n);
	int sx = (i/rn)*rn;
	int sy = (j/rn)*rn;
	for(int x =sx;x<sx+rn;x++){
		for(int y=sy;y<sy+rn;y++){
			if(sudko[x][y]==number){
				return false;
			}
		}
	}
	return true;
}

bool solveSudko( int sudko[][9], int i, int j, int &n){
	// (3) Base Case
//	cout<<i<<", "<<j<<endl;

	if(i==n){	// 1
		// print
		for(int k=0;k<n;k++){
			for(int u=0;u<n;u++){
				cout<<sudko[k][u]<<" ";
			}
			cout<<endl;
		}
		return true;
	}


	if(j==n){	// 2
		return solveSudko(sudko, i+1, 0,n);
	 }


	//skip pre-filled cells
	if(sudko[i][j]!=0){		// 3.
		return solveSudko(sudko, i, j+1, n);
	 }


	// Recursive Case...
	for(int number =1;number<=n;number++){
		if(canPlace(sudko,i,j,n,number)){
			// Assume 
			sudko[i][j] = number;
			bool couldWeSolve = solveSudko(sudko,i,j+1,n);
			if(couldWeSolve==true){
				return true;
			}
		}
	}

	sudko[i][j]=0;
	return false;
}
int main(){
	/* int mat[9][9]={
		{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}
	 };
	*/
	int mat[9][9];
	int n=9;
	cin>>n;
	
	for (int i=0;i<n;i++)
		for(int j=0;j<n; j++){
			cin>>mat[i][j];
		}
	solveSudko(mat,0,0,n);
	return 0;
}

/*
	pradeep@7:~/cp$ c++ sudko.cpp 
	pradeep@7:~/cp$ ./a.out
		5 3 4 6 7 8 9 1 2 
		6 7 2 1 9 5 3 4 8 
		1 9 8 3 4 2 5 6 7 
		8 5 9 7 6 1 4 2 3 
		4 2 6 8 5 3 7 9 1 
		7 1 3 9 2 4 8 5 6 
		9 6 1 5 3 7 2 8 4 
		2 8 7 4 1 9 6 3 5 
		3 4 5 2 8 6 1 7 9 
*/
