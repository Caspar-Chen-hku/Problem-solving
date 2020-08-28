class Solution {
public:
    string thousandSeparator(int n) {
        if (n < 1000) return to_string(n);
        string s = to_string(n%1000);
        while (s.length()<3) s = "0" + s;
        return thousandSeparator(n/1000) + "." + s;
    }
};