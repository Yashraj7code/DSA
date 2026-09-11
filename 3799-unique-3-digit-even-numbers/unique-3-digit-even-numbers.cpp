class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        int ans=0;
        set <int> s;
        for(int i=0;i<n;i++)
        {
            if(digits[i]%2!=0) //choosing last digit
                continue;
            for(int j=0;j<n;j++)
            {
                if(digits[j]==0 || j==i )
                    continue;
                for(int k=0;k<n;k++)
                {
                    if(k==i || k==j )
                        continue;
                    int num = digits[j] * 100 + digits[k] * 10 + digits[i];
                    s.insert(num);
                }
            }
        }
        return s.size();
    }
};