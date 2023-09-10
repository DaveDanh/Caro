#include<stdlib.h>
#include<windows.h>
#include<iostream>
#include <conio.h>
#include <cstdlib>
#include <algorithm>


using namespace std;

void printCol(int col){
    for (int i = 0; i<2;i++){
        for (int a = -1; a<col;a++){
            cout << "|     ";
        }
        cout << endl;
    }
}

void printRow(int col){
    for (int i = 0;i<col;i++){
        cout << "|_____";
    }
    cout << "|";
    cout << endl;
}

void printBoard(int col){
    for (int i = 0;i<col;i++){
        cout << " _____";
    }
    cout << endl;
    for (int k = 0;k<col;k++){
        printCol(col);
        printRow(col);

    }
}

void gotoxy(int x, int y){
    static HANDLE h = NULL;  
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };  
    SetConsoleCursorPosition(h,c);
}

bool CheckWin(char board[][12], int col, int k, char player){
    //Row
    int count = 0;
    for (int j = 0;j<col;j++){
        for (int i = 0;i<col;i++){
            if (board[i][j] == player){
                count ++;
                if (count == k){
                    return true;
                }
            }
            else{
                count = 0;
            }
        }
        count = 0;
    }

    //Col
    count = 0;
    for (int i = 0;i<col;i++){
        for (int j = 0;j<col;j++){
            if (board[i][j] == player){
                count ++;
                if (count == k){
                    return true;
                }
            }
            else{
                count = 0;
            }
        }
        count = 0;
    }

    //Dia
    for (int i = 0; i < col - (k - 1); i++) {
        for (int j = 0; j < col - (k - 1); j++) {
            int count = 0;
            for (int a = 0; a < k; a++) {
                if (board[i + a][j + a] == player) {
                    count++;
                    if (count == k) {
                        return true;
                    }
                } else {
                    count = 0;
                    break;
                }
            }
        }
    }

    //ReverseDia
    for (int i = 0; i < col - (k - 1); i++) {
        for (int j = col-1; j > col-k-1; j--) {
            int count = 0;
            for (int a = 0; a < k; a++) {
                if (board[i + a][j - a] == player) {
                    count++;
                    if (count == k) {
                        return true;
                    }
                } else {
                    count = 0;
                    break;
                }
            }
        }
    }
    return false;
    
}

