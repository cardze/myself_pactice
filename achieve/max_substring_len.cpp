#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int max_substring_len(string& a, string& b){
  vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1,0));
  int res =INT_MIN;
  for(int i=0 ; i<dp.size() ; i++){
    for(int j =0;j<dp[0].size();j++){
      if(a[i+1]==b[j+1]){
        dp[i+1][j+1] = dp[i][j]+1;
        res = max(res, dp[i+1][j+1]);
      }
    }
  }
  for(auto a:dp){
    for(auto b:a) cout<<b<<" ";
    cout<<endl;
  }
  return res;
}

int main(){
  string s1= "ishandsome";
  string s2 = "ishandsome";
  int res = max_substring_len(s1,s2);
  cout<<res<<endl;
  return 0 ;
}