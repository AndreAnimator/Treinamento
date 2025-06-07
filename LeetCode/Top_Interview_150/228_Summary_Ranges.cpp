class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int aux = 0;
        string output = "";
        vector<string> outputs;
        for(int j = aux; j < nums.size(); j++){
            int i = j;
            while(i + 1 < nums.size() && nums[i+1] == nums[i] + 1){
                i++;
            }
            if(i > j){
                output += to_string(nums[j]);
                output += "->";
                output += to_string(nums[i]);
            }else{
                output += to_string(nums[j]);
            }

            outputs.push_back(output);
            output = "";
            j = i;
        }
        return outputs;
    }
};
