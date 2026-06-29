class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        long long  sum=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            sum+=nums[i];
        }
        double average=(double)sum/n;
        int ans=floor(average) + 1;;
        while(mp.find(ans)!=mp.end() || ans<=0){
            ans++;
        }
        return ans;
    }
};