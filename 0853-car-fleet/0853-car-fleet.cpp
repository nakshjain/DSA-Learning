class Solution {
public:
    struct Compare{
        bool operator()(pair<int, int>& a, pair<int, int>& b){
            return a.first < b.first;
        }
    };

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> time;
        for(int i=0;i<position.size();i++){
            time.push_back({position[i], speed[i]});
        }
        sort(time.begin(), time.end(), Compare());
        int ans=0;
        float curTime=0;
        for(int i=time.size()-1;i>=0;i--){
            float t = (float) (target - time[i].first) / time[i].second;
            if(t>curTime){
                curTime=t;
                ans++;
            }
        }
        return ans;
    }
};