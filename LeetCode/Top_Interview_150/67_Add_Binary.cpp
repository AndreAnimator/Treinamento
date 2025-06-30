// this solution is not mine and is only intended for educational purpose
class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int indexA = a.size() - 1;
        int indexB = b.size() - 1;
        for(int carry = 0; indexA >= 0 || indexB >= 0 || carry; --indexA, --indexB){
            carry += (indexA >= 0 ? a[indexA] - '0' : 0) + (indexB >= 0 ? b[indexB] - '0' : 0);

            result.push_back((carry % 2) + '0');

            carry /= 2;
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
