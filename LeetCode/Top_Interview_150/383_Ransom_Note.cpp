class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ransomHash;
        for(char c : magazine){
            ransomHash[c]++;
        }
        for(char c : ransomNote){
            if(ransomHash[c] <= 0){
                return false;
            }
            ransomHash[c]--;
        }
        return true;
    }
};
