class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int l = p.length();
        vector<int> result;
        map<char,int> smap, pmap;
        if (s.length()<l) return result;
        
        for (char c:p){
            pmap[c]++;
        }
        for (int i=0; i<l; i++){
            smap[s[i]]++;
        }
        if (pmap==smap) result.push_back(0);
        for (int i=1; i<=s.length()-l; i++){
            smap[s[i-1]]--; smap[s[i+l-1]]++;
            if (smap[s[i-1]]==0){
                smap.erase(s[i-1]);
            }
            if (smap==pmap) result.push_back(i);
        }
        return result;
    }
};