class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size() - 1;
        int aux = nums.size() - 1;
        int num_aux = 0;
        int k = 0;
        while(size >= 0){
            if(nums[size] == val){
                num_aux = nums[aux];
                nums[aux] = nums[size];
                nums[size] = num_aux;
                aux--;
            }else{
                k++;
            }
            size -= 1;
        }
        return k;
    }
};
