class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sum;
        int aux = 0;
        for(int i = 0; i < nums.size(); i++){
            aux += nums[i];
            sum.push_back(aux);
        }
        return sum;
    }
};

/*
  Solução ótima (ou só uma solução legal mesmo):

  class Solution {
  public:
      vector<int> runningSum(vector<int>& nums) {
          for(int i=1;i<nums.size();i++)  nums[i]+=nums[i-1];
          return nums;
      }
  };
*/
