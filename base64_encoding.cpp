#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) std::cerr<<#x<<":"<<x<<std::endl

class Solution
{
public:
  string replace_all_space(string input){
    size_t start;
    string ret = input;
    while((start = ret.find(" "))!=string::npos){
      ret.erase(start, 1);
    }
    return ret;
  }
  string mul(string formula){
    string a, b;
    string without_space = replace_all_space(formula);
    size_t sp = without_space.find("*");
    a = without_space.substr(0, sp);
    b = without_space.substr(sp+1, without_space.size());
    // there is no need to calculate this case, where 0 time anything is 0 itself
    if(a == "0" || b =="0") return "0";
    string ret(a.size() + b.size(),0);
    // do the production from last bit of string
    for(int i= a.size()-1; i>= 0; i--){
      for(int j =b.size()-1 ; j>=0; j--){
        int num = ((a[i]-'0') * (b[j]-'0')) + ret[i+j+1];
        ret[i+j+1] = num % 10; // remain
        ret[i+j] += num / 10;  // add carry to next bit
      }
    }
    // add back the value '0'
    for(int i =0 ; i< ret.size(); i++) ret[i]+='0';
    // remove head of zero if any
    if(ret[0] == '0') return ret.substr(1);
    return ret;
  }
  int _divid_by_two(string& input){
    // Alert : this function will modified the input varible
    int remain = 0;
    int n = input.size();
    for(int i= 0; i< n ; i++){
      input[i] -='0';
    }
    for(int i = 0; i<n; i++){
      int num = input[i] + remain *10;
      input[i] = num / 2;
      remain = num % 2;
    }
    for(int i= 0; i< n ; i++){
      input[i] +='0';
    }
    if(input[0] == '0') input = input.substr(1);
    return remain; // for binary convertion 
  }
  string decimal_to_binary(string dec){
    string ret = "";
    stringstream ss;
    string tmp = dec;
    while(tmp.size()>0){
      ret+=char(_divid_by_two(tmp)+'0');
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
  string bin_to_hex(string bin){
    // with little endian style
    string ret = "";
    string completion = "";
    string tmp = bin;
    stringstream ss;
    int n = bin.size();
    int byte_len = 8;
    if(n % byte_len != 0) {
      for(int i =0 ; i< byte_len-(n % byte_len); i++){
        completion += '0';
      }
      tmp = completion + tmp;
    }
    n = tmp.size();
    for(int i = n-byte_len ; i>=0; i-=byte_len){
      string token = tmp.substr(i, byte_len);
      int store = 0;
      for(int j =0 ; j<byte_len; j++){
        store*=2;
        if(token[j] == '1') store ++;
      }
      ss<<hex<<store;
    }
    ret = ss.str();

    return ret;
  }
  char _mapper(string word){
    int val = 0;
    for(char c : word){
      val *= 2;
      if(c == '1') val++;
    }
    if(val>=26 && val <52) return 'a'+val-26;
    if(val>=52 && val <62) return '0'+val-52;
    if(val == 62) return '+';
    if(val == 63) return '/';
    return 'A'+val;
  }
  string _base64_helper(string token){
    string tmp = token;
    string ret = "";
    stringstream ss;
    ss<<hex<<tmp;
    int deci;
    ss>>deci;
    bitset<12> bin(deci);
    string bin_s = bin.to_string();
    string a = bin_s.substr(0, 6);
    string b = bin_s.substr(6, 6);
    ret = ret +_mapper(a)+_mapper(b);
    return ret;
  }
  string base64_encoding(string target){
    string ret = "";
    string com = "";
    string tmp = target;
    int com_num = target.size() % 3;
    if(target.size() % 3 != 0){
      for(int i=0;i<3-com_num;i++){
        com+='0';
      }
      tmp += com;
    }
    for(int i = 0; i< tmp.size(); i+=3){
      string token = tmp.substr(i, 3);
      ret+=_base64_helper(token);
    }
    if(com_num != 0) ret[ret.size() -1] = '=';
    return ret;
  }
  string encoding_bigNum(string formula)
  {
    string ret = mul(formula);
      DEBUG(ret);
    ret = decimal_to_binary(ret); // into binary form
      DEBUG(ret);
    ret = bin_to_hex(ret); // to hex with little indian
      DEBUG(ret);
    ret = base64_encoding(ret);
      DEBUG(ret);
    return ret;
  }
};

int main()
{
  // string formula = "108713406511 * 137993468292";
  string formula = "1087134 * 1379934";
  Solution s = Solution();
  cout<<s.encoding_bigNum(formula)<<endl;
  return 0;
}