class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
         sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
                if(nums[i]<0 ){
                        if(k>0){
                                nums[i]=-nums[i];
                                k--;
                        }
                        else{
                                break;
                        }
                }
        }
            int res=0;
            for(int x:nums){
                    res+=x;
            }
            cout<<res;
            if(k==0 or k%2==0){
                    return res;
            }
            sort(nums.begin(),nums.end());
            res=res-2*nums[0];
            return res;
    }
};