// https://leetcode.com/problems/regular-expression-matching/

// #include <utility>
// #include <sstream>
// #include <map>
// #include <deque>
// #include <cstring>
// #include <cmath>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;
// #define int long long int
#define debug(x) cout<<#x<<":"<<x<<endl;

bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();        
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0]=true;
        for(int k=1;k<=n;k++){
          if(p[k-1]=='*'){
            dp[0][k]=dp[0][k-2];
          }
        }
        for(int i=1;i<=m;i++){
          for(int j=1;j<=n;j++){
            if(p[j-1]=='.'||s[i-1]==p[j-1]){
              dp[i][j]=dp[i-1][j-1];
            }
            else if(p[j-1]=='*'){
              dp[i][j]=dp[i][j-2]||(dp[i-1][j]&&(s[i-1]==p[j-2]||p[j-2]=='.'));
            }
          }
          // for(auto i:dp){
          //   for(auto j:i){
          //     (j)?cout<<"true ":cout<<"false";
          //     cout<<" ";
          //   }
          //   cout<<endl;
          // }
          // cout<<endl;
        }
        return dp[m][n];
    }
int main(){
  string s,p;
  s="aa";
  p="a*";
  bool result = isMatch(s,p);
  (result)?cout<<"true"<<endl:cout<<"false"<<endl;

  return 0;
}