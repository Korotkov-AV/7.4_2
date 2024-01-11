#pragma once

class Shape
{
public:
	Shape() = default;

	virtual double square();
	virtual double volume();
};


class Line : public Shape
{
public:
	Line() = default;

	Line(int _x1, int _y1, int _x2, int _y2);

	int x1 = 0, y1 = 0, z1 = 0,
		x2 = 0, y2 = 0, z2 = 0;

	double side();

	virtual void shift(int m, int n, int k);
	virtual void scaleX(int a);
	virtual void scaleY(int d);
	virtual void scaleZ(int e);
	virtual void scale(int s);
};

class Sqr : public Line
{
public:
	Sqr() = default;

	Sqr(int _x1, int _y1, int _x2, int _y2);

	int x3 = 0, y3 = 0, z3 = 0,
		x4 = 0, y4 = 0, z4 = 0;

	double square() override;

	void shift(int m, int n, int k) override;
	void scaleX(int a) override;
	void scaleY(int d) override;
	void scaleZ(int e) override;
	void scale(int s) override;
};

class Cube : public Sqr
{
public:
	Cube() = default;

	Cube(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3);

	int	x5 = 0, y5 = 0, z5 = 0,
		x6 = 0, y6 = 0, z6 = 0,
		x7 = 0, y7 = 0, z7 = 0,
		x8 = 0, y8 = 0, z8 = 0;

	double square() override;
	double volume() override;

	void shift(int m, int n, int k) override;
	void scaleX(int a) override;
	void scaleY(int d) override;
	void scaleZ(int e) override;
	void scale(int s) override;
};

class Circle : public Shape
{
public:
	int x1 = 0, y1 = 0;
	double radius;

	Circle(int _x1, int _y1, double R);

	double square() override;
};

class Cylinder : public Circle
{
public:
	double height;

	Cylinder(int _x1, int _y1, double R, double H);

	double square() override;
	double volume() override;
};

