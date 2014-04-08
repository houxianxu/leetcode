// http://oj.leetcode.com/problems/surrounded-regions/

#include <stdio.h>
#include <vector>
#include <cstdlib>
using std::vector;

void DFS(char **board, int n, int m, int i, int j) { // assume board[i][j] == 'O'
   // printf("%s %s %d %d \n", "i", "j", i, j);

  board[i][j] = 'V'; // means visited
    // printf("%s %s %d %d \n", "i", "j", i, j);

  if (i >= 1 && board[i - 1][j] == 'O') {
    DFS(board, n, m, i - 1, j);
  }

  if (i <= n - 2 && board[i + 1][j] == 'O') {
    DFS(board, n, m, i + 1, j);
  }

  if (j >= 1 && board[i][j - 1] == 'O') {
    DFS(board, n, m, i, j - 1);
  }

  if (j <= m - 2 && board[i][j + 1] == 'O') {
    DFS(board, n, m, i, j + 1);
  }

}

void DFS_first_last_col(char **board, int n, int m) {
  int row = 0;
  int col = 0;

  for (row = 0; row < n; row++) {
    if (board[row][0] == 'O') {
      DFS(board, n, m, row, 0);
    }

    if (board[row][m - 1] == 'O') {
      DFS(board, n, m, row, m - 1);
    }
  }
}


void DFS_first_last_row(char **board, int n, int m) {
  int row = 0;
  int col = 0;

  for (col = 0; col < m; col++) {
    if (board[0][col] == 'O') {
      DFS(board, n, m, 0, col);
    }
      // printf("%s\n", "11");
      // printf("%s\n", "333");
    if (board[n - 1][col] == 'O') {
      // printf("%s\n", "11");
      // printf("%d %d \n", n - 1, col);
      DFS(board, n, m, n - 1, col);
      // printf("%s\n", "22");
    }
    // printf("%s\n", "22");
  }
}

void change_O_to_X_and_V_to_O(char **board, int n, int m) { // change O to X, and V to O
  int i = 0;
  int j = 0;

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (board[i][j] == 'V') {
        board[i][j] = 'O';
      } else if (board[i][j] == 'O') {
        board[i][j] = 'X';
      }
    }
  }
}

// board is n(rows) * m(cols)
void c_solve(char **board, int n, int m) {
  int row = 0;
  int col = 0;
  DFS_first_last_col(board, n, m);
  DFS_first_last_row(board, n, m);
  change_O_to_X_and_V_to_O(board, n, m); 
}

class Solution {
public:
    void solve(vector<vector<char> > &board) {
      int n = board.size();
      int m = 0;
      char **c_board = (char**)malloc(sizeof(char*)*board.size());
      for(int i = 0; i < n; i++) {
        m = board[i].size();
        c_board[i] = (char*)malloc(sizeof(char)*(m+1));
        for(int j = 0; j < m; j++) {
          c_board[i][j] = board[i][j];
        }
        c_board[i][board[i].size()] = '\0';
      }
      c_solve(c_board, n, m);
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
          board[i][j] = c_board[i][j];
        }
        free(c_board[i]);
      }
      free(c_board);
    }
};


void print_board(char board[][4]) {
  int i, j;
  for (i = 0; i < 3; i++) {
    printf("%s\n", board[i]);
  }
}

int main(int argc, const char *argv[])
{
  //char board[][4] = {"XXX","XOX","XXX"};
  // printf("%c\n", board[0][0]);
  // board[0][0] = '3';
  // print_board(board);
  // char **board; 
  // board = (char **) malloc(sizeof(char*)*3);
  // for(int i = 0; i < 3; i++) {}
  // c_solve(board[][4], 3, 3);
  // printf("%s\n", "11");
  // print_board(board);
  // int M = 3;

  char *board[] = {"XXXXX","XXXOX","XOXXX","XXXXX","XOXXX"};
  c_solve(board, 5, 5);

  return 0;
}


