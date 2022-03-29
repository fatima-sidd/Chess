#include "GameData.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

COORD coord= {0,0}; // this is global variable
int FR, FC, TR,TC, True =0;
bool a=false, b= false;
int left_w_b=0, right_w_b=0, w_k=0, left_b_b=0, right_b_b=0, b_k=0, Prev_TC, Prev_TR;

bool    PP=false,
        PQ=false, PB=false, PR=false, PK=false,
        Enp=false,
        castling=false,
        GameActive=true;

struct Chess{
    GameData GameState;
    string PlayerNames[2];
    bool GameActive = false;
} Game;



void SetColor(int);
void gotoxy(int, int);
void printBox (int, int, int, int, int);

void drawKing (int, int, int);
void drawPawn (int, int, int);
void drawQueen (int, int, int);
void drawRook (int, int, int);
void drawBishop (int, int, int);
void drawKnight (int, int, int);

void ShowPieces (Chess);
void drawCurrentPiece (int, int, Chess);


//-----------------------------
void ShowPieces(Chess Game)
{
    //print pieces on board
    for(int r =0; r < 8; r++ ){
        for(int c = 0; c < 8; c++){
            switch(Game.GameState.Board[r][c].Code){
                case NONE:
                    {
                        gotoxy(2+c*6, 2+r*3);
                        cout<<"  ";
                        break;
                    }

                default:
                    if(Game.GameState.Board[r][c].PieceColor == BLACK)
                    {
                        SetColor(8);
                        gotoxy(2+c*6, 2+r*3);
                        cout<<"B";
                    }
                    else
                    {
                        SetColor(15);
                        gotoxy(2+c*6, 2+r*3);
                        cout<<"W";
                    }

                    switch(Game.GameState.Board[r][c].Code){
                    case PAWN:
                        cout<<"P";
                    break;

                    case ROOK:
                        cout<<"R";
                    break;

                    case KNIGHT:
                        cout<<"kN";
                    break;

                    case BISHOP:
                        cout<<"B";
                    break;

                    case QUEEN:
                        cout<<"Q";
                    break;

                    case KING:
                        cout<<"K";
                    break;
                    }
                break;
            }
        }
    }
}
//----------------------
void drawCurrentPiece (int col, int row, Chess Game)
{
    int colour;

    if(Game.GameState.Board[row][col].PieceColor == WHITE)
        colour = 15; //white
    else
        colour = 8; //dark grey


    switch(Game.GameState.Board[row][col].Code){

        case NONE:
            printBox(10, 50, 0, 12, 14);
        break;

        case PAWN:
            drawPawn(colour, 50, 0);
        break;

        case ROOK:
            drawRook(colour, 50, 0);
        break;

        case KNIGHT:
            drawKnight(colour, 50, 0);
        break;

        case BISHOP:
            drawBishop(colour, 50, 0);
        break;

        case QUEEN:
            drawQueen(colour, 50, 0);
        break;

        case KING:
            drawKing(colour, 50, 0);
        break;
    }
}


//----------------------
void drawPawn (int color, int x, int y)
{
    printBox(10, x, y, 12, 14);
    x+=2;
    y++;
    SetColor(color);
    gotoxy(x, y);
    cout<<"   PAWN"; gotoxy(x,++y);
    cout<<"        "; gotoxy(x,++y);
    cout<<"        "; gotoxy(x,++y);
    cout<<"        "; gotoxy(x,++y);
    cout<<"        "; gotoxy(x,++y);
    cout<<"        "; gotoxy(x,++y);
    cout<<"        "; gotoxy(x,++y);
    cout<<"     _    "; gotoxy(x,++y);
    cout<<"    (_)   "; gotoxy(x,++y);
    cout<<"   (___)  "; gotoxy(x,++y);
    cout<<"   _|_|_  "; gotoxy(x,++y);
    cout<<"  (_____)  "; gotoxy(x,++y);
    cout<<" (_______) "; gotoxy(x,++y);
    cout<<" /_______\\"; gotoxy(x,++y);;
}

//----------------------
void drawKing (int color, int x, int y)
{
    printBox(10, x, y, 12, 14);
    x+=2;
    y++;
    SetColor(color);
    gotoxy(x, y);
    cout<<"   KING"; gotoxy(x,++y);
    cout<<"          "; gotoxy(x,++y);
    cout<<"   .::."; gotoxy(x,++y);
    cout<<"   _::_"; gotoxy(x,++y);
    cout<<" _/____\\_ "; gotoxy(x,++y);
    cout<<" \\      /"; gotoxy(x,++y);
    cout<<"  \\____/ "; gotoxy(x,++y);
    cout<<"  (____)   "; gotoxy(x,++y);
    cout<<"   |  |    "; gotoxy(x,++y);
    cout<<"   |__|    "; gotoxy(x,++y);
    cout<<"  /    \\   "; gotoxy(x,++y);
    cout<<" (______)  "; gotoxy(x,++y);
    cout<<"(________) "; gotoxy(x,++y);
    cout<<"/________\\"; gotoxy(x,++y);
}

//----------------------
void drawQueen (int color, int x, int y)
{
    printBox(10, x, y, 12, 14);
    x+=2;
    y++;
    SetColor(color);
    gotoxy(x, y);
    cout<<"   QUEEN"; gotoxy(x,++y);
    cout<<"           "; gotoxy(x,++y);
    cout<<"           "; gotoxy(x,++y);
    cout<<"   _()_    "; gotoxy(x,++y);
    cout<<" _/____\\_ "; gotoxy(x,++y);
    cout<<" \\      /"; gotoxy(x,++y);
    cout<<"  \\____/ "; gotoxy(x,++y);
    cout<<"  (____)   "; gotoxy(x,++y);
    cout<<"   |  |    "; gotoxy(x,++y);
    cout<<"   |__|    "; gotoxy(x,++y);
    cout<<"  /    \\   "; gotoxy(x,++y);
    cout<<" (______)  "; gotoxy(x,++y);
    cout<<"(________) "; gotoxy(x,++y);
    cout<<"/________\\"; gotoxy(x,++y);
}

//------------------------
void drawKnight (int color, int x, int y)
{
    printBox(10, x, y, 12, 14);
    x+=2;
    y++;
    SetColor(color);
    gotoxy(x, y);
    cout<<"  KNIGHT"; gotoxy(x,++y);
    cout<<"           "; gotoxy(x,++y);
    cout<<"           "; gotoxy(x,++y);
    cout<<"   (\\=,  "; gotoxy(x,++y);
    cout<<"  //  .\\ "; gotoxy(x,++y);
    cout<<" (( \\_  \\"; gotoxy(x,++y);
    cout<<"  ))  `\\_)"; gotoxy(x,++y);
    cout<<" (/     \\ "; gotoxy(x,++y);
    cout<<"  | _.-'| "; gotoxy(x,++y);
    cout<<"   )___(  "; gotoxy(x,++y);
    cout<<"  (=====) "; gotoxy(x,++y);
    cout<<"  }====={ "; gotoxy(x,++y);
    cout<<" (_______)"; gotoxy(x,++y);
    cout<<" /_______\\"; gotoxy(x,++y);
}

//----------------------
void drawBishop (int color, int x, int y)
{
    printBox(10, x, y, 12, 14);
    x+=2;
    y++;
    SetColor(color);
    gotoxy(x, y);
    cout<<"  BISHOP"; gotoxy(x,++y);
    cout<<"          "; gotoxy(x,++y);
    cout<<"          "; gotoxy(x,++y);
    cout<<"    _O    "; gotoxy(x,++y);
    cout<<"   / //\\  "; gotoxy(x,++y);
    cout<<"  {     } "; gotoxy(x,++y);
    cout<<"   \\___/  "; gotoxy(x,++y);
    cout<<"   (___)  "; gotoxy(x,++y);
    cout<<"    |_|   "; gotoxy(x,++y);
    cout<<"    |_|   "; gotoxy(x,++y);
    cout<<"   /   \\  "; gotoxy(x,++y);
    cout<<"  (_____) "; gotoxy(x,++y);
    cout<<" (_______)"; gotoxy(x,++y);
    cout<<" /_______\\"; gotoxy(x,++y);
}

//----------------------
void drawRook (int color, int x, int y)
{
    printBox(10, x, y, 12, 14);
    x+=2;
    y++;
    SetColor(color);
    gotoxy(x, y);
    cout<<"   ROOK"; gotoxy(x,++y);
    cout<<"          "; gotoxy(x,++y);
    cout<<"          "; gotoxy(x,++y);
    cout<<"  _  _  _  "; gotoxy(x,++y);
    cout<<" | || || | "; gotoxy(x,++y);
    cout<<" |_______| "; gotoxy(x,++y);
    cout<<" \\__ ___ / "; gotoxy(x,++y);
    cout<<"  |___|_|  "; gotoxy(x,++y);
    cout<<"  |_|___|  "; gotoxy(x,++y);
    cout<<"  |___|_|  "; gotoxy(x,++y);
    cout<<"  |_|___|  "; gotoxy(x,++y);
    cout<<"  (_____) "; gotoxy(x,++y);
    cout<<" (_______)"; gotoxy(x,++y);
    cout<<" /_______\\"; gotoxy(x,++y);
}

//----------------------
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//----------------------

void printGrid (int color, int x, int y)
{
    SetColor(color);

    gotoxy(x, y);


    //top row
    cout<<char(218);
    for(int j=1; j<=8; j++)
    {
        for(int i=1; i<=5; i++)
            cout<<char(196);
        if (j<8)
            cout<<char(194);
        else
            cout<<char(191);
    }

    //middle rows
    for (int row=1; row<=8; row++)
    {
        y++;
        gotoxy(x,y);
        //print a row with blanks
        cout<<char(179);
        for (int col=1; col<=8; col++)
        {
            for(int i=1; i<=5; i++)
                cout<<" ";

            cout<<char(179);
        }

        y++;
        gotoxy(x,y);
        //print a row with blanks
        cout<<char(179);
        for (int col=1; col<=8; col++)
        {
            for(int i=1; i<=5; i++)
                cout<<" ";

            cout<<char(179);
        }


        if (row<8)
        {
            y++;
            gotoxy(x,y);
            //print a row with joining + signs
            cout<<char(195);
            for (int col=1; col<=8; col++)
            {
                for(int i=1; i<=5; i++)
                    cout<<char(196);
                if (col<8)
                    cout<<char(197);
                else
                    cout<<char(180);
            }
        }
    }


    //bottom row
    y++;
    gotoxy(x,y);
    cout<<char(192);
    for(int j=1; j<=8; j++)
    {
        for(int i=1; i<=5; i++)
            cout<<char(196);
        if (j<8)
            cout<<char(193);
        else
            cout<<char(217);
    }

    SetColor(15);
}


//----------------------

void printBox (int color, int x, int y, int width, int height)
{
    SetColor(color);

    gotoxy(x, y);

    cout<<char(201);

    for(int i=1; i<=width; i++)
        cout<<char(205);

    cout<<char(187);

    for(int row=1; row<=height; row++)
    {
        y++;
        gotoxy(x,y);

        cout<<char(186);
        for(int i=1; i<=width; i++)
            cout<<" ";
        cout<<char(186);
    }

    y++;
    gotoxy(x,y);

    cout<<char(200);

    for(int i=1; i<=width; i++)
        cout<<char(205);

    cout<<char(188);

    SetColor(15);
}

//---------------------
void SetColor(int ForgC)
 {
     WORD wColor;

      HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                 //Mask out all but the background attribute, and add in the forgournd     color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
 }


void PromotePawn(PieceType P){
    // A special move that is allowed under special conditions
}

//--------------------


