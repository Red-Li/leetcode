/*
 Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(!s[0] && !p[0])
            return true;
        else if(!s[0])
            return p[0] == '*' && !p[1];
        else if(!p[0])
            return false;

        vector<vector<bool> > his;
        int ssize = -1;
		int pcount = 0;

        for(int i = 0; p[i]; ++i){
            his.push_back(vector<bool>(pcount, false));
            vector<bool> &res = his.back(); 

			int j;
            for(j = pcount; (ssize == -1 || j < ssize) && s[j]; ++j){
                bool pmatch = (!j || !i) || his[i - 1][j - 1]; //<! if his[i - 1][j - 1] matched
                bool match = false;
                if(p[i] == '*'){
                    match = pmatch || (j > 0 && his[i][j - 1]) || (i > 0 && his[i - 1][j]);
                }
				else if((p[i] == '?' || s[j] == p[i]) && (i || i == j)){
                    match = pmatch;
                }

                res.push_back(match);
            }
			ssize = j;

			pcount += p[i] != '*';
        }
        
        return his.back().back();
    }
};
