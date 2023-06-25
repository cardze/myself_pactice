#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int deepth(vector<string>& tree, int index){
    int dep = 0 ;
    int pivot = index;
    while(tree[pivot-1] != "null" || pivot<tree.size()){
        if(tree[pivot*2-1]!="null"){
            pivot*=2;
            dep++;
        }else if(tree[pivot*2]!="null"){
            pivot*=2;
            pivot+=1;
            dep++;
        }
    }
    return dep;
}

int longest_path_tree(vector<string>& tree){
    int index_last = tree.size();
    int res = 0;
    int i =0 ;
    for(;index_last>=1;index_last/=2){
        i++;
        res = max(res, i + deepth(tree, (index_last/2)*2));
    }
    return res;
}

int main(){
    int n;
    vector<int> output_arr;
    cin>>n;
    string s;
    getline(cin,s);
    for(int i =0 ;i<n;i++){
        getline(cin, s);
        vector<string> string_arr;
        stringstream ss;
        replace(s.begin(), s.end(), '[', ' ');
        replace(s.begin(), s.end(), ',', ' ');
        replace(s.begin(), s.end(), ']', ' ');

        string ele;
        ss<<s;
        while(ss>>ele){
            string_arr.push_back(ele);
        }
        int res = longest_path_tree(string_arr);
        cout<<res<<endl;
    }
/* 
5
[6,5,7]
[1,2,3,4,5]
[1,2,3,4,6,null,7]
[1,2,3,4,5,6,7,8,9,10]
[1,2,3,4,5,6,7,8,null,null,null,null,null,null,15] 
*/
    return 0;
}