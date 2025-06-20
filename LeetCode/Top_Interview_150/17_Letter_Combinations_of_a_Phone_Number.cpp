class Solution {
public:
// This solution is not mine and is only intended for educational purposes
    vector<string> letterCombinations(string digits) {
        vector<string> results;
        if(digits.empty()){
            return results;
        }
        unordered_map<char, string> digitToLetters ={
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        backtrack(digits, 0, "", results, digitToLetters);
        return results;
    }
    void backtrack(const string& digits, int index, string combination, vector<string>& results, const unordered_map<char, string>& digitToLetters){
        if(index == digits.length()){
            results.push_back(combination);
            return;
        }

        string letters = digitToLetters.at(digits[index]);
        for(char letter : letters){
            backtrack(digits, index + 1, combination + letter, results, digitToLetters);
        }
    }
};
