class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();
        int diff=0;
        int t=5;
        int f=0;
        int s=0;
        bool first=true;
        bool second=false;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1){
                if(first==false){
                    first=true;
                    second=false;
                }
                else{
                    second=true;
                    first=false;
                }
            }
            if(i==t){
                if(first==false){
                    first=true;
                    second=false;
                }
                else{
                    second=true;
                    first=false;
                }
                t+=6;
            }
                if(first) f+=nums[i];
                else s+=nums[i];
            
        }
        return f-s;
    }
};