bool isValidMove(GameData& Game, chessMove Move){
    // this function will return true if the move specified by the Move parameter is a valid move
    // You might make more functions to breakdown the task of this function into subtasks
    FR = Move.FromRow;
    FC = Move.FromColumn;
    TR = Move.ToRow;
    TC = Move.ToColumn;

    if(Game.Board[FR][FC].Code== PAWN )
    {
        if(Game.TurningPlayer== WHITE)
        {
            if (FR==6)
            {
                if( (TR == FR-2 && TC == FC) && (Game.Board[TR][TC].Code == NONE) && (Game.Board[FR][FC].PieceColor == WHITE) )
                {
                    True =1;
                    return true;
                }
            }

            if( (TR== FR-1 && TC == FC) && (Game.Board[TR][TC].Code == NONE) && (Game.Board[FR][FC].PieceColor ==WHITE ))
            {
                True =1;
                return true;
            }

            if (((TR== FR-1 && TC == FC+1) ||(TR== FR-1 && TC == FC-1)) &&  Game.Board[TR][TC].PieceColor == BLACK && Game.Board[TR][TC].Code != NONE && (Game.Board[FR][FC].PieceColor == WHITE ))
            {
                True =1;
                return true;
            }

            if (Enp==true)
            {
                if (((TR== FR-1 && TC == FC+1) ||(TR== FR-1 && TC == FC-1))&&   (Game.Board[TR][TC].PieceColor == NONE ) && (Game.Board[FR][FC].PieceColor ==WHITE ) && (Game.Board[TR+1][TC].PieceColor ==BLACK )  )
                {
                    True =1;
                    return true;
                }
            }
        }
        if(Game.TurningPlayer== BLACK)
        {

            if(  (TR== FR+1 && TC == FC) &&   (Game.Board[TR][TC].Code == NONE) && (Game.Board[FR][FC].PieceColor ==BLACK )  )
            {
                 True =1;
                 return true;
            }

            if (((TR== FR+1 && TC == FC+1) ||(TR== FR+1 && TC == FC-1)) &&   ((Game.Board[TR][TC].PieceColor ==WHITE ) && Game.Board[TR][TC].Code!=NONE && (Game.Board[FR][FC].PieceColor ==BLACK ) ) )
            {
                True =1;
                return true;
            }

            if (FR==1)
            {
                if( (TR== FR+2 && TC == FC) &&   (Game.Board[TR][TC].Code == NONE)&& (Game.Board[FR][FC].PieceColor ==BLACK )  )
                {
                    True =1;
                    return true;
                }
            }

            if (Enp==true)
            {
                if (((TR== FR+1 && TC == FC+1) ||(TR== FR+1 && TC == FC-1))&&   (Game.Board[TR][TC].PieceColor == NONE ) && (Game.Board[FR][FC].PieceColor ==BLACK ) && (Game.Board[TR-1][TC].PieceColor ==WHITE )  )
                {
                    True =1;
                    return true;
                }
            }
        }
    }
    if(Game.Board[FR][FC].Code== ROOK )
    {
        int i=0;
        if((TR == FR && TC== FC) || (TR!= FR && TC!=FC))//if trying to move to same box OR somewhere diagonal
        {
            True = 0;
            return false;
        }

        if( TR == FR)
        {
            if ( TC > FC)
            {
                for( i= FC +1; i< TC;i++)
                {
                    if( Game.Board[FR][i].Code != NONE)
                    {
                        True = 0;
                        return false;
                    }
                }
                if(Game.TurningPlayer== WHITE)
                {
                    if( ((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == BLACK ) ) &&  (Game.Board[FR][FC].PieceColor == WHITE ) )
                    {
                           True = 1;
                           return true;
                    }
                }
                if(Game.TurningPlayer== BLACK)
                {
                    if (((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == WHITE ) ) &&  (Game.Board[FR][FC].PieceColor == BLACK ) )
                    {
                         True = 1;
                         return true;
                    }
                }
            }
            if ( TC <FC)
            {
                for( i= FC -1; i> TC;i--)
                {
                    if( Game.Board[FR][i].Code != NONE)
                    {
                        True = 0;
                        return false;
                    }
                }

                if(Game.TurningPlayer== WHITE)
                {
                    if (((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == BLACK ) ) &&  (Game.Board[FR][FC].PieceColor == WHITE ) )
                    {
                        True = 1;
                        return true;
                    }

                }
                if(Game.TurningPlayer== BLACK)
                {
                    if (((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == WHITE ) ) &&  (Game.Board[FR][FC].PieceColor == BLACK ) )
                    {
                        True = 1;
                        return true;
                    }
                }
            }
        }

        if( TC == FC)
        {
            if ( TR > FR)
            {
                for( i= FR +1; i< TR;i++)
                {
                    if( Game.Board[i][FC].Code != NONE)
                    {
                        True = 0;
                        return false;
                    }
                }

                if(Game.TurningPlayer== WHITE)
                {
                    if (((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == BLACK ) ) &&  (Game.Board[FR][FC].PieceColor == WHITE ) )
                    {
                        True = 1;
                        return true;
                    }
                }

                if(Game.TurningPlayer== BLACK)
                 {   if (((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == WHITE ) )   &&  (Game.Board[FR][FC].PieceColor == BLACK ) )
                      {
                         True = 1;
                         return true;
                      }

                 }
            }

            if ( TR <FR)
            {
                for( i= FR -1; i> TR;i--)
                {
                    if( Game.Board[i][FC].Code != NONE)
                    {
                        True = 0;
                        return false;
                    }
                }

                if(Game.TurningPlayer== WHITE)
                {
                    if(((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == BLACK ) )  &&  (Game.Board[FR][FC].PieceColor == WHITE ) )
                    {
                        True = 1;
                        return true;
                    }
                 }

                if(Game.TurningPlayer== BLACK)
                {
                    if (((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == WHITE ) )  &&  (Game.Board[FR][FC].PieceColor == BLACK ) )
                    {
                        True = 1;
                        return true;
                    }
                }
            }
        }
    }



    if(Game.Board[FR][FC].Code== BISHOP )
    {
        if(abs(TR-FR)==abs(TC-FC))  //PROPER DIAGONAL VALUE ENTERED
        {
            int i=0,j=0;
            if(TR<FR && TC> FC)
            {
                for(i = FR-1,j=FC+1; i>TR && j< TC; i--,j++)
                {
                    if( Game.Board[i][j].Code != NONE)
                    {
                     True = 0;
                     return false;
                    }
                }
                if(Game.TurningPlayer== WHITE)
                {
                    if(((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == BLACK ) )   &&  (Game.Board[FR][FC].PieceColor == WHITE ) )
                    {
                        True = 1;
                        return true;
                    }
                }
                if(Game.TurningPlayer== BLACK)
                {
                    if (((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == WHITE ) )   &&  (Game.Board[FR][FC].PieceColor == BLACK ) )
                    {
                        True = 1;
                        return true;
                    }
                }
            }
            if(TR<FR && TC< FC)
            {
                for(i = FR-1,j=FC-1; i>TR && j> TC; i--,j--)
                {
                    if( Game.Board[i][j].Code != NONE)
                    {
                        True = 0;
                        return false;
                    }
                }
                if(Game.TurningPlayer== WHITE)
                {
                    if (((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == BLACK ) )   &&  (Game.Board[FR][FC].PieceColor == WHITE ) )
                    {
                        True = 1;
                        return true;
                    }
                }
                if(Game.TurningPlayer== BLACK)
                {
                    if (((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == WHITE ) )   &&  (Game.Board[FR][FC].PieceColor == BLACK ) )
                    {
                        True = 1;
                        return true;
                    }
                }
            }
            if(TR>FR && TC< FC)
            {
                for(i = FR+1,j=FC-1; i<TR && j> TC; i++,j--)
                {
                    if( Game.Board[i][j].Code != NONE)
                    {
                        True = 0;
                        return false;
                    }
                }
                if(Game.TurningPlayer== WHITE)
                {
                    if(((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == BLACK ) )   &&  (Game.Board[FR][FC].PieceColor == WHITE ) )
                    {
                        True = 1;
                        return true;
                    }

                }
                if(Game.TurningPlayer== BLACK)
                {
                    if (((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == WHITE ) )   &&  (Game.Board[FR][FC].PieceColor == BLACK ) )
                    {
                        True = 1;
                        return true;
                    }
                }
            }
            if(TR>FR && TC> FC)
            {
                for(i = FR+1,j=FC+1; i<TR && j< TC; i++,j++)
                {
                    if( Game.Board[i][j].Code != NONE)
                    {
                        True = 0;
                        return false;
                    }
                }
                if(Game.TurningPlayer== WHITE)
                {
                    if (((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == BLACK ) )   &&  (Game.Board[FR][FC].PieceColor == WHITE ) )
                    {
                        True = 1;
                        return true;
                    }
                }
                if(Game.TurningPlayer== BLACK)
                {
                    if (((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == WHITE ) )   &&  (Game.Board[FR][FC].PieceColor == BLACK ) )
                    {
                        True = 1;
                        return true;
                    }
                }
            }
        }
        else
        {
            True = 0;
            return  false;
        }
    }

    if(Game.Board[FR][FC].Code== KNIGHT )
    {
        if(Game.TurningPlayer== WHITE   &&  (Game.Board[FR][FC].PieceColor == WHITE ) )
        {
            if((TR== FR && TC== FC))
            {
                True=0;
                return false;
            }

            if(((TR==FR + 1 && TC == FC + 2) || (TR==FR + 2 && TC == FC + 1) || (TR==FR + 1 && TC == FC - 2) ||
                (TR==FR + 2 && TC == FC - 1) || (TR==FR - 1  && TC == FC + 2) || (TR==FR - 2 && TC == FC + 1) ||
                (TR==FR - 1  && TC == FC - 2 ) || (TR==FR - 2 && TC == FC - 1)) && (( Game.Board[TR][TC].Code== NONE ) ||  (Game.Board[TR][TC].PieceColor== BLACK)) )
            {
                True=1;
                return true;
            }
            else
            {
                True=0;
                return false;
            }
        }

        if(Game.TurningPlayer== BLACK   &&  (Game.Board[FR][FC].PieceColor == BLACK ) )
        {

            if((TR== FR && TC== FC))
            {
                True=0;
                return false;
            }
            if(((TR==FR + 1 && TC == FC + 2) || (TR==FR + 2 && TC == FC + 1) || (TR==FR + 1 && TC == FC - 2) ||
               (TR==FR + 2 && TC == FC - 1) || (TR==FR - 1  && TC == FC + 2) || (TR==FR - 2 && TC == FC + 1) ||
               (TR==FR - 1  && TC == FC - 2 ) || (TR==FR - 2 && TC == FC - 1)) && (( Game.Board[TR][TC].Code== NONE ) ||  (Game.Board[TR][TC].PieceColor== WHITE)) )
            {
                True=1;
                return true;
            }
            else
            {
                True=0;
                return false;
            }
        }
    }

    if(Game.Board[FR][FC].Code== QUEEN )
    {
        int i=0 , j=0;

        if( TR == FR)
        {
            if ( TC > FC)
            {
                for( i= FC +1; i< TC;i++)
                {
                    if( Game.Board[FR][i].Code != NONE)
                    {
                        True = 0;
                        return false;
                    }
                }
                if(Game.TurningPlayer== WHITE)
                {
                    if (((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == BLACK ) )   &&  (Game.Board[FR][FC].PieceColor == WHITE ) )
                    {
                        True = 1;
                        return true;
                    }
                }
                if(Game.TurningPlayer== BLACK)
                {
                    if (((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == WHITE ) )   &&  (Game.Board[FR][FC].PieceColor == BLACK ) )
                    {
                        True = 1;
                        return true;
                    }
                }
            }
            if ( TC <FC)
            {
                for( i= FC -1; i> TC;i--)
                {
                    if( Game.Board[FR][i].Code != NONE)
                    {
                        True = 0;
                        return false;
                    }
                }
                if(Game.TurningPlayer== WHITE)
                {
                    if (((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == BLACK ) )   &&  (Game.Board[FR][FC].PieceColor == WHITE ) )
                    {
                        True = 1;
                        return true;
                    }
                }
                if(Game.TurningPlayer== BLACK)
                {
                    if (((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == WHITE ) )   &&  (Game.Board[FR][FC].PieceColor == BLACK ) )
                    {
                        True = 1;
                        return true;
                    }
                }
            }
        }

        if( TC == FC)
        {
            if ( TR > FR)
            {
                for( i= FR +1; i< TR;i++)
                {
                     if( Game.Board[i][FC].Code != NONE)
                    {
                        True = 0;
                        return false;
                    }
                }
                if(Game.TurningPlayer== WHITE)
                {
                    if(((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == BLACK ) )   &&  (Game.Board[FR][FC].PieceColor == WHITE ) )
                    {
                        True = 1;
                        return true;
                    }
                }
                if(Game.TurningPlayer== BLACK)
                {
                    if (((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == WHITE ) )   &&  (Game.Board[FR][FC].PieceColor == BLACK ) )
                    {
                        True = 1;
                        return true;
                    }
                }
            }
            if ( TR <FR)
            {
                for( i= FR -1; i> TR;i--)
                {
                    if( Game.Board[i][FC].Code != NONE)
                    {
                        True = 0;
                        return false;
                    }
                }

                if(Game.TurningPlayer== WHITE)
                {
                    if (((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == BLACK ) )   &&  (Game.Board[FR][FC].PieceColor == WHITE ) )
                    {
                        True = 1;
                        return true;
                    }
                }
                if(Game.TurningPlayer== BLACK)
                {
                    if(((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == WHITE ) )   &&  (Game.Board[FR][FC].PieceColor == BLACK ) )
                    {
                        True = 1;
                        return true;
                    }
                }
            }
        }

        if(abs(TR-FR)==abs(TC-FC))  //PROPER DIAGONAL VALUE ENTERED
        {
            if(TR<FR && TC> FC)
            {
                for(i = FR-1,j=FC+1; i>TR && j< TC; i--,j++)
                {
                    if( Game.Board[i][j].Code != NONE)
                    {
                        True = 0;
                        return false;
                    }
                }
                if(Game.TurningPlayer== WHITE)
                {
                    if (((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == BLACK ) )   &&  (Game.Board[FR][FC].PieceColor == WHITE ) )
                    {
                        True = 1;
                        return true;
                    }
                }
                if(Game.TurningPlayer== BLACK)
                {
                    if (((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == WHITE ) )   &&  (Game.Board[FR][FC].PieceColor == BLACK ) )
                    {
                        True = 1;
                        return true;
                    }
                }
            }
            if(TR<FR && TC< FC)
            {
                for(i = FR-1,j=FC-1; i>TR && j> TC; i--,j--)
                {
                    if( Game.Board[i][j].Code != NONE)
                    {
                        True = 0;
                        return false;
                    }
                }
                if(Game.TurningPlayer== WHITE)
                {
                    if (((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == BLACK ) )   &&  (Game.Board[FR][FC].PieceColor == WHITE ) )
                    {
                        True = 1;
                        return true;
                    }
                }
                if(Game.TurningPlayer== BLACK)
                {
                    if(((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == WHITE ) )   &&  (Game.Board[FR][FC].PieceColor == BLACK ) )
                    {
                        True = 1;
                        return true;
                    }
                }
            }
            if(TR>FR && TC< FC)
            {
                for(i = FR+1,j=FC-1; i<TR && j> TC; i++,j--)
                {
                    if( Game.Board[i][j].Code != NONE)
                    {
                        True = 0;
                        return false;
                    }
                }
                if(Game.TurningPlayer== WHITE)
                {
                    if(((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == BLACK ) )   &&  (Game.Board[FR][FC].PieceColor == WHITE ) )
                    {
                        True = 1;
                        return true;
                    }
                }
                if(Game.TurningPlayer== BLACK)
                {
                    if(((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == WHITE ) )   &&  (Game.Board[FR][FC].PieceColor == BLACK ) )
                    {
                        True = 1;
                        return true;
                    }
                }
            }
            if(TR>FR && TC> FC)
            {
                for(i = FR+1,j=FC+1; i<TR && j< TC; i++,j++)
                {
                    if( Game.Board[i][j].Code != NONE)
                    {
                        True = 0;
                        return false;
                    }
                }
                if(Game.TurningPlayer== WHITE)
                {
                    if (((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == BLACK ) )   &&  (Game.Board[FR][FC].PieceColor == WHITE ) )
                    {
                        True = 1;
                        return true;
                    }
                }
                if(Game.TurningPlayer== BLACK)
                {
                    if(((Game.Board[TR][TC].Code== NONE ) || (Game.Board[TR][TC].PieceColor == WHITE ) )   &&  (Game.Board[FR][FC].PieceColor == BLACK ) )
                    {
                        True = 1;
                        return true;
                    }
                }
            }
        }
        else
        {
            True = 0;
            return false;
        }
    }

    if(Game.Board[FR][FC].Code== KING)
    {
        if(Game.TurningPlayer== WHITE)
        {
            if (TC<FC && FC==4 && TC==2
                && (isfacingCheck(Game, WHITE)==false)
                && w_k==0 && left_w_b==0
                && Game.Board[7][1].Code == NONE && Game.Board[7][2].Code == NONE &&  Game.Board[7][3].Code == NONE)
            {
                castling=true;
                True=1;
                return true;
            }

            if (TC>FC && FC==4 && TC==6
                && (isfacingCheck(Game, WHITE)==false)
                && w_k==0 && left_w_b==0
                && Game.Board[7][5].Code == NONE && Game.Board[7][6].Code == NONE )
            {
                castling=true;
                True=1;
                return true;
            }

            if(((TC==FC+1 && TR==FR  )||(TC==FC-1 && TR==FR )||
            (TC==FC   && TR==FR+1)||(TC==FC   && TR==FR-1)||
            (TC==FC-1 && TR==FR+1)||(TC==FC-1 && TR==FR-1)||
            (TC==FC+1 && TR==FR+1)||(TC==FC+1 && TR==FR-1))&&
            ((Game.Board[TR][TC].Code == NONE)||(Game.Board[TR][TC].PieceColor == BLACK ))    &&  (Game.Board[FR][FC].PieceColor == WHITE ) )
            {
                True=1;
                return true;
            }
            else
            {
                True=0;
                return false ;
            }
        }
        if(Game.TurningPlayer== BLACK)
        {
            if (TC<FC && FC==4 && TC==2
                && (isfacingCheck(Game, BLACK)==false)
                && b_k==0 && left_b_b==0
                && Game.Board[0][1].Code == NONE && Game.Board[0][2].Code == NONE &&  Game.Board[0][3].Code == NONE)
            {
                castling=true;
                True=1;
                return true;
            }

            if (TC>FC && FC==4 && TC==6
                && (isfacingCheck(Game, BLACK)==false)
                && b_k==0 && right_b_b==0
                && Game.Board[0][5].Code == NONE && Game.Board[0][6].Code == NONE )
            {
                castling=true;
                True=1;
                return true;
            }


            if(((TC==FC+1 && TR==FR  )||(TC==FC-1 && TR==FR )||
            (TC==FC   && TR==FR+1)||(TC==FC   && TR==FR-1)||
            (TC==FC-1 && TR==FR+1)||(TC==FC-1 && TR==FR-1)||
            (TC==FC+1 && TR==FR+1)||(TC==FC+1 && TR==FR-1))&&
            ((Game.Board[TR][TC].Code == NONE)||(Game.Board[TR][TC].PieceColor == WHITE ) )    &&  (Game.Board[FR][FC].PieceColor == BLACK ) )
            {
                True=1;
                return true;
            }
            else
            {
                True =0;
                return false ;
            }
        }
    }
    return false;
}

