#include <stdio.h>

//#define BOARD_SIZE 16
int board[64][64]; // 棋盤最大 64 x 64

// c1, r1: 左上角的座標
// c2, r2: 黑格子的座標
// size = 2^k
void chessboard(int r1, int c1, int r2, int c2, int size) {
  if (1 == size) {
    return;
  }
  int half_size;
  static int domino_num = 1;
  int d = domino_num++;
  half_size = size / 2;

  if (r2 < r1 + half_size && c2 < c1 + half_size) { // 黑格子在左上部分
    chessboard(r1, c1, r2, c2, half_size);
  } else { // 不在這邊，填右下部分
    board[r1 + half_size - 1][c1 + half_size - 1] = d;
    chessboard(r1, c1, r1 + half_size - 1, c1 + half_size - 1, half_size);
  }

  if (r2 < r1 + half_size && c2 >= c1 + half_size) { // 黑格子在右上部分
    chessboard(r1, c1 + half_size, r2, c2, half_size);
  } else { // 不在這邊，填左下部分
    board[r1 + half_size - 1][c1 + half_size] = d;
    chessboard(r1, c1 + half_size, r1 + half_size - 1, c1 + half_size,
               half_size);
  }

  if (r2 >= r1 + half_size && c2 < c1 + half_size) { // 黑格子在左下部分
    chessboard(r1 + half_size, c1, r2, c2, half_size);
  } else { // 不在這邊，填右上部分
    board[r1 + half_size][c1 + half_size - 1] = d;
    chessboard(r1 + half_size, c1, r1 + half_size, c1 + half_size - 1,
               half_size);
  }

  if (r2 >= r1 + half_size && c2 >= c1 + half_size) { // 黑格子在右下部分
    chessboard(r1 + half_size, c1 + half_size, r2, c2, half_size);
  } else { // 不在這邊，填左上部分
    board[r1 + half_size][c1 + half_size] = d;
    chessboard(r1 + half_size, c1 + half_size, r1 + half_size, c1 + half_size,
               half_size);
  }
}

int main() {

  // 讓使用者輸入有幾個黑色方塊，並決定棋盤邊長
  int N, L;
  int row, col;
  scanf("%d%d", &N, &L);
  // int board[64][64]; // 棋盤最大 64 x 64

  // 讓使用者輸入把哪些位置設成 0
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &row, &col);
    board[row][col] = 0;
  }

  int i, j;
  // board[2][2] = 0;
  chessboard(0, 0, col, row, L);
  for (i = 0; i < L; i++) {
    for (j = 0; j < L; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
  return 0;
}