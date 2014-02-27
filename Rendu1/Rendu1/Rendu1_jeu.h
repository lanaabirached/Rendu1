//
//  jeu.h
//  Rendu1
//

#ifndef Rendu1_jeu_h
#define Rendu1_jeu_h

#include <stdbool.h>
#include <stdio.h>

#define bubble struct bubble

bubble* bubbles;

bubble {
	unsigned short size;
	float x, y;
};

void skipLine(FILE* file);

void parseGameFile(char* filePath);

#endif
