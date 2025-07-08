class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        
    }
};
/*
The most obvious logic would be:

int size = nums.size() - 1;
int first_number, prev, aux = 0;
for(int i = 0; i < k; i++){
    first_number = nums[size];
    for(int j = 0; j <= size; j++){
        if(j == 0){
            prev = nums[j];
            nums[j] = first_number;
        }
        else{
            aux = nums[j];
            nums[j] = prev;
            prev = aux;
        }
    }
}
But not only is O(n*k) it exceeds time
*/
