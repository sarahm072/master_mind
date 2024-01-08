# Game Mastermind
Mastermind is a board game for two players whose goal is to find a code (color and position of 5 pegs) in 10 turns.
## Make game

This game was created using the following functions.

- The function "recouper_proposition()" retrieves the decoder's guess.

'''

    void retrieve_proposal(char proposal[5][20]) {
    for (int i = 0; i < 5; i++)
    {
        printf(" Enter your suggestion about box %d: ", i+1);
        scanf("%s", proposal[i]);

    }
    }
    


- The "evaluer()" function compares the codebreaker's combination with the decoder's guess. It determines the number of correctly placed pawns and the number of incorrectly placed pawns.

'''
    
    void evaluate(char combination[5][20], char proposal[5][20], int* nbGood, int* nbBad) {
    *nbGood = 0;
    *nbBad = 0;

    for (int i = 0; i < 5; i++)
    {
    if (strcmp(combination[i], proposal[i]) == 0)
        {
            (*nbGood)++;
            printf("%d A well-placed point \n",i+1);
        } else
        {
            for (int j = 0; j < 5; j++)
            {
                if (i != j && strcmp(combination[i], proposal[j]) == 0)
                {
                    (*nbBad)++;
                    printf("%d A badly placed point \n",i+1);
                    break;
                }
            }
        }
    }
    }



-The "jeu()" function progresses the game until the decoder guesses the codebreaker's combination or the maximum number of attempts is reached.
 
 '''

    void jeu() {
    printf(" \t\t    start! \n");
    printf("    There is 5 box array and there are 8 color guess the color of each box \n");
     printf(" The colors is: red, yellow, blue, green, purple, gray, black, white\n");
    char colors[8][20] = {"red","yellow","blue","green","purple","gray","black","white\n"};
    srand(time(0));

    char combination[5][20];
    for (int i = 0; i < 5; i++) {
        int randomNumber = rand() % 8;
        sprintf(combination[i], "%s", colors[randomNumber]);
    }
    int chances = 10;
      int nbGood, nbBad;


    while (chances > 0) {
        printf("\n\t\t\tThere are %d chances for you \n\n", chances);

        char proposal[5][20];
        retrieve_proposal(proposal);
        evaluate(combination, proposal, &nbGood, &nbBad);
        printf(" Number of colors well placed : %d\n", nbGood);
        printf(" Number of colors misplaced : %d\n", nbBad);

        if (nbGood == 5) {
            printf("  congratulations !\n");
            break;
        } else {
            chances--;
        }
    }

    if (chances == 0) {
        printf("game over!\n");
        for (int i = 0; i < 5; i++) {
        printf("%d:%s\t",i,combination[i]);
    }
    }
}
