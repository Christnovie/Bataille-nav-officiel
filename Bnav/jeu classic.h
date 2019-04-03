//
// Created by Christnovie.KIALA-BI on 22.03.2019.
//

#ifndef UNTITLED2_JEU_CLASSIC_H
#define UNTITLED2_JEU_CLASSIC_H

#endif //UNTITLED2_JEU_CLASSIC_H
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <mmsystem.h>
#pragma  execution_charater_set("utf-8")
#define BATEAUX5 5
#define BATEAUX4 4
#define BATEAUX3 3
#define BATEAUX2 2


#define GRILLESIZE 10

int tryAgains(int nbintro){
    while(nbintro > GRILLESIZE){
        printf("erreur valeur max est de %d",GRILLESIZE);
        printf("\nreintroduser la valeur: ");
        scanf("%d",&nbintro);
    }
    return nbintro;
}

void jeuClasic (int niveau) {
    SetConsoleOutputCP(65001);
    int Zero = 0,vivant = 1;
    // initialization du tableau//
    int b5[BATEAUX5]={vivant,vivant,vivant,vivant,vivant};
    int b4[BATEAUX4]={vivant,vivant,vivant,vivant};
    int b3[BATEAUX3]={vivant,vivant,vivant};
    int b2[BATEAUX2]={vivant,vivant};
    int b22[BATEAUX2]={vivant,vivant};

    int nbBateau = BATEAUX2 +BATEAUX5+BATEAUX3+BATEAUX4+BATEAUX2;
    int quitter ,lign,col,a = 0,i = 0,nbrand1,nbrand2,nbacrement,placement,placeV,placeH,num;
    int nbcoup,choixMode;


    int grille[GRILLESIZE][GRILLESIZE];
    for (lign = 0;lign < GRILLESIZE;lign++){
        for(col = 0;col < GRILLESIZE;col++){
            grille[lign][col]=Zero;
        }
    }

    char grile[GRILLESIZE][GRILLESIZE];
    for (lign = 0;lign < GRILLESIZE;lign++){
        for(col = 0;col < GRILLESIZE;col++){
            grile[lign][col]=*"-";
        }
    }


    srand( (unsigned)time( NULL ) );
    nbrand1 = rand() % 9;
    nbrand2 = rand() % 9;
    placement = 1 + rand() % 2;
    placeH = nbrand1;
    placeV = nbrand2;
    printf("%d %d",placeH,placeV);
    if(placement == 1){
        for (i = 0;i < BATEAUX5;i++){
            grille[placeH][placeV] = vivant;
            placeH++;
        }

    } else{
        for (i = 0;i < BATEAUX5;i++){
            grille[placeH][placeV] = vivant;
            placeV++;
        }
    }


    system("cls");
    printf("Choisir le mode:\n1.Mode score\n2.Mode coup restant\n0.quitter");
    scanf("%d",&choixMode);

if(choixMode == 2){
    nbcoup = niveau;} else{
    if (choixMode < 2){
    nbcoup = 0;} else {
    }
}

if(choixMode !=0) {
    do {
        placeV = 0;
        placeH = 0;
        num = 1;

        quitter = 0;
        printf("   coup restant: %d\n", nbcoup);
        printf("\n  1 2 3 4 5 6 7 8 9 10\n ");
        printf("_______________________\n ");
        for (a = 0; a < GRILLESIZE; a++) {
            printf("|");
            for (i = 0; i < GRILLESIZE; i++) {

                printf("%c|", grile[placeH][placeV]);

                placeV++;
            }
            printf("|%d\n ", num);

            num++;
        }
        printf("------------------------");
        printf("\n(entrer deux fois 0 de la grile  pour quitter)");
        printf("\nEntrer  la ligne:");
        scanf("%d", &lign);
        if(lign > GRILLESIZE){
            lign= tryAgains(lign);
        }
        printf("\nEntrer la colone:");
        scanf("%d", &col);
        if(col > GRILLESIZE){

            col = tryAgains(col);
        }
        col = col - 1;
        lign = lign - 1;


        while (grille[lign][col] == 2) {
            printf("La case a deja ete selectioner");
            printf("Try Again\n");
            printf("\nEntrer  la ligne:");
            scanf("%d", &lign);
            if(lign > GRILLESIZE){
                lign= tryAgains(lign);
            }
            printf("\nEntrer la colone:");
            scanf("%d", &col);
            if(col > GRILLESIZE){

                col = tryAgains(col);
            }
            col = col - 1;
            lign = lign - 1;
        }

        if (col == -1 && lign == -1) {
            quitter = 1;
        } else {
            if (grille[lign][col] == 1) {
                printf("Toucher\n");
                system("pause");
                grile[lign][col] = *"O";
                grille[lign][col] = 2;

            } else {
                printf("Rater\n");
                system("pause");
                grille[lign][col] = 2;
                grile[lign][col] = *"X";
            }


        }
        system("cls");
        if(choixMode == 1){
            nbcoup++;
        }else{
        nbcoup--;}
    } while ((quitter != 1) && (nbcoup != 0) );

    if(nbcoup==0 || nbcoup < nbBateau){
        printf("Partie perdu\n");

    } else{
        if(nbBateau == 0){
            printf("Bravo partie gagné\n");
        }
    }
}


}

