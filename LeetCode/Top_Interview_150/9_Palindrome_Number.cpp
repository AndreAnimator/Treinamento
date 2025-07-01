class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        long reverse = 0;
        int initial = x;
        while(x)
        {
            reverse *= 10;
            reverse += x % 10;
            x /= 10;
        }
        if(initial == reverse)
            return true;
        return false;
        
    }
};
