#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board){
    vector<vector<bool>> isValidRow(9, vector<bool>(9, false));
    vector<vector<bool>> isValidCol(9, vector<bool>(9, false));
    vector<vector<bool>> isValidBox(9, vector<bool>(9, false));
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            if(board[i][j] == '.') continue;
            else{
                if (isValidRow[i][(int) (board[i][j] - '1')] || isValidCol[j][(int) (board[i][j] - '1')] ||
                    isValidBox[j / 3 + (i / 3 * 3)][(int) (board[i][j] - '1')]) return false;
                else{
                    isValidRow[i][(int) (board[i][j] - '1')] = true;
                    isValidCol[j][(int) (board[i][j] - '1')] = true;
                    isValidBox[j / 3 + (i / 3 * 3)][(int) (board[i][j] - '1')] = true;
                }
            }
        }
    }
    return true;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
