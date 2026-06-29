class Solution {
public:
    bool valid(long long n,long long 
               x){
        int last=n%10;
        while(n>=10) n/=10;
        if(n==x && last==x) return true;
        return false;
    }
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            long long  sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(valid(sum,x)) cnt++;
            }
        }
        return cnt;
    }
};