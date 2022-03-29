#include "GameData.cpp"
#include <fstream>

//-- ----------------------------------

void PromotePawn(GameData& Game, chessMove Move){

    if (((Game.Board[TR][TC].Code == PAWN ) && ((Game.Board[TR][TC].PieceColor==WHITE && TR==0 ) || (Game.Board[TR][TC].PieceColor==BLACK&& TR==7 ))))
    {
        PP=true;
        cout<<endl<<endl<<"Choose what do you want to promote your pawn to?"<<endl<<endl
        <<"1. Queen"<<endl
        <<"2. Bishop"<<endl
        <<"3. Knight"<<endl
        <<"4. Rook"<<endl<<endl;

        int opt;
        cin>>opt;

        cout<<endl;

        if (opt==1)
            PQ=true;

        if (opt==2)
            PB=true;

        if (opt==3)
            PK=true;

        if (opt==4)
            PR=true;

    }

}


string getPlayerinfo(){
    string Name="";
    cout<< "\nEnter Player Name\n";
    do{
        cin.clear();
        fflush(stdin);
        getline(cin, Name);
    }while(Name.length() == 0);
    return Name;
}
void ShowGame(Chess Game)
{
    //Function to display the game status on screen
    int posX = 0;
    int posY = 6;
    char input;

    chessMove Move;

    bool fromSelected = 0;
    bool toSelected = 0;

    char key;

    printGrid(11, 0, 0);
    printBox(14, posX*6, posY*3, 5, 2); //keep size 5 & 2 while increasing x by 6 and y by 3

    ShowPieces(Game);

    drawCurrentPiece(posX, posY, Game);

    SetColor(3);
    gotoxy(50,17);
    cout<<"CURRENT PLAYER";


    printBox(3,65, 0, 40, 14);
    SetColor(15);
    gotoxy(67,1);
    cout<<"   W";
    gotoxy(67,2);
    cout<<" A S D     keys to move around";
    gotoxy(67,4);
    cout<<"SPACE BAR  to select FROM Position";
    gotoxy(67,5);
    cout<<"ENTER KEY  to select TO Position";

    gotoxy(67,7);
    cout<<"      -----------------------";

    gotoxy(67,9);
    cout<<"(1) - for New Game without saving";
    gotoxy(67,10);
    cout<<"(2) - to Save current state of game";
    gotoxy(67,11);
    cout<<"(3) - to Load from last saving point";
    gotoxy(67,13);
    cout<<"Esc - to Exit Game";


    gotoxy(50,18);
    if(Game.GameState.TurningPlayer==WHITE)
    {
        SetColor(15);
        cout<<"       [WHITE]";
        cout<<" "<<Game.PlayerNames[1] ;
    }
    else
    {
        SetColor(8);
        cout<<"       [BLACK]";
        cout <<" "<<Game.PlayerNames[0] ;
    }


    while(!isCheckmate(Game.GameState, Game.GameState.TurningPlayer))
    {
        key = getch();
        switch(key)
        {

            case 27: //Escape key to Quit Game
            {

                gotoxy(50,23);
                SetColor(4);
                cout<<"Are you sure you want to Quit Game? (Y/N) : ";
                cin>>input;

                if (input =='y' || input =='Y')
                    return;
                else
                {
                    gotoxy(50,23);
                    cout<<"                                                     ";
                }
                break;
            }
            case 49: //Number 1 to Start New
            {

                gotoxy(50,23);
                SetColor(4);
                cout<<"Do you want to Start a NEW GAME? (Y/N) : ";
                cin>>input;

                if (input =='y' || input =='Y')
                {
                    cout<<"Enter First(WHITE) Player's Info"<<endl;
                    Game.PlayerNames[1] = getPlayerinfo();
                    cout<<"\n\nEnter Second(BLACK) Player's Info"<<endl;
                    Game.PlayerNames[0] = getPlayerinfo();
                    initGame(Game.GameState);

                    printGrid(2, 0, 0);
                    printBox(14, posX*6, posY*3, 5, 2);
                }

                ShowPieces(Game);
                gotoxy(50,23);
                cout<<"                                                     ";

                break;
            }

            case 50: //Number 2 to Save
            {

                fstream st; // Creating object of fstream class
                st.open(FILEPATH,ios::out);  // Creating new file
                if(!st) // Checking whether file exist
                {
                    cout<<"File creation failed";
                }
                else
                {
                    st << Game.GameState.TurningPlayer <<endl;
                    for(int i=0; i<8; i++)
                        for(int j=0; j<8; j++)
                            st << Game.GameState.Board[i][j].PieceColor << " "<< Game.GameState.Board[i][j].Code << endl;
                }
                st.close();


                gotoxy(50,23);
                SetColor(4);
                cout<<"Your Game is Saved! Press any key to continue..";
                getch();

                gotoxy(50,23);
                cout<<"                                                 ";

                break;
            }

            case 51: //Number 3 to Load
            {

                gotoxy(50,23);
                SetColor(4);
                cout<<"Do you want to Load game from Last Save? (Y/N) : ";
                cin>>input;

                if (input =='y' || input =='Y')
                {
                    fstream st; // Creating object of fstream class
                    int firstNumber;
                    int clr, code;
                    st.open(FILEPATH,ios::in);  // Opening file in read mode
                    if(!st) // Checking whether file exist
                    {
                        cout<<"No file found";
                    }
                    else
                    {
                        st >> firstNumber;
                        if(firstNumber ==1)
                            Game.GameState.TurningPlayer = WHITE;
                        else
                            Game.GameState.TurningPlayer = BLACK;

                        for(int i=0; i<8; i++)
                            for(int j=0; j<8; j++)
                            {
                                st >> clr;
                                st >> code;

                                if(clr==0)
                                    Game.GameState.Board[i][j].PieceColor=BLACK;
                                if(clr==1)
                                    Game.GameState.Board[i][j].PieceColor=WHITE;

                                if(code==0)
                                    Game.GameState.Board[i][j].Code=NONE;
                                if(code==1)
                                    Game.GameState.Board[i][j].Code=PAWN;
                                if(code==2)
                                   Game.GameState.Board[i][j].Code=ROOK;
                                if(code==3)
                                    Game.GameState.Board[i][j].Code=BISHOP;
                                if(code==4)
                                   Game.GameState.Board[i][j].Code=KNIGHT;
                                if(code==5)
                                   Game.GameState.Board[i][j].Code=QUEEN;
                                if(code==6)
                                   Game.GameState.Board[i][j].Code=KING;
                            }
                    }
                    st.close();


                    printGrid(2, 0, 0);
                    printBox(14, posX*6, posY*3, 5, 2);
                }

                ShowPieces(Game);
                gotoxy(50,23);
                cout<<"                                                    ";
                break;
            }

            case 115: case 83: //s or S for down key
            {
                if(posY<7)
                {
                    posY++;
                    printGrid(11, 0, 0);
                    printBox(14, posX*6, posY*3, 5, 2);

                    ShowPieces(Game);

                    drawCurrentPiece(posX, posY, Game);

                    gotoxy(50,18);
                    if(Game.GameState.TurningPlayer==WHITE)
                    {
                        SetColor(15);
                        cout<<"       [WHITE]";
                         cout<<" "<<Game.PlayerNames[1] ;
                    }
                    else
                    {
                        SetColor(8);
                        cout<<"       [BLACK]";
                        cout<<" "<<Game.PlayerNames[0] ;
                    }

                    if(!fromSelected)
                    {
                        gotoxy(50,20);
                        SetColor(14);
                        cout<<"FROM : ["<<posY<<"]["<<posX<<"]";

                        gotoxy(50,21);
                        cout<<"             ";
                    }
                    else
                    {
                        gotoxy(50,21);
                        SetColor(6);
                        cout<<"TO   : ["<<posY<<"]["<<posX<<"]";
                    }
                }
                break;
            }

            case 119: case 87: //w or W for UP key
            {
                if(posY>0)
                {
                    posY--;
                    printGrid(11, 0, 0);
                    printBox(14, posX*6, posY*3, 5, 2);

                    ShowPieces(Game);

                    drawCurrentPiece(posX, posY, Game);

                    gotoxy(50,18);
                    if(Game.GameState.TurningPlayer==WHITE)
                    {
                        SetColor(15);
                        cout<<"       [WHITE]";
                        cout<<" "<< Game.PlayerNames[1] ;
                    }
                    else
                    {
                        SetColor(8);
                        cout<<"       [BLACK]";
                        cout<<" "<<Game.PlayerNames[0];
                    }

                    if(!fromSelected)
                    {
                        gotoxy(50,20);
                        SetColor(14);
                        cout<<"FROM : ["<<posY<<"]["<<posX<<"]";

                        gotoxy(50,21);
                        cout<<"             ";
                    }
                    else
                    {
                        gotoxy(50,21);
                        SetColor(6);
                        cout<<"TO   : ["<<posY<<"]["<<posX<<"]";
                    }
                }
                break;
            }

            case 97: case 65: //a or A for LEFT key
            {
                if(posX>0)
                {
                    posX--;
                    printGrid(11, 0, 0);
                    printBox(14, posX*6, posY*3, 5, 2);

                    ShowPieces(Game);

                    drawCurrentPiece(posX, posY, Game);

                    gotoxy(50,18);
                    if(Game.GameState.TurningPlayer==WHITE)
                    {
                        SetColor(15);
                        cout<<"       [WHITE]";
                        cout<<" "<<Game.PlayerNames[1] ;
                    }
                    else
                    {
                        SetColor(8);
                        cout<<"       [BLACK]";
                        cout<<" "<<Game.PlayerNames[0];
                    }

                    if(!fromSelected)
                    {
                        gotoxy(50,20);
                        SetColor(14);
                        cout<<"FROM : ["<<posY<<"]["<<posX<<"]";

                        gotoxy(50,21);
                        cout<<"             ";
                    }
                    else
                    {
                        gotoxy(50,21);
                        SetColor(6);
                        cout<<"TO   : ["<<posY<<"]["<<posX<<"]";
                    }
                }
                break;
            }

            case 100: case 68: //d or D for RIGHT key
            {
                if(posX<7)
                {
                    posX++;
                    printGrid(11, 0, 0);
                    printBox(14, posX*6, posY*3, 5, 2);

                    ShowPieces(Game);

                    drawCurrentPiece(posX, posY, Game);

                    gotoxy(50,18);
                    if(Game.GameState.TurningPlayer==WHITE)
                    {
                        SetColor(15);
                        cout<<"       [WHITE]";
                        cout<<" "<<Game.PlayerNames[1] ;
                    }
                    else
                    {
                        SetColor(8);
                        cout<<"       [BLACK]";
                        cout<<" "<< Game.PlayerNames[0];
                    }


                    if(!fromSelected)
                    {
                        gotoxy(50,20);
                        SetColor(14);
                        cout<<"FROM : ["<<posY<<"]["<<posX<<"]";

                        gotoxy(50,21);
                        cout<<"             ";
                    }
                    else
                    {
                        gotoxy(50,21);
                        SetColor(6);
                        cout<<"TO   : ["<<posY<<"]["<<posX<<"]";
                    }
                }
                break;
            }

            case 32: //pressing SPACE - set the FROM coordinates
            {
                Move.FromColumn = posX;
                Move.FromRow = posY;

                fromSelected = true;

                gotoxy(50,20);
                SetColor(14);
                cout<<"FROM : ["<<Move.FromRow<<"]["<<Move.FromColumn<<"]";

                break;
            }

            case 13: // Pressing Enter - set the TO coordinates
            {
                if(fromSelected)
                {
                    Move.ToColumn = posX;
                    Move.ToRow = posY;

                    fromSelected = false;

                    gotoxy(50,18);
                    if(Game.GameState.TurningPlayer==WHITE)
                    {
                        SetColor(15);
                        cout<<"       [WHITE]";
                        cout<<" "<<Game.PlayerNames[1] ;
                    }
                    else
                    {
                        SetColor(8);
                        cout<<"       [BLACK]";
                         cout<<" "<<Game.PlayerNames[0] ;
                    }


                    gotoxy(50,21);
                    SetColor(6);
                    cout<<"TO   : ["<<Move.ToRow<<"]["<<Move.ToColumn<<"]";


                    int moveCode = MakeMove(Game.GameState, Move);

                    PromotePawn(Game.GameState, Move);
                    if (PP==true)
                        MakeMove(Game.GameState, Move);

                    if(moveCode == 1) //resulting in facing check
                    {
                        gotoxy(50,23);
                        SetColor(4);
                        cout<<"You will be facing check. Press any key to try another move!";
                        getch();

                        printGrid(11, 0, 0);
                        printBox(14, posX*6, posY*3, 5, 2);
                        ShowPieces(Game);
                        gotoxy(50,23);
                        cout<<"                                                             ";
                    }
                    if(moveCode == 2) //resulting in facing check
                    {

                        if(Game.GameState.TurningPlayer == BLACK)
                            Game.GameState.TurningPlayer = WHITE;
                        else
                            Game.GameState.TurningPlayer = BLACK;

                        printBox(14, posX*6, posY*3, 5, 2);
                        ShowPieces(Game);
                        drawCurrentPiece(posX, posY, Game);
                          gotoxy(50,23);
                        SetColor(4);
                        cout<<" facing check!";
                        getch();

                        printGrid(11, 0, 0);
                        printBox(14, posX*6, posY*3, 5, 2);
                        ShowPieces(Game);
                        gotoxy(50,23);
                        cout<<"                                                             ";
                    }
                    if(moveCode == 0) //Fair Move
                    {
                        if(Game.GameState.TurningPlayer == BLACK)
                            Game.GameState.TurningPlayer = WHITE;
                        else
                            Game.GameState.TurningPlayer = BLACK;

                        printBox(14, posX*6, posY*3, 5, 2);
                        ShowPieces(Game);
                        drawCurrentPiece(posX, posY, Game);

                    }
                    if(moveCode == -1) //not a valid move
                    {
                        gotoxy(50,23);
                        SetColor(4);
                        cout<<"Wrong Move. Press any key to try again..";
                        getch();

                        gotoxy(50,23);
                        cout<<"                                        ";
                        printBox(14, posX*6, posY*3, 5, 2);
                        ShowPieces(Game);
                    }
                }
                break;
            }

            default:
            {
                continue;
            }
        }
    }

    gotoxy(50,25);
    SetColor(4);
    cout<<"!!! CHECK-MATE.. GAME OVER !!!";
}
//----------------------------------------------
bool Check( GameData& Game , chessMove Move)
{
}
//----------------------------------------------
int main(){
    Chess Game;
    chessMove Move;

    initGame(Game.GameState);
    ShowGame(Game);

    return 0;
}
