#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <sstream>
#include <map>
#include <stack>
#include <queue>

using namespace std;
#define debug(x) cout<<#x<<":"<<x<<endl;

int priority(char op) { 
    switch(op) { 
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default:            return 0;
    } 
} 

int main(){
  int c;
  cin>>c;
  while(c){
    debug(c);
    stack<char> oper;
    string s;
    char temp = getc(stdin);
    getline(cin, s);
    debug(s);
    stringstream ss;
    ss<<s;
    char ele;
    while(ss>>ele){
      switch (ele)
      {
      case '+': case '-': case '*': case '/':
        while(priority(oper.top()) >= priority(ele)) {
          cout<<oper.top();
          oper.pop();
        }
        oper.push(ele);
        break;
      case '(':
        oper.push(ele);
        break;
      case ')':
        while(oper.top() != '('){
          cout<<oper.top();
          oper.pop();
        }
        break;
      
      default:
        cout<<ele;
      }
    }
    c--;
  }
  return 0;
}

