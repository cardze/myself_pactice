#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;


int main(){
    int n;
    cin>>n;
    for(;n>0;n--){
        int m;
        cin>>m;
        int aj_mat[50000] = {0};
        for(;m>0;m--){
            int a,b;
            cin>>a;
            cin>>b;
            aj_mat[a]=b;
        }
        int min_source=INT32_MAX;
        int max_len=0;
        for(int i = 1; i<50000 ; i++){
            int pivot = i ;
            if(aj_mat[pivot] != 0){
                int start_point = i;
                int len = 0;
                int arrived[50000]={0};
                while(aj_mat[pivot] != 0 && aj_mat[pivot] != start_point && arrived[pivot]!=1){
                    len++;
                    arrived[pivot]=1;
                    pivot=aj_mat[pivot];
                }
                int ori = max_len;
                
                max_len = max(max_len, len);
                if(ori != max_len) min_source = start_point;
                if(ori == max_len) min_source = min(min_source, start_point);
            }
        }
        cout<<min_source<<endl;
    }
    return 0;
}

/*
3
3
1 2
2 3
3 1
4
1 2
2 1
4 3
3 2
5
1 2
2 1
5 3
3 4
4 5
*/