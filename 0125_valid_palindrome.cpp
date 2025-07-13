/*
    Link: https://leetcode.com/problems/valid-palindrome/description/
    Difficulty: Easy
    Possible Techniques: Two-pointers
*/

#include "include/headers.hpp"

class Solution {
public:
    bool isPalindrome(string s) {
        transformString(s);
        int left = 0;
        int right = s.size() - 1;

        while(left < right) {
            if(s[left] != s[right])
                return 0;
            left++;
            right--;
        }
        return 1;
    }

    void transformString(string& s) {
        string t;
        t.reserve(s.size());
        for(char c: s) { // construct a new string
            if(isalnum(c)) t += tolower(c);
        }
        s.swap(t); // copy t into s
    }
};

Solution sol;

int main(int argc, char *argv[]) {
    printBool(sol.isPalindrome("A man, a plan, a canal: Panama")); // expect true
    printBool(sol.isPalindrome("race a car")); // expect false
    printBool(sol.isPalindrome(" ")); // expect true
    printBool(sol.isPalindrome("......a.....")); // expect true
    
    return 0;
}

// .\scripts\run.ps1 -p 0125_valid_palindrome