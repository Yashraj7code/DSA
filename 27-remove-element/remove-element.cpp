class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)  //3,2,2,3 val=3
            {
               nums[count]=nums[i]; 
               count++;
            }
        }
        return count;
    }
};