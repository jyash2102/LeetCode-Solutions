class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> arr(n1,-1);
        stack<int> st;
        unordered_map<int,int> mpp;
        for(int i=0;i<n1;i++){
            mpp[nums1[i]]=i;
        }
        for(int i=0;i<n2;i++){
            while (!st.empty() && nums2[i] > st.top()){
                if (mpp.find(st.top()) != mpp.end()){
                    arr[mpp[st.top()]] = nums2[i];
                }
                st.pop();
            }
            st.push(nums2[i]);
        }
        return arr;
    }
};