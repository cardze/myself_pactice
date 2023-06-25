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

vector<string> letterCombinations(string digits) {
  vector<string> res;
  queue<string> q;
  map<char, string> com_candidates = {
    {'2',"abc"},
    {'3',"def"},
    {'4',"ghi"},
    {'5',"jkl"},
    {'6',"mno"},
    {'7',"pqrs"},
    {'8',"tuv"},
    {'9',"wxyz"}    
  }; 
  for(int i=0;i<digits.size();i++){
    char index = digits[i];
    string com_candidate = com_candidates[index];
    
    if(q.size()==0){
      for(auto j : com_candidate){
        q.push(string(1,j));
      }
    }else{
      int origial_len = q.size();
      for(int k=0;k<origial_len;k++){
        string temp = q.front();
        // debug(temp);
        q.pop();
        for(auto j : com_candidate){
          q.push(temp+string(1,j));
        }
      }
    }
  }

  while(q.size()>0){
    string ele = q.front();
    q.pop();
    res.push_back(ele);
  }
  return res;
}
int main(){
  string digit = "";
  vector<string> res = letterCombinations(digit);
  for(auto i : res){
    cout<<i<<" ";
  }
  cout<<endl;
  return 0;
}