#include <curses.h>
#include <windows.h>
#include <time.h>

using namespace std;


void imprimir_todo(int matriz[25][80]){
    for (int i=0; i<=25; i++)
        for (int j=0; j<=80; j++){
            if (matriz[i][j]==1)
                mvaddch(i,j,ACS_BLOCK);
            if (matriz[i][j]==2)
                mvaddch(i,j, ACS_DIAMOND);
        // Aca pueden ir mas impresioens siempre y cuando esten en la matriz
        }
    refresh();
}
int marco2(int matriz[25][80]){           //1 son murallas
    for(int i=4; i<=20; i++)
    {
        for(int j=4; j<=75; j++)
        {
            matriz[3][j] = 1;
        }
        matriz[i][3] = 1;

        matriz[i][76] = 1;
    }
    for(int j=4; j<=75; j++)
    {
            matriz[21][j] = 1;
    }
    matriz[21][3] = 1;
    matriz[21][76] = 1;
    matriz[3][3] = 1;
    matriz[3][76] = 1;

    refresh();
    imprimir_todo(matriz);
    }
void marco(int matriz[][80]){  //Marco 2.0
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
void menu(int matriz[25][80]){
    bool eleccion = true;
    int x = 31;
    int y = 13;
    int ch;
    while (eleccion)
    {
        //start_color();
        init_pair(1,COLOR_RED,COLOR_BLACK);
        attrset(COLOR_PAIR(1));
        mvprintw(8,33,"Shoot Many X");
        mvprintw(13,33,"Iniciar Juego");
        mvprintw(14,33,"Controles");
        mvprintw(15,33,"Creditos");
        mvprintw(16,33,"Salir");
        mvprintw(23,22,"Presione ENTER para elegir una opcion.");
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
void juego(int matriz[25][80]){
    int ch;
    int x = 35;
    int y = 13;
    while (1)
    {
        mvprintw(2,34,"Y: %d",y);
        mvprintw(2,40,"X: %d",x);
        ch = getch();
        if (ch == KEY_DOWN && y<19)
        {
            mvaddch(y, x, ' ');              //Nuevo cursor
            mvaddch(y, x+1, ' ');
            mvaddch(y, x+2, ' ');
            mvaddch(y+1, x+1, ' ');
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

        }
        refresh();
    }
}
void enemigos(int matriz[25][80],int i){
    srand(time(NULL));
    for(int r=0;r<i*2;r++)
    {
            mvprintw((rand()%17)+4, (rand()%72)+4, "X");
    }
}
void posicion_inicial(int matriz[25][80]){
        int x = 35;
        int y = 13;

        matriz[13][34] = 2;                 //2 es el cursor/jugador
        matriz[13][35] = 2;
        matriz[13][36] = 2;
        matriz[12][35] = 2;
}
void juego2(int matriz[25][80]){


    int release = 1;
    int ch;
    int x = 35;
    int y = 13;

        matriz[13][34] = 2;                 //2 es el cursor/jugador
        matriz[13][35] = 2;
        matriz[13][36] = 2;
        matriz[12][35] = 2;

    while (1)
    {
        mvprintw(2,34,"Y: %d",y);
        mvprintw(2,40,"X: %d",x);
        ch = getch();

        if (ch == KEY_DOWN && y<19)
        {
            if (matriz[y][x] == 2)
                matriz[y][x] = 0;
            if (matriz[y][x-1] == 2)
                matriz[y][x-1] = 0;
            if (matriz[y][x+1] == 2)
                matriz[y][x+1] = 0;
            if (matriz[y-1][x] == 2)
                matriz[y-1][x] = 0;
            if (matriz[y-1][x-1] == 2)
                matriz[y-1][x-1] = 0;
            if (matriz[y-1][x+1] == 2)
                matriz[y-1][x+1] = 0;
            if (matriz[y+1][x] == 2)
                matriz[y+1][x] = 0;
            if (matriz[y+1][x-1] == 2)
                matriz[y+1][x-1] = 0;
            if (matriz[y+1][x+1] == 2)
                matriz[y+1][x+1] = 0;
            y++;
                matriz[y][x] = 2;
                matriz[y][x-1] = 2;
                matriz[y][x+1] = 2;
                matriz[y+1][x] = 2;
                imprimir_todo(matriz);
        }
            if (ch == KEY_UP && y>5)
        {
            if (matriz[y][x] == 2)
                matriz[y][x] = 0;
            if (matriz[y][x-1] == 2)
                matriz[y][x-1] = 0;
            if (matriz[y][x+1] == 2)
                matriz[y][x+1] = 0;
            if (matriz[y-1][x] == 2)
                matriz[y-1][x] = 0;
            if (matriz[y-1][x-1] == 2)
                matriz[y-1][x-1] = 0;
            if (matriz[y-1][x+1] == 2)
                matriz[y-1][x+1] = 0;
            if (matriz[y+1][x] == 2)
                matriz[y+1][x] = 0;
            if (matriz[y+1][x-1] == 2)
                matriz[y+1][x-1] = 0;
            if (matriz[y+1][x+1] == 2)
                matriz[y+1][x+1] = 0;
            y--;
                matriz[y][x] = 2;
                matriz[y][x-1] = 2;
                matriz[y][x+1] = 2;
                matriz[y-1][x] = 2;
        }
        if (ch == KEY_LEFT && x>4)
        {
            if (matriz[y][x] == 2)
                matriz[y][x] = 0;
            if (matriz[y][x-1] == 2)
                matriz[y][x-1] = 0;
            if (matriz[y][x+1] == 2)
                matriz[y][x+1] = 0;
            if (matriz[y-1][x] == 2)
                matriz[y-1][x] = 0;
            if (matriz[y-1][x-1] == 2)
                matriz[y-1][x-1] = 0;
            if (matriz[y-1][x+1] == 2)
                matriz[y-1][x+1] = 0;
            if (matriz[y+1][x] == 2)
                matriz[y+1][x] = 0;
            if (matriz[y+1][x-1] == 2)
                matriz[y+1][x-1] = 0;
            if (matriz[y+1][x+1] == 2)
                matriz[y+1][x+1] = 0;
            x--;
                matriz[y][x] = 2;
                matriz[y][x-1] = 2;
                matriz[y-1][x] = 2;
                matriz[y+1][x] = 2;
        }
        if (ch == KEY_RIGHT && x<73)
        {
            if (matriz[y][x] == 2)
                matriz[y][x] = 0;
            if (matriz[y][x-1] == 2)
                matriz[y][x-1] = 0;
            if (matriz[y][x+1] == 2)
                matriz[y][x+1] = 0;
            if (matriz[y-1][x] == 2)
                matriz[y-1][x] = 0;
            if (matriz[y-1][x-1] == 2)
                matriz[y-1][x-1] = 0;
            if (matriz[y-1][x+1] == 2)
                matriz[y-1][x+1] = 0;
            if (matriz[y+1][x] == 2)
                matriz[y+1][x] = 0;
            if (matriz[y+1][x-1] == 2)
                matriz[y+1][x-1] = 0;
            if (matriz[y+1][x+1] == 2)
                matriz[y+1][x+1] = 0;
            x++;
                matriz[y][x] = 2;
                matriz[y][x+1] = 2;
                matriz[y-1][x] = 2;
                matriz[y+1][x] = 2;
        }                                //Al mantener presionada la tecla, la bala avanza mas rapido.
        if(ch == 'd'){                   // Para poder disparar las teclas son d,s,a,w.
            void baladerecha(int x,int y);
        }
        if(ch == 's'){
            void balaabajo(int x, int y);
        }
        if(ch == 'a'){
            void balaizquierda(int x, int y);
        }
        if(ch == 'w'){
            void balaarriba(int x, int y);
        }
        if(ch == 27){              //ESCAPE para volver al menu.

        }

}
}
int main()
{
    int matriz[25][80]={0};
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    noecho();
    nodelay(stdscr,1);
    //Funciones
    marco2(matriz);



    menu(matriz);



    //Aca se podria poner un contador de nivel onda nivel = 1 y con ++ al final para usarlo en la funcion de
    //creacion de enemigos, haciendo un ciclo de enemigos y juego
    marco2(matriz);
    posicion_inicial(matriz);

    enemigos(matriz,1);               //variable es nivel en que se encuentra uno, por ahora 1
    juego2(matriz);
    endwin();
    return 0;
}

