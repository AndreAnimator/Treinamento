// Solução ótima:
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = numeric_limits<int>::max();
        int size = 0;
        int iterator = 0;
        for(int i = 0; i < nums.size(); i++){
            size += nums[i];
            while(size >= target){
                if(i - iterator + 1 < minLen){
                    minLen = i - iterator + 1;
                }
                size -= nums[iterator];
                iterator++;
            }
        }
        return minLen != numeric_limits<int>::max() ? minLen : 0;
    }
};


// Solução que eu fiz inicialmente, funciona mas dá timelimit:
//
//        int aux = 0;
//        int size = 0;
//        int iterator = 0;
//        int output = 1000000;
//        int position = 0;
//        for(int i : nums){
//            if(i >= target){
//                return 1;
//            }
//            size = 0;
//            position = 0;
//            for(int j = iterator; j < nums.size(); j++){
//                position++;
//                size += nums[j];
//                if(size >= target){
//                    if(position < output){
//                        output = position;
//                    }
//                }
//            }
//            iterator++;
//        }
//        if(output == 1000000){
//            return 0;
//        }
//        else{
//            return output;
//        }
