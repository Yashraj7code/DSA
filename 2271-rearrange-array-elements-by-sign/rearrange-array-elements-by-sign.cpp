class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector <int> pos;
        vector <int> neg;
        int pos_pointer=0,neg_pointer=0;
        int len=(nums.size()/2);
        for (int i: nums)
        {
            if(i>0)
            {
                pos.push_back(i);
            }
            else
            {
                neg.push_back(i);
            }
        }
        int i=0;
        while(i<nums.size())
        {
            nums[i]=pos[pos_pointer];
            i=i+2;
            pos_pointer++;
        }
        i=1;
        while(i<nums.size())
        {
            nums[i]=neg[neg_pointer];
            i=i+2;
            neg_pointer++;
        }
        return nums;

    }
};