/*
class Solution {
public:
    int reverse(int x) {
        
    }
};

*/

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int xx = abs(x);
		int sign = (x & 0x80000000);

		if(sign){
			while(xx){
				if(INT_MIN / 10 > res)
					return 0;
				res *= 10;
				if(INT_MIN + (xx % 10) > res)
					return 0;
				res -= xx % 10;
				xx /= 10;
			}
		}
		else{
			while(xx){
				if(INT_MAX / 10 < res)
					return 0;
				res *= 10;
				if(INT_MAX - (xx % 10) < res)
					return 0;
				res += xx % 10;
				xx /= 10;
			}
		
		}
        
		return res;
    }
};
