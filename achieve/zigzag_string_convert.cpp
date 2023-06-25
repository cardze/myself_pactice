#include <iostream>
#include <string>

using namespace std;

string convert(string s, int numRows){
    if(numRows == 1 || numRows > s.length()) return s;
    string res = "";
    int jump_value = ((2*numRows)-2);
    for (int i = 0 ; i<numRows;i++){
        int index = i;
        while (index<s.length())
        {
            res+=s[index];
            if(i != 0 && i!=(numRows-1)){
                int next_index = index + 2*(numRows-1-i);
                if(next_index < s.length()) res += s[next_index];
            }
            index+=jump_value;
        }
    }
    return res;
}


int main(){
    string test_string = "123456789";
    string test_output = convert(test_string, 3);
    string right_output = "159246837";

    cout<<test_output<<endl;
    cout<<right_output<<endl;
    return 0;
}