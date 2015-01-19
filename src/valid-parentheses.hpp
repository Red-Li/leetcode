/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> his;
        map<char, char> pairs;
        pairs['('] = ')';
        pairs['['] = ']';
        pairs['{'] = '}';

        for(size_t i = 0; i < s.size(); ++i){
            if(pairs.find(s[i]) != pairs.end())
                his.push(s[i]);
            else if(his.size() && pairs[his.top()] == s[i])
                his.pop();
            else
                return false;
        }

        return !his.size();
    }
};
