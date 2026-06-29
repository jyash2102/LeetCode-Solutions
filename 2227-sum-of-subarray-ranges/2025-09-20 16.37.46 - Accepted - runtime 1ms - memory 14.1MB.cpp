class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        long long mincontrib=0;
        int nse,pse,el;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                nse=i;
                el=st.top();
                st.pop();
                if(!st.empty()) pse=st.top();
                else pse=-1;
                mincontrib+=(long long)(nse-el)*(el-pse)*nums[el];
            }
            st.push(i);
        }
        while(!st.empty()){
            el=st.top();
            st.pop();
            if(!st.empty()) pse=st.top();
            else pse=-1;
            nse=n;
            mincontrib+=(long long)(nse-el)*(el-pse)*nums[el];
        }
        while(!st.empty()) st.pop();
        long long maxcontrib=0;
        int nge,pge,ele;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                pge=i;
                ele=st.top();
                st.pop();
                if(!st.empty()) nge=st.top();
                else nge=n;
                maxcontrib+=(long long)(nge-ele)*(ele-pge)*nums[ele];
            }
            st.push(i);
        }
        while(!st.empty()){
            ele=st.top();
            st.pop();
            if(!st.empty()) nge=st.top();
            else nge=n;
            pge=-1;
            maxcontrib+=(long long)(nge-ele)*(ele-pge)*nums[ele];
        }
    return maxcontrib-mincontrib;
    }
};