#include <map>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <iostream>
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n-1];
                --n;
            } else {
                ++i;
            }
        }
        return n;
    }
};



int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(5);
    v.push_back(3);
    int res = Solution().removeElement(v, 3);
    cout << "result=" << res << endl;
    for (int i = 0; i < res; ++i) {
        cout << v[i] << endl;
    }
    return 0;
}
