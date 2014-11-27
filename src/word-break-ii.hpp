class Solution {
    vector<string> wordBreak(string s,
                             unordered_set<string> &dict,
                             vector<int> &flags, 
                             vector<vector<string> > &his)
    {
        vector<string> res;
        if(s.size()){
            for(unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++it){
                size_t psize = it->size();
                if(psize <= s.size() && s.substr(0, psize) == *it){
                    int idx = s.size() - psize;
                    string prefix = s.substr(0, psize);
                    if(!flags[idx]){
                        his[idx] = wordBreak(
                                        s.substr(psize, s.size() - psize), 
                                        dict,
                                        flags,
                                        his
                                    );
                        flags[idx] = 1;
                    }

                    for(size_t i = 0; i < his[idx].size(); ++i){
                        string &ss = his[idx][i];
                        res.push_back(prefix + (ss.size() ? " " : "") + ss);
                    }
                }
            }
        }
		else{
			res.push_back("");
		}

        return move(res);
    }
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<vector<string> > his(s.size(), vector<string>());
        vector<int> flags(s.size(), 0);

        return move(wordBreak(s, dict, flags, his));
    }
};
