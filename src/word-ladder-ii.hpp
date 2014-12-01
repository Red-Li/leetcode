/*
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

class Solution {
    void findLadders(string start, string end, 
            unordered_set<string> &dict,  
            int level,
            vector<string> &parents,
            vector<vector<string> > &res)
    {
        if(res.size() && parents.size() + 1 >= res.front().size())
            return;

        parents.push_back(start);

        vector<string> childs;
        for(size_t i = 0; i < start.size(); ++i){
            char oc = start[i];
            for(char c = 'a'; c <= 'x'; ++c){
                start[i] = c;
                if(start == end){
                    parents.push_back(end);
                    res.push_back(parents);
                    parents.pop_back();

                    continue;
                }

                if(dict.find(start) != dict.end()){
                    childs.push_back(start);
                    dict.erase(start);
                }
            }
            start[i] = oc;
        }
        
        for(size_t i = 0; i < childs.size(); ++i)
            findLadders(childs[i], end, dict, level + 1, parents, res);
        dict.insert(childs.begin(), childs.end());
        parents.pop_back();
    }


public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > res;
        vector<string> parents;

        dict.erase(start);
        findLadders(start, end, dict, 1, parents, res);

        return move(res);
    }
};
