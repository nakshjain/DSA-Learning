class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(ans, nums, 0, tmp);
        return ans;
    }

    void dfs(vector<vector<int>>& ans, const vector<int>& nums, int i, vector<int>& tmp){
        if(i==nums.size()){
            ans.push_back(tmp);
            return;
        };
        dfs(ans, nums, i+1, tmp);
        tmp.push_back(nums[i]);
        dfs(ans, nums, i+1, tmp);
        tmp.pop_back();
    }
};