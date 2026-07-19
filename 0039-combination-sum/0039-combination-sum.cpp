class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(ans, candidates, target, tmp, 0, 0);
        return ans;
    }

    void dfs(vector<vector<int>>& ans, const vector<int>& candidates, int target, vector<int> tmp, int currSum, int index){
        if(currSum>target) return;
        if(currSum==target){
            ans.push_back(tmp);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            tmp.push_back(candidates[i]);
            dfs(ans, candidates, target, tmp, currSum+candidates[i], i);
            tmp.pop_back();
        }
    }
};