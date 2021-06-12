class Solution {
    vector<vector<int>> dp;
public:
    int maxPoints(vector<int> &nums, int i, int j)
    {
        if (i>j)
            return 0;
        if (i==j)
            return nums[i];
        if (dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=max(nums[i]+min(maxPoints(nums,i+2,j),maxPoints(nums,i+1,j-1)),
                   nums[j]+min(maxPoints(nums,i+1,j-1),maxPoints(nums,i,j-2)));
    }
    bool PredictTheWinner(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        dp.resize(nums.size(),vector<int>(nums.size(),-1));
        int totalPoints=0;
        for (auto x:nums)
            totalPoints+=x;
        int max_points=maxPoints(nums,i,j);
        if (max_points>=totalPoints-max_points)
            return true;
        return false;
       
    }
};