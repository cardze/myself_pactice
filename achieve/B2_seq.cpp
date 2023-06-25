#include <iostream>
#include <string>
#include <vector>

using namespace std;

int judge_B2(vector<int>& input_arr){
    int arr_len = input_arr.size();
    if(arr_len > 100) return 0;
    if(arr_len == 2) return 1;
    if(arr_len == 3) return 1;
    for(int i =0 ;i < arr_len;i++){
        if(input_arr[i]<0 || input_arr[i]>10000 || (i>0 && input_arr[i]<=input_arr[i-1])) {

            // cout<<"yes"<<input_arr[i]<<endl;
            return 0;
        }
        for(int j = i + 3;j<arr_len;j++){
            int sum_of_two = input_arr[i] + input_arr[j];
            for(int k = i+1; k<j;k++){
                for(int m = j-1;m>k;m--){
                    // cout<<i<<" "<<j<<" "<<k<<" "<<m<<endl;
                    if(sum_of_two == input_arr[k] + input_arr[m]){
                        return 0;
                    }
                }
            }
        }
    }

    return 1;
}

int main(){
    vector<int> input_arr;
    int n=0;
    int case_num =1;
    while(cin>>n){
        input_arr.clear();
        for(;n>0;n--){
            int temp =0 ;
            cin>>temp;
            input_arr.push_back(temp);
        }
        int result=judge_B2(input_arr);
        if(result){
            cout<<"Case #"<<case_num<<": It is a B2-Sequence."<<endl;
            cout<<endl;
        }else{
            cout<<"Case #"<<case_num<<": It is not a B2-Sequence."<<endl;
            cout<<endl;
        }
        case_num++;
    }
    return 0;
}