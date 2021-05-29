class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int posSum = 0, negSum = 0;
        for (auto num : nums) {
            if (num > 0) posSum += num;
            else negSum += num;
        }
        if (goal <= negSum) return negSum - goal;
        if (goal >= posSum) return goal - posSum;

        vector<int> subsetSum1 = {0}, subsetSum2 = {0};

        for (int i = 0; i < (n / 2); i++) {
            const int v = subsetSum1.size();
            for (int t = 0; t < v; t++) {
                subsetSum1.push_back(subsetSum1[t] + nums[i]);
            }
        }

        for (int i = (n / 2); i < n; i++) {
            const int v = subsetSum2.size();
            for (int t = 0; t < v; t++) {
                subsetSum2.push_back(subsetSum2[t] + nums[i]);
            }
        }

        sort(subsetSum2.begin(), subsetSum2.end());

        int ans = INT_MAX;
        for (auto sum : subsetSum1) {
            auto it = lower_bound(subsetSum2.begin(), subsetSum2.end(), goal - sum);
            if (it != subsetSum2.end()) {
                ans = min(ans, abs(goal - (sum + *it)));
                auto it2 = it;
                it2++;
                if (it2 != subsetSum2.end())
                    ans = min(ans, abs(goal - (sum + *it2)));
            }
            if (it != subsetSum2.begin()) {
                ans = min(ans, abs(goal - (sum + * (--it))));
            }
        }
        return ans;
    }
};