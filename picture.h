#pragma once

struct Point {
	double x;
	double y;
} typedef Point, Line;

void Rectangle(int width, int height);
void Triangle(Point g1, Point g2, Point g3);
int IsPointInTriangle(Point p, Point p0, Point p1, Point p2);
void Circle(void);
void Interline(void);
void Square(int side);
void Horline(void);
