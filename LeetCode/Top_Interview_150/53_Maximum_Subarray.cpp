class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int globalMaximumSum = INT_MIN;
        int localMaxSum = 0;
        for(int i = 0; i < nums.size(); i++){
            localMaxSum = max(nums[i], nums[i] + localMaxSum);
            if(localMaxSum > globalMaximumSum){
                globalMaximumSum = localMaxSum;
            }
        }

        return globalMaximumSum;
    }
};
