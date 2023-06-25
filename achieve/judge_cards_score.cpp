#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

void show_vector(vector<int>& v){
    for(auto a:v) cout<<a<<" ";cout<<endl;
}

int judge(vector<int>& cards){
    vector<int> sorted_cards = cards;
    sort(sorted_cards.begin(), sorted_cards.end());
    vector<int> color;
    vector<int> digit;
    for(auto a:sorted_cards){
        color.push_back((a-1)/13);
        digit.push_back((a-1)%13);
    }
    vector<int> color_count;
    color_count.resize(4,0);
    for(auto a : color){
        color_count[a]++;
    }
    vector<int> digit_count;
    digit_count.resize(13,0);
    for(auto a:digit){
        digit_count[a]++;
    }
    // cout<<"digit: ";
    // show_vector(digit);
    // cout<<"color: ";

    // show_vector(color);
    // cout<<"digit_count: ";

    // show_vector(digit_count);
    // cout<<"color_count: ";

    // show_vector(color_count);

    int five_same =0;
    for(auto a:color_count){
        if(a >= 5){
            five_same =1;
        }
    }
    int conti_five_num = 0;
    int same_four_num = 0;
    int same_three_num = 0;
    int same_two_num = 0;
    int count =0;
    for(int i = 0; i<14 ; i++){
        if(digit_count[i%13] > 0){
            count++;
            
        }else{
            count=0;
        }
        if(count == 5){
            conti_five_num =1;
        }
        if(i<13){
            if(digit_count[i%13]==4) same_four_num = 1;
            if(digit_count[i%13]==3) same_three_num = 1;
            if(digit_count[i%13]==2) same_two_num += 1;
        }
    }
    if(conti_five_num && five_same) return 7;
    if(same_four_num) return 6;
    if(same_three_num && same_two_num) return 5;
    if(conti_five_num) return 4;
    if(same_three_num) return 3;
    if(same_two_num>=2) return 2;
    if(same_two_num == 1) return 1;
    return 0;
}

int main(){
    int n;
    cin>>n;
    for(;n>0;n--){
        vector<int> input_hand_card;
        for(int i = 0; i<6;i++){
            int ele;
            cin>>ele;
            input_hand_card.push_back(ele);    
        }
        int res = 0;
        auto it = input_hand_card.begin();
        for(int j =0 ;j<6;j++){ 
            int temp = *it;
            input_hand_card.erase(it);
            // cout<<"res: ";
            // cout<<res<<endl;
            res = max(res, judge(input_hand_card));
            input_hand_card.insert(it, temp);
            it++;
        }
        cout<<res<<endl;
    }
}