int minimax(char board[][12],int col, int k){
    int usefulmove[100] = {0};
    int counter = 0;
    int temp;
    int point[100] = {0};
    for (int i =0 ; i<col;i++){
        for (int j=0;j < col;j++){
            if (board[i][j] == 'X' or board[i][j] == 'O'){
                if (i != 0 or j != 0 or i!=col-1 or j!=col-1){
                    if (board[i+1][j+1] == ' '){
                        temp = col*(i+1)+(j+1);
                        usefulmove[counter] = temp;
                        counter++;
                    }
                    if (board[i+1][j] == ' '){
                        temp = col*(i+1)+j;
                        usefulmove[counter] = temp;
                        counter++;
                    }
                    if (board[i+1][j-1] == ' '){
                        temp = col*(i+1)+(j-1);
                        usefulmove[counter] = temp;
                        counter++;
                    }
                    if (board[i][j+1] == ' '){
                        temp = col*(i)+(j+1);
                        usefulmove[counter] = temp;
                        counter++;
                    }
                    if (board[i][j-1] == ' '){
                        temp = col*(i)+(j-1);
                        usefulmove[counter] = temp;
                        counter++;
                    }
                    if (board[i-1][j-1] == ' '){
                        temp = col*(i-1)+(j-1);
                        usefulmove[counter] = temp;
                        counter++;
                    }
                    if (board[i-1][j] == ' '){
                        temp = col*(i-1)+j;
                        usefulmove[counter] = temp;
                        counter++;
                    }
                    if (board[i-1][j+1] == ' '){
                        temp = col*(i-1)+(j+1);
                        usefulmove[counter] = temp;
                        counter++;
                    }
                }
                else{
                    if (i == 0 && j == 0){
                        if (board[i][j+1] == ' '){
                        temp = col*(i)+(j+1);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i+1][j] == ' '){
                        temp = col*(i+1)+(j);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i+1][j+1] == ' '){
                        temp = col*(i+1)+(j+1);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                    }
                    else if (i == col-1 && j == col-1){
                        if (board[i][j-1] == ' '){
                        temp = col*(i)+(j-1);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i-1][j] == ' '){
                        temp = col*(i-1)+(j);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i-1][j-1] == ' '){
                        temp = col*(i-1)+(j-1);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                    }
                    else if (i == 0 && j == col-1){
                        if (board[i+1][j] == ' '){
                        temp = col*(i+1)+(j);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i+1][j-1] == ' '){
                        temp = col*(i+1)+(j-1);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i][j-1] == ' '){
                        temp = col*(i)+(j-1);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                    }
                    else if (i == col-1 && j == 0){
                        if (board[i-1][j] == ' '){
                        temp = col*(i-1)+(j);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i-1][j+1] == ' '){
                        temp = col*(i-1)+(j+1);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i][j+1] == ' '){
                        temp = col*(i)+(j+1);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                    }
                    else if (i == 0){
                        if (board[i][j-1] == ' '){
                        temp = col*(i)+(j-1);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i][j+1] == ' '){
                        temp = col*(i)+(j+1);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i+1][j-1] == ' '){
                        temp = col*(i+1)+(j-1);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i+1][j] == ' '){
                        temp = col*(i+1)+(j);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i+1][j+1] == ' '){
                        temp = col*(i+1)+(j+1);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                    }
                    else if (i == col-1){
                        if (board[i][j-1] == ' '){
                        temp = col*(i)+(j-1);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i][j+1] == ' '){
                        temp = col*(i)+(j+1);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i-1][j-1] == ' '){
                        temp = col*(i-1)+(j-1);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i-1][j] == ' '){
                        temp = col*(i-1)+(j);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i-1][j+1] == ' '){
                        temp = col*(i-1)+(j+1);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                    }
                    else if (j == 0){
                        if (board[i-1][j] == ' '){
                        temp = col*(i-1)+(j);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i+1][j] == ' '){
                        temp = col*(i+1)+(j);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i-1][j+1] == ' '){
                        temp = col*(i-1)+(j+1);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i][j+1] == ' '){
                        temp = col*(i)+(j+1);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i+1][j+1] == ' '){
                        temp = col*(i+1)+(j+1);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                    }
                    else if (j == col-1){
                        if (board[i-1][j] == ' '){
                        temp = col*(i-1)+(j);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i+1][j] == ' '){
                        temp = col*(i+1)+(j);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i-1][j-1] == ' '){
                        temp = col*(i-1)+(j-1);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i][j-1] == ' '){
                        temp = col*(i)+(j-1);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                        if (board[i+1][j-1] == ' '){
                        temp = col*(i+1)+(j-1);
                        usefulmove[counter] = temp;
                        counter++;
                        }
                    }
                }
            
            }
        }
    }
    for (int a=0;a<counter;a++){
        board[usefulmove[a] / col][usefulmove[a] % col] = 'O';
        if (CheckWin(board, col , k , 'O')){
            point[a] = 1;
        }
        else{
            board[usefulmove[a] / col][usefulmove[a] % col] = 'X';
            if (CheckWin(board, col , k , 'X')){
                point[a] = -1;
            }
            else{
                point[a] = 0;
            }   
            board[usefulmove[a] / col][usefulmove[a] % col] = ' ';
        }
    }

    int ma = *max_element(begin(point),end(point));
    if (ma == 0){
        int mi = *min_element(begin(point),end(point));
        for (int b=0;b<counter;b++){
            if (point[b]==mi){
                return usefulmove[b];
                break;
            }
        }
    }
    else{
        for (int b=0;b<counter;b++){
            if (point[b]==ma){
                return usefulmove[b];
                break;
            }
        }
    }

}

