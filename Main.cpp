#include <curses.h>
#include <string>
using namespace std;

void disparo(int y, int x){     //Experimental, no funciona...

    //for (int i=y; y<0;y--)
    {
    mvprintw(y-1, x, "|");
    refresh();
    }


}

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

    // Pantalla de Inicio ---------------------------------------------------------------

    bool eleccion = true;
    int x = 31;
    int y = 13;
    int ch;
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    noecho();
    marco();

    while (eleccion)
    {
        mvprintw(8,33,"Shoot Many X");
        mvprintw(13,33,"Iniciar Juego");
        mvprintw(14,33,"Controles");
        mvprintw(15,33,"Creditos");
        mvprintw(16,33,"Salir");
        marco();
        mvprintw(y, x, ">");
        ch = getch();
        if (ch == KEY_DOWN && y<16)
        {
            mvprintw(y, x, " ");
            y++;
        }
        if (ch == KEY_UP && y>13)
        {
            mvprintw(y, x, " ");
            y--;
        }
        if (ch == ' ' && y == 13)
        {
            eleccion = false;
        }
        refresh();
    }
        clear();

    // Pantalla de juego ----------------------------------------------------------------

    x = 35;
    y = 13;
    initscr();
    curs_set(1);                //Recordar dejarlo en 0, lo puse en 1 para saber donde esta por el momento
    keypad(stdscr, TRUE);
    noecho();
    mvprintw(y, x, "^");
    marco();
    while (1)
    {
        mvprintw(2,34,"Y: %d",y);
        mvprintw(2,40,"X: %d",x);
        ch = getch();
        if (ch == KEY_DOWN && y<20)
        {
            mvprintw(y, x, " ");
            y++;
            mvprintw(y, x, "v");
        }
        if (ch == KEY_UP && y>4)
        {
            mvprintw(y, x, " ");
            y--;
            mvprintw(y, x, "^");
        }
        if (ch == KEY_LEFT && x>4)
        {
            mvprintw(y, x, " ");
            x--;
            mvprintw(y, x, "<");
        }
        if (ch == KEY_RIGHT && x<75)
        {
            mvprintw(y, x, " ");
            x++;
            mvprintw(y, x, ">");
        }
       if (ch == ' ')
        {
           move(y,x);
           printw("Insertar Disparo Aqui");
        }
        refresh();
    }
    endwin();
    return 0;
}
