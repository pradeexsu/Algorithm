#include<iostream>
#include<bitset>
using namespace std;
bitset<20>col, d1, d2;

int n;
int ans =0 , DONE;

///rowmask denote which positions(colms) in all rows are filled
/// ld, rd denotes unsafe positions along diagonals for the current row
/// done is vector of all 11111 ( n times 1 )
/// safe denotes the cols which are safe in the current row

/// Most optimisized n queen code !
void nqueen(int);
void solve(int, int, int);
int main()
{
	scanf("%d",&n);

	DONE = ((1<<n) - 1);
	//solve(0, 0, 0);
	
	nqueen(0);

	printf("%d\n",ans);

}

void nqueen(int r){
	if(r==n){ ans++; return; }
	for(int c = 0; c < n; c++)
		if(!col[c] && !d1[ r-c + n - 1 ] && !d2[ r + c ]){
			col[c] = d1[ r-c + n - 1 ] = d2[ r + c ] = 1;
			nqueen(r+1);
			col[c] = d1[ r-c + n - 1 ] = d2[ r + c ] = 0;
		}
}
void solve(int rowMask,int ld,int rd){

	if(rowMask==DONE){ ans++; return; }
	int safe = DONE&(~(rowMask|ld|rd));	
	while(safe){
		int p = safe &(-safe);
		safe = safe - p;
		solve(rowMask|p, (ld|p)<<1, (rd|p)>>1);
	}
}

