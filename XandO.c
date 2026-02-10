#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void displayGrid(char board[3][3])
{ // this part is for printing the x and o board
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
        }
        printf("\n \n");
    }
}
int main()
{
    char board[3][3] = {// for making the matric
                        {'1', '2', '3'},
                        {'4', '5', '6'},
                        {'7', '8', '9'}};

    bool isRunning = true; // while the game is running from the first to 9th round
    int rounds = 1;        // this is the rounds of play, x goes first in round1 o goes next in round 2
    bool oneWon = false;
    bool twoWon = false;
    int posToPlay = 0; // this if for the players to put in a position to play
    while (isRunning)  // game loop
    {
        if (rounds > 9)
        {                      // there are 9 squares to be played in, so the person shouldnt be able
            isRunning = false; // to play past the 9th round and so the bool cuts the loop
        }
        else if (rounds % 2 == 0)
        {
            displayGrid(board);
            printf("Player 2, please pick a number to play: "); // this part is for the player to pick between a spot
            scanf("%d", &posToPlay);
            int row = (posToPlay - 1) / 3; // this part would help us to know if the position they want to play has already been picked
            int col = (posToPlay - 1) % 3; // this part would help us to know if the position they want to play has already been picked

            if (posToPlay < 1 || posToPlay > 9)
            {
                printf("Invalid position. Please pick a number between 1 and 9: \n");
                continue;
            }
            if (board[row][col] == 'x' || board[row][col] == 'o')
            {
                printf("The position is already taken, please pick another one: \n");
                continue;
            }

            switch (posToPlay)
            { // this part is to input the users values into the code
            case 1:
                board[0][0] = 'o';
                break;
            case 2:
                board[0][1] = 'o';
                break;
            case 3:
                board[0][2] = 'o';
                break;
            case 4:
                board[1][0] = 'o';
                break;
            case 5:
                board[1][1] = 'o';
                break;
            case 6:
                board[1][2] = 'o';
                break;
            case 7:
                board[2][0] = 'o';
                break;
            case 8:
                board[2][1] = 'o';
                break;
            case 9:
                board[2][2] = 'o';
                break;

            default:
                printf("Please pick another number between thats on the board");
                scanf("%d", &posToPlay);
                break;
            }

            if ((board[0][0] == board[0][1]) && (board[0][1] == board[0][2]) || (board[1][0] == board[1][1]) && (board[1][1] == board[1][2]) || (board[2][0] == board[2][1]) && (board[2][1] == board[2][2]) || (board[0][0] == board[1][0]) && (board[1][0] == board[2][0]) || (board[0][1] == board[1][1]) && (board[1][1] == board[2][1]) || (board[0][2] == board[1][2]) && (board[1][2] == board[2][2]) || (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) || (board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))
            {
                twoWon = true;
                isRunning = false;
                break;
            }

            rounds++;
        }
        else
        {
            displayGrid(board);
            printf("Player 1, please pick a number to play: ");
            scanf("%d", &posToPlay);

            int row = (posToPlay - 1) / 3; // for example if the person picks 5, since its stored in an integer, the row and coulumn would be rounded down to 1 and 1 each
            int col = (posToPlay - 1) % 3;

            if (posToPlay < 1 || posToPlay > 9)
            {
                printf("Invalid position. Please pick a number between 1 and 9: \n");
                continue;
            }

            if (board[row][col] == 'x' || board[row][col] == 'o')
            {
                printf("The position is already taken, please pick another one: \n");
                continue;
            }

            switch (posToPlay)
            { // this part is to input the users values into the code
            case 1:
                board[0][0] = 'x';
                break;
            case 2:
                board[0][1] = 'x';
                break;
            case 3:
                board[0][2] = 'x';
                break;
            case 4:
                board[1][0] = 'x';
                break;
            case 5:
                board[1][1] = 'x';
                break;
            case 6:
                board[1][2] = 'x';
                break;
            case 7:
                board[2][0] = 'x';
                break;
            case 8:
                board[2][1] = 'x';
                break;
            case 9:
                board[2][2] = 'x';
                break;

            default:
                printf("Please pick another number between thats on the board");
                scanf("%d", &posToPlay);
                break;
            }
            rounds++;

            if ((board[0][0] == board[0][1]) && (board[0][1] == board[0][2]) || (board[1][0] == board[1][1]) && (board[1][1] == board[1][2]) || (board[2][0] == board[2][1]) && (board[2][1] == board[2][2]) || (board[0][0] == board[1][0]) && (board[1][0] == board[2][0]) || (board[0][1] == board[1][1]) && (board[1][1] == board[2][1]) || (board[0][2] == board[1][2]) && (board[1][2] == board[2][2]) || (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) || (board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))
            {
                oneWon = true;
                isRunning = false;
                break;
            }
        }
    }
    if (rounds == 9)
    {
        displayGrid(board);
        printf("It is a draw");
    }
    else if (oneWon)
    {
        displayGrid(board);
        printf("Player One wins!!!!!");
    }
    else if (twoWon)
    {
        displayGrid(board);
        printf("Player Two wins!!!!!");
    }
    return 0;
}