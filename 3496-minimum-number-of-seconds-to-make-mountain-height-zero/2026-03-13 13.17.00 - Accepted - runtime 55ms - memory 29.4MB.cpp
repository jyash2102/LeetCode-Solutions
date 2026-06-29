class Solution {
public:
    bool valid(int mountainHeight, vector<int>& workerTimes,long long mid){
        int n = workerTimes.size();
        long long height=0;
        for(int i=0;i<n;i++){
            long long val=(1LL*mid*2)/workerTimes[i];
            long long h = (sqrtl(1.0L + 4.0L * val) - 1.0L) / 2.0L;
            height+=h;
        }
        return (height>=mountainHeight);
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low=1;
        long long maxi=*max_element(workerTimes.begin(),workerTimes.end());
        long long sum = 1LL * mountainHeight * (mountainHeight + 1) / 2;
        long long high=1LL*sum*maxi;
        long long ans=-1;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(valid(mountainHeight,workerTimes,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};