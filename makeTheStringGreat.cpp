class Solution {
public:
    string makeGood(string s) {
        if (s.length() < 2){
            return s;
        }
        for (int i=0; i<s.length()-1; i++){
            if (abs(s[i]-s[i+1]) == abs('a'-'A')){
                s.erase(i, 2);
                return makeGood(s);
            }
        }
        return s;
    }
};