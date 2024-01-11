// 7.4_2.cpp :

#define _USE_MATH_DEFINES
#include"shape.h"
#include<cmath>

double Shape::square() {
	return 0;
}

double Shape::volume() {
	return 0;
}

Line::Line(int _x1, int _y1, int _x2, int _y2) {
	x1 = _x1; y1 = _y1;
	x2 = _x2; y2 = _y2;
}

double Line::side() {
	return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

void Line::shift(int m, int n, int k) {
	x1 += m; y1 += n;
	x2 += m; y2 += n;
}

void Line::scaleX(int a) {
	x1 *= a;
	x2 *= a;
}

void Line::scaleY(int d) {
	y1 *= d;
	y2 *= d;
}

void Line::scaleZ(int e) {
	z1 *= e;
	z2 *= e;
}

void Line::scale(int s) {
	x1 /= s;  y1 /= s;
	x2 /= s;  y2 /= s;
}


Sqr::Sqr(int _x1, int _y1, int _x2, int _y2) : Line(_x1, _y1, _x2, _y2) {
	x3 = ((_x1 + _x2) / 2 + (_y1 + _y2) / 2 - _y1);
	y3 = ((_x1 + _x2) / 2 + (_y1 + _y2) / 2 - _x1);
	x4 = ((_x1 + _x2) / 2 - (_y1 + _y2) / 2 + _y1);
	y4 = ((_y1 + _y2) / 2 - (_x1 + _x2) / 2 + _x1);
}

double Sqr::square() {
	return pow((x1 - x2), 2) + pow((y1 - y2), 2);
}

void Sqr::shift(int m, int n, int k) {
	Line::shift(m, n, k);
	x3 += m; y3 += n;
	x4 += m; y4 += n;
}

void Sqr::scaleX(int a) {
	Line::scaleX(a);
	x3 *= a;
	x4 *= a;
}

void Sqr::scaleY(int a) {
	Line::scaleY(a);
	y3 *= a;
	y4 *= a;
}

void Sqr::scaleZ(int a) {
	Line::scaleZ(a);
	z3 *= a;
	z4 *= a;
}

void Sqr::scale(int s) {
	Line::scale(s);
	x3 /= s; y3 /= s;
	x4 /= s; y4 /= s;
}


Cube::Cube(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3) : Sqr(_x1, _y1, _x2, _y2)
{
	double d = sqrt(pow(_x2 - _x1, 2) + pow(_y2 - _y1, 2) + pow(_z2 - _z1, 2));

	x1 = _x1; y1 = _y1; z1 = _z1;
	x2 = _x2; y2 = _y2; z2 = _z2;
	x3 = _x3; y3 = _y3; z3 = _z3;

	double xc = (_x1 + _x2 + _x3) / 3;
	double yc = (_y1 + _y2 + _y3) / 3;
	double zc = (_z1 + _z2 + _z3) / 3;

	x4 = xc + d / 2;
	y4 = yc + d / 2;
	z4 = zc + d / 2;

	x5 = xc - d / 2;
	y5 = yc + d / 2;
	z5 = zc + d / 2;

	x6 = xc - d / 2;
	y6 = yc - d / 2;
	z6 = zc + d / 2;

	x7 = xc + d / 2;
	y7 = yc - d / 2;
	z7 = zc + d / 2;

	x8 = xc + d / 2;
	y8 = yc - d / 2;
	z8 = zc - d / 2;
}

double Cube::square() {
	double d = (pow((x1 - x2), 2) + pow((y1 - y2), 2));

	return d * 6;
}

double Cube::volume() {
	double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));

	return pow(d, 2);
}

void Cube::shift(int m, int n, int k) {
	Sqr::shift(m, n, k);
	x5 += m; y5 += n; z5 += k;
	x6 += m; y6 += n; z6 += k;
	x7 += m; y7 += n; z7 += k;
	x8 += m; y8 += n; z8 += k;
}

void Cube::scaleX(int a) {
	Sqr::scaleX(a);
	x5 *= a;
	x6 *= a;
	x7 *= a;
	x8 *= a;
}

void Cube::scaleY(int a) {
	Sqr::scaleY(a);
	y5 *= a;
	y6 *= a;
	y7 *= a;
	y8 *= a;
}

void Cube::scaleZ(int a) {
	Sqr::scaleZ(a);
	z5 *= a;
	z6 *= a;
	z7 *= a;
	z8 *= a;
}

void Cube::scale(int s) {
	Sqr::scale(s);
	x5 /= s; y5 /= s; z5 /= s;
	x6 /= s; y6 /= s; z6 /= s;
	x7 /= s; y7 /= s; z7 /= s;
	x8 /= s; y8 /= s; z8 /= s;
}


Circle::Circle(int _x1, int _y1, double R) {
	x1 = _x1; y1 = _y1;
	radius = R;
}

double Circle::square() {
	return M_PI * radius * radius;
}

Cylinder::Cylinder(int _x1, int _y1, double R, double H) : Circle(_x1, _y1, R) {
	height = H;
}

double Cylinder::square() {
	return M_PI * radius * radius + 2 * radius * height;
}

double Cylinder::volume() {
	return M_PI * radius * radius * height;
}