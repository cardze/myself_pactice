#include <iostream>
// #include <cstring>
#include <vector>
// #include <algorithm>
#include <cmath>
#include <string>
// #include <utility>
// #include <sstream>
// #include <map>
// #include <deque>
#include <map>
using namespace std;
#define debug(x) cout<<#x<<":"<<x<<endl;
#define int long long int 


map<string, int> max_sub_seq(vector<int>& target_arr){
  int sum=0, smax=INT_MIN;
  int start=0, end=0;
  int size_arr = target_arr.size();
  for(int i=0; i<size_arr; i++){
    sum += target_arr[i];
    int last_smax = smax;
    smax = max(smax, sum);
    if(last_smax != smax){
      end = i;
    }    
    if(sum<0){
      sum =0;
      if(i+1<size_arr) start=i+1;
    }
  }
  if(start>end) start = end;
  map<string, int> res ;
  res["start"]=start;
  res["end"]=end;
  res["max"]=smax;
  return res;  
}

int main(){
  // input format handle
  int array_len=0;
  cin>>array_len;
  vector<int> arr;
  for(int i =0; i < array_len; i++){
    int ele = 0;
    cin>>ele;
    arr.push_back(ele);
  }
  // main function implement
  map<string, int> result = max_sub_seq(arr);
  for(const auto& [key, value]:result){
    cout<<key<<" : "<<value<<endl;
  }
  return 0;
}

// In this porble, you will ask to solve the 
// "Maximum Subarray" problem : Given an array,
// find a contiguous subarray in array a with
// the maximum summation; that is, for an array
// a with length n indexed from 0 to n-1, find
// two integers i, j with 0<= i <= j< n such 
// that sum from i to j is as large as possible.
// input : first line : n, length of array
//         second line : array, array data 
//                       seperate by space.
// output : start and end index of subseqenece 
//          that sum is maximum of all the possible 
//          subsequence.

