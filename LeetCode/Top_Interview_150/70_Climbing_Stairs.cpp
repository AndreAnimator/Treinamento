// this solution is not mine and is only intended for educationl purposes
class Solution {
public:
    int climbStair(int n, unordered_map<int, int>& memo){
        if(n == 0 || n == 1){
            return 1;
        }
        if(memo.find(n) == memo.end()){
            memo[n] = climbStair(n-1, memo) + climbStair(n-2, memo);
        }
        return memo[n];
    }
    int climbStairs(int n) {
        unordered_map<int, int> memo;
        return climbStair(n, memo);
    }
};
/*
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }

        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

*/
