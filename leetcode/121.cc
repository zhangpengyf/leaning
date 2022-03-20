#include <map>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <iostream>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = 1e5;
        int max_profit = -1;
        for (int price : prices) {
            if (price < min_price) {
                min_price = price;
                continue;
            }
            int tmp = price - min_price;
            if (tmp > max_profit) max_profit = tmp;
        }
        return max_profit;
    }
};



int main() {
    vector<int> v = {7, 1, 5, 3, 6, 4};
    cout << "result=" << Solution().maxProfit(v) << endl;
    return 0;
}
