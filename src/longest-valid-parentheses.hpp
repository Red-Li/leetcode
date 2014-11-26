
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        std::vector<bool> flags(s.size(), false);
        std::stack<char> st;
        std::stack<int> si;

        for(size_t i = 0; i < s.size(); ++i){
            if(s[i] == ')' && st.size() && st.top() == '('){
                flags[i] = true;
                flags[si.top()] = true;

                st.pop();
                si.pop();
            }
            else{
                st.push(s[i]);
                si.push(i);
            }
        }

        int curMax = 0, cur = 0;
        for(size_t i = 0; i < flags.size(); ++i){
            if(flags[i]){
                ++cur;
            }
            else{
                curMax = cur > curMax ? cur : curMax;
                cur = 0;
            }
        }
        curMax = cur > curMax ? cur : curMax;

        
        return curMax;
    }
};
