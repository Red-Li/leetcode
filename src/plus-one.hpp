
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        std::vector<int> res(digits);
        int i = res.size() - 1;
        int add = 1;

        while(add && i >= 0){
            res[i] += add;
            add = res[i] / 10;
            res[i] -= add * 10;
            --i;
        }

        if(add)
            res.insert(res.begin(), add);
        return std::move(res);
    }
};
