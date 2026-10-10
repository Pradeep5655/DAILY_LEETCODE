class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        long long total_diff = 0;
        vector<long long> count(100001, 0);
        
        for (int i = 0; i < n; i++) {
            long long diff = abs(nums1[i] - nums2[i]);
            count[diff]++;
            total_diff += diff;
        }
        if (k >= total_diff) return 0;
        
        for (int i = 100000; i > 0 && k > 0; i--) {
            if (count[i] > 0) {
                long long reduce = min(k, count[i]);
                count[i] -= reduce;
                count[i - 1] += reduce;
                k -= reduce;
            }
        }
        long long ans = 0;
        for (long long i = 1; i <= 100000; i++) {
            if (count[i] > 0) {
                ans += (i * i) * count[i];
            }
        }
        
        return ans;
    }
};