class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>s;
        int n=num.size();
        for(int i=0;i<n;i++){
            while(!s.empty() && k>0 && s.top()>num[i])
             {   s.pop();
                 k-=1;
             }
            if(!s.empty() || num[i]!='0') s.push(num[i]);
        }
        while(!s.empty() && k--)  s.pop();
        if(s.empty()) return "0";
        
        while(!s.empty()){
            num[n-1]=s.top();
            s.pop();
            n-=1;
        }
        num=num.substr(n);
        return num;
    }
};
