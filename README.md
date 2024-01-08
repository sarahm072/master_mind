# Game Master mind
Mastermind is a board game for two players whose goal is to find a code (color and position of 5 pegs) in 10 turns.
## Make game

This game was created using the following functions.

- The function "recouper_proposition()" retrieves the decoder's guess.

'''

    void recuperer_proposition(char proposition[5][20]) {
    for (int i = 0; i < 5; i++)
    {
        scanf("%s", proposition [i]);
    }
    }
    


- The "evaluer()" function compares the codebreaker's combination with the decoder's guess. It determines the number of correctly placed pawns and the number of incorrectly placed pawns.

'''
    
    void evaluer(char combinaison[5][20], char proposition[5][20], int* nbBien, int* nbMal) {
    *nbBien = 0;
    *nbMal = 0;
    for (int i = 0; i < 5; i++)
     {
     if (strcmp(combinaison[i], proposition[i]) == 0)
        {
            (*nbBien)++;
            printf("%d un poin bien place\n",i+1);
        } else
        {
            for (int j = 0; j < 5; j++)
            {
                if (i != j && strcmp(combinaison[j], proposition[i]) == 0)
                {
                    (*nbMal)++;
                    printf("%d un poin mal place\n",i+1);
                    break;
                }
            }
        }
      }
    }


-The "jeu()" function progresses the game until the decoder guesses the codebreaker's combination or the maximum number of attempts is reached.
 
 '''

    void jeu() {

    srand(time(0));
    char combinaison[5][20];
    for (int i = 0; i < 5; i++) {
        int randomNumber = rand() % 8;
        sprintf(combinaison[i], "%s", colors[randomNumber]);
    }
    int chances = 10;
      int nbBien, nbMal;
    while (chances > 0) {
        char proposition[5][20];
        recuperer_proposition(proposition);
        evaluer(combinaison, proposition, &nbBien, &nbMal);
        if (nbBien == 5) {
            printf("congratulations !\n");
            break;
        } else {
            chances--;
        }
    }

     if (chances == 0) 
     {
        printf("game over!\n");
     }
    }
