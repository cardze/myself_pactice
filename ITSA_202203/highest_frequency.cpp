#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <sstream>
#include <map>

using namespace std;
#define debug(x) cout<<#x<<":"<<x<<endl;


int main(){
  int x;
  char max = NULL;
  
  string s;
  cin>>x;
  getline(cin , s);
  while(x && getline(cin, s)){   
    int count[256] = {0};
    for(char a:s){
      int index = a;
      // debug(index);
      count[index]++;
      if(max == NULL){
        max = a;
      }else{
        max = (count[max] < count[a])?a:max;
      }
    }
    cout<<max<<endl;
    x--;
  }
  return 0;
}

