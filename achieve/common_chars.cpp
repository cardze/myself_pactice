#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

string common_chars(string& a, string& b){
    string res = "";
    for(char i='a'; i<='z'; i++){
        if(a.find(i)!=string::npos && b.find(i)!=string::npos) res+=i;
    }
    if(res.length() == 0 ) return "N";
    return res;
}


int main(){
    int n = 0;
    cin>>n;
    for(int i=0 ; i<n ;i++){
        string a, b;
        cin>>a;
        cin>>b;
        string output = common_chars(a,b);
        cout<<output<<endl;
    }
    return 0;
}