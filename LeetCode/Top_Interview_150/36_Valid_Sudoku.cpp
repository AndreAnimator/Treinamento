class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for(int r = 0; r < 9; ++r){
            for(int c = 0; c < 9; ++c){
                if(board[r][c] == '.'){
                    continue;
                }
                char value = board[r][c];
                int boxIndex = (r/3) * 3 + (c/3);
                if(rows[r].count(value) || cols[c].count(value) || boxes[boxIndex].count(value)){
                    return false;
                }

                rows[r].insert(value);
                cols[c].insert(value);
                boxes[boxIndex].insert(value);
            }
        }
        return true;
        // Pseudo código primário:
        //
        // unordered_map<int, int> rows;
        // unordered_map<int, unordered_map<int>> column;
        // for(int i = 0; i < board.size(); i++){
        //     rows = {0, 0};
        //     for(int j = 0; j < board.size();; j++){
        //         rows[board[i][j]]++;
                // if(rows > 1 || column[i][board[i][j]] > 1) : false
        //         column[i] += rows[board[i][j]];
                    // boxes[i/3][j/3].adicione o valor board[i][j]
        //     }
        // } 
        
    }
};
