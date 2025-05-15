class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int current_number = nums.front();
        int i = 1;
        for (std::vector<int>::iterator it = nums.begin() + 1; it != nums.end();)
        {
            if(nums.at(i) == current_number){
                nums.erase(it);
            }else{
                current_number = nums.at(i);
                i++;
                it++;
            }
        }
        return i;
    }
};

// optimized solution that i found:
// honestly i dont think it changes too much i was just going crazy with the vector functions
/** class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j=1; j<nums.size(); j++)
        {
            if (nums[i]!=nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
}; **/
