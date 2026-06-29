class Solution {
public:
    bool prime(int k){
        if(k==0||k==1) return false;
        int cnt=0;
        for(int i=2;i<=sqrt(k);i++){
            if(k%i==0) cnt++;
        }
        if(cnt>0) return false;
        else return true;
    }
    long long splitArray(vector<int>& nums) {
        int n=nums.size();
        long long sumA=0;
        long long sumB=0;
        for(int i=0;i<n;i++){
            if(prime(i)==true) sumA+=nums[i];
            else sumB+=nums[i];
        }
        if(sumA>sumB) return sumA-sumB;
        else return sumB-sumA;
    }  
};