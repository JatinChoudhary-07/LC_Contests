/*
Contest     : Weekly Contest 505
Question    : Q2
Problem     : Valid Binary Strings With Cost Limit

Topic       : Backtracking
Approach    : DFS Generation

Time        : O(2^n)
Space       : O(n)
*/

class Solution {
public:

    vector<string> ans;

    void dfs(int idx,
             int n,
             int k,
             int cost,
             string& curr) {

        if (cost > k) {
            return;
        }

        if (idx == n) {
            ans.push_back(curr);
            return;
        }

        curr.push_back('0');
        dfs(idx + 1, n, k, cost, curr);
        curr.pop_back();

        if (curr.empty() || curr.back() != '1') {

            curr.push_back('1');
            dfs(idx + 1, n, k, cost + idx, curr);
            curr.pop_back();
        }
    }

    vector<string> generateValidStrings(int n, int k) {

        string curr;

        dfs(0, n, k, 0, curr);

        return ans;
    }
};
