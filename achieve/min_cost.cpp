#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int min_cost(vector<vector<int>>& maze){
    if(maze.size()==1 && maze[0].size()==1) return maze[0][0];
    if(maze.size()==1){
        int sum =0;
        for(auto a:maze[0]) sum+=a;
        return sum;
    }
    if(maze[0].size()==1){
        int sum =0;
        for(int i =0;i<maze.size();i++) sum+=maze[i][0];
        return sum;
    }
    int n=maze.size();
    int m=maze[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    for(int i=n-1;i>=0;i--){
        for(int j =m-1 ; j>=0;j){
            if(i==0 && j==0) dp[i][j] = maze[i][j];
            else if(i==0) dp[i][j] += (maze[i][j]+dp[i][j-1]);
            else if(j==0) dp[i][j] += (maze[i][j]+dp[i-1][j]);
            else dp[i][j] += (maze[i][j]+min(dp[i][j-1],dp[i-1][j]));
        }
    }    
    
    return dp[n-1][m-1];
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>> maze ;

    for(;n>0;n--){
        int t, m;
        cin>>t>>m;
        maze.clear();
        for(int i=0;i<t;i++){
            vector<int> ele_vec;
            ele_vec.clear();
            for(int j = 0;j<m;j++){
                int ele;
                cin>>ele;
                ele_vec.push_back(ele);
            }
            maze.push_back(ele_vec);
        }
        
        int res = min_cost(maze);
        cout<<res<<endl;
    }

}