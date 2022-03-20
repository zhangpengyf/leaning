#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        int len = strs[0].size();
        int size = strs.size();
        for (int i = 0; i < len; ++i) {
            char& c = strs[0][i];
            for (int j = 1; j < size; j++) {
                if (strs[j].size() <= i || strs[j][i] != c) return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};


// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         string res = strs.empty() ? "" : strs[0];
//         for (string s : strs)
//             while (s.find(res) != 0) res = res.substr(0, res.length() - 1);
//         return res;
//     }
// };


int main () {
    vector<string> s;
    s.push_back("flower");
    s.push_back("flow");
    s.push_back("flight");
    cout << "result=" << Solution().longestCommonPrefix(s)<< endl;
    return 0;
}
