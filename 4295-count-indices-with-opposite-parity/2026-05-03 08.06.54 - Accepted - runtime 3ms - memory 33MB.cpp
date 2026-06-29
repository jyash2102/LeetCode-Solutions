class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        bool even=false;
        bool odd=false;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0) even=true;
            else odd=true;
            int cnt=0;
            for(int j=i+1;j<n;j++){
                if(nums[j]%2==0 && odd) cnt++;
                if(nums[j]%2==1 && even) cnt++;
            }
            ans.push_back(cnt);
            even=false;
            odd=false;
        }
        return ans;
    }
};