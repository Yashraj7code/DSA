class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int r=matrix.size();
        int c=matrix[0].size();
        int r1=0;
        int c1=c-1;
        
        while(r1<r && c1>=0)
        {
            int cell=matrix[r1][c1];
            if(cell==target)
            {
                return true;
            }
            else if(cell<target)
            {
                r1++; // go down
            }
            else
            {
                c1--; // go left or right
            }
        }
        return false;  
    }
};