//
//  jeu.c
//  Rendu1
//

#include <stdio.h>

#include "Rendu1_jeu.h"

void parseGameFile(char* filePath)
{

}

void skipLine(FILE* file)
{
	while(getc(file) != '\n');
}