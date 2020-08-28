class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int l = 0, r = reader.length()-1;
        int size, temp;
        while (r-l >= 2){
            size = (r-l+1)/3;
            temp = reader.compareSub(l, l+size-1, l+size, l+2*size-1);
            if (temp == 1){
                r = l+size-1;
            }else if (temp == 0){
                l = l+2*size;
            }else{
                l = l+size; r = l+2*size-1;
            }
        }
        if (l == r) return l;
        else if (reader.compareSub(l, l, r, r) == 1){
            return l;
        }else{
            return r;
        }
    }
};