#include <iostream>
using namespace std;

int main(){
  int num_input =0;
  cin>>num_input;
  for (int i = 0; i < num_input; i++)
  {
    long long int target, k;
    cin>>target>>k;
    if( k==1 || target%2 == 0 || (target%2==1 && k%2==1 ) ){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }

  return 0;
}