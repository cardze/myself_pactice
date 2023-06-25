#include <iostream>
#include <vector>
#include <string>
using namespace std;
//bad one with O(NM)
// int strStr(string haystack, string needle){
//     if(needle.empty() == true) return 0;
//     for(int pivot_haystack=0;pivot_haystack<haystack.length();pivot_haystack++){
//         if(needle[0]==haystack[pivot_haystack]){
//             int return_or_not = 1;
//             for(int pivot_needle=0;
//                 pivot_needle<needle.length();
//                 pivot_needle++){
//                     if(return_or_not == 1) return_or_not = (needle[pivot_needle] == haystack[pivot_haystack+pivot_needle])?1:0;
//                     else break;               
//             }
//             if(return_or_not == 1) return pivot_haystack;
//         }
//     }
//     return -1;
// }

//kmp algorithm
vector<int> kmpProcess(string needle) {
    int n = needle.size();
    vector<int> lps(n, 0);
    for (int i = 1, len = 0; i < n;) {
        if (needle[i] == needle[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

// better one with O(N+m)
int strStr(string haystack, string needle) {
    int m = haystack.size(), n = needle.size();
    if (!n) {
        return 0;
    }
    vector<int> lps = kmpProcess(needle);
    for (int i = 0, j = 0; i < m;) {
        if (haystack[i] == needle[j]) { 
            i++, j++;
        }
        if (j == n) {
            return i - j;
        }
        if (i < m && haystack[i] != needle[j]) {
            j ? j = lps[j - 1] : i++;
        }
    }
    return -1;
}

int main(){
    string test_haystack = "mississippi";
    string test_needle = "sipp";
    int result = strStr(test_haystack,test_needle);
    cout<<result<<endl;
    return 0;
}