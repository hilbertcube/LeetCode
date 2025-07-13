/*
    Link: https://leetcode.com/problems/two-sum/description/
    Difficulty: Easy
    Possible Techniques: Raw dog (brute force), Two-pointers, Hashmap
*/

#include "include/headers.hpp"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++) {
            numMap[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // if map contains complement
            if (numMap.count(complement) && numMap[complement] != i) {
                return {i, numMap[complement]};
            }
        }
        return {};
    }
};

Solution sol;

int main(int argc, char *argv[]) {
    vector<int> num1 = {2,7,11,15}; int target1 = 9;
    cout << sol.twoSum(num1, target1) << '\n';

    vector<int> num2 = {3,2,4}; int target2 = 6;
    cout << sol.twoSum(num2, target2) << '\n';

    vector<int> num3 = {3,3}; int target3 = 6;
    cout << sol.twoSum(num3, target3) << '\n';
    return 0;
}

// .\run.ps1 -p 0001_two_sums