#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const  NUM_PAWNS=5;
const  NUM_COLORS=7;

void retrieve_proposal();
void evaluate();
void jeu();


int main() {
    jeu();
    return 0;
}    


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
            printf("\033[1;32m");
            printf("%d A well-placed point \n",i+1);
            printf("\033[0m");
        } else
        {
            for (int j = 0; j < NUM_PAWNS; j++)
            {
                if (i != j && strcmp(combination[i], proposal[j]) == 0)
                {
                    (*nbBad)++;
                    printf("\033[1;31m");
                    printf("%d A badly placed point \n",i+1);
                    printf("\033[0m");
                    break;
                }
            }
        }
   }
}

void jeu() {
    printf(" \t\t    start! \n");
    printf("    There is 5 box array and there are 7 color guess the color of each box \n");
     printf(" The colors is: \n");
     printf("\033[1;31m"); printf("\t▓▓▓▓\t"); printf("red\n");
     printf("\033[1;33m"); printf("\t▓▓▓▓\t"); printf("yellow\n");
     printf("\033[1;32m"); printf("\t▓▓▓▓\t"); printf("green\n");
     printf("\033[1;34m"); printf("\t▓▓▓▓\t"); printf("bleu\n");
     printf("\033[1;35m"); printf("\t▓▓▓▓\t"); printf("purple\n");
     printf("\033[1;37m"); printf("\t▓▓▓▓\t"); printf("white\n");
     printf("\033[1;30m"); printf("\t▓▓▓▓\t"); printf("black\n");
     printf("\033[0m");
    char colors[NUM_COLORS][20] = {"red","yellow","blue","green","purple","black","white\n"};
    srand(time(0));
    char combination[NUM_PAWNS][20];
    for (int i = 0; i < NUM_PAWNS; i++) 
    {
        int randomNumber = rand() % 7;
        sprintf(combination[i], "%s", colors[randomNumber]);
    }
      int nbGood, nbBad;
       int chances=2 ;
    while (chances > 0) {
        printf("\n\t There are %d chances for you \n\n", chances);
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
             chances--;
        }
    }
    if (chances == 0) {
        system("@cls||clear");
        printf("game over!\n");
        for (int i = 0; i < NUM_PAWNS; i++) {
        printf("%d:%s\n",i+1,combination[i]);
    }
    }
}
