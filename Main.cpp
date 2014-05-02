#include <curses.h>

void marco(){

    for(int i=4; i<=20; i++){
        for(int j=4; j<=75; j++){
            mvprintw(3, j, "-");
        }
        mvprintw(i, 3, "|");
        mvprintw(i, 76, "|");
    }
    for(int j=4; j<=75; j++){
            mvprintw(21, j, "-");
        }


}

int main()
{
    int x = 35;
    int y = 13;
    int ch;
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    noecho();
    while (1)
    {
        marco();
        mvprintw(y, x, "X");
        ch = getch();
        if (ch == KEY_DOWN && y<20)
        {
            y++;
            clear();
        }
        if (ch == KEY_UP && y>4)
        {
            y--;
            clear();
        }
        if (ch == KEY_LEFT && x>4)
        {
            x--;
            clear();
        }
        if (ch == KEY_RIGHT && x<75)
        {
            x++;
            clear();
        }
        refresh();
    }
    endwin();
    return 0;
}
