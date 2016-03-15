#include "Extra.h"

int Size = 3; int Scale = 150;
int w = Size * Scale; int h = w;
bool a = true;//Game Over
bool b = false;//or circle or dugger


Circle *circ = new Circle[Size*Size];
Dagger *dag = new Dagger[Size*Size];
int *p = new int[Size*Size];//contains value,which points on the circle or dagger

void func()// function for initialization begining value, that isn't equal field's coords 
{
	for (int i = 0;i < Size*Size;i++)
	{
		circ[i].x_c = -1000000;
		circ[i].y_c = -1000000;

		dag[i].x_d[0] = -1000;dag[i].y_d[1] = -1000000;dag[i].y_d[2] = -1000;dag[i].y_d[3] = -100000;
		dag[i].y_d[0] = -1000000;dag[i].y_d[1] = -1000000;dag[i].y_d[2] = -1000;dag[i].y_d[3] = -1000000;
	
	}
}

void Field()
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	for (int j = -2;j < 3;j++)
		for (int i = -h/2+150;i < h/2;i+=150)
		{		
			glVertex2f(-w/2, i+j);
			glVertex2f(w/2, i + j);

			glVertex2f(i + j, -h/2);
			glVertex2f(i + j, h/2);
				
		}
	glEnd();
}

void Winner()
{
	int win = 0;
	if(win ==0){
		for (int i = 0;i < Size;i++)//winner in horizontal
	{
		int time = p[Size*i];
		for (int j = 0;j < Size;j++)
		{
			if (p[Size*i + j] == time) win = time;
			else
			{
				win = 0;break;
			}
		}
		if (win == 1)
			glutSetWindowTitle("Won player 1!!!");

		else if (win == 2)
			glutSetWindowTitle("Won player 2!!!");

		if ((win == 1 || win == 2))//draw line 
		{
			if(win == 2) glColor3f(1.0, 0.0, 0.0);
			else  glColor3f(0.0, 0.0, 1.0);
			glBegin(GL_LINES);
			for (int j = -2;j < 3;j++)
			{
				glVertex2f(-w / 2, ((h / 2 - Scale/2) - Scale*i + j));glVertex2f(w / 2, ((h / 2 - Scale/2) - Scale*i + j));
				a = false;
			}
			glEnd();
		}
		
}
	}
	if (win == 0)
	{
		for (int i = 0;i < Size;i++)//winner in vertical
		{
			int time = p[i];
			for (int j = 0;j < Size;j++)
			{
				if (p[i + Size*j] == time) win = time;
				else
				{
					win = 0;break;
				}
			}
			if (win == 1)
				glutSetWindowTitle("Won player 1!!!");

			else if (win == 2)
				glutSetWindowTitle("Won player 2!!!");

			if ((win == 1 || win == 2))//draw line
			{
				if (win == 2) glColor3f(1.0, 0.0, 0.0);
				else  glColor3f(0.0, 0.0, 1.0);
				glBegin(GL_LINES);
				for (int j = -2;j < 3;j++)
				{
					glVertex2f((-w / 2 + Scale / 2) + Scale*i + j, -h / 2);glVertex2f((-w / 2 + Scale / 2) + Scale*i + j, h / 2);
					a = false;
				}
				glEnd();
			}

		}
	}
	if(win ==0)
	{
		for (int i = 0, j = 0;i < Size;i++, j++)//winner on the extra diagonal
		{
			int time = p[0];
			if (p[Size*i + j] == time) win = time;
			else
			{
				win = 0;break;
			}
		}
		if (win == 1)
			glutSetWindowTitle("Won player 1!!!");

		else if (win == 2)
			glutSetWindowTitle("Won player 2!!!");

		if ((win == 1 || win == 2))//draw line
		{
			if (win == 2) glColor3f(1.0, 0.0, 0.0);
			else  glColor3f(0.0, 0.0, 1.0);;
			glBegin(GL_LINES);
			for (int j = -2;j < 3;j++)
			{
				glVertex2f(-w / 2, h / 2 + j);glVertex2f(w / 2, -h / 2 + j);
				a = false;
			}
			glEnd();
		}
		
	}

	if(win == 0)
	{
		for (int i = 0, j = Size-1;i < Size;i++, j--)//winner in main diagonal
		{
			int time = p[Size-1];
			if (p[Size*i + j] == time) win = time;
			else
			{
				win = 0;break;
			}

		}
		if ((win == 1 || win == 2))//draw line
		{
			if (win == 2) glColor3f(1.0, 0.0, 0.0);
			else  glColor3f(0.0, 0.0, 1.0);
			glBegin(GL_LINES);
			for (int j = -2;j < 3;j++)
			{
				glVertex2f(-w / 2, -h / 2 + j);glVertex2f(w / 2, h / 2 + j);
				a = false;
			}
			glEnd();
		}
	}
	
	if (win == 1)
		glutSetWindowTitle("Won player 1!!!");
	
	else if(win == 2)
		glutSetWindowTitle("Won player 2!!!");
	
	
}

