#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 100;
    cout << n<<endl;
    for(;n>0;n--){
        vector<int> output;
        output.clear();
        for(int i =0;i<6;i++){
            int ele = rand() % 52+1;
            if(output.size()==0) output.push_back(ele);
            else{
                for(auto a:output){
                    while(ele == a) ele = rand()%52+1; 
                }
                output.push_back(ele);
            }
        }
        for(auto a:output) cout<<a<<" ";
        cout<<endl;
    }
}