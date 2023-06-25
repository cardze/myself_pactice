#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<vector<int>> v;
    v.resize(5, {0});
    for(auto item:v) item.resize(5,0);
    for(auto item:v) cout<<item.size()<<endl;
    for(auto& item:v) item.resize(5,0);
    for(auto& item:v) cout<<item.size()<<endl;

    return 0;
}