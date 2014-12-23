/*
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

*/
class Solution {
public:
    int findMin(vector<int> &num) {
        size_t i = 0, j = num.size() - 1;
        while(i < j && i < j - 1){
            size_t m = (i + j) / 2;
            if(num[m] > num[i])
                i = m;
            else
                j = m;
        }

        i = (j - 1) % num.size();

        return num[j] > num[i] ? num[(j + 1) % num.size()] : num[j]; 
    }
};
