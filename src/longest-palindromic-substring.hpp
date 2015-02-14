/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

O(N^2)

Note: Can optimize to O(n) by An O(N) Solution (Manacher’s Algorithm)
http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html

*/


class Solution {
public:
    string longestPalindrome(string s) {
        if(!s.size())
            return string();

        int s_ = 0, n = 1;

        for(int i = 1; i < s.size(); ++i){
            int j = 0;
            while(j < i && (i + j + 1) < s.size() && s[i - j - 1] == s[i + j + 1]) ++j;
            
            if(j * 2 + 1 > n){
                s_ = i - j;
                n = j * 2 + 1;
            }
            
            j = 1;
            while(j <= i && (i + j - 1) < s.size() && s[i - j] == s[i + j - 1]) ++j;

            if((j - 1) * 2 > n){
                s_ = i - j + 1;
                n = (j - 1) * 2;
            }
        }

        return move(s.substr(s_, n));
    }
};
