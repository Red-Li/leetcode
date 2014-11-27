/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/


class Solution {
    bool wordBreak(string s, unordered_set<string> &dict, 
                    vector<int> &flags)
    {
		if(!s.size())
			return true;

        for(unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++it){
            size_t psize = it->size();
            if(psize <= s.size() && s.substr(0, psize) == *it){
                int idx = s.size() - psize;
                if(flags[idx] == -1){
                    flags[idx] = wordBreak(s.substr(psize, s.size() - psize), dict, flags);
                }

                if(flags[idx] == 1)
                    return true;
            }
        }

        return false;
    }

public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<int> flags(s.size(), -1);
        return wordBreak(s, dict, flags);
    }
};
