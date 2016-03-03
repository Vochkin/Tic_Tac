#pragma once
#include <iostream>
#include <conio.h>
#include <gl\glut.h>
#include <Windows.h>
using namespace std;

extern int w, h, Size, Scale;
extern bool b;


class Circle 
{
private:
	double radius = 50;

public:
	int x_c; int y_c;
	
	void Draw_Circle()
	{
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINE_LOOP);
		for (int j = -2;j < 3;j++)
			for (float i = 0.0; i < 2 * 3.14; i += 3.14 / 18)
			{			
				glVertex2f(this->x_c+j + this->radius*sin(i), this->y_c + j + this->radius*cos(i));
			}
		glEnd();
		
	}
};

class Dagger 
{
public:
	int x_d[4]; int y_d[4];
	
	void Draw_Dagger();
	

};
void Dagger::Draw_Dagger()
{
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);

	for (int i = 0;i < 4;i += 2)
	{
		for (int j = -2;j < 3;j++)
		{
			glVertex2f(x_d[i] + j, y_d[i]); glVertex2f(x_d[i + 1] + j, y_d[i + 1]);
		}
	}
	glEnd();
}