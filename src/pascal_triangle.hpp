
class Solution {
    vector<int> generateNext(vector<int> &p)
    {
        vector<int> r(1, 1);
        for(size_t i = 1; i < p.size(); ++i)
            r.push_back(p[i - 1] + p[i]);
        if(p.size())
            r.push_back(p.back());
        
        return move(r);
    }



public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > r;
        vector<int> p;
        vector<int> *pp = &p;

        for(int i = 0; i < numRows; ++i){
            r.push_back(generateNext(*pp));
            pp = &r.back();
        }

        return move(r);
    }
};
