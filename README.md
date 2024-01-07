# Jeu Mester mind
Master mind est un jeu de sociétè pour deux joueurs dont le but est trouver un code (couleur et position de 5 pions ) en 10 coups.
## Faire de jeu

Cette jeu a été créé à l'aide des fonctions suivantes

- la fonction recouper_proposition() qui récupère la proposition du décodeur

'''

    void recuperer_proposition(char proposition[5][20]) {
    for (int i = 0; i < 5; i++)
    {
        scanf("%s", proposition [i]);
    }
    }
    


- la fonction evaluer() qui compare la combinaison du codificateur et la proposition décodeur et déduit le nombre de pions bien placés et le nombre d epionts mal placés

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


-le fonction jeu() qui déroule le jeu jusqu'à ce que le décodeur devine la codificateur, ou que le nombre d'essais maximal soit atteint
 
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
