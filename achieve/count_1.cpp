#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int count_1(int input){
    int input_num = input;
    int count =0;
    if(input == 0) return 0;
    if(input == 1) return 1;
    while (input_num>0)
    {
        int remain = input_num % 2;
        input_num/=2;
        if(remain ==1) count++;
    }
    return count;
}

int main(){
    int n = 0;
    cin>>n;
    for(int i=0 ; i<n ;i++){
        int in;
        cin>>in;
        cout<<count_1(in)<<endl;
    }
    return 0;
}