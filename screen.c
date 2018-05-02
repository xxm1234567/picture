#include "screen.h"
#include<stdio.h>

void clearScreen(void){
	printf("%c[2J",ESC);
	fflush(stdout);
}
void setColor(int color){
	printf("%c[1;%dm",ESC,color);
	fflush(stdout);
}