void drawLogo(){
    system("cls");
    gotoxy(0,0);
    system("color 0D");
    cout << "        _________________                 _______                 _________________       __________________      " << endl;
    cout << "       |$$$$$$$$$$$$$$$$$|               /_____/ \\               /________________ \\     |_________________ \\  " << endl;
    cout << "       |$$ -----------.$$|              /%%/\\%%\\  \\              |$$ @@@@@@@@@|$$| |     |$$|$$$$$$$$$$$$$$| | "  << endl;
    cout << "       |$$|           |$$|             /%%/ /\\%%\\  \\             |$$||        |$$| |     |$$| |         |$$| | " << endl;
    cout << "       |$$|                           /%%/ /  \\%%\\  \\            |$$||        |$$| |     |$$| |         |$$| | " << endl;
    cout << "       |$$|                          /%%/_/____\\%%\\  \\           |$$|@@@@@@@@@|$$| |     |$$| |         |$$| | " << endl;
    cout << "       |$$|                         /%%/########\\%%\\  \\          |$$||    %%% \\---^^     |$$| |         |$$| |" << endl;
    cout << "       |$$|                        /%%/-/--------\\%%\\  \\         |$$||     %%% \\         |$$| |         |$$| |" << endl;
    cout << "       |$$|            __         /%%/ /          \\%%\\  \\        |$$||      %%% \\        |$$| |_________|$$| |" << endl;
    cout << "       |$$|___________|$$|       /%%/ /            \\%%\\  \\       |$$||       %%% \\       |$$|___________|$$| |" << endl;
    cout << "       |$$$$$$$$$$$$$$$$$|      /%%/ /              \\%%\\  \\      |$$||        %%% \\      |$$$$$$$$$$$$$$$$$| |" << endl;
    cout << "       '-----------------'     /%%/_/                \\%%\\__\\     |$$|/         %%%_\\     '-----------------'-'" << endl;
    cout << "" << endl;
}


int main(){
    int regame = 1;
    do {    
        drawLogo();
        int space = 0;
        bool turn = true;
        int col;
        int con=15;
        int mode=0;    
        cout << "Enter the size of the board: ";
        cin >> col;
        while (con > col ){
            cout << "Condition to win: ";
            cin >> con;
        }
        while (mode != 1 and mode != 2){
            cout << "Play with who?" << endl;
            cout << "1. Comp" << endl;
            cout << "2. Friend" << endl;
            cin >> mode;
        }
        system("cls");
        system("color 0F");
        printBoard(col);
        int curX = 3;
        int curY = 2;
        int maxY = 3*col-2;
        int maxX = 6*col-3;
        char board[12][12];
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < col; j++) {
                board[i][j] = ' ';
            }
        }
        while (space < col*col){
            gotoxy(0,3*col+2);
            if (turn == true){
                cout << "X turn";
            }
            else{
                cout << "O turn";
            }
            gotoxy(curX,curY);
            char ch = _getch();
            if (ch == 's' && curY<maxY){
                curY = curY + 3;
            }
            else if (ch == 'w' && curY>2){
                curY = curY - 3;
            }
            else if (ch == 'd' && curX<maxX){
                curX = curX + 6;
            }
            else if (ch == 'a' && curX>3){
                curX = curX - 6;
            }
            else if (ch == '\r'){
                int boardX = (curX-3)/6;
                int boardY = (curY-2)/3;
                if (board[boardX][boardY] == ' '){  
                    if (turn == true){    
                        cout << 'X';
                        turn = false;
                        board[boardX][boardY] = 'X';
                        if (CheckWin(board, col,con,'X')){
                            gotoxy(0,3*col+2);
                            cout << "X IS THE WINNER" << endl;
                            break;
                        }
                        if (mode == 1){    
                             
                                int selec = minimax(board,col,con);
                                board[selec/col][selec%col] = 'O';
                                gotoxy((selec/col)*6+3,(selec%col)*3+2);
                                cout << 'O';
                                turn = true;
                                space++;
                                if (CheckWin(board, col,con,'O')){
                                    gotoxy(0,3*col+2);
                                    cout << "O IS THE WINNER" << endl;
                                    break;
                                }
                            

                        }
                    }
                        else{
                            if (mode ==  2){    
                                cout << 'O';
                                turn = true;
                                board[boardX][boardY] = 'O';
                                if (CheckWin(board, col,con,'O')){
                                    gotoxy(0,3*col+2);
                                    cout << "O IS THE WINNER" << endl;
                                    break;
                                }
                            }
                        }
                }
                space++;
                }
            }
        if (!CheckWin(board, col,con,'O') && !CheckWin(board, col,con,'X')){
            gotoxy(0,3*col+2);
            cout << "A DRAW GAME" << endl;
        }
        cout << "Do you want to play again?";
        cout << endl << "1.YES";
        cout << endl << "2.NO" << endl;
        cin >> regame;
        if (regame == 2){
            exit(EXIT_SUCCESS);
        }
    } while(regame == 1);
}
