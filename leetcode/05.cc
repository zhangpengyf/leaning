//5. 最长回文子串
//https://leetcode.cn/problems/longest-palindromic-substring/

#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len < 2)
        {
            return s;
        }
        bool** dp = new bool*[len];
        for (int i = 0; i < len; i++)
        {
            dp[i] = new bool[len];
            memset(dp[i], 0, sizeof(bool)*len);
        }
        for (size_t i = 0; i < len; i++)
        {
            dp[i][i] = true;
        }
        
        // vector<vector<int> > dp(len, vector<int>(len));
        // // 初始化：所有长度为 1 的子串都是回文串
        // for (int i = 0; i < len; i++) {
        //     dp[i][i] = true;
        // }
        int max_len = 1;
        int index = 0;
        
        for (int L = 2; L <= len; L++)
        {
            for (int i = 0; i < len; i++)
            {
                int j = i + L -1;
                if (j > len - 1)
                {
                    break;
                }
                if (s[i] != s[j])
                {
                    dp[i][j] = false;
                } else {
                    if (L < 3)
                    {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                    if (dp[i][j])
                    {
                        int l = j - i + 1;
                        if (l > max_len)
                        {
                            max_len = l;
                            index = i;
                        }
                        
                    }
                    
                }
            }
            
        }
        for (int i = 0; i < len; i++)
        {
            delete []dp[i];
        }
        delete [] dp;
        return s.substr(index, max_len);
        
    }
};


int main() {
    Solution s;
    string str = "babab";
    cout << str << " result=" << s.longestPalindrome(str)<<endl;
    return 0;
}
