#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> arr_eversion(vector<int>& target_arr){
    int arr_len = target_arr.size();
    if(arr_len == 1) return target_arr;
    int pivot = target_arr[arr_len-1];
    vector<int> left;
    vector<int> right;
    for (int i =0 ;i<arr_len-1;i++){
        if(target_arr[i] > pivot) right.push_back(target_arr[i]);
        else left.push_back(target_arr[i]);
    }
    left.push_back(pivot);
    left.insert(left.end(), right.begin(),right.end());
    // for(int i =0 ; i<arr_len;i++) cout<<left[i]<<" ";
    // cout<<endl;
    return left;
}

int compare(vector<int>& arr_1, vector<int>& arr_2){
    for(int i=0;i<arr_1.size();i++){
        if(arr_1[i]!=arr_2[i]) return 0;
    }
    return 1;
}

int count_eversion(vector<int>& target_arr){
    int count = 0;
    vector<int> ori = target_arr;
    vector<int> com = arr_eversion(target_arr);
    while(com != ori){
        ori = com;
        com = arr_eversion(com);
        count++;
    }
    return count;
}

int main(){
    int n = 0;
    vector<int> input_arr;
    cin>>n;
    for(int i=0 ;i<n;i++){
        input_arr.clear();
        int m = 0;
        cin>>m;
        for(int j =0 ; j<m;j++) {
            int element =0;
            cin>>element;
            input_arr.push_back(element);
        }
        int res = count_eversion(input_arr);
        cout<<res<<endl;
    }

    // vector<int> test_input={5,3,2,4,1};
    // int result = count_eversion(test_input);
    // cout<<result<<endl;
    return 0;
}