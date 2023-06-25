#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;
// better solution
string addBinary(string a, string b)
    {
        string s = "";
        
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }
        
        return s;
    }

// string addBinary(string a, string b) {
//     if(a=="0") return b;
//     if(b=="0") return a;
//     long long int sum =0 ;
//     int carry =0;
//     string res ="";
//     for(int i=a.length()-1,j=b.length()-1;i>=0 || j>=0;i--,j--){
//         int a_bit = (i<0)?0:(a[i]-'0');
//         int b_bit = (j<0)?0:(b[j]-'0');
//         int sum = ( a_bit ^ b_bit) ^ carry;
//         carry = (a_bit & b_bit) | ((a_bit ^ b_bit) & carry);
//         // printf("%d %d %d\n",a_bit, b_bit, carry);
//         res.insert(0, to_string(sum));
//     }
//     if(carry) res.insert(0, to_string(carry));
//     return res;
// }
int main(){
    string a="10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
    string b="110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
    // string a= "11",b="1";
    string res = addBinary(a,b);
    cout<<res<<endl;
    return 0;
}