// TIC TAC TOE 
//---------------------------------------------
//
// TIC TAC TOE USING MINIMAX ALGORITHM
//
// THE GAME HAS A PLAYER VS PLAYER OPTION AND
// ALSO A PLAYER VS ARTIFICIAL INTELLIGENCE
//
//---------------------------------------------
// THE GAME WAS CREATED BY: RAFAEL GRECA 
// WWW.GITHUB.COM/RAFAELGRECA
//---------------------------------------------
//
// IF YOU GONNA USE THIS CODE, BE A NICE GUY AND GIVE
// THE CREDITS :)
// IF YOU HAVE ANY QUESTIONS ABOUT THE CODE, FEEL FREE
// TO ASK ME ANYTHING

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

vector <int> board(9,0);

char playerOption(int play){

  if(play == 1){
    return 'X';
  }else{
    if(play == 2){
      return 'O';
    }else{
      return '_';
    }
  }
}

int menu(){

  int option;

  printf("---------------------------------------\n");
  printf("              Tic Tac Toe \n");
  printf("---------------------------------------\n\n");
  printf("Tic Tac Toe created using the minimax \n              algorithm.\n\n");
  printf("  Game created by: Rafael Greca\n\n");
  printf("  ** www.github.com/rafaelgreca **\n\n");
  printf("  If you are gonna use this code, \n     please give the credits :)\n\n");
  printf("---------------------------------------\n");
  printf("              Menu Options  \n");
  printf("---------------------------------------\n\n");
  printf("  1- Player vs Player\n");
  printf("  2- Player vs AI\n\n");
  
  do{
    printf("Choose a option: ");
    scanf("%d",&option);
  }while(option<1 || option>2);

  return option;
}

void draw(int match){

  printf("\nMatch number %d\n\n",match);
  printf("  %c | %c | %c  \n",playerOption(board[0]),playerOption(board[1]),playerOption(board[2]));
  printf(" -----------\n");
  printf("  %c | %c | %c  \n",playerOption(board[3]),playerOption(board[4]),playerOption(board[5]));
  printf(" -----------\n");
  printf("  %c | %c | %c  \n",playerOption(board[6]),playerOption(board[7]),playerOption(board[8]));
  printf("\n");
}

void clearBoard(){

  for(int i=0; i<9; ++i) board[i] = 0;
}

void scoreboard(int matches, int player, int ia, int draws){
  
  printf("--------------------------------\n");
  printf("          Scoreboard    \n");
  printf("--------------------------------\n");
  printf("Player wins:  %d matches\n",player);
  printf("IA wins:      %d matches\n",ia);
  printf("Draws:        %d matches\n",draws);
  printf("Total:        %d matches\n",matches);
  printf("--------------------------------\n");
}

void scoreboardPvsP(int matches, int player1, int player2, int draws){
  
  printf("--------------------------------\n");
  printf("          Scoreboard    \n");
  printf("--------------------------------\n");
  printf("Player 1 wins:  %d matches\n",player1);
  printf("Player 2 wins:  %d matches\n",player2);
  printf("Draws:          %d matches\n",draws);
  printf("Total:          %d matches\n",matches);
  printf("--------------------------------\n");
}

bool checkMove(int move){

  if(board[move] == 0){
    return true;
  }else{
    return false;
  }

}

void playerMove(){

  int move;

  do{
    printf("Player, please enter with a valid number between 1 and 9: ");
    scanf("%d",&move);
  }while(!checkMove(move-1));

  board[move-1] = 1;

}

void player2Move(){

  int move;

  do{
    printf("Player 2, please enter with a valid number between 1 and 9: ");
    scanf("%d",&move);
  }while(!checkMove(move-1));

  board[move-1] = 2;
}

int checkVictory(){

  if(
  board[0]==1&&board[1]==1&&board[2]==1||
  board[3]==1&&board[4]==1&&board[5]==1||
  board[6]==1&&board[7]==1&&board[8]==1||
  board[0]==1&&board[3]==1&&board[6]==1||
  board[2]==1&&board[5]==1&&board[8]==1||
  board[1]==1&&board[4]==1&&board[7]==1||
  board[0]==1&&board[4]==1&&board[8]==1||
  board[2]==1&&board[4]==1&&board[6]==1){
    return -10;
  }
  
  if(
  board[0]==2&&board[1]==2&&board[2]==2||
  board[3]==2&&board[4]==2&&board[5]==2||
  board[6]==2&&board[7]==2&&board[8]==2||
  board[0]==2&&board[3]==2&&board[6]==2||
  board[2]==2&&board[5]==2&&board[8]==2||
  board[1]==2&&board[4]==2&&board[7]==2||
  board[0]==2&&board[4]==2&&board[8]==2||
  board[2]==2&&board[4]==2&&board[6]==2
  ){
    return 10;
  }

  return 0;

}

