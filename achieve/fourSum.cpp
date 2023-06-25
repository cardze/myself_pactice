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
vector<vector<int>> fourSum(vector<int>& nums, int target) {
  if(nums.size()<4) return {};
  sort(nums.begin(), nums.end());
  vector<vector<int>> res;
  long long int sum=0 ;
  for(int i=0;i<nums.size()-3;i++){
    
    for(int j=i+1;j<nums.size()-2;j++){
      int front=j+1, back=nums.size()-1;
      vector<int> ele;
      while(front<back){
        sum = 0;
        sum+=nums[i];
        sum+=nums[j];
        sum+=nums[front];
        sum+=nums[back];
        if(sum<target) front++;
        else if(sum>target) back--;
        else{
          ele = {nums[i],nums[j],nums[front],nums[back]};
          res.push_back(ele);
          //skip the duplicate one
          while(front<back && nums[front] == ele[2]) front++;
          while(front<back && nums[back]  == ele[3]) back--;
        }
      }
        while(j+1<nums.size()-2 && nums[j] == nums[j+1]) j++;
    }
    while(i+1<nums.size()-3 && nums[i] == nums[i+1]) i++;

  }
  // vector<map<int,int>> attr_list;
  // for(auto k:res){
  //   map<int,int> attr;
  //   for(auto ele:k){
  //     attr[ele]++;
  //   }
  //   attr_list.push_back(attr);
  // }
  // vector<bool> judge_attr(attr_list.size(), true);
  // for(int i=0;i<judge_attr.size();i++){
  //   if(judge_attr[i]){
  //     for(int j=i+1;j<judge_attr.size();j++){
  //       // make a check of distinct map is or isnt
  //       int compare_result = (attr_list[i].size()==attr_list[j].size()) && equal(attr_list[i].begin(), attr_list[i].end(), attr_list[j].begin());
  //       judge_attr[j] = judge_attr[j] && (!compare_result);
  //       // debug(judge_attr[j]);
  //       // debug(compare_result);
  //     }
  //   }
  // }
  // vector<vector<int>> true_res;
  // for(int i=0;i<judge_attr.size();i++){
  //   if(judge_attr[i]) true_res.push_back(res[i]);
  // }
  // return true_res;
          return res;

}
int main(){
  vector<int> input_nums = {-1,0,1,2,-1,-4};
  int target = -1;
  vector<vector<int>> res = fourSum(input_nums, target);
  for(auto i:res){
    for(auto j:i) cout<<j<<" ";
    cout<<endl;
  }
  return 0;
}