#include <map>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        if (nums.back() < 0 || nums.front() > 0) return {};
        for (int i = 0; i < len; ++i) {
            if(nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = len - 1;
            int target = 0 - nums[i];
            vector<int> tmp;
            while(k > j) {
                int sum = nums[j] + nums[k];
                if (nums[j] + nums[k] == target) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j+1]) {++j;}
                    while (j < k && nums[k] == nums[k-1]) {--k;}
                    --k;
                    ++j;
                } else if (sum < target) {
                    while (j < k && nums[j] == nums[j+1]) {++j;}
                    ++j;
                } else {
                    while (j < k && nums[k] == nums[k-1]) {--k;}
                    --k;
                }
            }
        }
        return result;
    }
};




int main() {
    vector<int> input = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    auto result = Solution().threeSum(input);
    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ",";
        }
        cout << "]"<<endl;
    }
    return 0;
}
