#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const  CHANCES = 10;
const  NUM_PAWNS=5;
const  NUM_COLORS=8;


void retrieve_proposal(char proposal[NUM_PAWNS][20]) {
    for (int i = 0; i <NUM_PAWNS; i++)
    {
        printf(" Enter your suggestion about box %d: ", i+1);
        scanf("%s", proposal[i]);

    }
}

void evaluate(char combination[NUM_PAWNS][20], char proposal[NUM_PAWNS][20], int* nbGood, int* nbBad) {
    *nbGood = 0;
    *nbBad = 0;

    for (int i = 0; i < NUM_PAWNS; i++)
   {
        if (strcmp(combination[i], proposal[i]) == 0)
        {
            (*nbGood)++;
            printf("%d A well-placed point \n",i+1);
        } else
        {
            for (int j = 0; j < NUM_PAWNS; j++)
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
    char colors[NUM_COLORS][20] = {"red","yellow","blue","green","purple","gray","black","white\n"};
    srand(time(0));

    char combination[NUM_PAWNS][20];
    for (int i = 0; i < NUM_PAWNS; i++) {
        int randomNumber = rand() % 8;
        sprintf(combination[i], "%s", colors[randomNumber]);
    }
      int nbGood, nbBad;


    while (CHANCES > 0) {
        printf("\n\t\t\tThere are %d chances for you \n\n", CHANCES);

        char proposal[NUM_PAWNS][20];
        retrieve_proposal(proposal);
        evaluate(combination, proposal, &nbGood, &nbBad);
        printf(" Number of colors well placed : %d\n", nbGood);
        printf(" Number of colors misplaced : %d\n", nbBad);

        if (nbGood == 5) {
            system("@cls||clear");
            printf("  congratulations !\n");
            break;
        } else {
            CHANCES--;
        }
    }

    if (CHANCES == 0) {
        system("@cls||clear");
        printf("game over!\n");
        for (int i = 0; i < NUM_PAWNS; i++) {
        printf("%d:%s\t",i,combination[i]);
    }
    }
}

int main() {
    jeu();
    return 0;
}

