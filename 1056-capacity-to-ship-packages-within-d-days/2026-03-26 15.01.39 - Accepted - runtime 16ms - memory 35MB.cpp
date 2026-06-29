class Solution {
public:
    bool isvalid(vector<int>& weights, int days,int mid){
        int n = weights.size();
        int cnt=1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum+weights[i]>mid){
                cnt++;
                sum=0;
                sum+=weights[i];
            }
            else{
                sum+=weights[i];
            }
        }
        return (cnt<=days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low=*max_element(weights.begin(), weights.end());
        int high=accumulate(weights.begin(), weights.end(), 0);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isvalid(weights,days,mid)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};