void Pressed_button(int button, int state, int x, int y)
{
	static int c = 0;static int d = 0;
	int x3 = -1, y3 = -1;
	switch (button,state)
	{
	case GLUT_LEFT_BUTTON | GLUT_UP: 
		if (!a)
			exit(0);

		
		for (int i = -w / 2;;i += Scale)
		{
			if ((x - w / 2) > i)x3++;
			else break;
		}

		for (int i = -h / 2;;i += Scale)
		{
			if ((y - w / 2) > i)y3++;
			else break;
		}
		
		if (b)// condition for draw circle
		{
			if (p[x3 + Size*y3] == 1 || p[x3 + Size*y3] == 2)
				break;
			else
				p[x3 + Size*y3] = 2;// 2 - it is circle
			circ[c].x_c =-w / 2 + (x3*Scale) + (Scale/2); circ[c].y_c = -(-h / 2 + (y3*Scale) + (Scale / 2));
			b = false; c++;
		
		} 
		else//condition for draw dugger
		{
			if (p[x3 + Size*y3] == 1 || p[x3 + Size*y3] == 2)
				break;
			else
				p[x3 + Size*y3] = 1;// 1 - it is dagger
				dag[d].x_d[0] = -w / 2 + 20 + (x3*Scale); dag[d].y_d[0] = -(-h / 2 + 20 + (y3*Scale));
				dag[d].x_d[1] = -w / 2 + 130 + (x3*Scale); dag[d].y_d[1] = -(-h / 2 + 130 + (y3*Scale));
				dag[d].x_d[2] = -w / 2 + 130 + (x3*Scale); dag[d].y_d[2] = -(-h / 2 + 20 + (y3*Scale));
				dag[d].x_d[3] = -w / 2 + 20 + (x3*Scale); dag[d].y_d[3] = -(-h / 2 + 130 + (y3*Scale));
				b = true; d++;
		}
		break;
	}
}

void MenuCheck(int v)
{
	switch (v)
	{
	case 1:Size = 2; break;
	case 2:Size = 3; break;
	case 3: Size = 4;break;
	case 4: Size = 5;break;
	
	}
}

void MenuInit()
{
	int M = glutCreateMenu(MenuCheck);
	glutSetMenu(M);
	glutAddMenuEntry("2:2", 1);
	glutAddMenuEntry("3:3", 2);
	glutAddMenuEntry("4:4", 3);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 0.8, 0.0, 0.0);

	Field();

	for (int i = 0;i < Size*Size;i++)
	{
		dag[i].Draw_Dagger();
		circ[i].Draw_Circle();
	}

	Winner();
	
	glFlush();
}


void timer(int = 0)
{

	display();

	glutTimerFunc(50, timer, 0);
}
void Initialize()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-w/2, w/2, -h/2, h/2, -600, 600);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	func();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(w, h);
	glutInitWindowPosition(500, 0);
	glutCreateWindow("Tic-tac");
	Initialize();
	
	glutDisplayFunc(display);
	glutTimerFunc(0, timer, 0);
	glutMouseFunc(Pressed_button);
	MenuInit();
	
	glutMainLoop();
	
	delete[] circ; delete[] dag; delete[] p;

	_getch();
	return 0;
}