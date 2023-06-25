#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;


int maxSubArray(vector<int>& nums) {
        int sum = 0, smax = INT_MIN;
        for (int num : nums) {
            sum += num;
            smax = max(smax, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return smax;
    }

int main(){
    vector<int> input_nums = {-2,1,-3,4,-1,2,1,-5,4};
    int result = maxSubArray(input_nums);
    cout<<result<<endl;
    return 0;
}