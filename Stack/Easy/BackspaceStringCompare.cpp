class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1,s2;
        for(int i=0;i<s.size();i++){
            if(!s1.empty() && s[i]=='#')
                s1.pop();
            if(s[i]!='#')
                s1.push(s[i]);
        }
        for(int i=0;i<t.size();i++){
            if(!s2.empty() && t[i]=='#')
                s2.pop();
            if(t[i]!='#')
                s2.push(t[i]);
        }
        if(s1.size()!=s2.size())
            return false;
        else{
            while(!s1.empty())
           { if(s1.top()!=s2.top())
                return false;
            s1.pop();
            s2.pop();}
        }
        return true;
    }
};
