#include <curses.h>
#include <windows.h>
#include <time.h>

using namespace std;


void imprimir_todo(int matriz[25][80]){
    for (int i=0; i<=25; i++)
        for (int j=0; j<=80; j++){
            if (matriz[i][j]==0)
                mvaddch(i,j,' ');
            if (matriz[i][j]==1)
                mvaddch(i,j,ACS_BLOCK);
            if (matriz[i][j]==2)
                mvaddch(i,j, ACS_DIAMOND);
            if (matriz[i][j]==3)
                mvaddch(i,j,ACS_UARROW);
            if (matriz[i][j]==4)
                mvaddch(i,j,ACS_LARROW);
            if (matriz[i][j]==5)
                mvaddch(i,j,ACS_RARROW);
            if (matriz[i][j]==6)
                mvaddch(i,j,ACS_DARROW);
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
void menu(int matriz[25][80], bool &exit, bool &juego, bool &creditos, bool &controles){
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
            juego = true;
        }
        if (ch == '\n' && y == 14)
        {
            eleccion = false;
            controles = true;
        }
        if (ch == '\n' && y == 15)
        {
            eleccion = false;
            creditos = true;
        }
        if (ch == '\n' && y == 16)
        {
            eleccion = false;
            exit = false;
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
void balaarriba2(int matriz[25][80], int x, int y){

    int ch;
    bool disparo=true;
    do{
            halfdelay(1);
            if(matriz[y-1][x]==3)
            matriz[y-1][x]=0;
            y--;
            refresh();
            ch = getch();
            matriz[y-1][x] = 3;
            imprimir_todo(matriz);
    }while(disparo && y>5);
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
void balaizquierda2(int matriz[25][80],int x, int y){

    int ch;
    bool disparo=true;
    do{
            halfdelay(1);
            if(matriz[y][x-1]==4)
            matriz[y][x-1]=0;
            x--;
            refresh();
            ch = getch();
            matriz[y][x-1] = 4;
            imprimir_todo(matriz);
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
void baladerecha2(int matriz[25][80], int x, int y){

    int ch;
    bool disparo=true;
    do{
            halfdelay(1);
            if(matriz[y][x+1]==5)
            matriz[y][x+1]=0;
            x++;
            refresh();
            ch = getch();
            matriz[y][x+1] = 5;
            imprimir_todo(matriz);
    }while(disparo && x<74);
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
void balaabajo2(int matriz[25][80], int x, int y){

    int ch;
    bool disparo=true;
    do{
            halfdelay(1);
            if(matriz[y+1][x]==6)
            matriz[y+1][x]=0;
            y++;
            refresh();
            ch = getch();
            matriz[y+1][x] = 6;
            imprimir_todo(matriz);
    }while(disparo && y<19);



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
void juego2(int matriz[25][80], bool &juego){

    bool release = true;
    int ch;
    int x = 35;
    int y = 13;


        matriz[13][34] = 2;                 //2 es el cursor/jugador
        matriz[13][35] = 2;
        matriz[13][36] = 2;
        matriz[12][35] = 2;
        imprimir_todo(matriz);

    while (release)
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
                imprimir_todo(matriz);
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
                imprimir_todo(matriz);
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
                imprimir_todo(matriz);
        }                                //Al mantener presionada la tecla, la bala avanza mas rapido.
        if(ch == 'd'){                   // Para poder disparar las teclas son d,s,a,w.
            baladerecha2(matriz,x,y);
        }
        if(ch == 's'){
            balaabajo2(matriz,x,y);
        }
        if(ch == 'a'){
            balaizquierda2(matriz,x,y);
        }
        if(ch == 'w'){
            balaarriba2(matriz,x,y);
        }

        if(ch == 27){              //ESCAPE para volver al menu.
            release = false;
            juego = false;
        }

}
}
int main()
{
    bool exit = true;
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    noecho();
    nodelay(stdscr,1);
    //Funciones
    while(exit)
    {
        bool juego = false;
        bool creditos = false;
        bool controles = false;
        int matriz[25][80]={0};
        clear();
        marco2(matriz);
        menu(matriz,exit,juego,creditos,controles);
        while (juego)
        {
        marco2(matriz);                               //Aca se podria poner un contador de nivel onda nivel = 1 y con ++ al final para usarlo en la funcion de
        posicion_inicial(matriz);                     //creacion de enemigos, haciendo un ciclo de enemigos y juego
        enemigos(matriz,1);                           //variable es nivel en que se encuentra uno, por ahora 1
        juego2(matriz,juego);
        }
        while (creditos)
        {
           int ch = getch();
           mvprintw(20,20,"Escribir Creditos, algo como esto.");
           mvprintw(21,20,"Apreta Esc para salir.");
           if (ch == 27)
                creditos = false;
        }
        while (controles)
        {
           int ch = getch();
           mvprintw(20,20,"Escribir Controles, algo como esto.");
           mvprintw(21,20,"Apreta Esc para salir.");
           if (ch == 27)
                controles = false;
        }
    }
    endwin();
    return 0;
}