//--------------------------------

int MakeMove(GameData& Game, chessMove Move)
{

    //Function to make a move on the board
    // It will return 0 if the move is valid and a code of error to specify why the move is not valid otherwise
    // returns 1 if current player could face check
    // returns -1 if Invalid move

    int tempCol, tempRow;
    chessPiece tempPiece;
    if (PP==true)
    {
        if (PQ==true)
        {
            Move.PawnPromotedTo=QUEEN;
            PQ=false;
        }

        if (PB==true)
        {
            Move.PawnPromotedTo=BISHOP;
            PB=false;
        }

        if (PR==true)
        {
            Move.PawnPromotedTo=ROOK;
            PR=false;
        }

        if (PK==true)
        {
            Move.PawnPromotedTo=KNIGHT;
            PK=false;
        }

        Game.Board[TR][TC].Code = Move.PawnPromotedTo;
        Game.Board[TR][TC].PieceColor = Game.Board[FR][FC].PieceColor;

        PP=false;
        return 3;

    }


    if (isValidMove(Game, Move)==true)
    {
        int ctr=0;
        if (castling==true)
        {

            //WHITE LEFT BISHOP
            if (Game.Board[FR][FC].Code ==KING
                && Game.Board[FR][FC].PieceColor ==WHITE
                && TC<FC && FC==4 && TC==2
                && w_k==0 && left_w_b==0
                && Game.Board[7][1].Code == NONE && Game.Board[7][2].Code ==  NONE &&  Game.Board[7][3].Code == NONE)
            {
                //BLACK ON MID POS
                Game.Board[7][3].Code = Game.Board[7][4].Code;
                Game.Board[7][3].PieceColor = Game.Board[7][4].PieceColor;
                Game.Board[7][4].Code = NONE;

                //if check on mid pos
                if (isfacingCheck(Game, WHITE)==true)
                {
                    Game.Board[7][4].Code = Game.Board[7][3].Code;
                    Game.Board[7][4].PieceColor = Game.Board[7][3].PieceColor;
                    Game.Board[7][3].Code = NONE;
                    ctr++;
                }
                //if no check on mid pos
                else
                {
                    //black on last pos
                    Game.Board[7][2].Code = Game.Board[7][3].Code;
                    Game.Board[7][2].PieceColor = Game.Board[7][3].PieceColor;
                    Game.Board[7][3].Code = NONE;
                    if (isfacingCheck(Game, WHITE)==true)
                    {
                        Game.Board[7][4].Code = Game.Board[7][2].Code;
                        Game.Board[7][4].PieceColor = Game.Board[7][2].PieceColor;
                        Game.Board[7][2].Code = NONE;
                        ctr++;
                    }
                    else
                    {
                        Game.Board[7][3].Code = Game.Board[7][0].Code;
                        Game.Board[7][3].PieceColor = Game.Board[7][0].PieceColor;
                        Game.Board[7][0].Code = NONE;
                    }
                }

            }

            //WHITE RIGHT BISHOP
            if (Game.Board[FR][FC].Code ==KING
                && Game.Board[FR][FC].PieceColor ==WHITE
                && TC>FC && FC==4 && TC==6
                && w_k==0 && right_w_b==0
                && Game.Board[7][5].Code == NONE && Game.Board[7][6].Code ==  NONE )
            {
                //BLACK ON MID POS
                Game.Board[7][5].Code = Game.Board[7][4].Code;
                Game.Board[7][5].PieceColor = Game.Board[7][4].PieceColor;
                Game.Board[7][4].Code = NONE;

                //if check on mid pos
                if (isfacingCheck(Game, WHITE)==true)
                {
                    Game.Board[7][4].Code = Game.Board[7][5].Code;
                    Game.Board[7][4].PieceColor = Game.Board[7][5].PieceColor;
                    Game.Board[7][5].Code = NONE;
                    ctr++;
                }
                //if no check on mid pos
                else
                {
                    //black on last pos
                    Game.Board[7][6].Code = Game.Board[7][5].Code;
                    Game.Board[7][6].PieceColor = Game.Board[7][5].PieceColor;
                    Game.Board[7][5].Code = NONE;
                    if (isfacingCheck(Game, WHITE)==true)
                    {
                        Game.Board[7][4].Code = Game.Board[7][6].Code;
                        Game.Board[7][4].PieceColor = Game.Board[7][6].PieceColor;
                        Game.Board[7][6].Code = NONE;
                        ctr++;
                    }
                    else
                    {
                        Game.Board[7][5].Code = Game.Board[7][7].Code;
                        Game.Board[7][5].PieceColor = Game.Board[7][7].PieceColor;
                        Game.Board[7][7].Code = NONE;
                    }
                }

            }

            //BLACK LEFT BISHOP
            if (Game.Board[FR][FC].Code ==KING
                && Game.Board[FR][FC].PieceColor ==BLACK
                && TC<FC && FC==4 && TC==2
                && b_k==0 && left_b_b==0
                && Game.Board[0][1].Code == NONE && Game.Board[0][2].Code ==  NONE &&  Game.Board[0][3].Code == NONE)
            {
                //KING ON MID POS
                Game.Board[0][3].Code = Game.Board[0][4].Code;
                Game.Board[0][3].PieceColor = Game.Board[0][4].PieceColor;
                Game.Board[0][4].Code = NONE;

                //if check on mid pos
                if (isfacingCheck(Game, BLACK)==true)
                {
                    Game.Board[0][4].Code = Game.Board[0][3].Code;
                    Game.Board[0][4].PieceColor = Game.Board[0][3].PieceColor;
                    Game.Board[0][3].Code = NONE;
                    ctr++;
                }
                //if no check on mid pos
                else
                {
                    //KING on last pos
                    Game.Board[0][2].Code = Game.Board[0][3].Code;
                    Game.Board[0][2].PieceColor = Game.Board[0][3].PieceColor;
                    Game.Board[0][3].Code = NONE;
                    if (isfacingCheck(Game, BLACK)==true)
                    {
                        Game.Board[0][4].Code = Game.Board[0][2].Code;
                        Game.Board[0][4].PieceColor = Game.Board[0][2].PieceColor;
                        Game.Board[0][2].Code = NONE;
                        ctr++;
                    }
                    else
                    {
                        PQ=true;
                        Game.Board[0][3].Code = Game.Board[0][0].Code;
                        Game.Board[0][3].PieceColor = Game.Board[0][0].PieceColor;
                        Game.Board[0][0].Code = NONE;
                    }
                }

            }

            //BLACK RIGHT BISHOP
            if (Game.Board[FR][FC].Code ==KING
                && Game.Board[FR][FC].PieceColor ==BLACK
                && TC>FC && FC==4 && TC==6
                && b_k==0 && right_b_b==0
                && Game.Board[0][5].Code == NONE && Game.Board[0][6].Code ==  NONE )
            {
                //BLACK ON MID POS
                Game.Board[0][5].Code = Game.Board[0][4].Code;
                Game.Board[0][5].PieceColor = Game.Board[0][4].PieceColor;
                Game.Board[0][4].Code = NONE;

                //if check on mid pos
                if (isfacingCheck(Game, BLACK)==true)
                {
                    Game.Board[0][4].Code = Game.Board[0][5].Code;
                    Game.Board[0][4].PieceColor = Game.Board[0][5].PieceColor;
                    Game.Board[0][5].Code = NONE;
                    ctr++;
                }
                //if no check on mid pos
                else
                {
                    //black on last pos
                    Game.Board[0][6].Code = Game.Board[0][5].Code;
                    Game.Board[0][6].PieceColor = Game.Board[0][5].PieceColor;
                    Game.Board[0][5].Code = NONE;
                    if (isfacingCheck(Game, BLACK)==true)
                    {
                        Game.Board[0][4].Code = Game.Board[0][6].Code;
                        Game.Board[0][4].PieceColor = Game.Board[0][6].PieceColor;
                        Game.Board[0][6].Code = NONE;
                        ctr++;
                    }
                    else
                    {
                        Game.Board[0][5].Code = Game.Board[0][7].Code;
                        Game.Board[0][5].PieceColor = Game.Board[0][7].PieceColor;
                        Game.Board[0][7].Code = NONE;
                    }
                }

            }


            castling=false;
            if (ctr!=0)
                return -1;

        }


        else
        {
            tempPiece.Code = Game.Board[TR][TC].Code;
            tempPiece.PieceColor = Game.Board[TR][TC].PieceColor;

            //making move

            Game.Board[TR][TC].Code = Game.Board[FR][FC].Code;
            Game.Board[TR][TC].PieceColor = Game.Board[FR][FC].PieceColor;
            Game.Board[FR][FC].Code = NONE;
        }


        if (Enp==true)
        {
        Enp=false;
        if (( FR==4 && TR==5 && TC==Prev_TC ) || (FR==3 && TR==2 && TC==Prev_TC))
        {
            Game.Board[Prev_TR][Prev_TC].Code = NONE;
        }
        }

    if (Game.Board[TR][TC].Code ==ROOK&& Game.Board[TR][TC].PieceColor ==WHITE && FC == 0)
        left_w_b++;

    if (Game.Board[TR][TC].Code ==ROOK && Game.Board[TR][TC].PieceColor ==WHITE && FC == 7)
        right_w_b++;

    if (Game.Board[TR][TC].Code ==ROOK&& Game.Board[TR][TC].PieceColor ==BLACK && FC == 0)
        left_b_b++;

    if (Game.Board[TR][TC].Code ==ROOK && Game.Board[TR][TC].PieceColor ==BLACK && FC == 7)
        right_b_b++;

    if (Game.Board[TR][TC].Code ==KING && Game.Board[TR][TC].PieceColor ==WHITE)
        w_k++;

    if (Game.Board[TR][TC].Code ==KING && Game.Board[TR][TC].PieceColor ==BLACK)
        b_k++;

    //checking if enpassant
    if (Game.Board[TR][TC].Code== PAWN){
        if ((TR==4 && FR==6 && Game.TurningPlayer== WHITE) || (TR== 3 && FR==1 && Game.TurningPlayer== BLACK))
        {
            Prev_TC=TC;
            Prev_TR=TR;
            Enp=true;
        }
    }

        if(isfacingCheck(Game, Game.TurningPlayer))
        {  if(Game.TurningPlayer== BLACK && a== true && b!= true){
            tempRow = FR;
            FR = TR;
            TR = tempRow;

            tempCol = FC;
            FC = TC;
            TC = tempCol;

            //reversing move
            Game.Board[TR][TC].Code = Game.Board[FR][FC].Code;
            Game.Board[TR][TC].PieceColor = Game.Board[FR][FC].PieceColor;
            Game.Board[FR][FC].Code = tempPiece.Code;
            Game.Board[FR][FC].PieceColor = tempPiece.PieceColor;

            return 1;
          }
          if( Game.TurningPlayer== BLACK && a!= true && b== true)
          {
              return 2;
          }

          if(Game.TurningPlayer== WHITE && a!= true && b== true){
            tempRow = FR;
            FR = TR;
            TR = tempRow;

            tempCol = FC;
            FC = TC;
            TC = tempCol;

            //reversing move
            Game.Board[TR][TC].Code = Game.Board[FR][FC].Code;
            Game.Board[TR][TC].PieceColor = Game.Board[FR][FC].PieceColor;
            Game.Board[FR][FC].Code = tempPiece.Code;
            Game.Board[FR][FC].PieceColor = tempPiece.PieceColor;

            return 1;
          }
          if( Game.TurningPlayer== WHITE && a== true && b!= true)
          {
              return 2;
          }
        }
        else //PROPER MOVE ALLOWED
        {
           return 0;

        }



    }
    else //Invalid Move - Error Code -1
        return -1;
}


