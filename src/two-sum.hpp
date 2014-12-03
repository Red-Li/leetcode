/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> nmap;
        for(size_t i = 0; i < numbers.size(); ++i){
            nmap[numbers[i]] = i;
        }
        
        vector<int> res;
        for(size_t i = 0; i < numbers.size(); ++i){
            int num1 = numbers[i],
                num2 = target - num1;
            if(nmap.find(num2) != nmap.end() 
                    && nmap[num2] != i){
                res.push_back(i + 1);
                res.push_back(nmap[num2] + 1);
                break;
            }
            else{
                nmap.erase(num1);
            }
        }

        return move(res);
    }
};
