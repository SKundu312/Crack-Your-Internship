class Solution {
public:
    void merge(vector<pair<int,int>>& arr,vector<int>& ans,int s,int mid,int e){
        int i=s,j=mid+1,c=0,k=0;
        vector<pair<int,int>> tmp(e-s+1);
        while(i<=mid && j<=e){
            if(arr[i].first<=arr[j].first){
                ans[arr[i].second]+=c;
                tmp[k++]=arr[i++];
            }
            else{
                c++;
                tmp[k++]=arr[j++];
            }
        }
            while(i<=mid){
                ans[arr[i].second]+=c;
                tmp[k++]=arr[i++];
            }
            while(j<=e){
                tmp[k++]=arr[j++];
            }
            for(int l=s;l<=e;l++)
                arr[l] = tmp[l-s];
    }
    
    void mergeSort(vector<pair<int,int>>& arr, vector<int>& ans,int s,int e){
        if(s>=e) return;
        int mid=s+(e-s)/2;
        mergeSort(arr,ans,s,mid);
        mergeSort(arr,ans,mid+1,e);
        merge(arr,ans,s,mid,e);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> arr(nums.size());
        for(int i=0;i<nums.size();i++){
            arr[i]=make_pair(nums[i],i);
        }
        vector<int> ans(nums.size(),0);
        mergeSort(arr,ans,0,nums.size()-1);
        return ans;
    }
};
