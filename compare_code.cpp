//10331
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

#define debug(x) cout<<#x<<":"<<x<<endl;

int judge(vector<int> input){
	int type, in;
	bool is_shunzi, is_same_type;
	vector<int> point;
	point.clear();
	for(int i=0; i<input.size(); i++){
		point.push_back((input[i]-1)%13);
	}

	sort(point.begin(), point.end());

	//shun zi
	is_shunzi = true;
	for(int i=1; i<point.size(); i++){
		is_shunzi &= ((point[i]-point[i-1])==1);
	}
	if(point[0]==0 && point[1]==9 && point[2]==10 &&
	   point[3]==11 && point[4]==12) is_shunzi=true;

	//judge type
	is_same_type = true;
	for(int i=1; i<point.size(); i++){
		is_same_type &= ((input[i]-1)/13 == (input[i-1]-1)/13);
	}


	vector<int> point_sum;
	point_sum.resize(13);
	for(int i=0; i<input.size(); i++){
		point_sum[(input[i]-1)%13]++;
	}

	bool is_three = false;
	bool is_four = false;
	int two_pair_cnt = 0;
	for(int i=0; i<point_sum.size(); i++){
		switch(point_sum[i]){
			case 4: is_four=true; break;
			case 3: is_three=true; break;
			case 2: two_pair_cnt++; break;
		}
	}

	bool is_hulu = (is_three & (two_pair_cnt==1));

	if(is_shunzi && is_same_type) return 7;
	else if(is_four) return 6;
	else if(is_hulu) return 5;
	else if(is_shunzi) return 4;
	else if(is_three) return 3;
	else if(two_pair_cnt==2) return 2;
	else if(two_pair_cnt==1) return 1;
	else return 0;
}

int main(){
	int n, in;
	vector<int> input;
	vector<int> five_cards;
	cin>>n;
	while(n--){
		input.clear();
		for(int i=0; i<6; i++){
			cin>>in;
			input.push_back(in);
		}

		int temp, now, maxn=0;
		auto it = input.begin();
		for(int i=0; i<6; i++){
			temp = *it;
			input.erase(it);
			now = judge(input);
			if(now>=maxn) maxn=now;
			input.insert(it, temp);
			it++;
		}

		cout<<maxn<<endl;
	}


	return 0;
}
