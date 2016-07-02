#include <stdio.h>
#include <unistd.h>

#include "board.h"

void print_board(size_t m, size_t n, char board[m][n]);
void copy_board(size_t m, size_t n, char dest[m][n], char src[m][n]);
void clear_screen(void);
void next_board(size_t m, size_t n, char board[m][n]);
int count_neighbours(size_t m, size_t n, char board[m][n], int x, int y);

int main(int argc, char **argv) {
    int counter = 0;
    
    while(1) {
        clear_screen();
        counter++;
        printf("Iteration: %d\n", counter);
        print_board(HEIGHT, WIDTH, board);
        next_board(HEIGHT, WIDTH, board);
        usleep(DELAY);
    }

    return 0;
}

void copy_board(size_t m, size_t n, char dest[m][n], char src[m][n]) {
    // We need to copy the null character too
    for(int y = 0; y < m; y++) {
        for(int x = 0; x < n; x++) {
            board_copy[y][x] = board[y][x];
        }
    }
}

void clear_screen(void) {
    printf("\033c");
}

void print_board(size_t m, size_t n, char board[m][n]) {
    for(int y = 0; y < m; y++) {
        for(int x = 0; x < n; x++) {
           printf("%c", board[y][x]); 
        }
        printf("\n");
    }
}

void next_board(size_t m, size_t n, char board[m][n]) {
    int neighbours = 0;

    copy_board(m, n, board_copy, board);

    for(int y = 0; y < m; y++) {
        for(int x = 0; x < n; x++) {
            neighbours = count_neighbours(m, n, board_copy, x, y); 

            if(neighbours == 3) {
                board[y][x] = '*';
            } else if(neighbours == 2 && board[y][x] == '*') {
                board[y][x] = '*';
            } else {
                board[y][x] = ' ';
            }
        }
    } 
}

int count_neighbours(size_t m, size_t n, char board[m][n], int x, int y) {
    int tmp_x;
    int tmp_y;
    int neighbours = 0;
    int offsets[8][2] = { {-1, -1}, { 0, -1}, { 1, -1},
                          {-1,  0},           { 1,  0},
                          {-1,  1}, { 0,  1}, { 1,  1} };

    for(int i = 0; i < 8; i++) {
       tmp_x = x + offsets[i][0];
       tmp_y = y + offsets[i][1];

       // Check we are inside the boundries
       if(tmp_x >= 0 && tmp_x < n && tmp_y >= 0 && tmp_y < m) {
           if(board[tmp_y][tmp_x] == '*') {
               neighbours++;
           }
       }
    }

    return neighbours;
}
