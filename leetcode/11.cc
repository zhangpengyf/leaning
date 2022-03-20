#include <map>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int len = height.size();
        if (len <= 1) return 0;

        int i = 0;
        int j = len -1;
        while (len-- > 0) {
            int area = min(height[i], height[j])*len;
            if (area > max) max = area;
            if(height[i] < height[j]) ++i;
            else --j;
        }
        return max;
    }
};




int main() {
    vector<int> height = {1,1};
    cout << "result=" << Solution().maxArea(height) << endl;
    return 0;
}
