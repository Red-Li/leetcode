
#ifndef NAMESPACE
#include <algorithm>
#include <string>
#endif
using namespace std;

class Solution {

    void iswap(char *s, int f, int t)
    {
        char c = s[f];
        if(f > t){
            for(int i = f ; i > t; --i)
                s[i] = s[i - 1];
        }
        else if(f < t){
            for(int i = f ; i < t; ++i)
                s[i] = s[i + 1];
        }
        s[t] = c;
    }

    bool permutation(int s, int e, int k, int &cur, char *result)
    {
        if(s == e){
            return ++cur == k;
        }

		if(permutation(s + 1, e, k, cur, result))
                return true;

        for(int i = s; i < e; ++i){
            iswap(result, i + 1, s);
            //std::swap(result[s], result[i + 1]);
            if(permutation(s + 1, e, k, cur, result))
                return true;
            iswap(result, s, i + 1);
            //std::swap(result[s], result[i + 1]);
        }

        return false;
    }


public:

    string getPermutation(int n, int k) {
        char seq[10];
        for(char i = 1; i < n + 1; ++i)
            seq[i - 1] = '0' + i;
        seq[n] = 0;

        int cur = 0;
        permutation(0, n - 1, k, cur, seq);
        
        return std::move(std::string(seq, n));
    }
};
