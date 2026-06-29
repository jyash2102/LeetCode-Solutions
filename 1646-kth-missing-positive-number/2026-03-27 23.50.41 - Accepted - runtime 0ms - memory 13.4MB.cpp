class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int prev=0;
        for(int i=0;i<n;i++){
            int missing = arr[i]-(prev+1);
            if(k<=missing){
                return prev+k;
            }
            k-=missing;
            prev=arr[i];
        }
        return prev+k;
    }
};