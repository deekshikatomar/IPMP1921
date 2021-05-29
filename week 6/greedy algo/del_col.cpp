class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int colsToDelete = 0;
        
        int maxColCount = strs[0].length();
        for(int colIndex = 0; colIndex < maxColCount; colIndex++) // Iterate over each column
        {
            for(int rowIndex = 0; rowIndex < strs.size() - 1; rowIndex++) // Iterate over each row item
            {
                if(strs[rowIndex][colIndex] <= strs[rowIndex+1][colIndex]) continue; // If consecutive items are sorted, continue, nothing to do
                else
                {
                    colsToDelete++; // If not sorted, mark this as a column that gets deleted and break from loop
                    break;
                }
            }
        }
        
        return colsToDelete;
    }
};