class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k,0);
        vector<long long> dp(k,0);

        for(int num:nums){
            vector<long long> next_dp(k,0);

            int curr_rem = num % k;

            next_dp[curr_rem] += 1;

            for(int i=0;i<k;++i){
                if(dp[i]>0){
                int new_rem = (i*curr_rem)%k;
                next_dp[new_rem] += dp[i];
                }
            }

            dp = next_dp;

            for(int i=0;i<k;++i){
                result[i] += dp[i];
            }
        }

        return result;
    }
};