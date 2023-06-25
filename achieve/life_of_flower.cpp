#include <iostream>
#include <string>
#include <vector>

using namespace std;

int water_flower(vector<int>& date_list){
    int flower_h = 1;
    
    if(date_list[0] == 1) flower_h+=1;
    if(date_list.size() == 1) return flower_h;
    for(int i =1 ;i< date_list.size();i++){
        if(date_list[i] == date_list[i-1]){
            if(date_list[i] == 0) return -1;
            else if(date_list[i] == 1) flower_h+=5;
        }else{
            if(date_list[i] == 1) flower_h+=1;
        }
    }
    return flower_h;
}

int main(){

    int num_input =0;
    vector<int> water_day;
    cin>>num_input;
    for (int i = 0; i < num_input; i++)
    {
        water_day.clear();
        int days=0;
        cin>>days;
        for (int i = 0; i < days; i++)
        {
            int temp =0;
            cin>>temp;
            water_day.push_back(temp);
        }
        int result = water_flower(water_day);
        cout<<result<<endl;
    }
    return 0;
}