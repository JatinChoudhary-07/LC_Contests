/*
Contest     : Weekly Contest 505
Question    : Q1
Problem     : Sum of Compatible Numbers in Range I

Topic       : Bit Manipulation
Approach    : Brute Force Enumeration

Time        : O(k)
Space       : O(1)
*/

class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {

        int sum = 0;

        for (int x = max(1, n - k); x <= n + k; x++) {

            if ((n & x) == 0) {
                sum += x;
            }
        }

        return sum;
    }
};
