class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1=s1.length(), l2=s2.length();
        if (l2<l1) return false;
        map<char,int> m1;
        for (char c:s1){
            m1[c]++;
        }
        map<char,int> m2;
        for (int i=0; i<l1; i++){
            m2[s2[i]]++;
        }
        if (m1==m2) return true;
        for (int i=l1; i<l2; i++){
            m2[s2[i-l1]]--;
            if (m2[s2[i-l1]]==0){
                m2.erase(s2[i-l1]);
            }
            m2[s2[i]]++;
            if (m1==m2) return true;
        }
        return false;
    }
};