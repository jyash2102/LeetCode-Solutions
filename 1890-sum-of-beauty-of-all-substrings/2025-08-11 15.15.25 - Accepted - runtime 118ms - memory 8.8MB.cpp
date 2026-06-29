class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum=0;
        for(int i=0;i<n;i++){
            int freq[26]={0};
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int mine=INT_MAX,maxe=0;
                for(int k=0;k<26;k++){
                    if(freq[k]>0){
                    mine=min(mine,freq[k]);
                    maxe=max(maxe,freq[k]);
                    }
                }
                sum+=(maxe-mine);
            }
        }
        return sum;
    }
};