class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int j=0,i=0;
        while(i<s.size()){
            if(i<s.size() && s[i]!=' ') j=i;
            while(i<s.size() && s[i]!=' ') i++;
            if(i==s.size()-1) reverse(s.begin()+j,s.end());
            else reverse(s.begin()+j,s.begin()+i);
            while(i<s.size() && s[i]==' ') i++;
        }
        i=s.size()-1;
        while(i>=0){
            while(i>=0 && s[i]==' ') i--;
            while(i>=0 && s[i]!=' ') ans+=s[i--];
            while(i>=0 && s[i]==' ') i--;
            if(i>=0) ans+=' ';
        }
        return ans;
    }
};
