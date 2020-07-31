class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> occur;
        int total = s1.length();
        for (char c:s1){
            occur[c]++;
        }
        int i = 0, j = 0;
        int total2 = 0;
        while (j < s2.length() && total2<total){
            if (occur.count(s2[j])==0){
                j++; i = j; total2=0; continue;
            }else{
                total2++; j++;
            }
        }
        return total == total2;
    }
};