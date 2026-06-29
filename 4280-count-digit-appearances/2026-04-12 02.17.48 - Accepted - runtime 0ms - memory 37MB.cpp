class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size();
        int cnt=0;
        for(auto& num: nums){
            while(num>0){
                int val=num%10;
                if(val==digit) cnt++;
                num/=10;
            }
        }
        return cnt;
    }
};