// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

// #include <utility>
// #include <sstream>
// #include <map>
// #include <deque>
// #include <cstring>
// #include <cmath>
// #include <string>
// #include <map>
// #include <stack>
// #include <queue>
// #include <unordered_map>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
// #define int long long int
#define debug(x) cout<<#x<<":"<<x<<endl;

int threeSumClosest(vector<int>& nums, int target) {
  sort(nums.begin(), nums.end());
  int sum = nums[0]+nums[1]+nums[2];
  for(int i =0; i<nums.size()-2;i++){
    int front = i+1;
    int back = nums.size()-1;
    int temp_sum = 0;
    while(front<back){
      temp_sum = nums[i]+nums[front]+nums[back];
      if(temp_sum == target) return temp_sum;
      if(abs(sum - target) >= abs(temp_sum - target)) sum = temp_sum;
      if(temp_sum<target) front++;
      else back--;
    }
  }
  return sum;
}
int main(){
  vector<int> input_arr = {4,0,5,-5,3,3,0,-4,-5};
  int target = -2;
  int res = threeSumClosest(input_arr, target);
  cout<<res<<endl;
  return 0;
}