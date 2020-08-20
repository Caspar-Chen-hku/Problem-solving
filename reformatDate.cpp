class Solution {
public:
    string reformatDate(string date) {
        int ind = date.find(' ');
        string day = date.substr(0, ind);
        int next = date.find(' ', ind+1);
        string month = date.substr(ind+1, next-ind-1);
        ind = next+1;
        string year = date.substr(ind);
        string res = year + "-";
        if (month == "Jan"){
            res += "01";
        }else if (month == "Feb"){
            res += "02";
        }else if (month == "Mar"){
            res += "03";
        }else if (month == "Apr"){
            res += "04";
        }else if (month == "May"){
            res += "05";
        }else if (month == "Jun"){
            res += "06";
        }else if (month == "Jul"){
            res += "07";
        }else if (month == "Aug"){
            res += "08";
        }else if (month == "Sep"){
            res += "09";
        }else if (month == "Oct"){
            res += "10";
        }else if (month == "Nov"){
            res += "11";
        }else{
            res += "12";
        }
        string daystr =day.substr(0, day.size()-2);
        if (daystr.size()==1) daystr = "0" + daystr;
        res += "-" + daystr;
        return res;
    }
};