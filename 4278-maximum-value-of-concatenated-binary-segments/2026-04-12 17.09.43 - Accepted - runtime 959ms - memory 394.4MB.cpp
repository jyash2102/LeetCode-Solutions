class Solution {
public:
    const int M=1e9+7;
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();
        vector<string> v;
        for(int i=0;i<n;i++){
            string s = string(nums1[i],'1')+string(nums0[i],'0');
            v.push_back(s);
        }
        sort(v.begin(),v.end(),[](auto& a,auto& b){
            int n1 = a.length();
            int n2 = b.length();
            int total=n1+n2;
            for(int i=0;i<total;i++){
                char ch1=(i<n1) ? a[i] : b[i-n1];
                char ch2=(i<n2) ? b[i] : a[i-n2];
                if(ch1!=ch2) return ch1>ch2;
            }
            return false;
        });
        long long ans=0;
        for(auto& str:v){
            for(char c: str){
                ans=((ans*2)+(c-'0'))%M;
            }
        }
        return ans;
    }
};