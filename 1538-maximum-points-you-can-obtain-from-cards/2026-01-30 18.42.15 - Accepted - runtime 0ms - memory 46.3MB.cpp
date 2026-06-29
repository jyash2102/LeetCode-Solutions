class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int i=0,j=0;
        int ans=0;
        int sum=0;
        int tsum=0;//total sum
        for(int i=0;i<n;i++) tsum+=cardPoints[i];
        while(j<n){
            sum+=cardPoints[j];
            while(j-i+1>n-k){
                sum-=cardPoints[i];
                i++;
            }
            if((j-i+1)==n-k){
                ans=max(ans,tsum-sum);
            }
            j++;
        }
        return ans;
    }
};