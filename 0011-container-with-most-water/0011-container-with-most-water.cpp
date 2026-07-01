class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0, l=0, r=height.size()-1;
        while(l<r){
            int water=min(height[l], height[r])*(r-l);
            ans=max(ans, water);
            if(height[l]<height[r]) l++;
            else r--;
        }
        return ans;
    }
};