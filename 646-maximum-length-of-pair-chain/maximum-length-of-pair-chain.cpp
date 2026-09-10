class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });
        int chain=0;
        int res=INT_MIN;
        int currend=INT_MIN;
        for(int i=0;i<pairs.size();i++)
        {
            if(pairs[i][0]>currend)
            {
                chain++;
                currend=pairs[i][1];
            }
        }
        return chain;
    }
};