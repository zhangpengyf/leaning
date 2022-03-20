#include <map>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <iostream>
using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = haystack.size();
        int len_needle = needle.size();
        if (len_needle == 0) return 0;
        int i = 0;
        for (; i < len - len_needle + 1; ++i) {
            for (int j = 0; j < len_needle; ++j) {
                if (haystack[i+j] != needle[j]) break;
                if (j == len_needle - 1) return i;
            }
        }
        return -1;
    }
};



int main() {
    cout << "result=" << Solution().strStr("abcd", "bc") << endl;
    return 0;
}
