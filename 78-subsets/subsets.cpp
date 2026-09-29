class Solution {
public:
    void retsub(vector<int>& nums, int n, int idx, vector<int>& current, vector<vector<int>>& ans) {
        if (idx == n) {
            ans.push_back(current);
            return;
        }
        retsub(nums, n, idx + 1, current, ans);
        current.push_back(nums[idx]);
        retsub(nums, n, idx + 1, current, ans);
        current.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        int n = nums.size();
        
        retsub(nums, n, 0, current, ans);
        
        return ans;
    }
};