class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i = 0, numOnes;
        while (i<data.size()){
            numOnes = getOnes(data[i]);
            switch (numOnes){
                case 0:
                    i++; break;
                case 1:
                case -1:
                    return false;
                default:
                    if (i+numOnes>data.size()) return false;
                    for (int j=i+1; j<i+numOnes; j++){
                        if (getOnes(data[j])!=1) return false;
                    }
                    i += numOnes;
            }
        }
        return true;
    }
    
private:
  int getOnes(uint32_t i) {
    if (i < 0x80) return 0;
    else if (i < 0xC0) return 1;
    else if (i < 0xE0) return 2;
    else if (i < 0xF0) return 3;
    else if (i < 0xF8) return 4;
    else return -1;
  }
};