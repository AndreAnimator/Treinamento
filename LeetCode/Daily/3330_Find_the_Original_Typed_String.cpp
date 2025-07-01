class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1;
        string make_unique_char = "";
        unordered_map<string, int> characters;
        for(int i = 0; i < word.size(); i++){
            if(i != 0 && word[i] != word[i - 1]){
                make_unique_char += word[i];
            }
            characters[word[i] + make_unique_char]++;
            if(characters[word[i] + make_unique_char ] > 1){
                count++;
            }
        }
        cout << count << endl;
        return count;
    }
};
