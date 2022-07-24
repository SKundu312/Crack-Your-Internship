//Recursion
class Solution {
public:
    bool fn(vector<int>& stones, int i, int k){
        if(i==stones.size()-1) return true;
        if(k<=0) return false;
        if((stones[stones.size()-1]-stones[i]<k) || (stones[i+1]-stones[i])>k) return false;
        int temp=i+1;
        while(stones[temp]-stones[i]<k) temp++;
        if(stones[temp]-stones[i]==k)
        return fn(stones,temp,k-1) || fn(stones,temp,k) || fn(stones,temp,k+1);
        else
            return false;
    }
    bool canCross(vector<int>& stones) {
        return fn(stones,0,1);
    }
};

//Tabulation with hashmap
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,set<int>> m;
        m[stones[0]+1]={1};
        for(int i=1;i<stones.size();i++){
            set<int> pos=m[stones[i]];
            for(auto it: pos){
                m[it+stones[i]].insert(it);
                m[it+stones[i]-1].insert(it-1);
                m[it+stones[i]+1].insert(it+1);
            }
            
        }
        return m[stones[stones.size()-1]].size()!=0;
    }
};
