/* Level 0 */
/* https://school.programmers.co.kr/learn/courses/30/lessons/120866 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// board_rows는 2차원 배열 board의 행 길이, board_cols는 2차원 배열 board의 열 길이입니다.
int solution(int** board, size_t board_rows, size_t board_cols) {
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