/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> ldict(dict);
        queue<string> toAccess;
        queue<int> levels;

        toAccess.push(start);
        levels.push(1);
        ldict.erase(start);

        while(!toAccess.empty()){
            string &s = toAccess.front();
            int level = levels.front();

            for(size_t i = 0; i < s.size(); ++i){
                char oc = s[i];
                for(char c = 'a'; c <= 'z'; ++c){
                    s[i] = c;
                    if(s == end)
                        return level + 1;

                    if(ldict.find(s) != ldict.end()){
                        toAccess.push(s);
                        levels.push(level + 1);
                        ldict.erase(s);
                    }
                }
                s[i] = oc;
            }

            toAccess.pop();
            levels.pop();
        }

        return 0;
    }
};
