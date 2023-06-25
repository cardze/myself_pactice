#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int mid = nums.size() / 2;
    int tail_of_nums = nums.size();
    int head_of_nums = 0;
    while(target != nums[mid]){
        int origin_val = mid;
        if(target > nums[mid]) {
            mid = (mid+tail_of_nums)/2;
            head_of_nums=origin_val;
        }
        if(target < nums[mid]) {
            mid = (mid+head_of_nums)/2;
            tail_of_nums=origin_val+1;
        }
        printf("in loop m= %d head = %d tail = %d\n",mid,head_of_nums,tail_of_nums);

        if(mid == origin_val){
            if(target > nums[mid]) return tail_of_nums;
            if(target < nums[mid]) return head_of_nums;
        }
    }
    return mid;
}

int main(){
    vector<int> input_nums = {1,3,5};
    int input_target =4;
    int result = searchInsert(input_nums, input_target);
    cout<<result<<endl;
    return 0;
}