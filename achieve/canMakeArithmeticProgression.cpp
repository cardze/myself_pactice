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

bool canMakeArithmeticProgression(vector<int>& arr) {
  if(arr.size()<=2) return true;
  int arr_min = INT_MAX;
  int arr_max = INT_MIN;
  for(auto i : arr){
    arr_min = min(arr_min, i);
    arr_max = max(arr_max, i);
  }
  
  if(arr_max == arr_min) return true;
  if((arr_max - arr_min)%(arr.size()-1) != 0) return false;
  int gap = (arr_max - arr_min)/(arr.size()-1);
  int index = 0;
  while(index<arr.size()){
    if((arr[index]-arr_min)/gap==index){
      index++;
    }else{
      int pos=(arr[index]-arr_min)/gap;
      if(arr[pos]==arr[index]) return false;
      if((arr[index]-arr_min)%gap != 0) return false;
      swap(arr[index] ,arr[pos]);
    }
  }

  return true;
}
int main(){
  vector<int> input_arr = {1,2,4};
  bool res = canMakeArithmeticProgression(input_arr);
  (res)?cout<<"True":cout<<"False";
  cout<<endl;
  return 0;
}