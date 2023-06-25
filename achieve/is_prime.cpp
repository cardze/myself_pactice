#include <iostream>
#include <vector>
#include <string>


using namespace std;
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
    int test_num = 667;
    int res = is_prime(test_num);
    cout<<res<<endl;
    return 0;
}