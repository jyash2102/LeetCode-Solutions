class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        priority_queue<int> pq;
        vector<int> mp(26,0);
        for(char& ch : tasks){
            mp[ch-'A']++;
        }
        for(auto& it:mp){
            if(it!=0) pq.push(it);
        }
        int ans=0;
        int cycle=n+1;
        while(!pq.empty()){
            vector<int> temp;
            for(int i=1;i<=cycle;i++){
                if(!pq.empty()){
                    int freq=pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            for(int& f:temp){
                if(f>0) pq.push(f);
            }
            if(pq.empty()) ans+=temp.size();
            else ans+=cycle;
        }
        return ans;
    }
};