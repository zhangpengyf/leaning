#include <map>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <iostream>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        int p = 0, q = 1;
        //p指向的都是不重复的
        //pq之间是重复的数字空出来的格子
        //p是下标，所以长度是p+1
        while (q < n) {
            if (nums[p] == nums[q]) {
                ++q;
            } else {
                nums[++p] = nums[q++];
            }
        }
        return p+1;
    }
};



int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    int res = Solution().removeDuplicates(v);
    cout << "result=" << res << endl;
    for (int i = 0; i < res; ++i) {
        cout << v[i] << endl;
    }
    return 0;
}
