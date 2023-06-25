// #include <utility>
// #include <sstream>
// #include <map>
// #include <deque>
// #include <cstring>
// #include <algorithm>
// #include <cmath>
// #include <map>
// #include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
#define debug(x) cout<<#x<<":"<<x<<endl;

int main(){
  #define int long long int
  int nums_bricks = 0;
  cin>>nums_bricks;
  stack<int> tower;
  queue<int> playground;
  int perfect_num = nums_bricks;
  int least_nums_of_operation = nums_bricks*nums_bricks+3*nums_bricks-2;
  cout<<least_nums_of_operation<<endl;
  //main method
  int total_counter = 0;
  for (int i = 0; i < nums_bricks; i++)
  {
    tower.push(i+1);
    total_counter++;
    cout<<"PLACE "<<i+1<<endl;
  }
  total_counter++;
  cout<<"PHOTO"<<endl;
  for(int j = 2;j<=nums_bricks/2;j++){
    for(int pop_index = 0;
    pop_index<j;
    pop_index++){
      int pop_temp = tower.top();
      tower.pop();
      playground.push(pop_temp);
      total_counter++;
      cout<<"POP"<<endl;
    }
    for(int push_index = 0;
    push_index<j;
    push_index++){
      int push_temp = playground.front();
      playground.pop();
      tower.push(push_temp);
      total_counter++;
      cout<<"PLACE "<<push_temp<<endl;
    }
    total_counter++;
    cout<<"PHOTO"<<endl;
  }
  queue<int> playground_back;
  for(int pop_index = 0;
    pop_index<nums_bricks/2;
    pop_index++){
      int pop_temp = tower.top();
      tower.pop();
      playground_back.push(pop_temp);
      total_counter++;
      cout<<"POP"<<endl;
    }
  for(int pop_index = 0;
    pop_index<nums_bricks-(nums_bricks/2);
    pop_index++){
      int pop_temp = tower.top();
      tower.pop();
      playground.push(pop_temp);
      total_counter++;
      cout<<"POP"<<endl;
    }
  for(int push_index = 0;
    push_index<nums_bricks/2;
    push_index++){
      int push_temp = playground_back.front();
      playground_back.pop();
      tower.push(push_temp);
      total_counter++;
      cout<<"PLACE "<<push_temp<<endl;
    }
  for(int push_index = 0;
    push_index<nums_bricks-(nums_bricks/2);
    push_index++){
      int push_temp = playground.front();
      playground.pop();
      tower.push(push_temp);
      total_counter++;
      cout<<"PLACE "<<push_temp<<endl;
    }
  total_counter++;
  cout<<"PHOTO"<<endl;
  for(int j = 2;j<=nums_bricks-(nums_bricks/2);j++){
    for(int pop_index = 0;
    pop_index<j;
    pop_index++){
      int pop_temp = tower.top();
      tower.pop();
      playground.push(pop_temp);
      total_counter++;
      cout<<"POP"<<endl;
    }
    for(int push_index = 0;
    push_index<j;
    push_index++){
      int push_temp = playground.front();
      playground.pop();
      tower.push(push_temp);
      total_counter++;
      cout<<"PLACE "<<push_temp<<endl;
    }
    total_counter++;
    cout<<"PHOTO"<<endl;
  }
  cout<<"what i predict : "<<least_nums_of_operation<<endl;
  cout<<"actual command count : "<<total_counter<<endl;  
  return 0;
}