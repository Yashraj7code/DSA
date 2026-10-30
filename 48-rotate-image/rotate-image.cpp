class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=i+1;j<row;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<row;i++)
        {
            vector<int> temp=matrix[i];
            reverse(temp.begin(),temp.end());
            matrix[i]=temp;
        }
    }
};