void initGame(GameData& Game){

    for(int r = 0; r < 2; r++)
        for(int c= 0; c < 8; c++ )
            Game.Board[r][c].PieceColor = BLACK;

    for(int r = 2; r < 6; r++)
        for(int c= 0; c < 8; c++ )
            Game.Board[r][c].Code = NONE;

    for(int r = 6; r < 8; r++)
        for(int c= 0; c < 8; c++ )
            Game.Board[r][c].PieceColor = WHITE;


    Game.Board[0][0].Code = Game.Board[0][7].Code = ROOK;
    Game.Board[7][0].Code = Game.Board[7][7].Code = ROOK;

    Game.Board[0][1].Code = Game.Board[0][6].Code = KNIGHT;
    Game.Board[7][1].Code = Game.Board[7][6].Code = KNIGHT;

    Game.Board[0][2].Code = Game.Board[0][5].Code = BISHOP;
    Game.Board[7][2].Code = Game.Board[7][5].Code = BISHOP;

    Game.Board[0][3].Code = Game.Board[7][3].Code = QUEEN;
    Game.Board[0][4].Code = Game.Board[7][4].Code = KING;

    for(int c= 0; c < 8; c++ )
        Game.Board[1][c].Code = Game.Board[6][c].Code = PAWN;

    Game.TurningPlayer = WHITE;

    return;
}

//------
bool fakeMove (GameData& Game, Color Player, int row, int col, int rowJump, int colJump)
{
    chessPiece tempPiece;

    int newRow = row+rowJump;
    int newCol = col+colJump;

    //must call isValidMove before calling this function. there's no check inside

    tempPiece.Code = Game.Board[newRow][newCol].Code;
    tempPiece.PieceColor = Game.Board[newRow][newCol].PieceColor;

    Game.Board[newRow][newCol].PieceColor = Player;
    Game.Board[newRow][newCol].Code = Game.Board[row][col].Code;

    Game.Board[row][col].Code = NONE;

    if(isfacingCheck(Game, Player))
    {
        //reversing fake move
        Game.Board[row][col].Code = Game.Board[newRow][newCol].Code;
        Game.Board[row][col].PieceColor = Game.Board[newRow][newCol].PieceColor;

        Game.Board[newRow][newCol].Code = tempPiece.Code;
        Game.Board[newRow][newCol].PieceColor = tempPiece.PieceColor;

        return true;
    }
    else
    {
        //reversing fake move
        Game.Board[row][col].Code = Game.Board[newRow][newCol].Code;
        Game.Board[row][col].PieceColor = Game.Board[newRow][newCol].PieceColor;

        Game.Board[newRow][newCol].Code = tempPiece.Code;
        Game.Board[newRow][newCol].PieceColor = tempPiece.PieceColor;
        return false;
    }
}

//------------------------------------

