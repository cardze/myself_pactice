#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define debug(x) cout<<#x<<":"<<x<<endl;

int sum_lines(string& a,string& b){
  int sum =0;
  int pivot = 0;
  for(int i =0;i<a.size();i++){
    for(int j=i;j<b.size();j++){
      if(a[i]==b[j] && j>= pivot){
        sum++;
        pivot=j;
        break;
      }
    }
  }
  return sum;
}

int main(){
  int n,m;
  cin>>n>>m;
  string a,b;
  cin>>a>>b;
  int max_sum =max(sum_lines(a,b),sum_lines(b,a));
  cout<<max_sum<<endl;
  
  return 0 ;
}