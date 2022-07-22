class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> nextG(nums2.size(),-1);
        int j=0;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
           }
            if(!st.empty())
                nextG[i]=st.top();
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i= 0; i<nums1.size(); i++ ){
        for(int j = 0 ;j <nums2.size() ;j++) {
            if(nums1[i] == nums2[j]) {
                ans.push_back(nextG[j]);  
                break;
            }
        }
    }
        return ans;
    }
};
