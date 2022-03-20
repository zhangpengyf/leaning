#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;


class Solution {
public:
  bool isValid(string s) {
    if (s.size() == 0 || s.size() %2 != 0) return false;
    stack<char> st;
    for (char& ch : s) {
      switch (ch) {
      case '(':
      case '{':
      case '[':
	st.push(ch);
	break;
      case ')':
      case '}':
      case ']':
	char tar = 0;
	if (ch == ')') tar = '(';
	if (ch == '}') tar = '{';
	if (ch == ']') tar = '[';
	if (st.empty() || st.top() != tar) return false;
	st.pop();
	break;
      }
    }
    return st.empty();
  }
};




int main() {
  cout << "result=" << Solution().isValid("[]{}()") <<endl;
  return 0;
}
