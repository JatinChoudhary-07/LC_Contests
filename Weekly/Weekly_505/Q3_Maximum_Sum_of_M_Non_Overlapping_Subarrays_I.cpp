/*
Contest     : Weekly Contest 505
Question    : Q3
Problem     : Maximum Sum of M Non-Overlapping Subarrays I

Topic       : Dynamic Programming / Prefix Sum / Monotonic Queue
Approach    : DP Optimization with Deque

Time        : O(m * n)
Space       : O(n)
*/

class Solution {
public:
    typedef long long ll;

    long long maximumSum(vector<int>& nums,
                         int m,
                         int l,
                         int r) {

        int n = nums.size();

        vector<ll> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        const ll NEG = -4e18;

        vector<ll> prev(n + 1, 0);
        vector<ll> curr(n + 1, NEG);

        ll ans = NEG;

        for (int t = 1; t <= m; t++) {

            fill(curr.begin(), curr.end(), NEG);

            deque<int> dq;

            for (int i = 1; i <= n; i++) {

                curr[i] = curr[i - 1];

                int add = i - l;

                if (add >= 0) {

                    ll val = prev[add] - pref[add];

                    while (!dq.empty() &&
                           prev[dq.back()] - pref[dq.back()] <= val) {
                        dq.pop_back();
                    }

                    dq.push_back(add);
                }

                while (!dq.empty() &&
                       dq.front() < i - r) {
                    dq.pop_front();
                }

                if (!dq.empty()) {

                    int j = dq.front();

                    curr[i] = max(
                        curr[i],
                        pref[i] + prev[j] - pref[j]
                    );
                }

                ans = max(ans, curr[i]);
            }

            swap(prev, curr);
        }

        return ans;
    }
};
