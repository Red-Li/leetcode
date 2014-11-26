
#ifndef NAMESPACE
#include <vector>
#endif

using namespace std;

class Solution {
    void permutation(vector<int> &num, int s, int e, vector<vector<int> > &result)
    {
        if(s == e){
            result.push_back(num);
            return;
        }

		permutation(num, s + 1, e, result);

        for(int i = s; i < e; ++i){
            int v = num[i + 1];
			num.erase(num.begin() + i + 1);
			num.insert(num.begin() + s, v);
            //std::swap(num[s], num[i + 1]);
            permutation(num, s + 1, e, result);
			num.erase(num.begin() + s);
			num.insert(num.begin() + i + 1, v);
            //std::swap(num[s], num[i + 1]);
        }
    }
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        
        if(num.size())
            permutation(num, 0, num.size() - 1, result);
        
        return std::move(result);
    }
};
