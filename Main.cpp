#include <curses.h>
#include <windows.h>
#include <time.h>

using namespace std;


void imprimir_todo(double matriz[25][80]){
    for (int i=0; i<=25; i++)
        for (int j=0; j<=80; j++){
            if (matriz[i][j]==0)                // 0 espacios en blanco
                mvaddch(i,j,' ');

            attron(COLOR_PAIR(1));
            if (matriz[i][j]==1)                // 1 murallas
                mvaddch(i,j,ACS_BLOCK);
            attroff(COLOR_PAIR(1));

            attron(COLOR_PAIR(3));
            if (matriz[i][j]==2)                // 2 cursor
                mvaddch(i,j, ACS_DIAMOND);
            attroff(COLOR_PAIR(3));

            attron(COLOR_PAIR(6));
            if (matriz[i][j]==3)                // 3 disparo hacia arriba
                mvaddch(i,j,ACS_UARROW);
            if (matriz[i][j]==4)                // 4 disparo hacia izquierda
                mvaddch(i,j,ACS_LARROW);
            if (matriz[i][j]==5)                // 5 disparo hacia derecha
                mvaddch(i,j,ACS_RARROW);
            if (matriz[i][j]==6)                // 6 disparo hacia abajo
                mvaddch(i,j,ACS_DARROW);
            attroff(COLOR_PAIR(6));

            attron(COLOR_PAIR(5));
            if (matriz[i][j]==7)                // 7 Enemjgos
                mvaddch(i,j, 'X');
            attroff(COLOR_PAIR(5));

            attron(COLOR_PAIR(2));              // 8 Explosion
            if (matriz[i][j]==8)
                mvaddch(i,j,ACS_BOARD);
            attroff(COLOR_PAIR(2));

            attron(COLOR_PAIR(2));
            if (matriz[i][j]==9)                // 9 Cursor golpeado
                mvaddch(i,j, ACS_DIAMOND);
            attroff(COLOR_PAIR(2));

        // Aca pueden ir mas impresioens siempre y cuando esten en la matriz
        }
    refresh();
}
void check_dano(double matriz[25][80], int &vida, int i, int j){
           if((matriz[i][j] == 2) && (matriz[i-1][j-1] == 7 || matriz[i-1][j+1] == 7 || matriz[i+1][j-1] == 7 || matriz[i+1][j+1] == 7 || matriz[i-2][j] == 7 || matriz[i][j-2] == 7 || matriz[i][j+2] == 7 || matriz[i+2][j] == 7))
               {
                   vida--;
                   for (int l=0; l<=25; l++)
                    {
                    for (int m=0; m<=80; m++)
                        if(matriz[l][m] == 2)
                           {
                            matriz[l][m] = 9;
                            imprimir_todo(matriz);
                           }
                    }
                    Sleep(400);
                    for (int l=0; l<=25; l++)
                    {
                    for (int m=0; m<=80; m++)
                        if(matriz[l][m] == 9)
                           {
                            matriz[l][m] = 2;
                            imprimir_todo(matriz);
                           }
                    }
               }
    }
