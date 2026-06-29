class Solution {
public:
    unordered_map<int,int> mpp;
    unordered_map<string,bool> dp;
    bool flag=false;
    void recur(vector<int>& nums,int jump,int idx){
        if(flag) return;
        int n = nums.size();
        string key = to_string(idx) + "_" + to_string(jump);
        if(dp.count(key)) return;

        dp[key] = true;
        if(idx==n-1){
            flag=true;
            return;
        }
        for(int i=jump-1;i<=jump+1;i++){
            if(i<=0) continue;
            int nextpos=nums[idx]+i;
            if(mpp.count(nextpos)) recur(nums,i,mpp[nextpos]);
        }
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1) return false;
        int n = stones.size();
        for(int i=0;i<n;i++) mpp[stones[i]]=i;;
        recur(stones,1,1);
        return flag;
    }
};