bool checkEmptySlots(){

  for(int i=0; i<9; ++i){
    
    if(board[i] == 0){
      
      return true;
      break;

    }
  }

  return false;
}

int minimax(int player){

  int score, victory = checkVictory();

  if(victory != 0){
    return victory;
  }

  if(!checkEmptySlots()){
    return 0;
  }

  if(player == -1){

    score = -100;

    for(int i=0; i<9; ++i){

      if(board[i] == 0){

        board[i] = 2;

        score = max(score,minimax(player*-1));

        board[i] = 0;

      }
    }

    return score;

  }else{

    score = 100;

    for(int i=0; i<9; ++i){

      if(board[i] == 0){
        
        board[i] = 1;

        score = min(score,minimax(player*-1));

        board[i] = 0;

      }
    }

    return score;

  }
}

void IAMove(){
  
  int value=-100, move=-1;

  for(int i=0; i<9; ++i){
    
    if(board[i] == 0){

      board[i] = 2;

      int score = minimax(1);

      board[i] = 0;

      if(value < score){
        value = score;
        move = i;
      }

    }

  }

  board[move] = 2;
}

int main(){

  char option;
  int matches=0, playerwins=0, iawins=0, draws=0;
  int player1=0, player2=0, drawspvp=0, matchespvp=0;

  do{

    clearBoard();

    if(matches > 1 || matchespvp > 1){
      cout << string( 100, '\n' );
    }

    int menuoption = menu();
    cout << string( 100, '\n' );

    int victory=0;
    bool winner=false;

    if(menuoption == 2){
      matches++;
      draw(matches);

      for(int i=0; i<9; ++i){
        
        if(i%2==0){
          playerMove();
          
          victory = checkVictory();

          if(victory != 0){
            if(victory == 10){
              printf("\nAI wins!\n");
              iawins++;
            }else{
              printf("\nPlayer wins!\n");
              playerwins++;
            }
            scoreboard(matches,playerwins,iawins,draws);
            draw(matches);
            winner = true;
            break;
          }
          
        }else{

          IAMove();

          victory = checkVictory();

          if(victory != 0){

            if(victory == 10){
              printf("\nAI wins!\n\n");
              iawins++;
            }else{
              printf("\nPlayer wins!\n\n");
              playerwins++;
            }
            scoreboard(matches,playerwins,iawins,draws);
            draw(matches);
            winner = true;
            break;
          }

          scoreboard(matches,playerwins,iawins,draws);
          draw(matches);
        }
      }

      if(!winner){
        printf("\nDraw!\n\n");
        draws++;
        scoreboard(matches,playerwins,iawins,draws);
        draw(matches);
      }
    }else{
      matchespvp++;
      draw(matchespvp);

      for(int i=0; i<9; ++i){
        
        if(i%2==0){
          playerMove();
          
          victory = checkVictory();

          if(victory != 0){
            if(victory == 10){
              printf("\nPlayer 2 wins!\n");
              player2++;
            }else{
              printf("\nPlayer 1 wins!\n");
              player1++;
            }
            scoreboardPvsP(matchespvp,player1,player2,drawspvp);
            draw(matchespvp);
            winner = true;
            break;
          }

          scoreboardPvsP(matchespvp,player1,player2,drawspvp);
          draw(matchespvp);
          
        }else{

          player2Move();

          victory = checkVictory();

          if(victory != 0){

            if(victory == 10){
              printf("\nPlayer 2 wins!\n\n");
              player2++;
            }else{
              printf("\nPlayer 1 wins!\n\n");
              player1++;
            }
            scoreboardPvsP(matchespvp,player1,player2,drawspvp);
            draw(matchespvp);
            winner = true;
            break;
          }

          scoreboardPvsP(matchespvp,player1,player2,drawspvp);
          draw(matchespvp);
        }
      }

      if(!winner){
        printf("\nDraw!\n\n");
        drawspvp++;
        scoreboardPvsP(matchespvp,player1,player2,drawspvp);
        draw(matchespvp);
      }
    }

    printf("Do you want to play again? \n");
    printf("Y-Yes or N-No\n");
    scanf(" %c",&option);
  }while(option == 'Y' || option == 'y');

  cout << string( 100, '\n' );
  scoreboard(matches,playerwins,iawins,draws);
  printf("\n\n");
  scoreboardPvsP(matchespvp,player1,player2,drawspvp);
}
