// This solution is not mine and is solely intended for educational purposes
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        string genes = "ACGT";
        while(!q.empty()){
            auto [word, level] = q.front(); 
            q.pop();
            if(word == endGene)
                return level;

            for(int i = 0; i < 8; i++){
                char original = word[i];
                for(char ch : genes){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        q.push({word, level + 1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return -1;
    }
};
