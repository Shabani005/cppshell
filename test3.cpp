#include <ncurses.h>

int main() {
    initscr();            // Start ncurses mode
    cbreak();             // Disable line buffering
    noecho();             // Don't echo input
    keypad(stdscr, TRUE); // Enable special keys

    printw("Press keys (ESC to exit):\n");
    refresh();

    int ch;
    while ((ch = getch()) != 27) { // 27 = ESC
        if (ch == '\t') {
            printw("Tab key pressed!\n");
        } else {
            printw("Key code: %d\n", ch);
        }
        refresh();
    }

    endwin(); // End ncurses mode
    return 0;
}