bool isCheckmate(GameData& Game, Color Player){
    bool uu=false // straight up
    ,dd=false//straight down
    ,ll=false,rr=false, // straight right and left
     ul=false // upper left box
     ,ur=false// upper right box
     ,dl=false // down left
     ,dr=false; // down right

     int kingX, kingY;


    //these loops find location of King for current player
    for (int i=0; i<8; i++)
        for(int j=0;j<8; j++)
            if (Game.Board[i][j].Code == KING && Game.Board[i][j].PieceColor == Player)
            {
                kingX = j;
                kingY = i;
            }

    if (isfacingCheck(Game, Player)) //means existing position is facing check
    {
        if( (kingX>0 && kingX<7) && (kingY>0 && kingY<7))  //if king is placed in middle 7x7 boxes and has possible 8 moves
        {
            //let fake a move to right
            if(Game.Board[kingY][kingX+1].Code == NONE && fakeMove(Game, Player, kingY, kingX, 0, 1))
                rr = true;

            //let fake a move to right upper box
            if(Game.Board[kingY-1][kingX+1].Code == NONE && fakeMove(Game, Player, kingY, kingX, -1, 1))
                ur = true;

            //let fake a move to right bottom box
            if(Game.Board[kingY+1][kingX+1].Code == NONE && fakeMove(Game, Player, kingY, kingX, 1, 1))
                dr = true;

            //let fake a move to left
            if(Game.Board[kingY][kingX-1].Code == NONE && fakeMove(Game, Player, kingY, kingX, 0, -1))
                ll = true;

            //let fake a move to left upper box
            if(Game.Board[kingY-1][kingX-1].Code == NONE && fakeMove(Game, Player, kingY, kingX, -1, -1))
                ul = true;

            //let fake a move to left bottom box
            if(Game.Board[kingY+1][kingX-1].Code == NONE && fakeMove(Game, Player, kingY, kingX, 1, -1))
                dl = true;

            //let fake a move to UP
            if(Game.Board[kingY-1][kingX].Code == NONE && fakeMove(Game, Player, kingY, kingX, -1, 0))
                uu = true;
            //lets fake a move to DOWN
            if(Game.Board[kingY+1][kingX].Code == NONE && fakeMove(Game, Player, kingY, kingX, 1, 0))
                dd = true;
        }//end condition for 7x7 inner matrix


        //set flags for special conditions (like first and last rows and columns)
        if(kingY == 0) //top row check
        {
            if(kingX ==0) //top left corner
            {
                ll = dl = uu = ul = ur = true;

               //let fake a move to right
                if(Game.Board[kingY][kingX+1].Code == NONE && fakeMove(Game, Player, kingY, kingX, 0, 1))
                    rr = true;
                //let fake a move to right bottom box
                if(Game.Board[kingY+1][kingX+1].Code == NONE && fakeMove(Game, Player, kingY, kingX, 1, 1))
                    dr = true;
                //lets fake a move to DOWN
                if(Game.Board[kingY+1][kingX].Code == NONE && fakeMove(Game, Player, kingY, kingX, 1, 0))
                    dd = true;
            }
            if(kingX ==7) //right upper corner
            {
                uu = ul = ur = rr = dr = true;
                //lets fake a move to DOWN
                if(Game.Board[kingY+1][kingX].Code == NONE && fakeMove(Game, Player, kingY, kingX, 1, 0))
                    dd = true;
                //let fake a move to left bottom box
                if(Game.Board[kingY+1][kingX-1].Code == NONE && fakeMove(Game, Player, kingY, kingX, 1, -1))
                    dl = true;
                //let fake a move to left
                if(Game.Board[kingY][kingX-1].Code == NONE && fakeMove(Game, Player, kingY, kingX, 0, -1))
                    ll = true;
            }
            if(kingX>0 && kingX<7)
            {
                uu = ul = ur = true;
               //let fake a move to right
                if(Game.Board[kingY][kingX+1].Code == NONE && fakeMove(Game, Player, kingY, kingX, 0, 1))
                    rr = true;
                //let fake a move to right bottom box
                if(Game.Board[kingY+1][kingX+1].Code == NONE && fakeMove(Game, Player, kingY, kingX, 1, 1))
                    dr = true;
                //lets fake a move to DOWN
                if(Game.Board[kingY+1][kingX].Code == NONE && fakeMove(Game, Player, kingY, kingX, 1, 0))
                    dd = true;
                //let fake a move to left bottom box
                if(Game.Board[kingY+1][kingX-1].Code == NONE && fakeMove(Game, Player, kingY, kingX, 1, -1))
                    dl = true;
                //let fake a move to left
                if(Game.Board[kingY][kingX-1].Code == NONE && fakeMove(Game, Player, kingY, kingX, 0, -1))
                    ll = true;
            }
        } // top row end

        if(kingY == 7) //bottom row check
        {

            if(kingX ==0) //bottom left corner
            {
                dd = dl = dr = ll = ul = true;
                //let fake a move to UP
                if(Game.Board[kingY-1][kingX].Code == NONE && fakeMove(Game, Player, kingY, kingX, -1, 0))
                    uu = true;
               //let fake a move to right
                if(Game.Board[kingY][kingX+1].Code == NONE && fakeMove(Game, Player, kingY, kingX, 0, 1))
                    rr = true;
                //let fake a move to right upper box
                if(Game.Board[kingY-1][kingX+1].Code == NONE && fakeMove(Game, Player, kingY, kingX, -1, 1))
                    ur = true;
            }

            if(kingX ==7) //right bottom corner
            {
                dd = dl = dr = rr = ur = true;
                //let fake a move to UP
                if(Game.Board[kingY-1][kingX].Code == NONE && fakeMove(Game, Player, kingY, kingX, -1, 0))
                    uu = true;
                //let fake a move to left
                if(Game.Board[kingY][kingX-1].Code == NONE && fakeMove(Game, Player, kingY, kingX, 0, -1))
                    ll = true;
                //let fake a move to left upper box
                if(Game.Board[kingY-1][kingX-1].Code == NONE && fakeMove(Game, Player, kingY, kingX, -1, -1))
                    ul = true;
            }
            if(kingX>0 && kingX<7)
            {
                dd = dl = dr = true;
                //let fake a move to UP
                if(Game.Board[kingY-1][kingX].Code == NONE && fakeMove(Game, Player, kingY, kingX, -1, 0))
                    uu = true;
               //let fake a move to right
                if(Game.Board[kingY][kingX+1].Code == NONE && fakeMove(Game, Player, kingY, kingX, 0, 1))
                    rr = true;
                //let fake a move to right upper box
                if(Game.Board[kingY-1][kingX+1].Code == NONE && fakeMove(Game, Player, kingY, kingX, -1, 1))
                    ur = true;
                //let fake a move to left
                if(Game.Board[kingY][kingX-1].Code == NONE && fakeMove(Game, Player, kingY, kingX, 0, -1))
                    ll = true;
                //let fake a move to left upper box
                if(Game.Board[kingY-1][kingX-1].Code == NONE && fakeMove(Game, Player, kingY, kingX, -1, -1))
                    ul = true;
            }
        } //end BOTTOM ROW
        if(kingX ==0) //left column check - middle 6 rows
        {
            ll = dl = ul = true;
            //let fake a move to right
            if(Game.Board[kingY][kingX+1].Code == NONE && fakeMove(Game, Player, kingY, kingX, 0, 1))
                rr = true;

            //let fake a move to right upper box
            if(Game.Board[kingY-1][kingX+1].Code == NONE && fakeMove(Game, Player, kingY, kingX, -1, 1))
                ur = true;

            //let fake a move to right bottom box
            if(Game.Board[kingY+1][kingX+1].Code == NONE && fakeMove(Game, Player, kingY, kingX, 1, 1))
                dr = true;

            //let fake a move to UP
            if(Game.Board[kingY-1][kingX].Code == NONE && fakeMove(Game, Player, kingY, kingX, -1, 0))
                uu = true;
            //lets fake a move to DOWN
            if(Game.Board[kingY+1][kingX].Code == NONE && fakeMove(Game, Player, kingY, kingX, 1, 0))
                dd = true;
        }
        if(kingX ==7)// right column check - middle 6 rows
        {
            rr = ur = dr = true;

            //let fake a move to left
            if(Game.Board[kingY][kingX-1].Code == NONE && fakeMove(Game, Player, kingY, kingX, 0, -1))
                ll = true;

            //let fake a move to left upper box
            if(Game.Board[kingY-1][kingX-1].Code == NONE && fakeMove(Game, Player, kingY, kingX, -1, -1))
                ul = true;

            //let fake a move to left bottom box
            if(Game.Board[kingY+1][kingX-1].Code == NONE && fakeMove(Game, Player, kingY, kingX, 1, -1))
                dl = true;

            //let fake a move to UP
            if(Game.Board[kingY-1][kingX].Code == NONE && fakeMove(Game, Player, kingY, kingX, -1, 0))
                uu = true;
            //lets fake a move to DOWN
            if(Game.Board[kingY+1][kingX].Code == NONE && fakeMove(Game, Player, kingY, kingX, 1, 0))
                dd = true;
        }


        //****************** KING CAN'T MOVE ANYWHERE ***********
        if (rr && uu && dd && ll && ul && dl && dr && ur) // if all 8 positions return true
            return true;
    }
}



 /*bool isfacingCheck(GameData& Game, Color Player)
{
    // This function must return true if player having Color Player is facing a check

    int kx, ky;

    //let's find and store locations of Kings
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(Game.Board[i][j].Code== KING && Game.Board[i][j].PieceColor==Player) //King of current playr found
            {
                kx = j;
                ky = i;
            }

    // Check on all sides for possible check by WHITE
    if (Player == BLACK)
    {
        //check for WHITE PAWNS - who can attack from bottom only since white pieces are below
        if(ky<7)
            if((Game.Board[ky+1][kx-1].Code == PAWN && Game.Board[ky+1][kx-1].PieceColor==WHITE) || (Game.Board[ky+1][kx+1].Code == PAWN && Game.Board[ky+1][kx+1].PieceColor==WHITE))
                return true;


        //check for Knights that can attack from 8 different spots .. making sure that checks are within board
        if (kx>1 && kx<6 && ky>1 && ky<6) //middle box of 6x6 - 8 possible spots of attack by knight
        {
            if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == WHITE) ||
               (Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == WHITE) ||
               (Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == WHITE) ||
               (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == WHITE) ||
               (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == WHITE) ||
               (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == WHITE) ||
               (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == WHITE) ||
               (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == WHITE))
                return true;
        }
        else
        {
            if(ky==0) //top row
            {
                if(kx==0) //top-left corner - 2 possible spots
                {
                    if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == WHITE) ||
                       (Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == WHITE))
                        return true;
                }
                if(kx==1) //top row, 2nd column - 3 possible spots
                {
                    if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == WHITE) ||
                       (Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == WHITE) ||
                       (Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == WHITE))
                        return true;
                }
                if(kx>1 && kx<6) //top row, middle 6 columns - 4 possible spots
                {
                    if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == WHITE) ||
                       (Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == WHITE) ||
                       (Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == WHITE) ||
                       (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == WHITE))
                            return true;
                }
                if(kx==6) //top row, 6th column - 3 possible spots
                {
                    if((Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == WHITE) ||
                       (Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == WHITE) ||
                       (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == WHITE))
                            return true;
                }
                if(kx==7) //top-right corner - 2 possible spots
                {
                    if((Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == WHITE) ||
                       (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == WHITE))
                            return true;
                }
            }

            if(ky==1) //2nd row
            {
                if(kx==0) // 3 possible spots
                {
                    if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == WHITE) ||
                       (Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == WHITE) ||
                       (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == WHITE))
                    return true;
                }
                if(kx==1) // 4 possible spots
                {
                    if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == WHITE) ||
                       (Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == WHITE) ||
                       (Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == WHITE) ||
                       (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == WHITE))
                    return true;
                }
                if(kx>1 && kx<6) // 6 possible spots
                {
                    if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == WHITE) ||
                       (Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == WHITE) ||
                       (Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == WHITE) ||
                       (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == WHITE) ||
                       (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == WHITE) ||
                       (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == WHITE))
                            return true;

                }
                if (kx==6) // 4 possible spots
                {
                    if(
                       (Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == WHITE) ||
                       (Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == WHITE) ||
                       (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == WHITE) ||
                       (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == WHITE))
                    return true;
                }
                if (kx==7) // 3 possible spots
                {
                    if(
                       (Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == WHITE) ||
                       (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == WHITE) ||
                       (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == WHITE))
                    return true;
                }
            }

            if(ky==6) //6th row
            {
                if(kx==0) // 3 possible spots
                {
                    if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == WHITE) ||
                       (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == WHITE) ||
                       (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == WHITE))
                        return true;
                }
                if(kx==1) // 4 possible spots
                {
                    if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == WHITE) ||
                       (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == WHITE) ||
                       (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == WHITE) ||
                       (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == WHITE))
                        return true;

                }
                if(kx>1 && kx<6) // 6 possible spots
                {
                    if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == WHITE) ||
                       (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == WHITE) ||
                       (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == WHITE) ||
                       (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == WHITE) ||
                       (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == WHITE) ||
                       (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == WHITE))
                        return true;

                }
                if (kx==6) // 4 possible spots
                {
                    if(
                       (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == WHITE) ||
                       (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == WHITE) ||
                       (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == WHITE) ||
                       (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == WHITE))
                        return true;
                }
                if (kx==7) // 3 possible spots
                {
                    if(
                       (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == WHITE) ||
                       (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == WHITE) ||
                       (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == WHITE))
                        return true;
                }
            }
            if(ky==7) //bottom row
            {
                if(kx==0) //bottom-left corner - 2 possible spots
                {
                    if(
                       (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == WHITE) ||
                       (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == WHITE))
                        return true;
                }
                if(kx==1) //bottom row, 2nd column - 3 possible spots
                {
                    if(
                       (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == WHITE) ||
                       (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == WHITE) ||
                       (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == WHITE))
                        return true;
                }
                if(kx>1 && kx<6) //bottom row, middle 6 columns - 4 possible spots
                {
                    if(
                       (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == WHITE) ||
                       (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == WHITE) ||
                       (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == WHITE) ||
                       (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == WHITE))
                        return true;
                }
                if(kx==6) //bottom row, 6th column - 3 possible spots
                {
                    if(
                       (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == WHITE) ||
                       (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == WHITE) ||
                       (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == WHITE))
                        return true;

                }
                if(kx==7) //bottom-right corner - 2 possible spots
                {
                    if(
                       (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == WHITE) ||
                       (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == WHITE))
                        return true;
                }
            }

            if(ky>1 && ky<6)
            {
                if(kx==0) //1st column, middle 6 rows - 4 possible spots
                {
                    if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == WHITE) ||
                       (Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == WHITE) ||
                       (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == WHITE) ||
                       (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == WHITE))
                        return true;
                }
                if(kx==1) //2nd column, middle 6 row - 6 possible spots
                {
                    if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == WHITE) ||
                       (Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == WHITE) ||
                       (Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == WHITE) ||
                       (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == WHITE) ||
                       (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == WHITE) ||
                       (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == WHITE))
                        return true;

                }
                if(kx==6) //2nd last column, middle 6 rows - 6 possible spots
                {
                    if(
                       (Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == WHITE) ||
                       (Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == WHITE) ||
                       (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == WHITE) ||
                       (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == WHITE) ||
                       (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == WHITE) ||
                       (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == WHITE))
                        return true;

                }
                if(kx==7) //last column, middle 6 row - 4 possible spots
                {
                    if(
                       (Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == WHITE) ||
                       (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == WHITE) ||
                       (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == WHITE) ||
                       (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == WHITE))
                        return true;

                }
            }
        }//end knight checks


        //check upwards.. ROOK or QUEEN can hit
        if(ky>0)
        {

            for(int row=ky-1; row>=0; row--)
            {
                if(Game.Board[row][kx].Code != NONE) //there's some piece in this direction
                {
                    if(Game.Board[row][kx].PieceColor == BLACK) //player's own piece means protection
                        break; //no need to check further
                    else
                    {
                        if (Game.Board[row][kx].Code == QUEEN || Game.Board[row][kx].Code == ROOK) //it is an opponent's queen or rook
                                return true;
                    }
                }
            }
        }

        //check downwards.. ROOK or QUEEN can hit
        if(ky<7)
        {

            for(int row=ky+1; row<=7; row++)
            {
                if(Game.Board[row][kx].Code != NONE) //there's some piece in this direction
                {
                    if(Game.Board[row][kx].PieceColor == BLACK) //player's own piece means protection
                        break; //no need to check further
                    else
                    {
                        if(Game.Board[row][kx].Code == QUEEN || Game.Board[row][kx].Code == ROOK) //it is an opponent's queen or rook
                                return true;
                    }
                }
            }
        }

        //check Left side.. ROOK or QUEEN can hit
        if(kx>0)
        {

            for(int col=kx-1; col>=0; col--)
            {
                if(Game.Board[ky][col].Code != NONE) //there's some piece in this direction
                {
                    if(Game.Board[ky][col].PieceColor == BLACK) //player's own piece means protection
                        break; //no need to check further
                    else
                    {
                        if(Game.Board[ky][col].Code == QUEEN || Game.Board[ky][col].Code == ROOK) //it is an opponent's queen or rook
                                return true;

                    }
                }
            }
        }

        //check Right side.. ROOK or QUEEN can hit
        if (kx<7)
        {


            for(int col=kx+1; col<=7; col++)
            {
                if(Game.Board[ky][col].Code != NONE) //there's some piece in this direction
                {
                    if(Game.Board[ky][col].PieceColor == BLACK) //player's own piece means protection
                        break; //no need to check further
                    else
                    {
                        if(Game.Board[ky][col].Code == QUEEN || Game.Board[ky][col].Code == ROOK) //it is an opponent's queen or rook
                                return true;
                    }
                }
            }
        }

        //check Diagonal. Right-Upper side.. BISHOP or QUEEN can hit.. Excluding Pawn check here.
        if (ky>0 && kx<7)
        {

            for(int row=ky-1, col=kx+1; row>=0 || col<=7; row--, col++)
            {
                if(Game.Board[row][col].Code != NONE) //there's some piece in this direction
                {
                    if(Game.Board[row][col].PieceColor == BLACK) //player's own piece means protection
                        break; //no need to check further
                    else
                    {
                        if(Game.Board[row][col].Code == QUEEN || Game.Board[row][col].Code == BISHOP) //it is an opponent's queen or bishop
                                return true;
                    }
                }
            }
        }

        //check Diagonal. Left-Upper side.. BISHOP or QUEEN can hit.. Excluding Pawn check here.
        if(ky>0 && kx>0)
        {
            for(int row=ky-1, col=kx-1; row>=0 || col>=0; row--, col--)
            {
                if(Game.Board[row][col].Code != NONE) //there's some piece in this direction
                {
                    if(Game.Board[row][col].PieceColor == BLACK) //player's own piece means protection
                        break; //no need to check further
                    else
                    {
                        if(Game.Board[row][col].Code == QUEEN || Game.Board[row][col].Code == BISHOP) //it is an opponent's queen or bishop
                                return true;
                    }
                }
            }
        }

       //check Diagonal. Right-Bottom side.. BISHOP or QUEEN can hit.. Excluding Pawn check here.
       if(ky<7 && kx<7)
       {

            for(int row=ky+1, col=kx+1; row<=7 || col<=7; row++, col++)
            {
                if(Game.Board[row][col].Code != NONE) //there's some piece in this direction
                {
                    if(Game.Board[row][col].PieceColor == BLACK) //player's own piece means protection
                        break; //no need to check further
                    else
                    {
                        if(Game.Board[row][col].Code == QUEEN || Game.Board[row][col].Code == BISHOP) //it is an opponent's queen or bishop
                                return true;
                    }
                }
            }
       }

       //check Diagonal. Left-Bottom side.. BISHOP or QUEEN can hit.. Excluding Pawn check here.
       if(kx>0 && ky<7)
       {
           for(int row=ky+1, col=kx-1; row<=7 || col>=0; row++, col--)
            {
                if(Game.Board[row][col].Code != NONE) //there's some piece in this direction
                {
                    if(Game.Board[row][col].PieceColor == BLACK) //player's own piece means protection
                        break; //no need to check further
                    else
                    {
                        if(Game.Board[row][col].Code == QUEEN || Game.Board[row][col].Code == BISHOP) //it is an opponent's queen or bishop
                                return true;
                    }
                }
            }
       }

        //Code will reach here if Player is BLACK and there's no threat from any side
        return false;
    } //BLACK PLAYER Conditions End here..


    if (Player == WHITE) //replicating all above conditions for WHITE player to check against Black threat
    {
        //check for BLACK PAWNS - who can attack from bottom only since white pieces are below
        if(ky>0)
            if((Game.Board[ky-1][kx-1].Code == PAWN && Game.Board[ky-1][kx-1].PieceColor==BLACK) || (Game.Board[ky-1][kx+1].Code == PAWN && Game.Board[ky-1][kx+1].PieceColor==BLACK))
                return true;

        //check for Knights that can attack from 8 different spots .. making sure that checks are within board
        if (kx>1 && kx<6 && ky>1 && ky<6) //middle box of 6x6 - 8 possible spots of attack by knight
        {
            if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == BLACK) ||
               (Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == BLACK) ||
               (Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == BLACK) ||
               (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == BLACK) ||
               (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == BLACK) ||
               (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == BLACK) ||
               (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == BLACK) ||
               (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == BLACK))
                return true;
        }
        else
        {
            if(ky==0) //top row
            {
                if(kx==0) //top-left corner - 2 possible spots
                {
                    if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == BLACK) ||
                       (Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == BLACK))
                        return true;
                }
                if(kx==1) //top row, 2nd column - 3 possible spots
                {
                    if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == BLACK) ||
                       (Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == BLACK) ||
                       (Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == BLACK))
                        return true;
                }
                if(kx>1 && kx<6) //top row, middle 6 columns - 4 possible spots
                {
                    if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == BLACK) ||
                       (Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == BLACK) ||
                       (Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == BLACK) ||
                       (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == BLACK))
                        return true;
                }
                if(kx==6) //top row, 6th column - 3 possible spots
                {
                    if((Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == BLACK) ||
                       (Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == BLACK) ||
                       (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == BLACK))
                        return true;
                }
                if(kx==7) //top-right corner - 2 possible spots
                {
                    if((Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == BLACK) ||
                       (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == BLACK))
                       return true;
                }
            }

            if(ky==1) //2nd row
            {
                if(kx==0) // 3 possible spots
                {
                    if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == BLACK) ||
                       (Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == BLACK) ||
                       (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == BLACK))
                    return true;
                }
                if(kx==1) // 4 possible spots
                {
                    if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == BLACK) ||
                       (Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == BLACK) ||
                       (Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == BLACK) ||
                       (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == BLACK))
                    return true;
                }
                if(kx>1 && kx<6) // 6 possible spots
                {
                    if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == BLACK) ||
                       (Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == BLACK) ||
                       (Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == BLACK) ||
                       (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == BLACK) ||
                       (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == BLACK) ||
                       (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == BLACK))
                    return true;

                }
                if (kx==6) // 4 possible spots
                {
                    if(
                       (Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == BLACK) ||
                       (Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == BLACK) ||
                       (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == BLACK) ||
                       (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == BLACK))
                    return true;
                }
                if (kx==7) // 3 possible spots
                {
                    if(
                       (Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == BLACK) ||
                       (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == BLACK) ||
                       (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == BLACK))
                    return true;
                }
            }

            if(ky==6) //6th row
            {
                if(kx==0) // 3 possible spots
                {
                    if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == BLACK) ||
                       (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == BLACK) ||
                       (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == BLACK))
                        return true;
                }
                if(kx==1) // 4 possible spots
                {
                    if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == BLACK) ||
                       (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == BLACK) ||
                       (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == BLACK) ||
                       (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == BLACK))
                        return true;

                }
                if(kx>1 && kx<6) // 6 possible spots
                {
                    if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == BLACK) ||
                       (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == BLACK) ||
                       (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == BLACK) ||
                       (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == BLACK) ||
                       (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == BLACK) ||
                       (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == BLACK))
                        return true;

                }
                if (kx==6) // 4 possible spots
                {
                    if(
                       (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == BLACK) ||
                       (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == BLACK) ||
                       (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == BLACK) ||
                       (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == BLACK))
                        return true;
                }
                if (kx==7) // 3 possible spots
                {
                    if(
                       (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == BLACK) ||
                       (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == BLACK) ||
                       (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == BLACK))
                        return true;
                }
            }
            if(ky==7) //bottom row
            {
                if(kx==0) //bottom-left corner - 2 possible spots
                {
                    if(
                       (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == BLACK) ||
                       (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == BLACK))
                        return true;
                }
                if(kx==1) //bottom row, 2nd column - 3 possible spots
                {
                    if(
                       (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == BLACK) ||
                       (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == BLACK) ||
                       (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == BLACK))
                        return true;
                }
                if(kx>1 && kx<6) //bottom row, middle 6 columns - 4 possible spots
                {
                    if(
                       (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == BLACK) ||
                       (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == BLACK) ||
                       (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == BLACK) ||
                       (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == BLACK))
                        return true;
                }
                if(kx==6) //bottom row, 6th column - 3 possible spots
                {
                    if(
                       (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == BLACK) ||
                       (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == BLACK) ||
                       (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == BLACK))
                        return true;

                }
                if(kx==7) //bottom-right corner - 2 possible spots
                {
                    if(
                       (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == BLACK) ||
                       (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == BLACK))
                        return true;
                }
            }

            if(ky>1 && ky<6)
            {
                if(kx==0) //1st column, middle 6 rows - 4 possible spots
                {
                    if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == BLACK) ||
                       (Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == BLACK) ||
                       (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == BLACK) ||
                       (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == BLACK))
                        return true;
                }
                if(kx==1) //2nd column, middle 6 row - 6 possible spots
                {
                    if((Game.Board[ky+1][kx+2].Code == KNIGHT && Game.Board[ky+1][kx+2].PieceColor == BLACK) ||
                       (Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == BLACK) ||
                       (Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == BLACK) ||
                       (Game.Board[ky-1][kx+2].Code == KNIGHT && Game.Board[ky-1][kx+2].PieceColor == BLACK) ||
                       (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == BLACK) ||
                       (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == BLACK))
                        return true;

                }
                if(kx==6) //2nd last column, middle 6 rows - 6 possible spots
                {
                    if(
                       (Game.Board[ky+2][kx+1].Code == KNIGHT && Game.Board[ky+2][kx+1].PieceColor == BLACK) ||
                       (Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == BLACK) ||
                       (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == BLACK) ||
                       (Game.Board[ky-2][kx+1].Code == KNIGHT && Game.Board[ky-2][kx+1].PieceColor == BLACK) ||
                       (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == BLACK) ||
                       (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == BLACK))
                        return true;

                }
                if(kx==7) //last column, middle 6 row - 4 possible spots
                {
                    if(
                       (Game.Board[ky+2][kx-1].Code == KNIGHT && Game.Board[ky+2][kx-1].PieceColor == BLACK) ||
                       (Game.Board[ky+1][kx-2].Code == KNIGHT && Game.Board[ky+1][kx-2].PieceColor == BLACK) ||
                       (Game.Board[ky-2][kx-1].Code == KNIGHT && Game.Board[ky-2][kx-1].PieceColor == BLACK) ||
                       (Game.Board[ky-1][kx-2].Code == KNIGHT && Game.Board[ky-1][kx-2].PieceColor == BLACK))
                        return true;

                }
            }
        }//end knight checks


        //check upwards.. ROOK or QUEEN can hit
        if(ky>0)
        {


        for(int row=ky-1; row>=0; row--)
        {
            if(Game.Board[row][kx].Code != NONE) //there's some piece in this direction
            {
                if(Game.Board[row][kx].PieceColor == WHITE) //player's own piece means protection
                    break; //no need to check further
                else
                {
                    if (Game.Board[row][kx].Code == QUEEN || Game.Board[row][kx].Code == ROOK) //it is an opponent's queen or rook
                            return true;
                }
            }
        }
        }

        //check downwards.. ROOK or QUEEN can hit
        if(ky<7)
        {


        for(int row=ky+1; row<=7; row++)
        {
            if(Game.Board[row][kx].Code != NONE) //there's some piece in this direction
            {
                if(Game.Board[row][kx].PieceColor == WHITE) //player's own piece means protection
                    break; //no need to check further
                else
                {
                    if(Game.Board[row][kx].Code == QUEEN || Game.Board[row][kx].Code == ROOK) //it is an opponent's queen or rook
                        return true;
                }
            }
        }
        }

        //check Left side.. ROOK or QUEEN can hit
        if(kx>0)
        {


        for(int col=kx-1; col>=0; col--)
        {
            if(Game.Board[ky][col].Code != NONE) //there's some piece in this direction
            {
                if(Game.Board[ky][col].PieceColor == WHITE) //player's own piece means protection
                    break; //no need to check further
                else
                {
                    if(Game.Board[ky][col].Code == QUEEN || Game.Board[ky][col].Code == ROOK) //it is an opponent's queen or rook
                        return true;
                }
            }
        }
        }
        //check Right side.. ROOK or QUEEN can hit
        if(kx<7){
        for(int col=kx+1; col<=7; col++)
        {
            if(Game.Board[ky][col].Code != NONE) //there's some piece in this direction
            {
                if(Game.Board[ky][col].PieceColor == WHITE) //player's own piece means protection
                    break; //no need to check further
                else
                {
                    if(Game.Board[ky][col].Code == QUEEN || Game.Board[ky][col].Code == ROOK) //it is an opponent's queen or rook
                        return true;
                }
            }
        }
        }

        //check Diagonal. Right-Upper side.. BISHOP or QUEEN can hit.. Excluding Pawn check here.
        if(kx<7 && ky>0){
        for(int row=ky-1, col=kx+1; row>=0 || col<=7; row--, col++)
        {
            if(Game.Board[row][col].Code != NONE) //there's some piece in this direction
            {
                if(Game.Board[row][col].PieceColor == WHITE) //player's own piece means protection
                    break; //no need to check further
                else
                {
                    if(Game.Board[row][col].Code == QUEEN || Game.Board[row][col].Code == BISHOP) //it is an opponent's queen or bishop
                        return true;
                }
            }
        }
        }

        //check Diagonal. Left-Upper side.. BISHOP or QUEEN can hit.. Excluding Pawn check here.
        if(kx>0 && ky>0){
        for(int row=ky-1, col=kx-1; row>=0 || col>=0; row--, col--)
        {
            if(Game.Board[row][col].Code != NONE) //there's some piece in this direction
            {
                if(Game.Board[row][col].PieceColor == WHITE) //player's own piece means protection
                    break; //no need to check further
                else
                {
                    if(Game.Board[row][col].Code == QUEEN || Game.Board[row][col].Code == BISHOP) //it is an opponent's queen or bishop
                        return true;
                }
            }
        }
        }

       //check Diagonal. Right-Bottom side.. BISHOP or QUEEN can hit.. Excluding Pawn check here.
       if(kx<7 && ky<7){
        for(int row=ky+1, col=kx+1; row<=7 || col<=7; row++, col++)
        {
            if(Game.Board[row][col].Code != NONE) //there's some piece in this direction
            {
                if(Game.Board[row][col].PieceColor == WHITE) //player's own piece means protection
                    break; //no need to check further
                else
                {
                    if(Game.Board[row][col].Code == QUEEN || Game.Board[row][col].Code == BISHOP) //it is an opponent's queen or bishop
                        return true;
                }
            }
        }
        }

       //check Diagonal. Left-Bottom side.. BISHOP or QUEEN can hit.. Excluding Pawn check here.
       if(kx>0 && ky<7){
        for(int row=ky+1, col=kx-1; row<=7 || col>=0; row++, col--)
        {
            if(Game.Board[row][col].Code != NONE) //there's some piece in this direction
            {
                if(Game.Board[row][col].PieceColor == WHITE) //player's own piece means protection
                    break; //no need to check further
                else
                {
                    if(Game.Board[row][col].Code == QUEEN || Game.Board[row][col].Code == BISHOP) //it is an opponent's queen or bishop
                        return true;
                }
            }
        }
        }
        //Code will reach here if Player is WHITE and there's no threat from any side
        return false;
    }
} */


