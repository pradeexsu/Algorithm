#include<bits/stdc++.h>
using namespace std;
int dp[3001][3001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s,t;
	cin>>s>>t;
	int n = s.size();
	int m = t.size();
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			if(s[i-1]==t[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else{
				dp[i][j] = max(dp[i][j-1], dp[i-1][j] );	
			}
		}
	}
//	cout<<"* * ";
//	for (int i=0;i<=m;i++)cout<<t[i]<<" ";
//	cout<<"\n";
//	for (int i=0; i<=n; i++){
//		if(i==0)
//			cout<<"* ";
//		else
//			cout<<s[i-1]<<" ";
//		for(int j=0; j<=m; j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<"\n";
//	}

	list<char> lcs;
   
 int i = n, j = m;
   while (i > 0 && j > 0)
   {

      if (s[i-1] == t[j-1])
      {
          lcs.push_front( s[i-1] );
          i--; j--;
      }

      else if (dp[i-1][j] >= dp[i][j-1])
         i--;
      else
         j--;
   }
	for (auto c:lcs)cout<<c;
	return 0;
};
