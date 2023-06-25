#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define debug(x) cout<<#x<<":"<<x<<endl;

int main(){
  int n;
  cin>>n;
  for(;n>0;n--){
    int m;
    cin>>m;
    int sum =0;
    int min_a=INT_MAX;
    int max_b=INT_MIN;
    for(int i =0;i<m;i++){
      int a,b;
      cin>>a>>b;
      if(a>min_a && a < max_b){
        sum+=(b-max_b);
        max_b = max(b,max_b);
      }
      else if(b<max_b && b>min_a){
        sum+=(min_a-a);
        min_a = min(min_a,a);
      }else{
        min_a = min(min_a,a);
        max_b = max(b,max_b);
        sum +=(b-a);
      }
    }
    cout<<sum<<endl;
  }
  return 0 ;
}