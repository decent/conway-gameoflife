#ifndef __BOARD_H
#define __BOARD_H

#define HEIGHT 50
#define WIDTH 50

// 0.1 sec
#define DELAY_NSEC 100000000L

char board[HEIGHT][WIDTH] = { "                                                  ",
                              "                                                  ",
                              "                                                  ",
                              "                                                  ",
                              "             ***                                  ",
                              "                                                  ",
                              "                                                  ",
                              "                                                  ",
                              "                                                  ",
                              "              ***                                 ",
                              "               ***                                ",
                              "                                                  ",
                              "                         **                       ",
                              "                         **                       ",
                              "                           **                     ",
                              "                           **                     ",
                              "                                                  ",
                              "                                                  ",
                              "                                                  ",
                              "                                                  ",
                              "                                                  ",
                              "                                                  ",
                              "               *    *                             ",
                              "             ** **** **                           ",
                              "               *    *                             ",
                              "                                                  ",
                              "                                                  ",
                              "                                                  ",
                              "                                                  ",
                              "                            *                     ",
                              "                          * *                     ",
                              "                **      **            **          ",
                              "               *   *    **            **          ",
                              "    **        *     *   **                        ",
                              "    **        *   * **    * *                     ",
                              "              *     *       *                     ",
                              "               *   *                              ",
                              "                **                                ",
                              "                                                  ",
                              "                                                  ",
                              "                                                  ",
                              "                                                  ",
                              "                                                  ",
                              "                                                  ",
                              "                                                  ",
                              "                                                  ",
                              "                                                  ",
                              "                                                  ",
                              "                                                  ",
                              "                                                  "};


char board_copy[HEIGHT][WIDTH];

#endif
