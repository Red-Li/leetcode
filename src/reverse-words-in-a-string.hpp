/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
 *
 */

class Solution {
public:
    void reverseWords(string &s) {
        string tmp;
        int cpos = s.size() - 1; 
        while(cpos >= 0){
            while(cpos >= 0 && s[cpos] <= ' ') cpos--;
            int e = cpos;
            while(cpos >= 0 && s[cpos] > ' ') cpos--;
            int ss = cpos;
            
            if(ss < e)
                tmp +=  tmp.size() ? " " + s.substr(ss + 1, e - ss)
                                   : s.substr(ss + 1, e - ss);
        }

        s = std::move(tmp);
    }
};
