//iterative
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int maxa=0,ans;
        while(i<j){
            ans=(j-i)*min(height[i],height[j]);
            if(maxa<ans) maxa=ans;
            if(height[i]<=height[j]) i++;
            else j--;
        }
        return maxa;
    }
};

//recursive
class Solution {
public:
    int help(int i, int j, vector<int>& height){
        if(i>=j) return 0;
        int ans=(j-i)*min(height[i],height[j]);
        if(height[i]<=height[j]) 
            return max(ans,help(i+1,j,height));
        else
            return max(ans,help(i,j-1,height));
    }
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        return help(i,j,height);
    }
};
