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
            if (matriz[i][j]==7)
                mvaddch(i,j, 'X');
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
        mvprintw(7,33,"Shoot");
        mvprintw(8,36,"Many");



        mvprintw(5,40, "xxx    xxx");
        mvprintw(6,40, " xx    xx");
        mvprintw(7,40, "  xx  xx");
        mvprintw(8,40, "    xx");
        mvprintw(9,40, "  xx  xx");
        mvprintw(10,40," xx    xx");
        mvprintw(11,40,"xxx    xxx");



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
    }while(disparo && y>5 && matriz[y-2][x] == 0);
     matriz[y-1][x] = {0};
    imprimir_todo(matriz);
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
    }while(disparo && x>5 && matriz[y][x-2] == 0);
     matriz[y][x-1] = {0};
    imprimir_todo(matriz);
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
    }while(disparo && matriz[y][x+2] == 0);
     matriz[y][x+1] = {0};
    imprimir_todo(matriz);
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
    }while(disparo && y<19 && matriz[y+2][x] == 0);
    matriz[y+1][x] = {0};
    imprimir_todo(matriz);
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
    matriz[(rand()%17+4)][(rand()%17+4)]=7;
    imprimir_todo(matriz);

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

        if (ch == KEY_DOWN && y<19 && matriz[y+2][x] == 0 && matriz[y+1][x-1] == 0 &&  matriz[y+1][x+1] == 0)
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
            if (ch == KEY_UP && y>5 && matriz[y-2][x] == 0 && matriz[y-1][x-1] == 0 &&  matriz[y-1][x+1] == 0)
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
        if (ch == KEY_LEFT && x>5 && matriz[y][x-2] == 0 && matriz[y-1][x-1] == 0 &&  matriz[y+1][x-1] == 0)
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
        if (ch == KEY_RIGHT && x<74 && matriz[y][x+2] == 0 && matriz[y-1][x+1] == 0 &&  matriz[y+1][x+1] == 0)
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
void check_dano(int matriz[25][80], int &vida){
    for (int i=0; i<=25; i++){
        for (int j=0; j<=80; j++)
           if((matriz[i][j] == 2) && (matriz[i+1][j] == 7 || matriz[i-1][j] == 7 || matriz[i][j+1] == 7 || matriz[i][j-1] == 7))
               vida--;
    }
}
void mov_enemigo(int matriz[25][80]){
    srand(time(NULL));
    int mov = 0;
    bool check = true;
    for (int i=0; i<=25; i++)
        for (int j=0; j<=80; j++){
            if (matriz[i][j]==7)
                {
                    matriz[i][j] = 0;

            while (check){
                    mov = (rand()%4)+1;
                if (mov == 1 && matriz[i-1][j] == 0)
                   {
                    matriz[i-1][j] = 7;
                    check = false;
                   }
                if (mov == 2 && matriz[i][j+1] == 0)
                    {
                    matriz[i][j+1] = 7;
                    check = false;
                    }
                if (mov == 3 && matriz[i+1][j] == 0)
                    {
                    matriz[i+1][j] = 7;
                    check = false;
                    }
                if (mov == 4 && matriz[i][j-1] == 0)
                    {
                    matriz[i][j-1] = 7;
                    check = false;
                    }
                        }
                }
                                }
}
void escenario_lv1(int matriz[25][80]){





matriz [10][22]={1};
matriz [9][22]={1};
matriz[8][22]={1};
matriz[7][22]={1};
matriz[7][21]={1};
matriz[7][20]={1};

matriz[10][57]={1};
matriz[9][57]={1};
matriz[8][57]={1};
matriz[7][57]={1};
matriz[7][58]={1};
matriz[7][59]={1};

matriz[17][57]={1};
matriz[16][57]={1};
matriz[15][57]={1};
matriz[14][57]={1};
matriz[17][58]={1};
matriz[17][59]={1};

matriz[17][22]={1};
matriz[17][21]={1};
matriz[17][20]={1};
matriz[16][22]={1};
matriz[15][22]={1};
matriz[14][22]={1};

matriz[13][4]={1};
matriz[12][4]={1};
matriz[11][4]={1};
matriz[13][5]={1};
matriz[12][5]={1};
matriz[11][5]={1};
matriz[13][6]={1};
matriz[12][6]={1};
matriz[11][6]={1};
matriz[13][7]={1};
matriz[12][7]={1};
matriz[11][7]={1};
matriz[12][8]={1};
matriz[12][9]={1};
matriz[12][10]={1};
matriz[12][11]={1};


matriz  [13][75]={1};
matriz  [12][75]={1};
matriz  [11][75]={1};
matriz  [13][74]={1};
matriz  [12][74]={1};
matriz  [11][74]={1};
matriz  [13][73]={1};
matriz  [12][73]={1};
matriz  [11][73]={1};
matriz  [13][72]={1};
matriz  [12][72]={1};
matriz  [11][72]={1};
matriz  [12][71]={1};
matriz  [12][70]={1};
matriz  [12][69]={1};
matriz  [12][68]={1};

imprimir_todo(matriz);
}
void escenario_lv2(int matriz[25][80]){

matriz[4][39]={1};
matriz[5][39]={1};
matriz[6][39]={1};
matriz[7][39]={1};
matriz[8][39]={1};
matriz[9][39]={1};

matriz[9][40]={1};
matriz[9][41]={1};
matriz[9][42]={1};
matriz[9][43]={1};
matriz[9][44]={1};

matriz[9][38]={1};
matriz[9][37]={1};
matriz[9][36]={1};
matriz[9][35]={1};
matriz[9][34]={1};

matriz[20][39]={1};
matriz[19][39]={1};
matriz[18][39]={1};
matriz[17][39]={1};
matriz[16][39]={1};
matriz[15][39]={1};

matriz[15][40]={1};
matriz[15][41]={1};
matriz[15][42]={1};
matriz[15][43]={1};
matriz[15][44]={1};

matriz[15][38]={1};
matriz[15][37]={1};
matriz[15][36]={1};
matriz[15][35]={1};
matriz[15][34]={1};

matriz[12][5]={1};
matriz[12][6]={1};
matriz[12][7]={1};
matriz[12][8]={1};
matriz[12][9]={1};
matriz[12][10]={1};
matriz[12][11]={1};
matriz[12][12]={1};
matriz[12][13]={1};
matriz[12][14]={1};
matriz[12][15]={1};
matriz[12][16]={1};
matriz[12][17]={1};
matriz[12][18]={1};
matriz[12][19]={1};
matriz[12][20]={1};

matriz[11][20]={1};
matriz[10][20]={1};
matriz[9][20]={1};
matriz[8][20]={1};
matriz[7][20]={1};
matriz[6][20]={1};

imprimir_todo(matriz);
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

    //start_color();
    //init_pair(1,COLOR_RED,COLOR_BLACK);

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
        escenario_lv1(matriz);
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
           mvprintw(4,16,"1)Para moverte utiliza las flechas del teclado:");
           mvaddch(7,38, ACS_UARROW);
           mvaddch(8,36, ACS_LARROW);
           mvaddch(8,40, ACS_RARROW);
           mvaddch(8,38, ACS_DARROW);

           mvprintw(10,16,"2)Para disparar pulsa W,A,S,D de la siguiente manera:");
           mvaddch(13,38, ACS_UARROW);
           mvprintw(14,38,"W");
           mvaddch(17,38, ACS_DARROW);
           mvprintw(16,38,"D");
           mvaddch(15,34, ACS_LARROW);
           mvprintw(15,35," A");
           mvaddch(15,42, ACS_RARROW);
           mvprintw(15,39," D");



           mvprintw(21,20,"Apreta Esc para salir.");
           if (ch == 27)
                controles = false;
        }
    }
    endwin();
    return 0;
}

