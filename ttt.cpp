//Mark Zhang - 4 March 2021 - TicTacToe: played on a 3x3 grid board with 2 players 'X' and 'O'.
//Players take turns filling 1 of the 9 grid squares per turn with their symbol.
//The first player to get 3 of their symbols in a row, column, or diagonal wins.
#include <iostream>
#include <cstring>
using namespace std;

//declare functions
bool checkwin(char board[3][3]);
bool checkmove(char coordinate[3], char board[3][3]);
void printboard(char board[3][3]);
void clearboard(char board[3][3]);

int main(){ //main function
  char board[3][3];
  char coordinate[50];
  char playerturn = 'X';
  char play = 'y';
  bool playing = true;
  int xwins = 0;
  int owins = 0;
  clearboard(board);
  while(playing == true){ //the game loops while the player wants to play again
    int moves = 0;
    bool ended = false;
    while(moves < 10){ //If all squares are filled with no winner, the game is a tie
    int x = 0, y = 0;
    printboard(board);
    cout << moves << endl;
  cout << "Turn: " << playerturn <<  endl;
  do{ //do while loop takes input and checks if it is valid using checkmove() function, if the input is not valid, asks the user to re-enter
    cout << "Enter a coordinate (ex. a1, b2, c3): " << endl;  
    cin.getline(coordinate, 3);
    if(checkmove(coordinate, board) == false){
      cout << "Your move, " << coordinate << ", was invalid. Please enter a valid move" << endl;
    }
    else if(coordinate[1] == '1'){ //converts user input to integer coordinates
	x = 0;
      }
      else if(coordinate[1] == '2'){
	x = 1;
      }
      else if(coordinate[1] == '3'){
	x = 2;
      }
      if(coordinate[0] == 'a'){
	y = 0;
      }
      else if(coordinate[0] == 'b'){
	y = 1;
      }
      else if(coordinate[0] == 'c'){
	y = 2;
      }
  }while(checkmove(coordinate, board) == false);
  
  board[x][y] = playerturn; 
  moves++;
  if(checkwin(board) == true){
      //if a win occurs after a move is made, the player who made the move is the winner
      cout << playerturn << " wins!" << endl;
	if(playerturn == 'X'){
	  xwins++;
	}
	else if(playerturn == 'O'){
	  owins++;
	}
	ended = true;
	printboard(board);
	cout << "X has won: " << xwins << " times" << endl; 
	cout << "O has won: " << owins << " times" << endl;
	cout << "would you like to play again? y/n" << endl;
	//At the end of the game, asks if player wants to play again
	clearboard(board);
	cin >> play;
	if(play == 'n'){
	  playing = false;
	}
	else if(play == 'y'){
	  playing = true;
	  cout << '\n' << "-----------------------------------------------------" << '\n' << endl;
	}
      break;
    }
    else if(checkwin(board) == false && moves == 9){ //if board is full and no one has won, it's a tie
      ended = true;
      printboard(board);
      cout << "tie!" << endl;
      cout << "X has won: " << xwins << " times" << endl; 
      cout << "O has won: " << owins << " times" << endl;
      cout << "would you like to play again? y/n" << endl;
      clearboard(board);
      cin >> play;
        if(play == 'n'){
          playing = false;
	  cout << "cya" << endl;
        }
        else if(play == 'y'){
          playing = true;
	  cout << '\n' << "-----------------------------------------------------" << '\n' << endl;
        }
	break;
    }
    else if(playerturn == 'X' && ended == false){
      playerturn = 'O';
    }
    else if(playerturn =='O' && ended == false){
      playerturn = 'X';
    }
  }
  }
  return 0;
}

  bool checkwin(char board[3][3]) { //if someone has won, checkwin returns true
   if((board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') || (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X' )
           || (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') || (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
           || (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') || (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
           || (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')) {
       return true;
   }
   else if((board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') || (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O' )
           || (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') || (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
           || (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') || (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
           || (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')) {
       return true;
   }
   else {
       return false;
   }
}     


bool checkmove(char coordinate[50], char board[3][3]){ //checks if move is legal. Returns true if the coordinates are valid and if the board position at those coordinates is empty
  bool isvalid = true;
  int x = 0, y = 0;
  if(strlen(coordinate) > 3){
    isvalid = false;
  }
  if(coordinate[1] == '1'){
        x = 0;
      }
      else if(coordinate[1] == '2'){
        x = 1;
      }
      else if(coordinate[1] == '3'){
        x = 2;
      }
      else{
       isvalid = false;
      }
      
      if(coordinate[0] == 'a'){
        y = 0;
      }
      else if(coordinate[0] == 'b'){
        y = 1;
      }
      else if(coordinate[0] == 'c'){
        y = 2;
      }
      else{
	isvalid = false;
      }

      if(board[x][y] == 'X' || board[x][y] == 'O'){
	isvalid = false;
      }
      return isvalid;
}
void printboard(char board[3][3]){ //Prints out the board
  cout << "  1 2 3" << endl;
  cout << "a " << board[0][0] << ' ' << board[1][0] << ' ' << board[2][0] << ' ' << endl;
  cout << "b " << board[0][1] << ' ' << board[1][1] << ' ' << board[2][1] << ' ' << endl;
  cout << "c " << board[0][2] << ' ' << board[1][2] << ' ' << board[2][2] << ' ' << endl;
}
void clearboard(char board[3][3]){ //Clears the board
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      board[i][j]=' ';
    }
  }
}
