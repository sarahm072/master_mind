#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void retrieve_proposal(char proposal[5][20]) {
    for (int i = 0; i < 5; i++)
    {
        printf(" Enter your suggestion about box %d: ", i+1);
        scanf("%s", proposal[i]);

    }
}

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

int main() {
    jeu();
    return 0;
}

