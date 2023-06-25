#include <iostream>

using namespace std;

int fibo(int n ){
    int n1 = 1 , n0 =1;
    if (n==1 || n==0) return 1;
    for(int i =0 ; i<n-2;++i){
        int temp =n1;
        n1 = n0 + n1;
        n0 =temp;
    }
    return n1 + n0;
}

int main(){
    int input =1 ;
    while (input)
    {
        cin >>input;
        cout << " "<< fibo(input) << endl;/* code */
    }
    
    
}