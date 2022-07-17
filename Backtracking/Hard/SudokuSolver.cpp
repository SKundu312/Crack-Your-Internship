class Solution {
public:
    bool isSafe(int row,int col,char c,vector<vector<char>>& board){
    for(int k=0;k<9;k++){
        if(board[row][k]==c) return false;  // checking the row if similar char exists.
        if(board[k][col]==c) return false;  // checking the column if similar char exists.
        if(board[3*(row/3)+k/3][3*(col/3)+k%3]==c) return false;  // checking the 3x3 grid.
    }
    return true;
}
    bool backtrack(vector<vector<char>>& board){
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col]=='.'){
                    for(char i='1';i<='9';i++){
                        if(isSafe(row,col,i,board)){
                            board[row][col]=i;
                            if(backtrack(board)){ 
                                return true;}
                            else board[row][col]='.';
                         }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};
