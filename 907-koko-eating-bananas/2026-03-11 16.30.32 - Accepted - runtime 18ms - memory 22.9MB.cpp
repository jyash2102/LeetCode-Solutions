class Solution {
public:
    long long hours(vector<int>& piles,int mid){
        int n = piles.size();
        long long hr=0;
        for(int i=0;i<n;i++){
            hr+=ceil((double)piles[i]/mid);
        }
        return hr;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low=1,high=*max_element(piles.begin(),piles.end()),ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(hours(piles,mid)<=h){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};