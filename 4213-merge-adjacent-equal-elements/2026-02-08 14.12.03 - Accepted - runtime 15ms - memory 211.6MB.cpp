class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans;
        stack<long long> st;
        for(auto& it : nums){
            if(st.empty()){
                st.push(it);
            }
            else{
                long long el=it;
                while(!st.empty() && st.top()==el){
                    st.pop();
                    el=el*2;
                }
                st.push(el);
            }
        }
        while(!st.empty()){
            long long el=st.top();
            ans.push_back(el);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};