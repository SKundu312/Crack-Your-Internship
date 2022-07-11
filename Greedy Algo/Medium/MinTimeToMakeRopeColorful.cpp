class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        for(int i=0;i<colors.size()-1;i++){
            if(colors[i]==colors[i+1]){
                vector<int> s;
                s.push_back(neededTime[i]);
                while(colors[i]==colors[i+1]){
                    s.push_back(neededTime[i+1]);
                    i++;
                }
                sort(s.begin(),s.end());
                for(int j=0;j<s.size()-1;j++)
                    ans+=s[j];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int minCost(string col, vector<int>& need) {
      int ans=0,sum=0;
    
     for(int i=1;i<col.size();i++)
     {  
       if(col[i-1]==col[i])
     { 
       ans+=min(need[i],need[i-1]);
       need[i]=max(need[i],need[i-1]);
     }
     }
      return ans;
    }
};

//greedy
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size(),ans=0;
        for(int i=1;i<n;++i)
        {
            if(colors[i]==colors[i-1])
            {
                int time=neededTime[i-1],maxt=neededTime[i-1];
                while(i<n && colors[i]==colors[i-1])
                {
                    time+=neededTime[i];
                    maxt=max(neededTime[i],maxt);
                    i++;
                }
                ans+=time-maxt; // we sum up time of all ballons of same color and remove it except the ballon with largest time
            }
            
        }
        return ans;
    }
};
