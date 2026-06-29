class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int n = events.size();
        vector<int> ans;;
        int cnt=0;
        int s=0;
        for(int i=0;i<n;i++){
            if(cnt==10) break;
            if(events[i]=="WD" || events[i]=="NB"){
                s++;
            }
            else if(events[i]=="W"){
                cnt++;
            }
            else s+=stoi(events[i]);
        }
        return{s,cnt};
    }
};