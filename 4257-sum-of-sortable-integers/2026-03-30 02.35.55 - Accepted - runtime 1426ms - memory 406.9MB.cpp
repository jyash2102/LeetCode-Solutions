class Solution {
public:
    bool pivot(vector<int>& nums){
        int n = nums.size();
        if(n==2) return true;
        vector<int> sorted=nums;
        sort(sorted.begin(),sorted.end());
        int drops=0;
        if(sorted==nums) return true;
      for (int i = 0; i < n; i++) {
        // Compare current element with the next one
        // Use (i + 1) % n to wrap around to the start index
        if (nums[i] > nums[(i + 1) % n]) {
            drops++;
        }
    }

    // If there is 1 or 0 drops, it can be sorted by rotation
    return drops <= 1;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        vector<int> sorted=nums;
        sort(sorted.begin(),sorted.end());
        if(sorted==nums) ans++;
        for(int i=2;i<=n;i++){
            vector<int> temp;
            if(n%i==0){
                vector<int> v;
                int k=0;
                for(int j=0;j<n;j++){
                    if(k==i){
                        if(pivot(v)){
                            sort(v.begin(),v.end());
                            for(int u=0;u<v.size();u++){
                                temp.push_back(v[u]);
                            }
                        }
                        v.clear();
                        v.push_back(nums[j]);
                        k=1;
                    }
                    else{
                        v.push_back(nums[j]);
                        k++;
                    }
                }
                if(k==i){
                        if(pivot(v)){
                            sort(v.begin(),v.end());
                            for(int u=0;u<v.size();u++){
                                temp.push_back(v[u]);
                            }
                        }
                        k=0;
                        v.clear();
                    }
                if(temp.size()==n && temp==sorted){
                    ans+=i;
                }
            }
        }
        return ans;
    }
};