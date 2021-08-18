//code by Craig Baron
//simple 2 player TicTacToe
#include <stdio.h>
void menu();
void printGameBoard( char playBoard[3][3]);
void createGameBoard(char playBoard[3][3]);
void player1Turn(char playBoard[3][3]);
void player2Turn(char playBoard[3][3]);
void startGame(char playBoard[3][3]);
int checkVertical(char playBoard[3][3]);
int checkHorizontal(char playBoard[3][3]);
int checkDiagnal(char playBoard[3][3]);
void viewInstructions(char playBoard[3][3]);

 int main()
 {
    menu();
    return 0;
 }

 void menu()
 {
    char playBoard[3][3];
    int input = 1;
    while(input != 0)
    {
        printf("Welcome to TicTacToe!\n");
        printf("Enter:\n0: To End Game\n1: To Play\n2: To View Instructions!\n");
        scanf("%d", &input);
        if(input == 0)
        {
          printf("Goodbye! Thanks for playing (:\n");
          return;
        }
        if(input == 2)
        {
          viewInstructions(playBoard);
          continue;
        }
        createGameBoard(playBoard);
        printf("\n\nGameBoard is ready!\n");
        printGameBoard(playBoard);
        startGame(playBoard);
    }
 }
 void viewInstructions(char playBoard[3][3])
 {
   int i,j, counter = 0;
   char nums[] = {'0', '1', '2', '3','4', '5', '6', '7', '8'};
   printf("\nWhen it is your turn enter the number corresponding to the spot you are trying to place.\n");
   for(i=0; i<3; i++)
   {
       for(j=0; j<3; j++)
       {
         playBoard[j][i] = nums[counter];
         counter++;
       }
   }
   printGameBoard(playBoard);
   printf("\n");
   return;
 }
 void startGame(char playBoard[3][3])
 {
    int timer = 0;
    int winner;
    while(timer < 9)
    {
      if(timer % 2 == 0)
      {
        player1Turn(playBoard);
      }
      else
      {
        player2Turn(playBoard);
      }
      printGameBoard(playBoard);
      if(checkVertical(playBoard) == 1 || checkHorizontal(playBoard) == 1 || checkDiagnal(playBoard) == 1)
      {
        if(timer % 2 == 0)
        {
          printf("GAME OVER Player 1 has one!\n\n");
          return;
        }
        else
        {
          printf("GAME OVER Player 2 has WON!\n\n");
          return;
        }
      }
      timer++;
    }
    printf("GAME OVER DRAW!\n\n");
    return;
 }
 int checkVertical(char playBoard[3][3])
 {
    if(playBoard[0][0] == playBoard[0][1] && playBoard[0][1] == playBoard[0][2] && playBoard[0][0] != ' ')
    {
      return 1;
    }
    else if(playBoard[1][0] == playBoard[1][1] && playBoard[1][1] == playBoard[1][2] && playBoard[1][0] != ' ')
    {
      return 1;
    }
    else if(playBoard[2][0] == playBoard[2][1] && playBoard[2][1] == playBoard[2][2] && playBoard[2][0] != ' ')
    {
      return 1;
    }
    else
    {
      return 0;
    }
 }
 int checkHorizontal(char playBoard[3][3])
 {
    if(playBoard[0][0] == playBoard[1][0] && playBoard[1][0] == playBoard[2][0] && playBoard[0][0] != ' ')
    {
      return 1;
    }
    else if(playBoard[0][1] == playBoard[1][1] && playBoard[1][1] == playBoard[2][1] && playBoard[0][1] != ' ')
    {
      return 1;
    }
    else if(playBoard[0][2] == playBoard[1][2] && playBoard[1][2] == playBoard[2][2] && playBoard[0][2] != ' ')
    {
      return 1;
    }
    else
    {
      return 0;
    }
 }
 int checkDiagnal(char playBoard[3][3])
 {
    if(playBoard[0][0] == playBoard[1][1] && playBoard[1][1] == playBoard[2][2] && playBoard[0][0] != ' ')
    {
      return 1;
    }
    else if(playBoard[2][0] == playBoard[1][1] && playBoard[1][1] == playBoard[0][2] && playBoard[2][0] != ' ')
    {
      return 1;
    }
    else
    {
      return 0;
    }
 }
 void createGameBoard(char playBoard[3][3])
 {
    int i,j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
          playBoard[j][i] = ' ';
        }
    }
 }

 void printGameBoard(char playBoard[3][3])
 {
   int i, j;
   for(i=0; i<3; i++)
   {
       if(i == 0)
       {
           printf("-------------------\n");
       }
       for(j=0; j<3; j++)
       {
           printf("|  %c  ", playBoard[j][i]);
           if(j == 2)
           {
             printf("|");
           }
       }
       printf("\n-------------------\n");
   }
 }
void player1Turn(char playBoard[3][3])
{
   int input, counter = 0;
   printf("Player1(X) enter your spot number!\n");
   scanf("%d",&input);
   if(input < 0 || input > 8)
   {
     player1Turn(playBoard);
     return;
   }
   int i,j;
   for(i=0; i<3; i++)
   {
       for(j=0; j<3; j++)
       {
         if(input == counter)
         {
           if(playBoard[j][i] != ' ')
           {
             player1Turn(playBoard);
             return;
           }
            playBoard[j][i] = 'X';
            return;
         }
         counter++;
       }
   }

}
void player2Turn(char playBoard[3][3])
{
  int input, counter = 0;
  printf("Player2(O) enter your spot number!\n");
  scanf("%d",&input);
  if(input < 0 || input > 8)
  {
    player2Turn(playBoard);
    return;
  }
  int i,j;
  for(i=0; i<3; i++)
  {
      for(j=0; j<3; j++)
      {
        if(input == counter)
        {
           if(playBoard[j][i] != ' ')
           {
             player2Turn(playBoard);
             return;
           }
           playBoard[j][i] = 'O';
           return;
        }
        counter++;
      }
  }
}
