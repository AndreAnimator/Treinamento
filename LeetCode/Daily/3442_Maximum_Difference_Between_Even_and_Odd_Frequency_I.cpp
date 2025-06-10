class Solution {
public:
    int maxDifference(string s) {
        int even_frequency = s.length();
        int odd_frequency = 0;
        unordered_map<char, int> frequency_map;

        for(char a : s){
            frequency_map[a]++;
        }
        for(char a: s){
            if(frequency_map[a]%2 == 0){
                if(frequency_map[a] <= even_frequency){
                    even_frequency = frequency_map[a];
                }
            }else{
                if(frequency_map[a] >= odd_frequency){
                    odd_frequency = frequency_map[a];
                }
            }
        }
        if(even_frequency == s.length() && odd_frequency != 0){
            even_frequency = 0;
        }
        return odd_frequency - even_frequency;
    }
};