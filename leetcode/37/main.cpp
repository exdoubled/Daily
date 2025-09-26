#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(int row, int col, char val, vector<vector<char>>& board){
    for(int i = 0; i < 9; i++) {
        if (board[row][i] == val) {
            return false;
        }
    }
    for(int j = 0; j < 9; j++) {
        if (board[j][col] == val) {
            return false;
        }
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for(int i = startRow; i < startRow + 3; i++) {
        for(int j = startCol; j < startCol + 3; j++) {
            if(board[i][j] == val ) {
                return false;
            }
        }
    }
    return true;
}

bool dfs(vector<vector<char>>& board){
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            if(board[i][j] == '.'){
                for(int k = 1; k <=9; ++k){
                    if(isValidSudoku(i, j, (char) (k + '0'), board)){
                        board[i][j] = (char) (k + '0');
                        if(dfs(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board){
    dfs(board);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
