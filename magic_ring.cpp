
// #include <utility>
// #include <deque>
// #include <cstring>
// #include <cmath>
// #include <string>
// #include <map>
// #include <stack>
// #include <unordered_map>
#include <queue>
#include <sstream>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
// #define int long long int
#define debug(x) cout<<#x<<":"<<x<<endl;


int magic_value_matrix[4][4]= {
  {13,1,5,9},
  {10,14,2,6},
  {7,11,15,3},
  {4,8,12,16}
};

int bitmap_static(int value, int* ret){
  int level=0;
  int temp_val = value;
  int temp_record_arr[4]={0};
  int arr_counter = 0;
  while(temp_val){
    temp_record_arr[arr_counter++]=temp_val%2;
    if(temp_val%2) level++;
    temp_val/=2;
  }
  debug(level);
  int result=0;
  if(level==1){
    for(int i=0;i<4;i++){
      if(temp_record_arr[i]) result=magic_value_matrix[i][i];
    }
  }else{
    int head=-1, tail=-1;
    int level_counter = 0;
    int arr_ptr = 0;
    while(level_counter < level){
      while(temp_record_arr[(arr_ptr++)%4]){
        // debug(temp_record_arr[arr_ptr%4]);
        // debug(level_counter);
        if(head==-1){
          head=(arr_ptr-1)%4;
        }else if(tail==-1){
          tail=(arr_ptr-1)%4;
        }
        if(head!=-1 && tail!=-1){
          result+=magic_value_matrix[head][tail];
          level_counter++;
          head=tail;
          tail=-1;
        }
        if(level_counter >= level ) break;
      }
    }
  }
  ret[level-1] = max(ret[level-1], result);
  return result;
}

int main(){
  int n=4;
  int ret[4]={0};
  int temp_ret = 0;
  for(int i=1;i<(1<<4);i++){
    debug(i);
    temp_ret=bitmap_static(i, ret);
    debug(temp_ret);
  }
  cout<<endl;
  for(auto i:ret){
    cout<<i<<" ";
  }
  return 0;
}