bool isfacingCheck(GameData& Game, Color Player){
    // This function must return true if player having Color Player is facing a check



for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {




            if(Game.Board[i][j].PieceColor== BLACK && Game.Board[i][j].Code== KING)
            {


                 if((Game.Board[i+1][j-1].Code == PAWN  &&  Game.Board[i+1][j-1].PieceColor == WHITE ) || (Game.Board[i+1][j+1].Code == PAWN &&  Game.Board[i+1][j+1].PieceColor == WHITE)  )

                    {
                             True=1;
                             a=true;
                             return true;
                    }






                // ROOK CHECK

               for(int k=i-1;k>=0;k--) // check from upwards//run karna
               {

                          if( (Game.Board[k][j].Code != ROOK  && Game.Board[k][j].Code != QUEEN)   && Game.Board[k][j].Code!=NONE)
                            {    a=false;
                                True = 0;
                                break;

                            }
                            else if( (Game.Board[k][j].Code == ROOK  || Game.Board[k][j].Code == QUEEN) && Game.Board[k][j].PieceColor == WHITE )
                            {
                                True = 1;
                                a=true;
                                return true;
                            }


                   }
                for(int k=i+1;k<8;k++) // check from downwards
               {
                   if(Game.Board[k][j].Code!=NONE)
                   {

                         if( (Game.Board[k][j].Code != ROOK && Game.Board[k][j].Code != QUEEN ) && Game.Board[k][j].Code!=NONE)
                            {   a=false;
                                True = 0;
                                break;
                            }
                             else if( (Game.Board[k][j].Code == ROOK || Game.Board[k][j].Code == QUEEN)  && Game.Board[k][j].PieceColor == WHITE )
                            {
                                True = 1;
                                a=true;
                                return true;
                            }

                       }
                   }

                for(int k=j+1;k<8;k++) // check from downwards
               {
                   if(Game.Board[i][k].Code!=NONE)
                   {

                         if( (Game.Board[i][k].Code != ROOK  && Game.Board[i][k].Code != QUEEN) && Game.Board[i][k].Code!=NONE)
                            {
                                True = 0;
                                a=false;
                                break;
                            }
                             else if( (Game.Board[i][k].Code == ROOK  || Game.Board[i][k].Code == QUEEN)&& Game.Board[i][k].PieceColor == WHITE )
                            {
                                True = 1;
                                a=true;
                                return true;
                            }

                       }
                   }

                for(int k=j-1;k>=0;k--) // check from downwards
               {
                   if(Game.Board[i][k].Code!=NONE)
                   {

                         if( (Game.Board[i][k].Code != ROOK && Game.Board[i][k].Code !=  QUEEN)  && Game.Board[i][k].Code!=NONE)
                            {
                                True = 0;
                                a=false;
                                break;
                            }
                             else if( (Game.Board[i][k].Code == ROOK || Game.Board[i][k].Code == QUEEN) && Game.Board[i][k].PieceColor == WHITE)
                            {
                                True = 1;
                                a=true;
                                return true;
                            }

                       }
                   }



    // check  for bishop
    int m=0;
             for(int k=i-1,m=j-1;k>=0, m>=0;k--,m--) // check from downwards
               {
                   if(Game.Board[k][m].Code!=NONE)
                   {

                         if( Game.Board[k][m].Code != BISHOP && Game.Board[k][m].Code != QUEEN  && Game.Board[k][m].Code!=NONE)
                            {
                                True = 0;
                                a=false;;
                                break;
                            }
                             else if( (Game.Board[k][m].Code == BISHOP || Game.Board[k][m].Code== QUEEN) && Game.Board[k][m].PieceColor == WHITE)
                            {
                                True = 1;
                                a=true;
                                return true;
                            }

                       }
                   }

              for(int k=i+1,m=j+1;k<8 , m<8;k++,m++) // check from downwards
               {
                   if(Game.Board[k][m].Code!=NONE)
                   {

                         if( Game.Board[k][m].Code != BISHOP && Game.Board[k][m].Code != QUEEN && Game.Board[k][m].Code!=NONE)
                            {
                                True = 0;
                                a=false;
                                break;
                            }
                             else if( (Game.Board[k][m].Code == BISHOP || Game.Board[k][m].Code == QUEEN) && Game.Board[k][m].PieceColor == WHITE)
                            {
                                True = 1;
                                a=true;
                                return true;
                            }

                       }
                   }
//run

                for(int k=i+1,m=j-1;k<8 , m>=0;k++,m--) // check from downwards
               {
                   if(Game.Board[k][m].Code!=NONE)
                   {

                         if( (Game.Board[k][m].Code != BISHOP  && Game.Board[k][m].Code != QUEEN) && Game.Board[k][m].Code!=NONE)
                            {
                                True = 0;
                                a=false;
                                break;
                            }
                             else if(( Game.Board[k][m].Code == BISHOP || Game.Board[k][j].Code == QUEEN) && Game.Board[k][m].PieceColor == WHITE)
                            {
                                True = 1;
                                a=true;
                                return true;
                            }

                       }
                   }
                  for(int k=i-1,m=j+1;k>=0;k--,m++) // check from downwards
               {
                   if(Game.Board[k][m].Code!=NONE)
                   {

                         if( Game.Board[k][m].Code != BISHOP &&  Game.Board[k][m].Code != QUEEN  && Game.Board[k][m].Code!=NONE)
                            {
                                True = 0;
                                a=false;//run
                                break;
                            }
                             else{
                                if( (Game.Board[k][m].Code == BISHOP || Game.Board[k][m].Code != QUEEN)&&  Game.Board[k][m].PieceColor== WHITE)
                                {


                                        True=1;
                                        a=true;
                                        return true;

                                }
                             }

                       }
                   }





                //check for Knights that can attack from 8 different spots .. making sure that checks are within board
       if (j>1 && j<6 && i>1 && i<6) //middle box of 6x6 - 8 possible spots of attack by knight
        {
            if((Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == WHITE) ||
               (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == WHITE) ||
               (Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j-1].PieceColor == WHITE) ||
               (Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j-2].PieceColor == WHITE) ||
               (Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == WHITE) ||
               (Game.Board[i-2][j+1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == WHITE) ||
               (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j-1].PieceColor == WHITE) ||
               (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j-2].PieceColor == WHITE))
               {
                   True=1;
                   a=true;
                   return true;
               }

        }
        else
        {
            if(i==0) //top row
            {
                if(j==0) //top-left corner - 2 possible spots
                {
                    if((Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == WHITE) ||
                       (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == WHITE))
                       {
                           True=1;
                           a=true;
                            return true;
                       }

                }
                if(j==1) //top row, 2nd column - 3 possible spots
                {
                    if((Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == WHITE) ||
                       (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == WHITE) ||
                       (Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j-1].PieceColor == WHITE))
                       {
                           True=1;
                           a=true;
                            return true;
                       }
                }
                if(j>1 && j<6) //top row, middle 6 columns - 4 possible spots
                {
                    if((Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == WHITE) ||
                       (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == WHITE) ||
                       (Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j-1].PieceColor == WHITE) ||
                       (Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j-2].PieceColor == WHITE))
                    {
                           True=1;
                           a=true;
                            return true;
                    }
                }
                if(j==6) //top row, 6th column - 3 possible spots
                {
                    if((Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == WHITE) ||
                       (Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j-1].PieceColor == WHITE) ||
                       (Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j-2].PieceColor == WHITE))
                    {
                           True=1;
                           a=true;
                            return true;
                    }
                }
                if(j==7) //top-right corner - 2 possible spots
                {
                    if((Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j-1].PieceColor == WHITE) ||
                       (Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j-2].PieceColor == WHITE))
                        {
                            True=1;
                            a=true;
                            return true;
                       }
                }
            }

            if(i==1) //2nd row
            {
                if(j==0) // 3 possible spots
                {
                    if((Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == WHITE) ||
                       (Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == WHITE) ||
                       (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == WHITE))
                    {
                           True=1;
                           a=true;
                            return true;
                    }
                }
                if(j==1) // 4 possible spots
                {
                    if((Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == WHITE) ||
                    (Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == WHITE) ||
                    (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == WHITE) ||
                    (Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j-1].PieceColor == WHITE))
                    {
                           True=1;
                           a=true;
                            return true;
                    }
                }
                if(j>1 && j<6) // 6 possible spots
                {
                  if((Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == WHITE) ||
                   (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == WHITE) ||
                   (Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j-1].PieceColor == WHITE) ||
                   (Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j-2].PieceColor == WHITE) ||
                   (Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == WHITE) ||
                   (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j-2].PieceColor == WHITE))
                   {
                       True=1;
                       a=true;
                       return true;
                   }
                }
                if (j==6) // 4 possible spots
                {
                     if(
                   (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == WHITE) ||
                   (Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j-1].PieceColor == WHITE) ||
                   (Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j-2].PieceColor == WHITE) ||
                   (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j-2].PieceColor == WHITE))
                   {
                       True=1;
                       a=true;
                       return true;
                   }
                }
                if (j==7) // 3 possible spots
                {
                    if(
                   (Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j-1].PieceColor == WHITE) ||
                   (Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j-2].PieceColor == WHITE) ||
                   (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j-2].PieceColor == WHITE))
                   {
                       True=1;
                       a=true;
                       return true;
                   }
                }
            }

            if(i==6) //6th row
            {
                if(j==0) // 3 possible spots
                {
                        if((Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == WHITE) ||
                           (Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == WHITE) ||
                           (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == WHITE))
                       {
                           True=1;
                           a=true;
                            return true;
                       }
                }
                if(j==1) // 4 possible spots
                {
                     if((Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == WHITE) ||
                        (Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == WHITE) ||
                        (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j-1].PieceColor == WHITE) ||
                        (Game.Board[i-2][j+1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == WHITE))
                       {
                           True=1;
                           a=true;
                            return true;
                       }
                }
                if(j>1 && j<6) // 6 possible spots
                {
                    if((Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == WHITE) ||
                   (Game.Board[i-2][j+1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == WHITE) ||
                   (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j-1].PieceColor == WHITE) ||
                   (Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j-2].PieceColor == WHITE) ||
                   (Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == WHITE) ||
                   (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j-2].PieceColor == WHITE))
                   {
                       True=1;
                       a=true;
                       return true;
                   }
                }
                if (j==6) // 4 possible spots
                {

                    if(
                   (Game.Board[i-2][j+1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == WHITE) ||
                   (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j-1].PieceColor == WHITE) ||
                   (Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j-2].PieceColor == WHITE) ||
                   (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j-2].PieceColor == WHITE))
                   {
                       True=1;
                       a=true;
                       return true;
                   }
                }
                if (j==7) // 3 possible spots
                {
                    if(
                   (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j-1].PieceColor == WHITE) ||
                   (Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j-2].PieceColor == WHITE) ||
                   (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j-2].PieceColor == WHITE))
                   {
                       True=1;
                       a=true;
                       return true;
                   }

                }
            }
            if(i==7) //bottom row
            {
                if(j==0) //bottom-left corner - 2 possible spots
                {
                      if(
                           (Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == WHITE) ||
                           (Game.Board[i-2][j+1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == WHITE))
                       {
                           True=1;
                           a=true;
                            return true;
                       }

                }
                if(j==1) //bottom row, 2nd column - 3 possible spots
                {
                       if(
                           (Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == WHITE) ||
                           (Game.Board[i-2][j+1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == WHITE) ||
                           (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j-1].PieceColor == WHITE))
                       {
                           True=1;
                           a=true;
                            return true;
                       }

                }
                if(j>1 && j<6) //bottom row, middle 6 columns - 4 possible spots
                {
                    if(
                   (Game.Board[i-2][j+1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == WHITE) ||
                   (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j-1].PieceColor == WHITE) ||
                   (Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == WHITE) ||
                   (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j-2].PieceColor == WHITE))
                   {
                       True=1;
                       a=true;
                       return true;
                   }
                }
                if(j==6) //bottom row, 6th column - 3 possible spots
                {
                     if(
                   (Game.Board[i-2][j+1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == WHITE) ||
                   (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j-1].PieceColor == WHITE) ||
                   (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j-2].PieceColor == WHITE))
                   {
                       True=1;
                       a=true;
                       return true;
                   }

                }
                if(j==7) //bottom-right corner - 2 possible spots
                {
                   if(
                   (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j-1].PieceColor == WHITE) ||
                   (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j-2].PieceColor == WHITE))
                   {
                       True=1;
                       a=true;
                       return true;
                   }
                }
            }

            if(i>1 && i<6)
            {
                if(j==0) //1st column, middle 6 rows - 4 possible spots
                {

              if((Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == WHITE) ||
               (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == WHITE) ||
               (Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == WHITE) ||
               (Game.Board[i-2][j+1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == WHITE)

               )
               {
                   True=1;
                   a=true;
                   return true;
               }

                }
                if(j==1) //2nd column, middle 6 row - 6 possible spots
                {
                if((Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == WHITE) ||
               (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == WHITE) ||
               (Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j-1].PieceColor == WHITE) ||
               (Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == WHITE) ||
               (Game.Board[i-2][j+1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == WHITE) ||
               (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j-1].PieceColor == WHITE)
             )
                   {
                       True=1;
                       a=true;
                       return true;
                   }
                }
                if(j==6) //2nd last column, middle 6 rows - 6 possible spots
                {
                    if(
               (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == WHITE) ||
               (Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j-1].PieceColor == WHITE) ||
               (Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j-2].PieceColor == WHITE) ||
               (Game.Board[i-2][j+1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == WHITE) ||
               (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j-1].PieceColor == WHITE) ||
               (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j-2].PieceColor == WHITE))
               {
                   True=1;
                   a=true;
                   return true;
               }

                }
                if(j==7) //last column, middle 6 row - 4 possible spots
                {

                  if((Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == WHITE) ||
                   (Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == WHITE) ||
                   (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == WHITE) ||
                   (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == WHITE)

                   )
                   {
                       True=1;
                       a=true;
                       return true;
                   }
                }
            }
        }















            }


    // starting for white player
         if(Game.Board[i][j].PieceColor== WHITE && Game.Board[i][j].Code== KING)
            {
                 if((Game.Board[i-1][j-1].Code == PAWN  &&  Game.Board[i-1][j-1].PieceColor == BLACK ) || (Game.Board[i-1][j+1].Code == PAWN &&  Game.Board[i-1][j+1].PieceColor == BLACK)  )
                    {
                         True=1;
                         b=true;
                         return true;
                    }

                // ROOK CHECK
              for(int k=i-1;k>=0;k--) // check from upwards
               {
                    if( (Game.Board[k][j].Code != ROOK  && Game.Board[k][j].Code != QUEEN)   && Game.Board[k][j].Code!=NONE)
                    {
                            True = 0;
                            b=false;
                            break;

                    }
                    else if( (Game.Board[k][j].Code == ROOK  || Game.Board[k][j].Code == QUEEN) && Game.Board[k][j].PieceColor == BLACK)
                    {
                            True = 1;
                            b=true;
                            return true;
                    }


                }
                for(int k=i+1;k<8;k++) // check from downwards
               {
                   if(Game.Board[k][j].Code!=NONE)
                   {

                         if( (Game.Board[k][j].Code != ROOK && Game.Board[k][j].Code != QUEEN ) && Game.Board[k][j].Code!=NONE)
                            {
                                True = 0;
                                b=false;
                                break;
                            }
                             else if( (Game.Board[k][j].Code == ROOK || Game.Board[k][j].Code == QUEEN)  && Game.Board[k][j].PieceColor == BLACK )
                            {
                                True = 1;
                                b=true;
                                return true;
                            }

                       }
                   }

                for(int k=j+1;k<8;k++) // check from downwards
               {
                   if(Game.Board[i][k].Code!=NONE)
                   {

                         if( (Game.Board[i][k].Code != ROOK  && Game.Board[i][k].Code != QUEEN) && Game.Board[i][k].Code!=NONE)
                            {
                                True = 0;
                                b=false;
                                break;
                            }
                             else if( (Game.Board[i][k].Code == ROOK  || Game.Board[i][k].Code == QUEEN)&& Game.Board[i][k].PieceColor == BLACK )
                            {
                                True = 1;
                                b=true;
                                return true;
                            }

                       }
                   }

                for(int k=j-1;k>=0;k--) // check from downwards
               {
                   if(Game.Board[i][k].Code!=NONE)
                   {

                         if( (Game.Board[i][k].Code != ROOK && Game.Board[i][k].Code !=  QUEEN)  && Game.Board[i][k].Code!=NONE)
                            {
                                True = 0;
                                b=false;
                                break;
                            }
                             else if( (Game.Board[i][k].Code == ROOK || Game.Board[i][k].Code == QUEEN) && Game.Board[i][k].PieceColor == BLACK)
                            {
                                True = 1;
                                b=true;
                                return true;
                            }

                       }
                   }



    // check  for bishop
    int m=0;
             for(int k=i-1,m=j-1;k>=0, m>=0;k--,m--) // check from downwards
               {
                   if(Game.Board[k][m].Code!=NONE)
                   {

                         if( Game.Board[k][m].Code != BISHOP && Game.Board[k][m].Code != QUEEN  && Game.Board[k][m].Code!=NONE)
                            {
                                True = 0;
                                b=false;
                                break;
                            }
                             else if( (Game.Board[k][m].Code == BISHOP || Game.Board[k][m].Code== QUEEN) && Game.Board[k][m].PieceColor == BLACK)
                            {
                                True = 1;
                                b=true;
                                return true;
                            }

                       }
                   }

              for(int k=i+1,m=j+1;k<8 , m<8;k++,m++) // check from downwards
               {
                   if(Game.Board[k][m].Code!=NONE)
                   {

                         if( Game.Board[k][m].Code != BISHOP && Game.Board[k][m].Code != QUEEN && Game.Board[k][m].Code!=NONE)
                            {
                                True = 0;
                                b=false;
                                break;
                            }
                             else if( (Game.Board[k][m].Code == BISHOP || Game.Board[k][m].Code == QUEEN) && Game.Board[k][m].PieceColor == BLACK)
                            {
                                True = 1;
                                b=true;
                                return true;
                            }

                       }
                   }
//run

                for(int k=i+1,m=j-1;k<8 , m>=0;k++,m--) // check from downwards
               {
                   if(Game.Board[k][m].Code!=NONE)
                   {

                         if( (Game.Board[k][m].Code != BISHOP  && Game.Board[k][m].Code != QUEEN) && Game.Board[k][m].Code!=NONE)
                            {
                                True = 0;
                                b=false;
                                break;
                            }
                             else if(( Game.Board[k][m].Code == BISHOP || Game.Board[k][j].Code == QUEEN) && Game.Board[k][m].PieceColor == BLACK)
                            {
                                True = 1;
                                b=true;
                                return true;
                            }

                       }
                   }
                  for(int k=i-1,m=j+1;k>=0;k--,m++) // check from downwards
               {
                   if(Game.Board[k][m].Code!=NONE)
                   {

                         if( Game.Board[k][m].Code != BISHOP &&  Game.Board[k][m].Code != QUEEN  && Game.Board[k][m].Code!=NONE)
                            {
                                True = 0;
                                b=false;//run
                                break;
                            }
                             else{
                                if( (Game.Board[k][m].Code == BISHOP || Game.Board[k][m].Code != QUEEN)&&  Game.Board[k][m].PieceColor==BLACK)
                                {


                                        True=1;
                                        b=true;
                                        return true;

                                }
                             }

                       }
                   }





                //check for Knights that can attack from 8 different spots .. making sure that checks are within board
       if (j>1 && j<6 && i>1 && i<6) //middle box of 6x6 - 8 possible spots of attack by knight
        {
            if((Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == BLACK) ||
               (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == BLACK) ||
               (Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j-1].PieceColor == BLACK) ||
               (Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j-2].PieceColor == BLACK) ||
               (Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == BLACK) ||
               (Game.Board[i-2][j+1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == BLACK) ||
               (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j-1].PieceColor == BLACK) ||
               (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j-2].PieceColor == BLACK))
               {
                   True=1;
                   b=true;
                   return true;
               }

        }
        else
        {
            if(i==0) //top row
            {
                if(j==0) //top-left corner - 2 possible spots
                {
                    if((Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == BLACK) ||
                       (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == BLACK))
                       {
                           True=1;
                           b=true;
                            return true;
                       }

                }
                if(j==1) //top row, 2nd column - 3 possible spots
                {
                    if((Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == BLACK) ||
                       (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == BLACK) ||
                       (Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j-1].PieceColor == BLACK))
                       {
                           True=1;
                           b=true;
                            return true;
                       }
                }
                if(j>1 && j<6) //top row, middle 6 columns - 4 possible spots
                {
                    if((Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == BLACK) ||
                       (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == BLACK) ||
                       (Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j-1].PieceColor == BLACK) ||
                       (Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j-2].PieceColor == BLACK))
                    {
                           True=1;
                           b=true;
                            return true;
                    }
                }
                if(j==6) //top row, 6th column - 3 possible spots
                {
                    if((Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == BLACK) ||
                       (Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j-1].PieceColor == BLACK) ||
                       (Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j-2].PieceColor == BLACK))
                    {
                           True=1;
                           b=true;
                            return true;
                    }
                }
                if(j==7) //top-right corner - 2 possible spots
                {
                    if((Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j-1].PieceColor == BLACK) ||
                       (Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j-2].PieceColor == BLACK))
                        {
                            True=1;
                            b=true;
                            return true;
                       }
                }
            }

            if(i==1) //2nd row
            {
                if(j==0) // 3 possible spots
                {
                    if((Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == BLACK) ||
                       (Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == BLACK) ||
                       (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == BLACK))
                    {
                           True=1;
                           b=true;
                            return true;
                    }
                }
                if(j==1) // 4 possible spots
                {
                    if((Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == BLACK) ||
                    (Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == BLACK) ||
                    (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == BLACK) ||
                    (Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j-1].PieceColor == BLACK))
                    {
                           True=1;
                           b=true;
                            return true;
                    }
                }
                if(j>1 && j<6) // 6 possible spots
                {
                  if((Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == BLACK) ||
                   (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == BLACK) ||
                   (Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j-1].PieceColor == BLACK) ||
                   (Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j-2].PieceColor == BLACK) ||
                   (Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == BLACK) ||
                   (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j-2].PieceColor == BLACK))
                   {
                       True=1;
                       b=true;
                       return true;
                   }
                }
                if (j==6) // 4 possible spots
                {
                     if(
                   (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == BLACK) ||
                   (Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j-1].PieceColor == BLACK) ||
                   (Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j-2].PieceColor == BLACK) ||
                   (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j-2].PieceColor == BLACK))
                   {
                       True=1;
                       b=true;
                       return true;
                   }
                }
                if (j==7) // 3 possible spots
                {
                    if(
                   (Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j-1].PieceColor == BLACK) ||
                   (Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j-2].PieceColor == BLACK) ||
                   (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j-2].PieceColor == BLACK))
                   {
                       True=1;
                       b=true;
                       return true;
                   }
                }
            }

            if(i==6) //6th row
            {
                if(j==0) // 3 possible spots
                {
                        if((Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == BLACK) ||
                           (Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == BLACK) ||
                           (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == BLACK))
                       {
                           True=1;
                           b=true;
                            return true;
                       }
                }
                if(j==1) // 4 possible spots
                {
                     if((Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == BLACK) ||
                        (Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == BLACK) ||
                        (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j-1].PieceColor == BLACK) ||
                        (Game.Board[i-2][j+1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == BLACK))
                       {
                           True=1;
                           b=true;
                            return true;
                       }
                }
                if(j>1 && j<6) // 6 possible spots
                {
                    if((Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == BLACK) ||
                   (Game.Board[i-2][j+1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == BLACK) ||
                   (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j-1].PieceColor == BLACK) ||
                   (Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j-2].PieceColor == BLACK) ||
                   (Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == BLACK) ||
                   (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j-2].PieceColor == BLACK))
                   {
                       True=1;
                       b=true;
                       return true;
                   }
                }
                if (j==6) // 4 possible spots
                {

                    if(
                   (Game.Board[i-2][j+1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == BLACK) ||
                   (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j-1].PieceColor == BLACK) ||
                   (Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j-2].PieceColor == BLACK) ||
                   (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j-2].PieceColor == BLACK))
                   {
                       True=1;
                       b=true;
                       return true;
                   }
                }
                if (j==7) // 3 possible spots
                {
                    if(
                   (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j-1].PieceColor == BLACK) ||
                   (Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j-2].PieceColor == BLACK) ||
                   (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j-2].PieceColor == BLACK))
                   {
                       True=1;
                       b=true;
                       return true;
                   }

                }
            }
            if(i==7) //bottom row
            {
                if(j==0) //bottom-left corner - 2 possible spots
                {
                      if(
                           (Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == BLACK) ||
                           (Game.Board[i-2][j+1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == BLACK))
                       {
                           True=1;
                           b=true;
                            return true;
                       }

                }
                if(j==1) //bottom row, 2nd column - 3 possible spots
                {
                       if(
                           (Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == BLACK) ||
                           (Game.Board[i-2][j+1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == BLACK) ||
                           (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j-1].PieceColor == BLACK))
                       {
                           True=1;
                           b=true;
                            return true;
                       }

                }
                if(j>1 && j<6) //bottom row, middle 6 columns - 4 possible spots
                {
                    if(
                   (Game.Board[i-2][j+1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == BLACK) ||
                   (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j-1].PieceColor == BLACK) ||
                   (Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == BLACK) ||
                   (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j-2].PieceColor == BLACK))
                   {
                       True=1;
                       b=true;
                       return true;
                   }
                }
                if(j==6) //bottom row, 6th column - 3 possible spots
                {
                     if(
                   (Game.Board[i-2][j+1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == BLACK) ||
                   (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j-1].PieceColor == BLACK) ||
                   (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j-2].PieceColor == BLACK))
                   {
                       True=1;
                       b=true;
                       return true;
                   }

                }
                if(j==7) //bottom-right corner - 2 possible spots
                {
                   if(
                   (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j-1].PieceColor == BLACK) ||
                   (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j-2].PieceColor == BLACK))
                   {
                       True=1;
                       b=true;
                       return true;
                   }
                }
            }

            if(i>1 && i<6)
            {
                if(j==0) //1st column, middle 6 rows - 4 possible spots
                {

              if((Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == BLACK) ||
               (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == BLACK) ||
               (Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == BLACK) ||
               (Game.Board[i-2][j+1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == BLACK)

               )
               {
                   True=1;
                   b=true;
                   return true;
               }

                }
                if(j==1) //2nd column, middle 6 row - 6 possible spots
                {
                if((Game.Board[i+1][j+2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == BLACK) ||
               (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == BLACK) ||
               (Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j-1].PieceColor == BLACK) ||
               (Game.Board[i-1][j+2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == BLACK) ||
               (Game.Board[i-2][j+1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == BLACK) ||
               (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j-1].PieceColor == BLACK)
             )
                   {
                       True=1;
                       b=true;
                       return true;
                   }
                }
                if(j==6) //2nd last column, middle 6 rows - 6 possible spots
                {
                    if(
               (Game.Board[i+2][j+1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == BLACK) ||
               (Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j-1].PieceColor == BLACK) ||
               (Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j-2].PieceColor == BLACK) ||
               (Game.Board[i-2][j+1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == BLACK) ||
               (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j-1].PieceColor == BLACK) ||
               (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j-2].PieceColor == BLACK))
               {
                   True=1;
                   b=true;
                   return true;
               }

                }
                if(j==7) //last column, middle 6 row - 4 possible spots
                {

                  if((Game.Board[i+1][j-2].Code == KNIGHT && Game.Board[i+1][j+2].PieceColor == BLACK) ||
                   (Game.Board[i+2][j-1].Code == KNIGHT && Game.Board[i+2][j+1].PieceColor == BLACK) ||
                   (Game.Board[i-1][j-2].Code == KNIGHT && Game.Board[i-1][j+2].PieceColor == BLACK) ||
                   (Game.Board[i-2][j-1].Code == KNIGHT && Game.Board[i-2][j+1].PieceColor == BLACK)

                   )
                   {
                       True=1;
                       b=true;
                       return true;
                   }
                }
            }


            }
        }



        }
    }

     return false;

}



