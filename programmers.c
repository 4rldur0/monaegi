/* Level 0 */
/* https://school.programmers.co.kr/learn/courses/30/lessons/120866 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// board_rows�� 2���� �迭 board�� �� ����, board_cols�� 2���� �迭 board�� �� �����Դϴ�.
int solution1(int** board, size_t board_rows, size_t board_cols) {
    int answer = 0;
    int i, k;
    for (i = 0; i < board_rows; i++) {
        for (k = 0; k < board_cols; k++) {
            if (board[i][k] == 1) {
                if (k > 0 && board[i][k - 1] != 1) board[i][k - 1] = 2;
                if (k < board_cols - 1 && board[i][k + 1] != 1)  board[i][k + 1] = 2;
                if (i > 0) {
                    if (board[i - 1][k] != 1) board[i - 1][k] = 2;
                    if (k > 0 && board[i - 1][k - 1] != 1) board[i - 1][k - 1] = 2;
                    if (k < board_cols - 1 && board[i - 1][k + 1] != 1)  board[i - 1][k + 1] = 2;
                }
                if (i < board_rows - 1) {
                    if (board[i + 1][k] != 1) board[i + 1][k] = 2;
                    if (k > 0 && board[i + 1][k - 1] != 1) board[i + 1][k - 1] = 2;
                    if (k < board_cols - 1 && board[i + 1][k + 1] != 1)  board[i + 1][k + 1] = 2;
                }
            }
        }
    }
    for (i = 0; i < board_rows; i++) {
        for (k = 0; k < board_cols; k++) {
            if (board[i][k] == 0)  answer++;
        }
    }
    return answer;
}

/* https://school.programmers.co.kr/learn/courses/30/lessons/120875 */

// dots_rows는 2차원 배열 dots의 행 길이, dots_cols는 2차원 배열 dots의 열 길이입니다.
int solution2(int** dots, size_t dots_rows, size_t dots_cols) {
    int i,k, cnt=0;
    double d[6];
    for(i=0;i<dots_rows-1;i++){
        for(k=i+1;k<dots_rows;k++){
            d[cnt++]=((double)dots[i][1]-dots[k][1])/((double)dots[i][0]-dots[k][0]);
        }
    }
    if(d[0]==d[5])  return 1;
    if(d[1]==d[4])  return 1;
    if(d[2]==d[3])  return 1;
    return 0;
}