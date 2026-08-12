class TicTacToe {
public:
    vector<vector<int>> board;
    int n;
    TicTacToe(int n) {
        board.resize(n, vector<int>(n));
        this->n = n;
    }

    bool rowColWin(int &row, int& col, int& player) {
        bool wins = true;

        for(int j = 0; j<n; j++) {
            if(board[row][j] != player) {
                wins = false;
                break;
            }
        }

        if(wins)
            return wins;

        for(int i = 0; i<n; i++) {
            if(board[i][col] != player) {
                wins = false;
                    break;
            }
        }

        return wins;
    }

    bool diagWin(int& player) {
        for(int row = 0; row<n; row++) {
            if(board[row][row] != player)
                return false;
        }
        return true;
    }

    bool antiDiagWin(int& player) {
        for(int row = 0; row<n; row++) {
            if(board[row][n-row-1] != player)
                return false;
        }
        return true;
    }

    int move(int row, int col, int player) {
        if(player == 1) {
            board[row][col] = 1;
            if(rowColWin(row, col, player)) {
                return 1;
            }

            if(row == col && diagWin(player)) {
                return 1;
            } else if(row+col == n && antiDiagWin(player)) {
                return 1;
            }
        } else {
            board[row][col] = 2;
            if(rowColWin(row, col, player)) {
                return 2;
            }

            if(row == col && diagWin(player)) {
                return 2;
            } else if(row+col == n-1 && antiDiagWin(player)) {
                return 2;
            }
        }

        return 0;
    }
};

class TicTacToe {
public:
    int n;
    vector<int> rows;
    vector<int> cols;
    int diag = 0;
    int antiDiag = 0;
    TicTacToe(int n) {
        this->n = n;
        rows.resize(n, 0);
        cols.resize(n, 0);
        diag = 0;
        antiDiag = 0;
    }

    int move(int row, int col, int player) {
        if(player == 1) {
            rows[row]++;
            cols[col]++;
            if(row == col)
                diag++;

            if(row+col == n-1)
                antiDiag++;

            if(rows[row] == n || cols[col] == n || diag == n || antiDiag == n)
                return 1;
        } else {
            rows[row]--;
            cols[col]--;
            if(row == col)
                diag--;

            if(row+col == n-1)
                antiDiag--;

            if(rows[row] == -n || cols[col] == -n || diag == -n || antiDiag == -n)
                return 2;
        }

        return 0;
    }
};
