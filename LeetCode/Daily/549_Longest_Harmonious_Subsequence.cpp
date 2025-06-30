class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, j = 0;
        for(int i = 0; i < nums.size(); i++){
            while(nums[i] - nums[j] > 1){
                j++;
            }
            if(nums[i] - nums[j] == 1){
                res = max(res, i - j + 1);
            }
        }
        return res;
    }
};
