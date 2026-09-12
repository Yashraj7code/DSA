class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>res;
        sort(arr.begin(),arr.end());
        int min=arr[1]-arr[0];
        for(int i=1;i<arr.size();i++)
        {
            int temp=arr[i]-arr[i-1];
            if(temp<min)
            {
                res.clear();  //found new minimum so previous value doesnt matter
                min=temp;
                res.push_back({arr[i-1],arr[i]});
            }
            else if(temp==min)
            {
                res.push_back({arr[i-1],arr[i]});
            }
        }
        return res;
    }
};