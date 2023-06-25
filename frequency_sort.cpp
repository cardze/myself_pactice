// #include <utility>
// #include <sstream>
// #include <map>
// #include <deque>
// #include <cstring>
// #include <cmath>
// #include <map>
// #include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;
// #define int long long int
#define debug(x) cout<<#x<<":"<<x<<endl;

vector<int> frequencySort(vector<int>& nums) {
  unordered_map<int, int> freq_map;
  
  for(auto i : nums){
    freq_map[i]+=1;
  }
  sort(begin(nums), end(nums), [&](int a, int b){
    return freq_map[a]==freq_map[b]?a>b:freq_map[a]<freq_map[b];//return true will not change the position...
  });

  return nums;
}

int main(){
  vector<int> input_arr = {1, 1, 2, 2, 2, 3, 3};
  frequencySort(input_arr);
  for(auto i : input_arr) cout<<i<<" ";
  cout<<endl;
  return 0;
}