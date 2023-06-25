#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std; 

int myAtoi(string str) {
    if(str.length() == 0)return 0;
    if(str.length() == 1 && !('0'<=str[0] && str[0]<='9')) return 0;
    long long int result = 0;
    int indicator = 1;

    int i = str.find_first_not_of(' ');
    if(i == -1) return 0;
    if(str[i] == '-' || str[i] == '+')
        indicator = (str[i++] == '-')? -1 : 1;
        
    while('0'<= str[i] && str[i] <= '9') 
    {
        result = result*10 + (str[i++]-'0');
        if(result*indicator >= INT_MAX) return INT_MAX;
        if(result*indicator <= INT_MIN) return INT_MIN;                
    }
        
    return result*indicator;
    }
int main(){
    string s = "  ";
    int res= myAtoi(s);
    cout<<res<<endl;
    return 0;
}