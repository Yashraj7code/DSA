class Solution {
public:
    string largestOddNumber(string num) {
        int len=num.length();
        int res=len;
        for(int i=len-1;i>=0;i--){
            if((num[i]-'0')%2==0){
                res--;
            }
            else{
                break;
            }
        }
        string ret="";
        for(int i=0;i<res;i++)
        {
            ret+=num[i];
        }
        return ret;
    }
};