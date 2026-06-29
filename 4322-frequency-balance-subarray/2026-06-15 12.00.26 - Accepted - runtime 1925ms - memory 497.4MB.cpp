class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans=1;
        for(int i=0;i<n;i++){
            unordered_map<int,int> freq,cnt;
            for(int j=i;j<n;j++){
                int val=nums[j];
                if(freq[val]>0) cnt[freq[val]]--;
                if(cnt.count(freq[val]) && cnt[freq[val]]==0) cnt.erase(freq[val]);
                freq[val]++;
                cnt[freq[val]]++;
                bool ok=false;
                if(freq.size()==1) ok=true;
                else if(cnt.size()==2){
                    vector<pair<int,int>> v;
                    for(auto& [x,f] : cnt){
                        v.push_back({x,f});
                    }
                    sort(v.begin(),v.end());
                    if(v[0].first*2 == v[1].first) ok=true;
                }
                if(ok) ans=max(ans,(j-i)+1);
            }
        }
        return ans;
    }
};