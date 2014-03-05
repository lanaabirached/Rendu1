//
//  jeu.c
//  Rendu1
//

#include <stdio.h>
#include <stdlib.h>

#define PROG_DEBUG 1
#define MAX_PSEUDO 8
#define NBR_PLAYERS 2



#include "Rendu1_jeu.h"

static char pseudo[MAX_PSEUDO + 1];
static float score[NBR_PLAYERS];
static short energie[NBR_PLAYERS], nb_disques[NBR_PLAYERS];
static float*** pos_C = NULL;
static short** val_disque = NULL;



void parseGameFile(char* filePath)
{
    FILE* gameFile = fopen(filePath, "r");
    
    bool endLecture = 0;
    unsigned short i = 0, j = 0;
    unsigned short playerId = 0;
    
    do {
        switch (getc(gameFile)) {
                
            case '#':
                if (PROG_DEBUG) printf("diese!\n");                                             //
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
                pos_C = (float***) calloc(NBR_PLAYERS, sizeof(float**));
                
                for (i = 0; i < 2 ; i++)
                {
                    pos_C[i] = (float**) calloc(nb_disques[i], sizeof(float*));
                    
                    for (j = 0; j < nb_disques[playerId]; j++)
                    {
                        pos_C[i][j] = (float*) calloc(2, sizeof(float));
                    }
                }
                
                // create value of the discs' table
                val_disque = (short**) calloc(NBR_PLAYERS, sizeof(short));
                
                for (i = 0; i < NBR_PLAYERS; i++)
                {
                    val_disque[playerId] = (short*) calloc(nb_disques[playerId], sizeof(short));
                }
                
                
                for (i = 0; i <= nb_disques[playerId]; i++)
                {
                    fscanf(gameFile, "%f %f",
                           &pos_C[playerId][i][0] , &pos_C[playerId][i][1]);
                    fscanf(gameFile, "%hd", &val_disque[playerId][i]);
                }
                
                if (PROG_DEBUG)
                {
                    printf("\n");
                    printf("[ pseudo = %s  \n",pseudo);
                    printf("[ score  = %f  \n",score[playerId]);
                    printf("[ energi = %hd \n",energie[playerId]);
                    printf("[ nb_dis = %hd \n",nb_disques[playerId]);
                    for (i = 0; i <= nb_disques[playerId]; i++)
                    {
                        printf("%f %f ", pos_C[playerId][i][0] , pos_C[playerId][i][1]); //problem ???
                        printf("%hd", val_disque[playerId][i]);
                    }
                    
                }
                
                
                
                    playerId++;
                
                
                    break;
                }
                
    } while (!endLecture);
    
}

void skipLine(FILE* file)
{
    printf(".\n");
	while(getc(file) != '\n');
}