
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {

            vector<int> freq(26, 0);

            int distinct = 0;
            int maxFreq = 0;
            int maxCount = 0;

            for(int j = i; j < n; j++) {

                int ch = s[j] - 'a';

                if(freq[ch] == 0)
                    distinct++;

                freq[ch]++;

                if(freq[ch] > maxFreq) {
                    maxFreq = freq[ch];
                    maxCount = 1;
                }
                else if(freq[ch] == maxFreq) {
                    maxCount++;
                }

                int len = j - i + 1;

                if(maxFreq * maxCount == len) {
                    ans = max(ans, len);
                }
            }
        }

        return ans;
    }
};
