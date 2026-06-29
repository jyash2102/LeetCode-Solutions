class Solution {
public:
    bool valid(vector<int>& bloomDay,int mid,int k,int m){
        int n = bloomDay.size();
        int bouq=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                cnt++;
                if(cnt>=k){
                    bouq++;
                    cnt=0;
                }
            }
            else cnt=0;
        }
        return (bouq>=m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m * k > bloomDay.size()) return -1;
        int low=1,high=*max_element(bloomDay.begin(),bloomDay.end()),ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(valid(bloomDay,mid,k,m)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};