void mov_enemigo(double matriz[25][80]){
    srand(time(NULL));
    int mov = 0;
    for (int i=0; i<=25; i++){
        for (int j=0; j<=80; j++){
            if (matriz[i][j]==7)
                {
                    bool check = true;
                    matriz[i][j] = 0;

            while (check){
                    mov = (rand()%4)+1;
                if (mov == 1 && matriz[i-1][j] == 0)
                   {
                    matriz[i-1][j] = 7;
                    check = false;
                   }
                else if (mov == 2 && matriz[i][j+1] == 0)
                    {
                    matriz[i][j+1] = 7;
                    check = false;
                    }
                else if (mov == 3 && matriz[i+1][j] == 0)
                    {
                    matriz[i+1][j] = 7;
                    check = false;
                    }
                else if (mov == 4 && matriz[i][j-1] == 0)
                    {
                    matriz[i][j-1] = 7;
                    check = false;
                    }
                 else if (matriz[i-1][j] != 0 && matriz[i][j+1] != 0 && matriz[i+1][j] != 0 && matriz[i][j-1] != 0)
                    {
                    matriz[i][j] = 7;
                    check = false;
                    }
                        }
                }
                                }
                            }

}
int marco2(double matriz[25][80]){           //1 son murallas
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
void menu(double matriz[25][80], bool &exit, bool &juego, bool &creditos, bool &controles, bool &bio){
    bool eleccion = true;
    int x = 31;
    int y = 13;
    int ch;
    while (eleccion)
    {
    attron(COLOR_PAIR(3));
        mvprintw(7,33,"Shoot");
        mvprintw(8,36,"Many");
    attroff(COLOR_PAIR(3));

    attron(COLOR_PAIR(5));
        mvprintw(5,40, "xxx    xxx");
        mvprintw(6,40, " xx    xx");
        mvprintw(7,40, "  xx  xx");
        mvprintw(8,40, "    xx");
        mvprintw(9,40, "  xx  xx");
        mvprintw(10,40," xx    xx");
        mvprintw(11,40,"xxx    xxx");
    attroff(COLOR_PAIR(5));

    attron(COLOR_PAIR(2));
        mvprintw(13,33,"Iniciar Juego");
        mvprintw(14,33,"Biografias");
        mvprintw(15,33,"Controles");
        mvprintw(16,33,"Creditos");
        mvprintw(17,33,"Salir");
        mvprintw(23,22,"Presione ENTER para elegir una opcion.");
    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(1));
        mvaddch(y, x, ACS_RARROW);//FLECHA
    attroff(COLOR_PAIR(1));
        ch = getch();
        if (ch == KEY_DOWN && y<17)
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
            bio = true;
        }
        if (ch == '\n' && y == 15)
        {
            eleccion = false;
            controles = true;
        }
        if (ch == '\n' && y == 16)
        {
            eleccion = false;
            creditos = true;
        }
        if (ch == '\n' && y == 17)
        {
            eleccion = false;
            exit = false;
        }
        refresh();
    }
    clear();
}
void balaarriba2(double matriz[25][80], int x, int y, int &puntuacion){

    int ch;
    bool disparo=true;
    while(disparo && y>5 && matriz[y-2][x] == 0){
            halfdelay(1);
            if(matriz[y-1][x]==3)
            matriz[y-1][x]=0;
            y--;
            refresh();
            ch = getch();
            matriz[y-1][x] = 3;
            imprimir_todo(matriz);

    }
   if(matriz[y-2][x]==1 && matriz[y-1][x]==2){
    matriz[y-1][x]={2};
    imprimir_todo(matriz);
   }
   else if(matriz[y-2][x]==1){
   Sleep(200);
   matriz[y-1][x] = {8};
   imprimir_todo(matriz);
   Sleep(200);
   matriz[y-1][x] = {0};
   imprimir_todo(matriz);
   }
   else if(matriz[y-2][x]==7 && matriz[y-1][x]==2){
    matriz[y-2][x]={8};
    imprimir_todo(matriz);
    Sleep(200);
    matriz[y-2][x]={0};
    imprimir_todo(matriz);
    matriz[y-1][x]={2};
    puntuacion +=100;
    imprimir_todo(matriz);
   }
   else if(matriz[y-2][x]==7){
   matriz[y-2][x] = {8};
   imprimir_todo(matriz);
   Sleep(200);
   matriz[y-2][x] = {0};
   matriz[y-1][x] = {0};
   imprimir_todo(matriz);
   puntuacion +=100;
   }



}
void balaizquierda2(double matriz[25][80],int x, int y, int &puntuacion){

    int ch;
    bool disparo=true;
    while(disparo && x>5 && matriz[y][x-2] == 0){
            halfdelay(1);
            if(matriz[y][x-1]==4)
            matriz[y][x-1]=0;
            x--;
            refresh();
            ch = getch();
            matriz[y][x-1] = 4;
            imprimir_todo(matriz);
    }
   if(matriz[y][x-2]==1 && matriz[y][x-1]==2){
    matriz[y][x-1]={2};
    imprimir_todo(matriz);
   }
   else if(matriz[y][x-2]==1){
   Sleep(200);
   matriz[y][x-1] = {8};
   imprimir_todo(matriz);
   Sleep(200);
   matriz[y][x-1] = {0};
   imprimir_todo(matriz);
   }
   else if(matriz[y][x-2]==7 && matriz[y][x-1]==2){
    matriz[y][x-2]={8};
    imprimir_todo(matriz);
    Sleep(200);
    matriz[y][x-2]={0};
    imprimir_todo(matriz);
    matriz[y][x-1]={2};
    puntuacion +=100;
    imprimir_todo(matriz);
   }
   else if(matriz[y][x-2]==7){
   matriz[y][x-2] = {8};
   imprimir_todo(matriz);
   Sleep(200);
   matriz[y][x-2] = {0};
   matriz[y][x-1] = {0};
   imprimir_todo(matriz);
   puntuacion +=100;
   }


}
void baladerecha2(double matriz[25][80], int x, int y, int &puntuacion){

    int ch;
    bool disparo=true;

    while(disparo && matriz[y][x+2] == 0){
            halfdelay(1);
            if(matriz[y][x+1]==5)
            matriz[y][x+1]=0;
            x++;
            refresh();
            ch = getch();
            matriz[y][x+1] = 5;
            imprimir_todo(matriz);
    }
   if(matriz[y][x+2]==1 && matriz[y][x+1]==2){
    matriz[y][x+1]={2};
    imprimir_todo(matriz);
   }
   else if(matriz[y][x+2]==1){
   Sleep(200);
   matriz[y][x+1] = {8};
   imprimir_todo(matriz);
   Sleep(200);
   matriz[y][x+1] = {0};
   imprimir_todo(matriz);
   }
   else if(matriz[y][x+2]==7 && matriz[y][x+1]==2){
    matriz[y][x+2]={8};
    imprimir_todo(matriz);
    Sleep(200);
    matriz[y][x+2]={0};
    imprimir_todo(matriz);
    matriz[y][x+1]={2};
    puntuacion +=100;
    imprimir_todo(matriz);
   }
   else if(matriz[y][x+2]==7){
   matriz[y][x+2] = {8};
   imprimir_todo(matriz);
   Sleep(200);
   matriz[y][x+2] = {0};
   matriz[y][x+1] = {0};
   imprimir_todo(matriz);
   puntuacion +=100;
   }
}
void balaabajo2(double matriz[25][80], int x, int y, int &puntuacion){

    int ch;
    bool disparo=true;
    while(disparo && y<19 && matriz[y+2][x] == 0){
            halfdelay(1);
            if(matriz[y+1][x]==6)
            matriz[y+1][x]=0;
            y++;
            refresh();
            ch = getch();
            matriz[y+1][x] = 6;
            imprimir_todo(matriz);
    }
   if(matriz[y+2][x]==1 && matriz[y+1][x]==2){
    matriz[y+1][x]={2};
    imprimir_todo(matriz);
   }
   else if(matriz[y+2][x]==1){
   Sleep(200);
   matriz[y+1][x] = {8};
   imprimir_todo(matriz);
   Sleep(200);
   matriz[y+1][x] = {0};
   imprimir_todo(matriz);
   }
   else if(matriz[y+2][x]==7 && matriz[y+1][x]==2){
    matriz[y+2][x]={8};
    imprimir_todo(matriz);
    Sleep(200);
    matriz[y+2][x]={0};
    imprimir_todo(matriz);
    matriz[y+1][x]={2};
    puntuacion +=100;
    imprimir_todo(matriz);
   }
   else if(matriz[y+2][x]==7){
   matriz[y+2][x] = {8};
   imprimir_todo(matriz);
   Sleep(200);
   matriz[y+2][x] = {0};
   matriz[y+1][x] = {0};
   imprimir_todo(matriz);
   puntuacion +=100;
   }
}
void enemigos(double matriz[25][80],int nivel,int &enemigos_matar){
    srand(time(NULL));
    bool comprobar = true;
    enemigos_matar = 0;
        matriz[12][39] = 2;
        matriz[12][40] = 2;
        matriz[12][38] = 2;
        matriz[11][39] = 2;
    for(int r=0;r<nivel*4;r++)
    {
        int y,x;
        comprobar = true;
        while(comprobar)
        {
            do{
                    y = (rand()%17)+4;
                    x = (rand()%72)+4;
            }while((y>7 && y<17) && (x>34 && x<44));
                if (matriz[y][x]==0)
                {
                matriz[y][x]=7;
                comprobar = false;
                imprimir_todo(matriz);
                }
        }
        enemigos_matar++;
    }
    enemigos_matar *= 100;
}
void juego2(double matriz[25][80], bool &juego, int &puntuacion, int enemigos_matar, int nivel){

    int puntuacion_inicial = puntuacion;
    bool release = true;
    int ch;
    int x = 39;
    int y = 12;
    int vida = 3;

        matriz[12][39] = 2;                 //2 es el cursor/jugador
        matriz[12][40] = 2;
        matriz[12][38] = 2;
        matriz[11][39] = 2;
        matriz[13][39] = 2;
        imprimir_todo(matriz);

    while (release)
    {
       /* mvprintw(2,34,"Y: %d",y);                 //Funcion coordenada
        mvprintw(2,40,"X: %d",x);
       */
        mvprintw(1,34,"NIVEL: %d",nivel);
        mvprintw(1,60, "Puntuacion: %d",puntuacion);

        attron(COLOR_PAIR(2));
        if (vida == 3){
        mvprintw(2,60, "Vidas: ");
        mvaddrawch(2,67,3);
        mvaddrawch(2,69,3);
        mvaddrawch(2,71,3);
        }
        if (vida == 2){
        mvprintw(2,60, "Vidas:");
        mvaddrawch(2,67,3);
        mvaddrawch(2,69,3);
        }
        if (vida == 1){
        mvprintw(2,60, "Vidas:");
        mvaddrawch(2,67,3);
        }
        attroff(COLOR_PAIR(2));
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
                matriz[y-1][x] = 2;
                mov_enemigo(matriz);
                imprimir_todo(matriz);
                check_dano(matriz,vida,y,x);
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
                matriz[y+1][x] = 2;
                mov_enemigo(matriz);
                imprimir_todo(matriz);
                check_dano(matriz,vida,y,x);
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
                matriz[y][x+1] = 2;
                mov_enemigo(matriz);
                imprimir_todo(matriz);
                check_dano(matriz,vida,y,x);
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
                matriz[y][x-1] = 2;
                mov_enemigo(matriz);
                imprimir_todo(matriz);
                check_dano(matriz,vida,y,x);
        }                                //Al mantener presionada la tecla, la bala avanza mas rapido.
        if(ch == 'd'){                   // Para poder disparar las teclas son d,s,a,w.
            baladerecha2(matriz,x,y,puntuacion);
            mov_enemigo(matriz);
        }
        if(ch == 's'){
            balaabajo2(matriz,x,y,puntuacion);
            mov_enemigo(matriz);
        }
        if(ch == 'a'){
            balaizquierda2(matriz,x,y,puntuacion);
            mov_enemigo(matriz);
        }
        if(ch == 'w'){
            balaarriba2(matriz,x,y,puntuacion);
            mov_enemigo(matriz);
        }

        if(ch == 27){              //ESCAPE para volver al menu.
            release = false;
            juego = false;
        }
        if (vida == 0)
        {
            clear();
            attron(COLOR_PAIR(3));
        mvaddch(5,15,ACS_DIAMOND);
        mvaddch(5,14,ACS_DIAMOND);
        mvaddch(5,13,ACS_DIAMOND);
        mvaddch(5,12,ACS_DIAMOND);
        mvaddch(5,11,ACS_DIAMOND);
        mvaddch(5,10,ACS_DIAMOND);
        mvaddch(6,10,ACS_DIAMOND);
        mvaddch(7,10,ACS_DIAMOND);
        mvaddch(8,10,ACS_DIAMOND);
        mvaddch(9,10,ACS_DIAMOND);
        mvaddch(10,10,ACS_DIAMOND);
        mvaddch(11,10,ACS_DIAMOND);
        mvaddch(11,11,ACS_DIAMOND);
        mvaddch(11,12,ACS_DIAMOND);
        mvaddch(11,13,ACS_DIAMOND);
        mvaddch(11,14,ACS_DIAMOND);
        mvaddch(11,15,ACS_DIAMOND);
        mvaddch(10,15,ACS_DIAMOND);
        mvaddch(9,15,ACS_DIAMOND);
        mvaddch(8,15,ACS_DIAMOND);
        mvaddch(8,14,ACS_DIAMOND);
        mvaddch(8,13,ACS_DIAMOND);

        //LETRA A

        mvaddch(11,17,ACS_DIAMOND);
        mvaddch(10,17,ACS_DIAMOND);
        mvaddch(9,17,ACS_DIAMOND);
        mvaddch(8,17,ACS_DIAMOND);
        mvaddch(7,17,ACS_DIAMOND);
        mvaddch(6,17,ACS_DIAMOND);
        mvaddch(5,17,ACS_DIAMOND);
        mvaddch(5,18,ACS_DIAMOND);
        mvaddch(5,19,ACS_DIAMOND);
        mvaddch(5,20,ACS_DIAMOND);
        mvaddch(5,21,ACS_DIAMOND);
        mvaddch(5,22,ACS_DIAMOND);
        mvaddch(6,22,ACS_DIAMOND);
        mvaddch(7,22,ACS_DIAMOND);
        mvaddch(8,22,ACS_DIAMOND);
        mvaddch(9,22,ACS_DIAMOND);
        mvaddch(10,22,ACS_DIAMOND);
        mvaddch(11,22,ACS_DIAMOND);
        mvaddch(8,22,ACS_DIAMOND);
        mvaddch(8,21,ACS_DIAMOND);
        mvaddch(8,20,ACS_DIAMOND);
        mvaddch(8,19,ACS_DIAMOND);
        mvaddch(8,18,ACS_DIAMOND);

        //letra M
        mvaddch(5,25,ACS_DIAMOND);
        mvaddch(6,25,ACS_DIAMOND);
        mvaddch(7,25,ACS_DIAMOND);
        mvaddch(8,25,ACS_DIAMOND);
        mvaddch(9,25,ACS_DIAMOND);
        mvaddch(10,25,ACS_DIAMOND);
        mvaddch(11,25,ACS_DIAMOND);
        mvaddch(6,26,ACS_DIAMOND);
        mvaddch(7,27,ACS_DIAMOND);
        mvaddch(8,28,ACS_DIAMOND);
        mvaddch(7,29,ACS_DIAMOND);
        mvaddch(6,30,ACS_DIAMOND);
        mvaddch(5,31,ACS_DIAMOND);
        mvaddch(6,31,ACS_DIAMOND);
        mvaddch(7,31,ACS_DIAMOND);
        mvaddch(8,31,ACS_DIAMOND);
        mvaddch(9,31,ACS_DIAMOND);
        mvaddch(10,31,ACS_DIAMOND);
        mvaddch(11,31,ACS_DIAMOND);

        //letra E

        mvaddch(5,34,ACS_DIAMOND);
        mvaddch(5,35,ACS_DIAMOND);
        mvaddch(5,36,ACS_DIAMOND);
        mvaddch(5,37,ACS_DIAMOND);
        mvaddch(5,38,ACS_DIAMOND);
        mvaddch(5,39,ACS_DIAMOND);
        mvaddch(6,34,ACS_DIAMOND);
        mvaddch(7,34,ACS_DIAMOND);
        mvaddch(8,34,ACS_DIAMOND);
        mvaddch(9,34,ACS_DIAMOND);
        mvaddch(10,34,ACS_DIAMOND);
        mvaddch(11,34,ACS_DIAMOND);
        mvaddch(11,35,ACS_DIAMOND);
        mvaddch(11,36,ACS_DIAMOND);
        mvaddch(11,37,ACS_DIAMOND);
        mvaddch(11,38,ACS_DIAMOND);
        mvaddch(11,39,ACS_DIAMOND);
        mvaddch(8,35,ACS_DIAMOND);
        mvaddch(8,36,ACS_DIAMOND);
        mvaddch(8,37,ACS_DIAMOND);
        mvaddch(8,38,ACS_DIAMOND);
        mvaddch(8,39,ACS_DIAMOND);

        //LETRA O

        mvaddch(14,17,ACS_DIAMOND);
        mvaddch(15,17,ACS_DIAMOND);
        mvaddch(16,17,ACS_DIAMOND);
        mvaddch(17,17,ACS_DIAMOND);
        mvaddch(18,17,ACS_DIAMOND);
        mvaddch(19,17,ACS_DIAMOND);
        mvaddch(20,17,ACS_DIAMOND);
        mvaddch(20,18,ACS_DIAMOND);
        mvaddch(20,19,ACS_DIAMOND);
        mvaddch(20,20,ACS_DIAMOND);
        mvaddch(20,21,ACS_DIAMOND);
        mvaddch(20,22,ACS_DIAMOND);
        mvaddch(19,22,ACS_DIAMOND);
        mvaddch(18,22,ACS_DIAMOND);
        mvaddch(17,22,ACS_DIAMOND);
        mvaddch(16,22,ACS_DIAMOND);
        mvaddch(15,22,ACS_DIAMOND);
        mvaddch(14,22,ACS_DIAMOND);
        mvaddch(14,21,ACS_DIAMOND);
        mvaddch(14,20,ACS_DIAMOND);
        mvaddch(14,19,ACS_DIAMOND);
        mvaddch(14,18,ACS_DIAMOND);

        //LETRA V

        mvaddch(14,25,ACS_DIAMOND);
        mvaddch(15,25,ACS_DIAMOND);
        mvaddch(16,26,ACS_DIAMOND);
        mvaddch(17,26,ACS_DIAMOND);
        mvaddch(18,27,ACS_DIAMOND);
        mvaddch(19,27,ACS_DIAMOND);
        mvaddch(20,28,ACS_DIAMOND);
        mvaddch(19,29,ACS_DIAMOND);
        mvaddch(18,29,ACS_DIAMOND);
        mvaddch(17,30,ACS_DIAMOND);
        mvaddch(16,30,ACS_DIAMOND);
        mvaddch(15,31,ACS_DIAMOND);
        mvaddch(14,31,ACS_DIAMOND);

        //LETRA E

        mvaddch(14,34,ACS_DIAMOND);
        mvaddch(15,34,ACS_DIAMOND);
        mvaddch(16,34,ACS_DIAMOND);
        mvaddch(17,34,ACS_DIAMOND);
        mvaddch(18,34,ACS_DIAMOND);
        mvaddch(19,34,ACS_DIAMOND);
        mvaddch(20,34,ACS_DIAMOND);
        mvaddch(14,35,ACS_DIAMOND);
        mvaddch(14,36,ACS_DIAMOND);
        mvaddch(14,37,ACS_DIAMOND);
        mvaddch(14,38,ACS_DIAMOND);
        mvaddch(14,39,ACS_DIAMOND);
        mvaddch(17,35,ACS_DIAMOND);
        mvaddch(17,36,ACS_DIAMOND);
        mvaddch(17,37,ACS_DIAMOND);
        mvaddch(17,38,ACS_DIAMOND);
        mvaddch(17,39,ACS_DIAMOND);
        mvaddch(20,35,ACS_DIAMOND);
        mvaddch(20,36,ACS_DIAMOND);
        mvaddch(20,37,ACS_DIAMOND);
        mvaddch(20,38,ACS_DIAMOND);
        mvaddch(20,39,ACS_DIAMOND);

        //LETRA R

        mvaddch(14,42,ACS_DIAMOND);
        mvaddch(15,42,ACS_DIAMOND);
        mvaddch(16,42,ACS_DIAMOND);
        mvaddch(17,42,ACS_DIAMOND);
        mvaddch(18,42,ACS_DIAMOND);
        mvaddch(19,42,ACS_DIAMOND);
        mvaddch(20,42,ACS_DIAMOND);
        mvaddch(14,43,ACS_DIAMOND);
        mvaddch(14,44,ACS_DIAMOND);
        mvaddch(14,45,ACS_DIAMOND);
        mvaddch(14,46,ACS_DIAMOND);
        mvaddch(14,47,ACS_DIAMOND);
        mvaddch(15,47,ACS_DIAMOND);
        mvaddch(16,47,ACS_DIAMOND);
        mvaddch(17,47,ACS_DIAMOND);
        mvaddch(17,46,ACS_DIAMOND);
        mvaddch(17,45,ACS_DIAMOND);
        mvaddch(17,44,ACS_DIAMOND);
        mvaddch(17,43,ACS_DIAMOND);
        mvaddch(18,45,ACS_DIAMOND);
        mvaddch(19,46,ACS_DIAMOND);
        mvaddch(20,47,ACS_DIAMOND);

        attroff(COLOR_PAIR(3));
        //logo SMX
        attron(COLOR_PAIR(5));

        mvprintw(8,54,"xxxx    xxxx");
        mvprintw(9,55,  "xxx    xxx");
        mvprintw(10,55,  " xx    xx");
        mvprintw(11,55,  "  xx  xx");
        mvprintw(12,55, "    xx");
        mvprintw(13,55, "  xx  xx");
        mvprintw(14,55, " xx    xx");
        mvprintw(15,55, "xxx    xxx");
        mvprintw(16,54,"xxxx    xxxx");
        attroff(COLOR_PAIR(5));

        mvprintw(21,52,"PUNTUACION FINAL = %d",puntuacion);
        refresh();
        Sleep(2000);
        release = false;
        juego = false;
        }
        if (puntuacion - puntuacion_inicial == enemigos_matar)
        {
            release = false;
            juego = true;
            matriz[y-1][x-1] = 0;
            matriz[y-1][x] = 0;
            matriz[y][x+1] = 0;
            matriz[y][x-1] = 0;
            matriz[y][x] = 0;
            matriz[y][x+1] = 0;
            matriz[y+1][x-1] = 0;
            matriz[y+1][x] = 0;
            matriz[y+1][x+1] = 0;
            Sleep(1000);
        }
    }
}
void escenario_cero(double matriz[25][80]){
    //clear();
    for (int i=4;i<21;i++){
        for(int j=4;j<76;j++)
            matriz[i][j] = 0;
    }
    //imprimir_todo(matriz);
}
void escenario_lv1(double matriz[25][80]){

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
matriz  [12][67]={1};

imprimir_todo(matriz);
}
void escenario_lv2(double matriz[25][80]){

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

matriz[12][4]={1};
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

matriz[13][20]={1};
matriz[14][20]={1};
matriz[15][20]={1};
matriz[16][20]={1};
matriz[17][20]={1};

matriz[12][75]={1};
matriz[12][74]={1};
matriz[12][73]={1};
matriz[12][72]={1};
matriz[12][71]={1};
matriz[12][70]={1};
matriz[12][69]={1};
matriz[12][68]={1};
matriz[12][67]={1};
matriz[12][66]={1};
matriz[12][65]={1};
matriz[12][64]={1};
matriz[12][63]={1};
matriz[12][62]={1};
matriz[12][61]={1};
matriz[12][60]={1};
matriz[12][59]={1};
matriz[12][58]={1};

matriz[11][58]={1};
matriz[10][58]={1};
matriz[9][58]={1};
matriz[8][58]={1};
matriz[7][58]={1};

matriz[13][58]={1};
matriz[14][58]={1};
matriz[15][58]={1};
matriz[16][58]={1};
matriz[17][58]={1};

imprimir_todo(matriz);
}
void escenario_lv3(double matriz[25][80]){

matriz[10][4]={1};
matriz[10][5]={1};
matriz[10][6]={1};
matriz[10][7]={1};
matriz[10][8]={1};
matriz[10][9]={1};
matriz[10][10]={1};
matriz[10][11]={1};
matriz[10][12]={1};
matriz[10][13]={1};
matriz[10][14]={1};
matriz[10][15]={1};
matriz[10][16]={1};
matriz[10][17]={1};

matriz[9][17]={1};
matriz[8][17]={1};
matriz[7][17]={1};

matriz[7][18]={1};
matriz[7][19]={1};
matriz[7][20]={1};
matriz[7][21]={1};
matriz[7][22]={1};
matriz[7][23]={1};
matriz[7][23]={1};
matriz[7][24]={1};
matriz[7][25]={1};

matriz[14][4]={1};
matriz[14][5]={1};
matriz[14][6]={1};
matriz[14][7]={1};
matriz[14][8]={1};
matriz[14][9]={1};
matriz[14][10]={1};
matriz[14][11]={1};
matriz[14][12]={1};
matriz[14][13]={1};
matriz[14][14]={1};
matriz[14][15]={1};
matriz[14][16]={1};
matriz[14][17]={1};

matriz[15][17]={1};
matriz[16][17]={1};
matriz[17][17]={1};

matriz[17][18]={1};
matriz[17][19]={1};
matriz[17][20]={1};
matriz[17][21]={1};
matriz[17][22]={1};
matriz[17][23]={1};
matriz[17][24]={1};
matriz[17][25]={1};

matriz[13][25]={1};
matriz[12][25]={1};
matriz[11][25]={1};

matriz[10][75]={1};
matriz[10][74]={1};
matriz[10][73]={1};
matriz[10][72]={1};
matriz[10][71]={1};
matriz[10][70]={1};
matriz[10][69]={1};
matriz[10][68]={1};
matriz[10][67]={1};
matriz[10][66]={1};
matriz[10][65]={1};
matriz[10][64]={1};
matriz[10][63]={1};
matriz[10][62]={1};

matriz[9][62]={1};
matriz[8][62]={1};
matriz[7][62]={1};

matriz[7][61]={1};
matriz[7][60]={1};
matriz[7][59]={1};
matriz[7][58]={1};
matriz[7][57]={1};
matriz[7][56]={1};
matriz[7][55]={1};
matriz[7][54]={1};

matriz[14][75]={1};
matriz[14][74]={1};
matriz[14][73]={1};
matriz[14][72]={1};
matriz[14][71]={1};
matriz[14][70]={1};
matriz[14][69]={1};
matriz[14][68]={1};
matriz[14][67]={1};
matriz[14][66]={1};
matriz[14][65]={1};
matriz[14][64]={1};
matriz[14][63]={1};
matriz[14][62]={1};

matriz[15][62]={1};
matriz[16][62]={1};
matriz[17][62]={1};

matriz[17][61]={1};
matriz[17][60]={1};
matriz[17][59]={1};
matriz[17][58]={1};
matriz[17][57]={1};
matriz[17][56]={1};
matriz[17][55]={1};
matriz[17][54]={1};

matriz[13][54]={1};
matriz[12][54]={1};
matriz[11][54]={1};

matriz[4][39]={1};
matriz[5][39]={1};
matriz[6][39]={1};
matriz[7][39]={1};
matriz[8][39]={1};
matriz[9][39]={1};

matriz[9][38]={1};
matriz[9][37]={1};
matriz[9][36]={1};
matriz[9][35]={1};
matriz[9][34]={1};
matriz[9][33]={1};
matriz[9][32]={1};

matriz[9][40]={1};
matriz[9][41]={1};
matriz[9][42]={1};
matriz[9][43]={1};
matriz[9][44]={1};
matriz[9][45]={1};
matriz[9][46]={1};

matriz[20][39]={1};
matriz[19][39]={1};
matriz[18][39]={1};
matriz[17][39]={1};
matriz[16][39]={1};

matriz[15][32]={1};
matriz[15][33]={1};
matriz[15][34]={1};
matriz[15][35]={1};
matriz[15][36]={1};
matriz[15][37]={1};
matriz[15][38]={1};
matriz[15][39]={1};
matriz[15][40]={1};
matriz[15][41]={1};
matriz[15][42]={1};
matriz[15][43]={1};
matriz[15][44]={1};
matriz[15][45]={1};
matriz[15][46]={1};

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
    bool avance = true;

    start_color();
    init_pair(1,COLOR_GREEN,COLOR_BLACK);
    init_pair(2,COLOR_RED,COLOR_BLACK);
    init_pair(3,COLOR_CYAN,COLOR_BLACK);
    init_pair(4,COLOR_BLUE,COLOR_BLACK);
    init_pair(5,COLOR_YELLOW,COLOR_BLACK);
    init_pair(6,COLOR_MAGENTA,COLOR_BLACK);
    init_pair(6,COLOR_MAGENTA,COLOR_BLACK);

//Funciones
    while (avance)
        {
           int ch = getch();

    attron(COLOR_PAIR(3));
    mvprintw(8,12,"   LUEGO DE LA INFAME GUERRA MUNDIAL DE LOS CARACTERES");
    mvprintw(9,12,"            SOLOS DOS RAZAS SOBREVIVIERON.");
    mvprintw(10,12,"ESTAS DOS RAZAS, AHORA LUCHAN PARA GANAR LA SOBERANIA SUPREMA.");
    mvprintw(11,12,"     LOS CARACTERES ( X ) CONTRA LOS CARACTERES ( + )                ");
    mvprintw(12,12,"  FUERON PROTAGONISTAS DE DICHA LUCHA POR LA GLORIA.");

    mvprintw(13,12,"EL TIEMPO TRANSCURRIA, Y LA SUPERIORIDAD NUMERICA DE LAS ( X )  ");
    mvprintw(14,12,"              PROVOCO LA CAIDA DEL 99% DE LAS ( + )");
    mvprintw(15,12,"                       SIN EMBARGO...");
    mvprintw(16,12," UN ULTIMO GUERRERO SE NIEGA A CAER, VIVIENDO SU PROPIA LUCHA");
    mvprintw(17,12,"                  EN BUSCA DE VENGANZA...");

    attroff(COLOR_PAIR(3));

    mvprintw(23,22,"Presione ENTER para continuar.");

           if (ch == '\n')
                avance = false;
        }

    while(exit)
    {
        int puntuacion = 0;
        int enemigos_matar = 0;
        bool juego = false;
        bool creditos = false;
        bool controles = false;
        bool bio = false;
        bool bio2 = false;
        int nivel = 1;
        int escenario = 1;
        double matriz[25][80]={0};
        clear();
        marco2(matriz);
        menu(matriz,exit,juego,creditos,controles,bio);
        while (juego)
        {
        marco2(matriz);                               //Aca se podria poner un contador de nivel onda nivel = 1 y con ++ al final para usarlo en la funcion de
        if(escenario == 1)                                              //creacion de enemigos, haciendo un ciclo de enemigos y juego
        {
        escenario_cero(matriz);
        escenario_lv1(matriz);
        escenario++;
        }
        else if(escenario == 2)
        {
        escenario_cero(matriz);
        escenario_lv2(matriz);
        escenario++;
        }
        else if(escenario == 3)
        {
        escenario_cero(matriz);
        escenario_lv3(matriz);
        escenario = 1;
        }
        enemigos(matriz,nivel,enemigos_matar);                           //variable es nivel en que se encuentra uno, por ahora 1
        juego2(matriz,juego,puntuacion,enemigos_matar,nivel);
        nivel++;
        }
        while (bio){

                int ch = getch();

    attron(COLOR_PAIR(2));
    mvprintw(5,12, "                   -BIOGRAFIA-        ");
    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(1));
    mvprintw(6,12, " .............                    ");
    mvprintw(7,12, " .           .                    ");
    mvprintw(8,12, " .           .                    ");
    mvprintw(9,12, " .           .   <MASTER CROSS>   ");
    mvprintw(10,12," .           .                    ");
    mvprintw(11,12," .           .                    ");
    mvprintw(12,12," .............                               ");
    mvprintw(13,12,"                                            ");
    mvprintw(14,12," >Ultimo sobreviviente de los ( + )                    ");
    mvprintw(15,12," >Gran guerrero dotado de un arma multidireccional   ");
    mvprintw(16,12," >Protagonista y heroe de SMX");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(3));
    mvaddch(9,19,ACS_DIAMOND);
    mvaddch(8,19,ACS_DIAMOND);
    mvaddch(9,18,ACS_DIAMOND);
    mvaddch(9,20,ACS_DIAMOND);
    mvaddch(10,19,ACS_DIAMOND);
    attroff(COLOR_PAIR(3));

    mvprintw(23,22,"Presione ENTER para continuar.");

           if (ch == '\n')
                bio2 = true;

        while (bio2){
                int ch = getch();
                attron(COLOR_PAIR(2));
    mvprintw(5,12, "                   -BIOGRAFIA-        ");
attroff(COLOR_PAIR(2));

attron(COLOR_PAIR(1));
    mvprintw(6,12, " .............                    ");
    mvprintw(7,12, " .           .                    ");
    mvprintw(8,12, " .           .                    ");
    mvprintw(9,12, " .           .    < X CHAR >   ");
    mvprintw(10,12," .           .                    ");
    mvprintw(11,12," .           .                    ");
    mvprintw(12,12," .............                               ");
    mvprintw(13,12,"                                            ");
    mvprintw(14,12," >Unidad principal de la faccion ( X )  ");
    mvprintw(15,12," >Generalmente son muchos, y atacan en masa");
    mvprintw(16,12," >Carecen de inteligencia, solo los mueve su sed de sangre");
attroff(COLOR_PAIR(1));

attron(COLOR_PAIR(5));
    mvprintw(9,19, "X");
    attroff(COLOR_PAIR(5));

    mvprintw(23,22,"Presione ENTER para volver al menu.");

      if (ch == '\n')
                bio2 = false;
                bio = false;
        }
        }
        while (creditos)
        {
           int ch = getch();
           attron(COLOR_PAIR(5));
          mvprintw(4,16,"                   -CREDITOS-");
          attroff(COLOR_PAIR(5));
          attron(COLOR_PAIR(1));
          mvprintw(6,16,"Desarrollado por: ");
          attroff(COLOR_PAIR(1));

          mvprintw(8,16, "Jose Ignacio Smith");
          mvprintw(9,16, "Carlos Vidal Diaz");
          mvprintw(10,16, "Gabriel Colin Collao");
          attron(COLOR_PAIR(3));
          mvprintw(13,16,"Shot Many X (R) es una marca registrada, la aplicacion");
          mvprintw(14,16,"fue desarrollada a fin de presentar un proyecto para el");
          mvprintw(15,16,"ramo de PROGRAMACION, usando la libreria ncurses.");
          attroff(COLOR_PAIR(3));
          attron(COLOR_PAIR(2));
          mvprintw(18,16,"    ------FACULTAD DE INGENIERIA UDP------");
          attroff(COLOR_PAIR(2));
           mvprintw(21,20,"         Apreta Esc para salir.");
           if (ch == 27)
                creditos = false;
        }
        while (controles)
        {
           int ch = getch();

           attron(COLOR_PAIR(1));
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

           mvprintw(18,16,"3)Presiona cualquier tecla mientras disparas psra aumentar");
           mvprintw(19,16,"la velocidad de la bala.");
           attroff(COLOR_PAIR(1));

           attron(COLOR_PAIR(2));
           mvprintw(21,20,"Apreta Esc para salir.");
           attroff(COLOR_PAIR(2));
           if (ch == 27)
                controles = false;
        }
    }
    endwin();
    return 0;
}

