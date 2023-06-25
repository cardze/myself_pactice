// #include <utility>
// #include <sstream>
// #include <map>
// #include <deque>
// #include <cstring>
// #include <cmath>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;
// #define int long long int
#define debug(x) cout<<#x<<":"<<x<<endl;

// string intToRoman(int num) {
//         int temp_input=num;
//         map<int, string> num_map={
//             {1,"I"},
//             {4, "IV"},
//             {5,"V"},
//             {9, "IX"},
//             {10,"X"},
//             {40, "XL"},
//             {50,"L"},
//             {90, "XC"},
//             {100,"C"},
//             {400, "CD"},
//             {500,"D"},
//             {900, "CM"},
//             {1000,"M"}
//         };
//         vector<int> num_list = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
//         string res = "";
//         for(auto i:num_list){
//           int multi_num = temp_input/i;
//           if(multi_num > 0){
//             temp_input=temp_input-(multi_num*i);
//             while(multi_num>0){
//               res.append(num_map[i]);
//               multi_num--;
//             }
//           }
//         }

//         return res;
//     }
// here using space to exchange speed is good action
string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }

int main(){
  int input_num = 1994;
  string answer = "MCMXCIV";
  string result = intToRoman(input_num);
  // int result = test_function(input_num);
  string check_answer =(result==answer)?"right":"wrong";
  cout<<result<<endl; 
  cout<<check_answer<<endl;

  return 0;
}