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
    string s;
    cin>>s;
    int N=0;
    for(char a:s){
      int temp = a-'0';
      
      N+=temp;
    }
    
    N-=(int)(*(s.end()-1)-'0');

    int S=0;
    for(int i=1;i<N;i++){
      if(N % i ==0) S+=i;
    }

    int G = S+(int)(*(s.end()-1)-'0');

    

    if(G-N >= 0){
      cout<<(G-N)<<endl;
    }else{
      cout<<"-1"<<endl;
    }
    c--;
  }
  return 0;
}