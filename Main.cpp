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
            mvaddch(y, x, ' ');
            mvaddch(y-1,x, ACS_UARROW);
            y--;
            refresh();
            ch = getch();
            mvprintw(4, x, " ");
            }while(disparo && y>4);
}
void balaizquierda(int x, int y){
    int ch;
    bool disparo=true;
            do{
            halfdelay(1);
            mvaddch(y, x, ' ');
            mvaddch(y,x-1, ACS_LARROW);
            x--;
            refresh();
            ch = getch();
            mvprintw(y, 4, " ");
            }while(disparo && x>4);

}
void baladerecha(int x, int y){
    int ch;
    bool disparo=true;
            do{
            halfdelay(1);
            mvaddch(y, x, ' ');
            mvaddch(y,x+1, ACS_RARROW);
            x++;
            refresh();
            ch = getch();
            mvprintw(y, 75, " ");
            }while(disparo && x<75);
}
void balaabajo(int x, int y){
    int ch;
    bool disparo=true;
            do{
            halfdelay(1);
            mvaddch(y, x, ' ');
            mvaddch(y+1,x, ACS_DARROW);
            y++;
            refresh();
            ch = getch();
            mvprintw(20, x, " ");
            }while(disparo && y<20);
}
void juego(){
    marco();
    int ch;
    int x = 35;
    int y = 13;
    bool disparo=true;
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
        refresh();
    }
}
void enemigos(int i){

    srand(time(NULL));
    for(int r=0;r<i*2;r++)
    {
            mvprintw((rand()%17)+4, (rand()%72)+4, "X");
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

    //Aca se podria poner un contador de nivel onda nivel = 1 y con ++ al final para usarlo en la funcion de
    //creacion de enemigos, haciendo un ciclo de enemigos y juego
    enemigos(1);               //variable es nivel en que se encuentra uno, por ahora 1
    juego();
    endwin();
    return 0;
}
