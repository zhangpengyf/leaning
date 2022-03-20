#include <string>
#include <iostream>

using namespace std;

// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000


class Solution {
public:
    int romanToInt(string s) {
        int i = s.size() - 1;
        int sum = 0;
        int last = 0;
        while (i >= 0) {
            int num = 0;
            switch (s[i--]) {
            case 'I' :
                num = 1;
                break;
            case 'V' :
                num = 5;
                break;
            case 'X':
                num = 10;
                break;
            case 'L' :
                num = 50;
                break;
            case 'C':
                num = 100;
                break;
            case 'D':
                num = 500;
                break;
            case 'M':
                num = 1000;
                break;
            }
            if (last <= num) sum += num;
            else sum -= num;
            last = num;
        }
        return sum;
    }
};

int main() {
    Solution s;
    cout << "result=" << s.romanToInt("MCMXCIV") << endl;
}
