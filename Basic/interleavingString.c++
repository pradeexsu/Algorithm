#include<bits/stdc++.h>
using namespace std;
class Solution {
   map<pair<int,int>,bool>dp;
   map<pair<int,int>,bool>visited;
public:
    Solution(){
    }
    
    bool isInterleave(string s1, string s2, string s3) {
         if(s1.size()+s2.size() != s3.size())
            return false;
        return is_inter_leave(s1, s2, s3, 0, 0, 0);
    }
    
    bool is_inter_leave(string s1, string s2, string s3, int i, int j, int k){
        if(visited[{i,j}])
            return dp[{i,j}];

        if(i==s1.size()){
            visited[{i,j}] = true;
            return dp[{i,j}] = (s2==s3.substr(k));
        }
        
        if(j==s2.size()){
            visited[{i,j}] = true;
            return dp[{i,j}] = (s1==s3.substr(k));
        }

        if(s1[i]==s3[k] && is_inter_leave(s1,s2,s3, i+1, j, k+1)){
            visited[{i,j}] = true;
            return dp[{i,j}] = true;
        }
        
        if(s2[j]==s3[k] && is_inter_leave(s1,s2,s3, i, j+1, k+1)){
           visited[{i,j}] = true;
            return dp[{i,j}]=true;
        }
        
        visited[{i,j}] = 1;
        return dp[{i,j}] = false;
    }
};
int main(){
    Solution s;
    string s1="aabcc",s2="dbbca", s3 = "aadbbcbcac";
    cout<<s.isInterleave(s1, s2, s3);
    return 0;
}