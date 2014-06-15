#include <curses.h>
#include <windows.h>
#include <time.h>

using namespace std;

void marco(){  //Marco 2.0
    for(int i=4; i<=20; i++)
    {
        for(int j=4; j<=75; j++)
        {
            mvaddch(3, j, ACS_HLINE);
        }
        mvaddch(i, 3, ACS_VLINE);
        mvaddch(i, 76, ACS_VLINE);
    }
    for(int j=4; j<=75; j++)
    {
            mvaddch(21, j, ACS_HLINE);
    }
    mvaddch(21, 3, ACS_LLCORNER);
    mvaddch(21, 76, ACS_LRCORNER);
    mvaddch(3, 3, ACS_ULCORNER);
    mvaddch(3, 76, ACS_URCORNER);
}
void menu(){
    marco();
    bool eleccion = true;
    int x = 31;
    int y = 13;
    int ch;
    while (eleccion)
    {
        mvprintw(8,33,"Shoot Many X");
        mvprintw(13,33,"Iniciar Juego");
        mvprintw(14,33,"Controles");
        mvprintw(15,33,"Creditos");
        mvprintw(16,33,"Salir");
        mvprintw(23,22,"Presione ENTER para elegir una opción.");
        marco();
        mvaddch(y, x, ACS_RARROW);//FLECHA
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
        if (ch == '\n' && y == 13)
        {
            eleccion = false;
        }
        refresh();
    }
    clear();
}
void balaarriba(int x, int y){
    int ch;
    bool disparo=true;
            do{
            halfdelay(1);
            mvaddch(y-2, x+1, ' ');
            mvaddch(y-3,x+1, ACS_UARROW);
            y--;
            refresh();
            ch = getch();
            mvaddch(4, x+1, ' ');
            mvaddch(2, x+1, ' ');
            }while(disparo && y>6);
}
void balaizquierda(int x, int y){
    int ch;
    bool disparo=true;
            do{
            halfdelay(1);
            mvaddch(y, x-1, ' ');
            mvaddch(y,x-2, ACS_LARROW);
            x--;
            refresh();
            ch = getch();
            mvaddch(y, 4, ' ');
            mvaddch(y, 2, ' ');
            }while(disparo && x>5);
}
void baladerecha(int x, int y){
    int ch;
    bool disparo=true;
            do{
            halfdelay(1);
            mvaddch(y, x+3, ' ');
            mvaddch(y,x+4, ACS_RARROW);
            x++;
            refresh();
            ch = getch();
            mvaddch(y, 75, ' ');
            mvaddch(y, 77, ' ');
            }while(disparo && x<72);
}
void balaabajo(int x, int y){
    int ch;
    bool disparo=true;
            do{
            halfdelay(1);
            mvaddch(y+2, x+1, ' ');
            mvaddch(y+3,x+1, ACS_DARROW);
            y++;
            refresh();
            ch = getch();
            mvaddch(20, x+1, ' ');
            mvaddch(22, x+1, ' ');
            }while(disparo && y<18);
}
void juego(){
    marco();
    int ch;
    int x = 35;
    int y = 13;
    while (1)
    {
        marco();
        mvprintw(2,34,"Y: %d",y);
        mvprintw(2,40,"X: %d",x);
        ch = getch();
        if (ch == KEY_DOWN && y<19)
        {
            mvaddch(y, x, ' ');              //Nuevo cursor
            mvaddch(y, x+1, ' ');
            mvaddch(y, x+2, ' ');
            mvaddch(y+1, x+1, ' ');
            clear();
            y++;
            mvaddch(y,x,ACS_DIAMOND);
            mvaddch(y,x+1,ACS_DIAMOND);
            mvaddch(y,x+2,ACS_DIAMOND);
            mvaddch(y+1, x+1,ACS_DIAMOND);
        }
            if (ch == KEY_UP && y>5)
        {
            mvaddch(y, x, ' ');
            mvaddch(y, x+1, ' ');
            mvaddch(y, x+2, ' ');
            mvaddch(y-1, x+1, ' ');
            clear();
            y--;
            mvaddch(y,x,ACS_DIAMOND);
            mvaddch(y,x+1,ACS_DIAMOND);
            mvaddch(y,x+2,ACS_DIAMOND);
            mvaddch(y-1,x+1,ACS_DIAMOND);
        }
        if (ch == KEY_LEFT && x>4)
        {
            mvaddch(y-1,x+1,' ');
            mvaddch(y,x+1,' ');
            mvaddch(y+1,x+1,' ');
            mvaddch(y,x,' ');
            clear();
            x--;
            mvaddch(y-1,x+1,ACS_DIAMOND);
            mvaddch(y,x+1,ACS_DIAMOND);
            mvaddch(y+1,x+1,ACS_DIAMOND);
            mvaddch(y,x,ACS_DIAMOND);
        }
        if (ch == KEY_RIGHT && x<73)
        {
            mvaddch(y-1,x+1,' ');
            mvaddch(y,x+1,' ');
            mvaddch(y+1,x+1,' ');
            mvaddch(y,x+2,' ');
            clear();
            x++;
            mvaddch(y-1,x+1,ACS_DIAMOND);
            mvaddch(y,x+1,ACS_DIAMOND);
            mvaddch(y+1,x+1,ACS_DIAMOND);
            mvaddch(y,x+2,ACS_DIAMOND);
        }                                //Al mantener presionada la tecla, la bala avanza mas rapido.
        if(ch == 'd'){                   // Para poder disparar las teclas son d,s,a,w.
            baladerecha(x, y);
        }
        if(ch == 's'){
            balaabajo(x, y);
        }
        if(ch == 'a'){
            balaizquierda(x, y);
        }
        if(ch == 'w'){
            balaarriba(x, y);
        }
        if(ch == 27){              //ESCAPE para volver al menu.
            menu();
        }
        refresh();
    }
}
int main()
{
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    noecho();
    nodelay(stdscr,1);
    //Funciones
    menu();
    juego();

    endwin();
    return 0;
}
