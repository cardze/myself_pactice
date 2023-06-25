#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std; 

long long int modulation(long long int x,long long int y, long long int m){
    long long int a=x;
    long long int n=y;

    long long int sum =1;

    for (long long int i = 0; i < n; i++)
    {
        sum*=a;
        while(sum>m) sum-=m;
    }
    return sum;
}


int main(){
    int n = 0;
    cin>>n;
    for(int i =0;i<n;i++){
        long long int a,b,c;
        cin>>a;
        cin>>b;
        cin>>c;
        long long int res = modulation(a,b,c);
        cout<<res<<endl;

    }
    
    return 0;
}