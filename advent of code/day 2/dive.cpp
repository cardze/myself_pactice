// Adventure of Code Day 2 
// https://adventofcode.com/2021/day/2

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
  string command;
  int value;
  int position=0, depth=0, aim=0;
  while(cin>>command>>value){
    if(command=="forward"){
      position+=value;
      depth+=(aim*value);
    }else if(command=="down"){
      aim+=value;
    }else if(command=="up"){
      aim-=value;
    }else{
      cerr<<"input has some weird action..."<<endl;
    }
  }
  cout<<(position*depth)<<endl;
  return 0;
}