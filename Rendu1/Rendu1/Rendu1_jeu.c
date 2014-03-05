//
//  jeu.c
//  Rendu1
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_PSEUDO 8
#define NBR_PLAYERS 2


#include "Rendu1_jeu.h"

static char pseudo[MAX_PSEUDO];
static float score[NBR_PLAYERS];
static short energie[NBR_PLAYERS], nb_disques[NBR_PLAYERS];
static float*** pos_C = NULL;
static short** val_disque = NULL;



void parseGameFile(char* filePath)
{
    FILE* gameFile = fopen(filePath, "r");
    
    bool endLecture = 0;
    unsigned short i = 0, j = 0;
    unsigned char playerId = 0;
    
    pos_C = (float***) calloc(NBR_PLAYERS, sizeof(float**));
    if (pos_C == NULL)
    {
        printf("Allocation failure."); // to change
    }
    
    do {
        switch (getc(gameFile)) {
                
            case '#':
                printf("diese!\n");                                             //
                skipLine(gameFile);
                break;
                
            case -1:
                endLecture = 1;
                break;
                
            case ' ': // to improve
                skipLine(gameFile);
                break;
                
            case '\n':
                break;
                
            case '\r':
                break;
                
            case '\t':
                break;
                
            default:
                fseek(gameFile, -1, SEEK_CUR);
                fscanf(gameFile, "%s", pseudo);
                fscanf(gameFile, "%f %hd %hd", &score[playerId],
                       &energie[playerId], &nb_disques[playerId]);
                
                // create position of C's table
                pos_C[playerId] = (float**) calloc(nb_disques[playerId], sizeof(float*));
                
                for (i = 0; i < nb_disques[playerId]; i++)
                {
                    pos_C[playerId][i] = (float*) calloc(2, sizeof(float));
                }
                
                // create value of the discs' table
                val_disque = (short**) calloc(NBR_PLAYERS, sizeof(short));
                
                for (i = 0; i < NBR_PLAYERS; i++) {
                    val_disque[playerId] = (short*) calloc(nb_disques[playerId], sizeof(short));
                }
                
                for (i = 0; i <= nb_disques[playerId]; i++)
                {
                    fscanf(gameFile, "%f %f ",
                           &pos_C[playerId][i][0] , &pos_C[playerId][i][1]);
                    fscanf(gameFile, "%hd", &val_disque[playerId][i]);
                }
                
                    
                    printf("[ pseudo = %s  ]\n",pseudo);
                    printf("[ score  = %f  ]\n",score[0]);
                    printf("[ energi = %hd ]\n",energie[0]);
                    printf("[ nb_dis = %hd ]\n",nb_disques[0]);
                    
                    playerId++;
                    
                    break;
                }
                
    } while (!endLecture);
    
}

void skipLine(FILE* file)
{
    printf(".");
	while(getc(file) != '\n');
}