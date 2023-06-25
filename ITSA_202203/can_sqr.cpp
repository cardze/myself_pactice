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
  int c;
  cin>>c;
  while(c){
    int c_loop;
    cin>>c_loop;
    int count[1000]={0};
    int can_sqr = 0;
    while(c_loop){
      int temp;
      cin>>temp;
      count[temp]++;
      if(count[temp] >= 4) can_sqr=1; 
      c_loop--;
    }
    string res = (can_sqr)?"yes":"no";
    cout<<res<<endl;
    c--;
  }
  return 0;
}