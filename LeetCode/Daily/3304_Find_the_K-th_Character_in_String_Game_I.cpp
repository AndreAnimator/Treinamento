class Solution {
public:
    char kthCharacter(int k) {
        string list = "a";
        while(list.length() < k){
            string duplicate = list;
            for(char c : duplicate){
                if(c == 122){
                    c = 97;
                }
                c++;
                list += c;
            }
        }
        return list[k-1];
    }
};
