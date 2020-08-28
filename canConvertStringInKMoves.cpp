class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.length()!=t.length()) return false;
        unordered_map<int,int>mp;
        int left=k%26;
        for(int i=0;i<s.length();i++){
            if(s[i]==t[i]) continue;
            int req;
            if(s[i]<t[i]){
                req=t[i]-s[i];
            }else{
                req=t[i]-'a'+('z'-s[i])+1;
            }
            if(req>k) return false;
            mp[req]++;
            int max=k/26;
            if(req<=left) max++;
            if(mp[req]>max) return false;
        }
        return true;
    }
};
