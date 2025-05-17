class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> index;
        int major_element = 0;
        for(int i = 0; i < nums.size(); i++){
            index[nums[i]]++;
            if(index[nums[i]] >= nums.size()/2 && index[nums[i]] > index[major_element]){
                major_element = nums[i];
            }
        }
        return major_element;
    }
};
