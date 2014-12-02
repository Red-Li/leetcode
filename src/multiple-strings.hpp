/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

class Solution {
    string add(string num1, string num2)
    {
        if(!num1.size())
            return num2;
        else if(!num2.size())
            return num1;

        size_t minSize = min(num2.size(), num1.size());
        
        int add = 0;
        size_t i = 0;
        string res;
        for(; i < minSize; ++i){
            int v1 = num1[i] - '0',
                v2 = num2[i] - '0';
            int v = v1 + v2 + add;
            add = v / 10;
            v %= 10;
            
            res.push_back('0' + v);
        }

        while(i < num1.size()){
            int v = (num1[i] - '0') + add;
            add = v / 10;
            v %= 10;

            res.push_back('0' + v);
			++i;
        }

        while(i < num2.size()){
            int v = (num2[i] - '0') + add;
            add = v / 10;
            v %= 10;

            res.push_back('0' + v);
			++i;
        }

        if(add)
            res.push_back('0' + add);

        return move(res);
    }
    
    string mul_const(string num, int shift, int c)
    {
        if(c == 0)
            return move(string("0"));

        num.insert(0, shift, '0');

        string res;
        int add = 0;
        for(size_t i = 0; i < num.size(); ++i){
            int v = (num[i] - '0') * c + add;
            add = v / 10;
            v %= 10;

            res.push_back('0' + v);
        }

        if(add)
            res.push_back('0' + add);
        
        return move(res);
    }

public:
    string multiply(string num1, string num2) {
        if(!num1.size() || !num2.size())
            return move(string("0"));
        
        num1 = string(num1.rbegin(), num1.rend());
        num2 = string(num2.rbegin(), num2.rend());

        string &s1 = num1.size() > num2.size() ? num1 : num2;
        string &s2 = num1.size() > num2.size() ? num2 : num1;
        string res("0");

        for(size_t i = 0; i < s2.size(); ++i){
            string tmp = mul_const(s1, i, s2[i] - '0');
            res = add(res, tmp);
        }

        return move(string(res.rbegin(), res.rend()));
    }
};
