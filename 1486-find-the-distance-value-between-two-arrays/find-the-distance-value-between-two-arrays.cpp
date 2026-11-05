class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res=0;
        for(int x: arr1)
        {
            int count=0;
            for(int i: arr2)
            {
                if(abs(x-i)>d)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            if(count==arr2.size())
            {
                res++;
            }
        }
        return res;
    }
};