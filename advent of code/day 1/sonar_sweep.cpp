// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

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

int main(){
  int ans = 0;
  int input_depth=0;
  int input_counter=0;
  int window[3] = {0,0,0};
  int former_sum=0;
  int now_sum=0;
  while(cin>>input_depth){
    if(input_counter<3){
      window[input_counter%3]=input_depth;
      for(int i=0;i<input_counter%3;i++){
        window[i]+=input_depth;
      }
      former_sum=window[(input_counter+1)%3];
      for(int k=0;k<3;k++){
        cout<<window[k]<<" ";
      }
      cout<<endl;
    }else{
      
      for(int j=0;j<3;j++){
        window[j]+=input_depth;
      }
      now_sum = window[(input_counter+1)%3];
      debug(now_sum);
      debug(former_sum);
      if(now_sum>former_sum) ans++;
      window[input_counter%3]=input_depth;
      former_sum=now_sum;
    }
    input_counter++;
  }
  cout<<ans<<endl;
  return 0;
}