/*!
 * \mainpage
 * \author semberlo
 * \version 1.0
 *
 * \section intro_sec Tetris
 * Проект создан при помощи:
 * 1. C language
 * 2. ncurses
 * 3. Doxygen
 *
 * \section brief_sec Brief
 * BrickGame — популярная портативная консоль 90-ых годов с несколькими тысячами
 * встроенными играми, разработанная в Китае. Изначально была копией
 * разработанной в СССР и выпущенной Nintendo в рамках платформы GameBoy игры
 * «Тетрис», но включала в себя также и множество других игр, которые
 * добавлялись с течением времени. Консоль имела небольшой экранчик с игровым
 * полем размера 10х20, представляющим из себя матрицу «пикселей». Справа от
 * поля находилось табло с цифровой индикацией состояния текущей игры, рекордами
 * и прочей дополнительной информацией. Самыми распространенными играми на
 * BrickGame были: тетрис, танки, гонки, фроггер и змейка.
 *
 * В данном проекте реализована самая популярная игра из серии BrickGame -
 * Tetris.
 *
 */
#include <stdio.h>

#include "brick_game/tetris/backend.h"
#include "gui/cli/frontend.h"

void gameLoop() {
  start();

  WINDOW *board = NULL, *next = NULL, *score = NULL;
  WINDOWINIT(board, next, score);

  Tgame game = gameInit();
  Gstatus status = GO;

  while (status != END) {
    if (status == PAUSE) {
      pause();
    }

    status = tick(&game, action());

    PRINT(board, next, score, &game);

    if (status == AGAIN) {
      status = again(&game);
    }
  }
}

int main() {
  CURSINIT();
  gameLoop();
  wclear(stdscr);
  endwin();

  return 0;
}