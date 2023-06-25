#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define debug(x) cout<<#x<<":"<<x<<endl;

int main(){
  int n;
  string oops="oops";
  cin>>n;
  for(;n>0;n--){
    string s;
    cin>>s;
    int sum = 0;
    int is_float =0;
    string is_signed= "";
    int float_shift = 1;
    for(auto c:s){
      if(c>'0' && c<'9'){
        sum*=10;
        sum+=(c-'0');
        if(is_float) {
          float_shift*=10;
          is_float++;
          }
      }
      else if(c=='.'){
        is_float=1;
      }else if(c=='+' || c == '-'){
        is_signed+=c;
      }else if(c=='t' ||c=='T'){
        sum*=5;
        if(is_signed !="") cout<<is_signed;
        if(is_float>0){
          if(is_float-1<3){
            cout<<sum/float_shift<<".";
            if(sum%float_shift == 0) cout<<"00";
            else cout<<sum%float_shift;
          }else{
            int sig = sum / (float_shift/1000);
            if(sig%10>4) sig+=10;
            sig/=10;
            cout<<sig/100<<"."<<sig%100;
          }
          
        }else{
          cout<<sum;
        }
        cout<<"C"<<endl;
        break;
      }else{
        sum = 0;
        is_float =0;
        is_signed= "";
        float_shift = 1;
      }
    }
    if(sum==0) cout<<oops<<endl;
  }
}