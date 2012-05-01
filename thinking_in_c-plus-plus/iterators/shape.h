#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

class Shape
{
public:
	virtual void draw() = 0;
	virtual void erase() = 0;
	virtual ~Shape(){}
};

class Circle : public Shape
{
public:
	void draw()
	{ std::cout << "Circle::draw()" << std::endl; }

	void erase()
	{ std::cout << "Circle::erase()" << std::endl; }

	~Circle()
	{ std::cout << "Circle::~Circle()" << std::endl; }
};

class Square: public Shape
{
public:
	void draw()
	{ std::cout << "Square::draw()" << std::endl; }
	void erase()
	{ std::cout << "Square::erase()" << std::endl; }
	~Square()
	{ std::cout << "Square::Square~()" << std::endl; }
};

class Line : public Shape
{
public:
	void draw()
	{ std::cout << "Line::draw()" << std::endl; }
	void erase()
	{ std::cout << "Line::erase()" << std::endl; }
	~Line()
	{ std::cout << "Line::~Line()" << std::endl; }
};

#endif //SHAPE_H
