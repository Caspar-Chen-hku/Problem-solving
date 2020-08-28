class Solution {
public:
    int minFlips(string target) {
        int res = 0;
        for (int i=0; i<target.size(); i++){
            if (target[i]=='1' && (i == 0 || target[i-1]=='0')){
                res++;
            }else if (target[i]=='0' && i > 0 && target[i-1]=='1'){
                res++;
            }
        }
        return res;
    }
};