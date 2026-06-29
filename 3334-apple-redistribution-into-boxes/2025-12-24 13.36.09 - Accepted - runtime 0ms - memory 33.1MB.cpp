class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end());
        int apples=0;
        for(int i=0;i<apple.size();i++){
            apples+=apple[i];
        }
        int cnt=0;
        int j=capacity.size()-1;
        while(j>=0 && apples>0){
            apples-=capacity[j];
            cnt++;
            j--;
        }
        return cnt;
    }
};