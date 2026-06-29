class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0) return false;
        priority_queue<int,vector<int>,greater<int>> pq;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[hand[i]]++;
        }
        for(auto& it: mpp){
            if(it.second>0) pq.push(it.first);
        }
        while(!pq.empty()){
            int start=pq.top();
            for(int i=0;i<groupSize;i++){
                int curr=start+i;
                if(mpp[curr]==0) return false;
                mpp[curr]--;
                if(pq.top()==curr && mpp[curr]==0){
                    pq.pop();
                }
            }
        }
        return true;
    }
};