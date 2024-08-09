class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        for (int i = 0; i < accounts.size(); i++)
        {
            int soma = 0;
            for (int j = 0; j < accounts[0].size(); j++){
                soma += accounts[i][j];
            }
            if(soma >= max)
                max = soma;
        }
        return max;
    }
};

/*Solução ótima;
  
*/
