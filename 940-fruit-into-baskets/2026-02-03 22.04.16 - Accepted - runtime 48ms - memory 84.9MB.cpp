class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int i=0,j=0;
        unordered_map<int,int> mpp;
        int maxlen=INT_MIN;
        while(j<n){
            mpp[fruits[j]]++;
            while(mpp.size()>2){
                mpp[fruits[i]]--;
                if(mpp[fruits[i]]==0) mpp.erase(fruits[i]);
                i++;
            }
           
                maxlen=max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};