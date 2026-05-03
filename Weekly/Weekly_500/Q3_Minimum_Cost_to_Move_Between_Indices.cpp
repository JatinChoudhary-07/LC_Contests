/*
Contest     : Weekly Contest 500
Question    : Q3
Problem     : Minimum Cost to Move Between Indices

Topic       : Prefix Sum / Greedy
Approach    : Forward + Backward Prefix Cost

Time        : O(n + q)
Space       : O(n)
*/

class Solution {
public:

    vector<int> minCost(vector<int>& nums,
                        vector<vector<int>>& queries) {

        int n = nums.size();

        // Build closest array
        vector<int> closest(n);

        for (int i = 0; i < n; i++) {

            if (i == 0) {

                closest[i] = 1;

            } else if (i == n - 1) {

                closest[i] = n - 2;

            } else {

                int leftDiff = nums[i] - nums[i - 1];
                int rightDiff = nums[i + 1] - nums[i];

                closest[i] = (leftDiff <= rightDiff)
                             ? i - 1
                             : i + 1;
            }
        }

        // Forward prefix cost
        vector<long long> forward(n, 0);

        for (int i = 0; i < n - 1; i++) {

            int diff = nums[i + 1] - nums[i];

            int cost = (closest[i] == i + 1)
                       ? 1
                       : diff;

            forward[i + 1] = forward[i] + cost;
        }

        // Backward prefix cost
        vector<long long> backward(n, 0);

        for (int i = n - 1; i > 0; i--) {

            int diff = nums[i] - nums[i - 1];

            int cost = (closest[i] == i - 1)
                       ? 1
                       : diff;

            backward[i - 1] = backward[i] + cost;
        }

        // Process queries
        vector<int> ans;

        for (auto& q : queries) {

            int left = q[0];
            int right = q[1];

            if (left <= right) {

                ans.push_back(
                    (int)(forward[right] - forward[left])
                );

            } else {

                ans.push_back(
                    (int)(backward[right] - backward[left])
                );
            }
        }

        return ans;
    }
};
