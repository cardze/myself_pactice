#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lengthOfLastWord(string s) {
    if(s.length()==0) return 0;
    if(s.length()==1 && s[0] != 32) return 1;  
    int index = s.length()-1;
    while(s[index] == 32) index--;
    string mod_str = s.substr(0,index+1);
    int finded = mod_str.find_last_of(" ");
    return mod_str.substr(finded+1).length();
}

int main(){
    string test_input = "   fly me   to   the moon  ";
    int res = lengthOfLastWord(test_input);
    cout<<res<<endl;
    return 0;
}