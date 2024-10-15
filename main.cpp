#include <iostream>

void updateBoard(char *spaces);
void playerMove(char *spaces, char pMove);
void computerMove(char *spaces, char cMove);
bool isTie(char *spaces);
bool isWin(char *spaces, char pMove);

int main(){
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char pMove = 'X';
    char cMove = 'O';
    char temp[9] = {'a','b','c','d','e','f','g','h','i'};

    std::cout << "--------- Tic Tac Toe Game START ---------\n";
    std::cout << "           Press Ctrl+C to End\n";
    updateBoard(spaces);
    while(true){
        
        playerMove(spaces, pMove);
        updateBoard(spaces);
        if(isWin(spaces, pMove) == true || isTie(spaces) == true){
            break;
        }
        computerMove(spaces,cMove);
        updateBoard(spaces);
        if(isWin(spaces, pMove) == true || isTie(spaces) == true){
            break;
        }
        
    }

    return 0;
}

void updateBoard(char *spaces){
    std::cout << "             " << "     |     |     \n";
    std::cout << "             " << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  \n";
    std::cout << "             " << "_____|_____|_____\n";
    std::cout << "             " << "     |     |     \n";
    std::cout << "             " << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  \n";
    std::cout << "             " << "_____|_____|_____\n";
    std::cout << "             " << "     |     |     \n";
    std::cout << "             " << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  \n";
    std::cout << "             " << "     |     |     \n\n";
}
void playerMove(char *spaces, char pMove){
    int number=-1;
    while(number<1 || number>9){
        std::cout<< "Enter a number between 1-9: ";
        std::cin >> number;
    }
    number--;
    if(spaces[number] == ' '){
        spaces[number] = pMove;
    } else {
        std::cout << "[Spaces already taken]" << '\n';
        playerMove(spaces, pMove);
    }
    
}
void computerMove(char *spaces, char cMove){
    srand(time(0));
    int num = 0;
    while(true){
        num = rand() % 9;
        if(spaces[num] == ' '){
            spaces[num] = cMove;
            break;
        }
        if(isTie(spaces) == true){
            break;
        }
    }
}
bool isTie(char *spaces){
    for(int i=0;i<9;i++){           // Cant use (sizeof(spaces)/sizeof(spaces[0])) for length of array because sizeof would take the size of the POINTER to the array, not the size of the array itself :(
        if(spaces[i] == ' '){
            return false;
        }
    }
    std::cout << "It's a tie!\n";
    return true;
}
bool isWin(char *spaces, char pMove){
    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
        spaces[0] == pMove ? std::cout << "You win!\n" : std::cout << "You lose :(\n";
        return true;
    } else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
        spaces[3] == pMove ? std::cout << "You win!\n" : std::cout << "You lose :(\n";
        return true;
    } else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
        spaces[6] == pMove ? std::cout << "You win!\n" : std::cout << "You lose :(\n";
        return true;
    } else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
        spaces[0] == pMove ? std::cout << "You win!\n" : std::cout << "You lose :(\n";
        return true;
    } else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
        spaces[1] == pMove ? std::cout << "You win!\n" : std::cout << "You lose :(\n";
        return true;
    } else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
        spaces[2] == pMove ? std::cout << "You win!\n" : std::cout << "You lose :(\n";
        return true;
    } else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
        spaces[0] == pMove ? std::cout << "You win!\n" : std::cout << "You lose :(\n";
        return true;
    } else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
        spaces[2] == pMove ? std::cout << "You win!\n" : std::cout << "You lose :(\n";
        return true;
    } 
    return false;
}