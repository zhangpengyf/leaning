//3. 无重复字符的最长子串
//https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

#include <vector>
#include <iostream>
#include <string.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vec;
        //存储每个字符最后出现的位置。-1表示没出现过
        vec.resize(256, -1);
        int len = s.size();
        int left = 0;
        int res = 0;
        //for循环遍历的是截止位置，不是起始位置
        for (int end = 0; end < len; ++end) {
            if (vec[s[end]] >= left) {
                res = max(res, end - left);
                //如果字符在[left-end)之间出现过left可以直接移动到重复字符的下一个位置
                //如果left只是加1，会多一些没用的循环
                left = vec[s[end]] + 1;
            }
            //vec不能是char,否则字符长度大于128，会变成负数
            vec[s[end]] = end;          
        }
        res = max(res, len - left);
        return res;
    }
};


int main() {
    Solution s;
    cout << "result=" << s.lengthOfLongestSubstring("hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")<<endl;
//    cout << "reslut=" << s.lengthOfLongestSubstring("bbbbb")<<endl;
    //   cout << "result=" << s.lengthOfLongestSubstring("pwwkew")<<endl;
    return 0;
}
