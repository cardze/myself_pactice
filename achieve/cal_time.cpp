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

vector<int> prime_table = {};
int is_prime(int n){
    if(n < 0)  return -1; 
    if(n == 0) return 0;
    if(n == 1) return 0;
    if(n == 2) return 1;

    for(int j=0;j<prime_table.size();j++){
        if(n == prime_table[j]) return 1;
    }

    for(int i =2;i<=(n/2);i++){
        if(n % i == 0 ) return 0; 
    }
    prime_table.push_back(n);
    return 1;
}

int main(){
  int n;
  cin>>n;
  for(;n>0;n--){
    int ele;
    cin>>ele;
    int year = 1970;
    int month = 1;
    int day =1;
    while(ele/365){
      if((year % 4==0 && year%100!= 100) || year%400==0){
        ele-=366;
      }else{
        ele-=365;
      }
      year++;
    }
    while(ele/30 || ((ele/28)&&((year % 4==0 && year%100!= 100) || year%400==0))){
      if((month!=2 && month<8 && month%2==1)||(month>7 && month%2==0)){
        ele-=31;
      }else if(month == 2){
        if((year % 4==0 && year%100!= 100) || year%400==0){
          ele -= 29;
        }else{
          ele -= 28;
        }
      }
      else{
        ele-=30;
      }
      month++;
    }
    day += ele;
    cout<<year<<"-"<<month<<"-"<<day<<endl;
  }
  return 0;
}

