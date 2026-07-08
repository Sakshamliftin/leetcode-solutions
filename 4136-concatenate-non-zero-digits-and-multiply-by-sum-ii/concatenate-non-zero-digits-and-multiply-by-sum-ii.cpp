#define MOD 1000000007

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> preNum(n + 1, 0);
        vector<long long> preSum(n + 1, 0);
        vector<int> cnt(n + 1, 0);
        vector<long long> power(n + 1, 1);

        // powers of 10
        for (int i = 1; i <= n; i++)
            power[i] = (power[i - 1] * 10) % MOD;

        // Prefixes considering ONLY non-zero digits
        for (int i = 1; i <= n; i++) {
            int d = s[i - 1] - '0';

            preNum[i] = preNum[i - 1];
            preSum[i] = preSum[i - 1];
            cnt[i] = cnt[i - 1];

            if (d != 0) {
                preNum[i] = (preNum[i - 1] * 10 + d) % MOD;
                preSum[i] = (preSum[i - 1] + d) % MOD;
                cnt[i]++;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int k = cnt[r + 1] - cnt[l];

            long long number =
                (preNum[r + 1] -
                 (preNum[l] * power[k]) % MOD +
                 MOD) % MOD;

            long long digitSum =
                (preSum[r + 1] - preSum[l] + MOD) % MOD;

            ans.push_back((number * digitSum) % MOD);
        }

        return ans;
    }
};