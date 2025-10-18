class Solution {
public:
    string intToRoman(int num) {
        string res((num / 1000),'M');
        num %= 1000;
        int x = num /100;
        switch(x){
            case 9:
            res += "CM";
            break;
            case 8:
            case 7:
            case 6:
            case 5:
            res += "D" + string(x-5,'C');
            break;
            case 4:
            res += "CD";
            break;
            case 3:
            case 2:
            case 1:
            res += string(x,'C');
        }
        num %= 100;
        x = num /10;
        switch(x){
            case 9:
            res += "XC";
            break;
            case 8:
            case 7:
            case 6:
            case 5:
            res += "L" + string(x-5,'X');
            break;
            case 4:
            res += "XL";
            break;
            case 3:
            case 2:
            case 1:
            res += string(x,'X');
        }
        num %= 10;

        switch(num){
            case 9:
            res += "IX";
            break;
            case 8:
            case 7:
            case 6:
            case 5:
            res += "V" + string(num-5,'I');
            break;
            case 4:
            res += "IV";
            break;
            case 3:
            case 2:
            case 1:
            res += string(num,'I');
        }
        return res;
    }
};
