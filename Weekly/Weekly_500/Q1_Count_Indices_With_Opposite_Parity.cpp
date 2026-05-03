/*
Contest     : Weekly Contest 500
Question    : Q1
Problem     : Count Indices With Opposite Parity

Topic       : Arrays / Math
Approach    : Brute Force

Time        : O(n^2)
Space       : O(1)
*/

class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {

        int n = nums.size();

        vector<int> answer;

        for (int i = 0; i < n; i++) {

            int score = 0;

            int parity = (nums[i] % 2 == 0) ? 0 : 1;

            for (int j = i + 1; j < n; j++) {

                if (parity == 0) {

                    if (nums[j] % 2 != 0) {
                        score++;
                    }

                } else {

                    if (nums[j] % 2 == 0) {
                        score++;
                    }
                }
            }

            answer.push_back(score);
        }

        return answer;
    }
};
