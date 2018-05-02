#include<stdio.h>
#include "picture.h"
#include "screen.h"
double CalculateDistancePointToLine(Point p, Point g1, Point g2);
int IsPointInTriangle(Point p, Point p0, Point p1, Point p2);
int main(void) {
	clearScreen();
	int x = 0;
	Point g1 = { g1.x = 1, g1.y = 1 };
	Point g2 = { g2.x = 7, g2.y = 1 };
	Point g3 = { g3.x = 7, g3.y = 7 };
	printf("************************************************\n");
	printf("This is menu\n");
	printf("Rectangle : 1\nHorline : 2\nTriangle : 3\nCiecle : 4\nInterline : 5\nSquare : 6\n");
	printf("************************************************");
	scanf("%d", &x);
	switch(x){
       	case 1: Rectangle(5, 8);
	break;
	case 2: Horline();
	break;
	case 3: Triangle(g1, g2, g3);
	break;
	//Horline();
	case 4: Circle();
	break;
	//Horline();
	case 5: Interline();
	break;
	//Horline();
	case 6: Square(4);
	break;
	}
	getchar();
}
