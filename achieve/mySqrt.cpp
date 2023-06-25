#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int mySqrt(int x) {
    long n = x;
    while(n*n > x){
        n= (n + x/n)/2;
    }
    return n;
}

int main(){
    int test = 8;
    int res = mySqrt(test);
    cout<<res<<endl;
}
