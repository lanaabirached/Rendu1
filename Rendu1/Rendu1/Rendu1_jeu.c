//
//  jeu.c
//  Rendu1
//

#include <stdio.h>
#include <stdlib.h>

#define PROG_DEBUG false
#define MAX_PSEUDO 8
#define NBR_PLAYERS 2



#include "Rendu1_jeu.h"

static char pseudo[MAX_PSEUDO + 1];
static short score[NBR_PLAYERS];
static unsigned short energie[NBR_PLAYERS], nb_disques[NBR_PLAYERS];
static float*** pos_C = NULL;
static unsigned short** val_disque = NULL;

bool parseGameFile(char* filePath)
{
    FILE* gameFile = fopen(filePath, "r");

    if (gameFile == NULL) {
        printf("#ERROR: Unable to load file.\n");
        return false;
    }
    
    bool endLecture = false;
    unsigned short playerId = 0;
    int reader;

    pos_C       = (float***) calloc(NBR_PLAYERS, sizeof(float**));
    val_disque  = (unsigned short**) calloc(NBR_PLAYERS, sizeof(float*));
    
    do {
        switch (getc(gameFile)) {
            case '#':
                if (PROG_DEBUG) printf("Comment!\n");                                             //
                skipLine(gameFile);
                break;

            case -1:
                endLecture = true;
                break;

            case ' ': // to improve
            case '\r':
            case '\t':
                skipLine(gameFile);
                break;
            case '\n':
                break;

            default:
                fseek(gameFile, -1, SEEK_CUR);
                
                // read pseudo
                fscanf(gameFile, "%8s", pseudo); // to add, max pseudo
                if (getc(gameFile) != ' ')
                    printf("#WARNING: Pseudo too long.\n");
                
                // read score
                if(!fscanf(gameFile, "%hd", &score[playerId]))
                {
                    printf("#ERROR: Unable to read score.\n");
                    return false;
                }
                // read energy
                if(!fscanf(gameFile, "%d", &reader))
                {
                    printf("#ERROR: Unable to read energy.\n");
                    return false;
                }
                if (reader < 0) {
                    printf("#ERROR: Negative energy.\n");
                    return false;
                }
                energie[playerId] = reader;
                
                // read number of disks
                if(!fscanf(gameFile, "%d", &reader))
                {
                    printf("#ERROR: Unable to read number of disks.\n");
                    return false;
                }
                if (reader < 0) {
                    printf("#ERROR: Negative number of disks.\n");
                    return false;
                }
                nb_disques[playerId] = reader;
                
                // read disks
                pos_C[playerId] = (float**) calloc(nb_disques[playerId], sizeof(float*));
                val_disque[playerId] = (unsigned short*) calloc(nb_disques[playerId], sizeof(unsigned short));
                
                for (unsigned short i=0; i < nb_disques[playerId]; i++)
                    pos_C[playerId] = calloc(2, sizeof(float));
                
                printf("%d", nb_disques[playerId]);
                pos_C[playerId][0][0] = 42;
                pos_C[playerId][0][1] = 77;
                
                
                
//                if(!fscanf(gameFile, "%f %hd %hd", &score[playerId],
//                       &energie[playerId], &nb_disques[playerId]))
//                {
//                    printf("ERROR: Unable to read player info.");
//                    return false;
//                }
//                
//                if(score[playerId] < 0)
//                    
//                
//                
//                if (PROG_DEBUG)
//                {
//                    printf("\n");
//                    printf("[ pseudo = %s  \n",pseudo);
//                    printf("[ score  = %f  \n",score[playerId]);
//                    printf("[ energi = %hd \n",energie[playerId]);
//                    printf("[ nb_dis = %hd \n",nb_disques[playerId]);
//                    //                    for (unsigned short i = 0; i <= nb_disques[playerId]; i++)
//                    //                    {
//                    //                        printf("%f %f ", pos_C[playerId][i][0] , pos_C[playerId][i][1]); //problem ???
//                    //                        printf("%hd", val_disque[playerId][i]);
//                    //                    }
//                    
//                }
//                
//                // create position of C's table
//                pos_C = (float***) calloc(NBR_PLAYERS, sizeof(float**));
//                
//                for (unsigned short i = 0; i < 2 ; i++)
//                {
//                    pos_C[i] = (float**) calloc(nb_disques[i], sizeof(float*));
//                    
//                    for (unsigned short j = 0; j < nb_disques[playerId]; j++)
//                    {
//                        pos_C[i][j] = (float*) calloc(2, sizeof(float));
//                    }
//                }
//                
//                // create value of the discs' table
//                val_disque = (short**) calloc(NBR_PLAYERS, sizeof(short));
//                
//                for (unsigned short i = 0; i < NBR_PLAYERS; i++)
//                {
//                    val_disque[playerId] = (short*) calloc(nb_disques[playerId], sizeof(short));
//                }
//                
//                
//                for (unsigned short i = 0; i <= nb_disques[playerId]; i++)
//                {
//                    fscanf(gameFile, "%f %f",
//                           &pos_C[playerId][i][0] , &pos_C[playerId][i][1]);
//                    fscanf(gameFile, "%hd", &val_disque[playerId][i]);
//                }
//                
//                if (PROG_DEBUG)
//                {
//                    printf("\n");
//                    printf("[ pseudo = %s  \n",pseudo);
//                    printf("[ score  = %f  \n",score[playerId]);
//                    printf("[ energi = %hd \n",energie[playerId]);
//                    printf("[ nb_dis = %hd \n",nb_disques[playerId]);
////                    for (unsigned short i = 0; i <= nb_disques[playerId]; i++)
////                    {
////                        printf("%f %f ", pos_C[playerId][i][0] , pos_C[playerId][i][1]); //problem ???
////                        printf("%hd", val_disque[playerId][i]);
////                    }
//                    
//                }
                
                
                
                    playerId++;
                
                
                    break;
                }
                
    } while (!endLecture);
    
    return true;
}

void skipLine(FILE* file)
{
	while(getc(file) != '\n');
}