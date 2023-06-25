#include <iostream>
#include <string>
#include <vector>

using namespace std;

int test_num(string input_str){
    if( input_str.at(1) == 49 || input_str.at(1) == 50){
        int eng_to_num = input_str[0];
        if (eng_to_num >= 65 && eng_to_num < 91){
            if(eng_to_num == 73) eng_to_num = 34;
            if(eng_to_num == 79) eng_to_num = 35;
            if(eng_to_num == 87) eng_to_num = 32;
            if(eng_to_num == 90) eng_to_num = 33;
            if (eng_to_num >= 65 && eng_to_num < 73) eng_to_num -= 55;
            if (eng_to_num >= 74 && eng_to_num < 79) eng_to_num -= 56;
            if (eng_to_num >= 80 && eng_to_num < 87) eng_to_num -= 57;
            if (eng_to_num >= 88 && eng_to_num < 90) eng_to_num -= 58;
        }
        int fir = eng_to_num / 10;
        int last = eng_to_num % 10;
        vector<int> nums = {fir, last};
        for (int i = 0;i<9;i++){
            nums.push_back(input_str[i+1]-48);
        }
        vector<int> weight = {1,9,8,7,6,5,4,3,2,1,1};
        int sum = 0;
        for (int j=0;j<11;j++){
            sum += (nums[j] * weight[j]);
        }
        // return sum; //for test sum's value
        if(sum % 10 == 0){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
    return -1;
}

int main(){
    int input;
    cin >> input;
    string test = "M123456789";
    // int output = test_num(test);
    // cout<<output<<endl;
    while (input--)
    {
        test.clear();
        cin>>test;
        // cout<<test<<endl;
        if (test_num(test) == 0){
            cout<<"F"<<endl;
        }else{
            cout<<"T"<<endl;
        }
    }

    return 0;
}