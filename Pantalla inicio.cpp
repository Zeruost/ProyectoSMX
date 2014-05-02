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

    int x = 31;
    int y = 13;
    int ch;
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    noecho();

    while (1)
    {
        mvprintw(8,33,"Shoot Many X");
        mvprintw(13,33,"Iniciar Juego");
        mvprintw(14,33,"Creditos");
        mvprintw(15,33,"Salir");
        marco();
        mvprintw(y, x, ">");
        ch = getch();
        if (ch == KEY_DOWN && y<15)
        {
            y++;
            clear();
        }
        if (ch == KEY_UP && y>13)
        {
            y--;
            clear();
        }
        if (ch == KEY_LEFT && x>31)
        {
            x--;
            clear();
        }
        if (ch == KEY_RIGHT && x<31)
        {
            x++;
            clear();
        }
        refresh();
    }

    endwin();
    return 0;
}
