// https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/

// #include <utility>
// #include <sstream>
// #include <deque>
// #include <cstring>
// #include <cmath>
// #include <string>
// #include <map>
// #include <stack>
// #include <unordered_map>
#include <queue>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
// #define int long long int
#define debug(x) cout<<#x<<":"<<x<<endl;

vector<vector<int>> dp=vector<vector<int>>(1000, vector<int>(1001, -1));
int numberOfWays(int startPos, int endPos, int k) {
  if((k-abs(startPos-endPos))%2) return 0;
  if(k<abs(startPos-endPos)) return 0;
  if(k==abs(startPos-endPos)) return 1;
  if(k==0&&startPos==endPos) return 1;
  else if(k==0) return 0;
  int &ans=dp[abs(startPos-endPos)][k];
  if(ans!=-1) return ans;
  return ans=(numberOfWays(startPos-1, endPos, k-1)+numberOfWays(startPos+1, endPos, k-1))%1000000007;
}
int main(){
  int input_start = 1, input_end=2, k=3;
  cout<<numberOfWays(input_start, input_end, k)<<endl;
  return 0;
}