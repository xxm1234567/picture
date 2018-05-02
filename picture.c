#include <stdio.h>
#include <math.h>
#include "picture.h"

#define R 10
#define X 10
#define Y 10

double CalculateDistancePointToLine(Point p, Point g1, Point g2);
int IsPointInTriangle(Point p, Point p0, Point p1, Point p2);

void Rectangle(int width, int height) {
	int maxRow = 10, maxColumn = 10;
	int x = 0;
	int y = 0;
	// visit every coordinate one time (x, y)
	for (x = 0; x <= maxRow; x++) {
		// when the x coordinate pass the width, the drawing is finished
		if (x > width) {
			break;
		}
		for (y = 0; y <= maxColumn; y++) {
			// when the y coordinate pass the height, go to next column
			if (y > height) {
				break;
			}
			// check, whether the coordinate is on a line
			if (x <= width && y == 0 ||
				x == 0 && y <= height ||
				x == width && y <= height ||
				x <= width && y == height) {
				printf("*");
			}
			printf("\t");
		}
		printf("\n");
	}
}

double CalculateDistancePointToLine(Point p, Point g1, Point g2) {
	// calculate vector between the two points
	Line v = {
		v.x = g2.x - g1.x,
		v.y = g2.y - g1.y
	};
	// t for perpendicular
	double t = (v.x * (g1.x - p.x) + v.y * (g1.y - p.y)) / (-(pow(v.x, 2) + pow(v.y, 2)));
	// perpendicular point
	Point l = {
		l.x = g1.x + t * v.x,
		l.y = g1.y + t * v.y
	};
	// calculate distance
	return sqrt(pow(l.x - p.x, 2) + pow(l.y - p.y, 2));
}

int IsPointInTriangle(Point p, Point p0, Point p1, Point p2) {
	double A = (1 / (double)2) * (-p1.y * p2.x + p0.y * (-p1.x + p2.x) + p0.x * (p1.y - p2.y) + p1.x * p2.y);
	double sign = A < 0 ? -1 : 1;
	double s = (p0.y * p2.x - p0.x * p2.y + (p2.y - p0.y) * p.x + (p0.x - p2.x) * p.y) * sign;
	double t = (p0.x * p1.y - p0.y * p1.x + (p0.y - p1.y) * p.x + (p1.x - p0.x) * p.y) * sign;

	return s >= 0 && t >= 0 && (s + t) <= 2 * A * sign;
}

void Triangle(Point g1, Point g2, Point g3) {
	int maxRow = 10, maxColumn = 10;
	int x = 0;
	int y = 0;
	// visit every coordinate one time (x, y), start with 1
	for (x = 0; x <= maxRow; x++) {
		for (y = 0; y <= maxColumn; y++) {
			// check, whether the coordinate is on a line
			Point p = { p.x = x, p.y = y };
			if (IsPointInTriangle(p, g1, g2, g3) && (
				CalculateDistancePointToLine(p, g1, g2) < 0.5 ||
				CalculateDistancePointToLine(p, g2, g3) < 0.5 ||
				CalculateDistancePointToLine(p, g3, g1) < 0.5)) {
				printf("*");
			}
			printf("\t");
		}
		printf("\n");
	}
}

void Circle(void) {
	int x, y;
	int m;
	int i;
	for (y = R; y >= -R; y--) {
		m = 2 * sqrt(R*R - y * y);
		for (x = 1; x < X + R - m; x++) {
			printf(" ");
		}
		printf("*");
		for (; x < X + R + m; x++) {
			printf(" ");
		}
		printf("*\n");
	}
}

void Interline(void) {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < i; j++) {
			printf(" ");
		}
		for (j = 0; j < 7 - 2 * i; j++) {
			if (j == 0 || j == 6 - 2 * i) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	for (i = 0; i < 4; i++) {
		for (j = 3; j > i; j--) {
			printf(" ");
		}
		for (j = 0; j < 2 * i + 1; j++) {
			if (j == 0 || j == 2 * i) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

void Square(int side) {
	Rectangle(side, side);
}

void Horline(void) {
	printf("*******************************\n");
}
