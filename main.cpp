#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <GL/glut.h>

using namespace std;

// ##########################################################################
//				TABLICE(globalne) RGB - NA NICH OPIERA SIE ALGORYTM
// ##########################################################################
struct RGB
{
	float r, g, b;
};
RGB Czerwony[3][3] =
{
	{{1, 0, 0}, {1, 0, 0}, {1, 0, 0}},
	{{1, 0, 0}, {1, 0, 0}, {1, 0, 0}},
	{{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}
};
RGB Bialy[3][3] =
{
	{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}},
	{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}},
	{{1, 1, 1}, {1, 1, 1}, {1, 1, 1,}}
};
RGB Niebieski[3][3] =
{
	{{0, 0, 1}, {0, 0, 1}, {0, 0, 1}},
	{{0, 0, 1}, {0, 0, 1}, {0, 0, 1}},
	{{0, 0, 1}, {0, 0, 1}, {0, 0, 1}}
};
RGB Pomaranczowy[3][3] =
{
	{{0.95, 0.5, 0}, {0.95, 0.5, 0}, {0.95, 0.5, 0}},
	{{0.95, 0.5, 0}, {0.95, 0.5, 0}, {0.95, 0.5, 0}},
	{{0.95, 0.5, 0}, {0.95, 0.5, 0}, {0.95, 0.5, 0}}
};
RGB Zolty[3][3] =
{
	{{1, 1, 0}, {1, 1, 0}, {1, 1, 0}},
	{{1, 1, 0}, {1, 1, 0}, {1, 1, 0}},
	{{1, 1, 0}, {1, 1, 0}, {1, 1, 0}}
};
RGB Zielony[3][3] =
{
	{{0, 0.8, 0}, {0, 0.8, 0}, {0, 0.8, 0}},
	{{0, 0.8, 0}, {0, 0.8, 0}, {0, 0.8, 0}},
	{{0, 0.8, 0}, {0, 0.8, 0}, {0, 0.8, 0}}	
}; 
// ##########################################################################
//									PROGRAM
// ##########################################################################
int okno, xMysz=-100, yMysz=-175, xTMP, yTMP, xAngle=-20, yAngle=-35; // zmienne globalne
LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void Rysuj_Kwadracik(float x, float y, float z, float xRotate, float yRotate, float zRotate, RGB kolor)
{
	
	glPushMatrix ();

	glTranslatef(x, y, z);
	glRotatef(xRotate, 1, 0, 0);
	glRotatef(zRotate, 0, 1, 0);
	glRotatef(yRotate, 0, 0, 1);
	glColor3f(kolor.r, kolor.g, kolor.b); 

	
	glBegin(GL_QUADS); 
		glVertex3f(-0.1, 0.1, 0); glVertex3f(0.1, 0.1, 0);
    	glVertex3f(0.1, -0.1, 0); glVertex3f(-0.1, -0.1, 0);
    glEnd();
 
	glPopMatrix();	
} //Rysuj_Kwadracik()

void Scena_Kostka()
{
    glClearColor(0, 0, 0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); 
	

	
	/*
	//swiatla
	glEnable(GL_LIGHTING);
	GLfloat  ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };//swiat³o otaczaj¹ce
	GLfloat  diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };//œwiat³o rozproszone
	GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};     //œwiat³o odbite
	GLfloat  lightPos[] = { 0.0f, 150.0f, 150.0f, 1.0f };//pozycja œwiat³a
	
	glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);  //swiat³o otaczaj¹ce
	//glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);  //œwiat³o rozproszone
	////glLightfv(GL_LIGHT0,GL_SPECULAR,specular); 		//œwiat³o odbite
	//glLightfv(GL_LIGHT0,GL_POSITION,lightPos);		//pozycja œwiat³a 
	
	glEnable(GL_COLOR_MATERIAL); //uaktywnienie œledzenia kolorów
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);   //kolory ustalone za pomoc¹ glColor
	//glNormal3f(0.0f,0.0f,2.0f);
	//glEnable(GL_LIGHT0); glDisable(GL_LIGHT0);
	*/
	
	glPushMatrix ();
		
		glRotatef(xAngle, 0, 1, 0);
    	glRotatef(yAngle, -1, 0, 0);
	glEnable(GL_CULL_FACE);

	//############################ Czerwony  #############################
	glFrontFace(GL_CW);
    Rysuj_Kwadracik(0, 0, 0.31, 0, 0, 0, Czerwony[1][1]); 			//srodek
	Rysuj_Kwadracik(-0.21, 0, 0.31, 0, 0, 0, Czerwony[1][0]); 		//lewy srodkowy
	Rysuj_Kwadracik(0.21, 0, 0.31, 0, 0, 0, Czerwony[1][2]); 		// prawy srodkowy 
	Rysuj_Kwadracik(0, -0.21, 0.31, 0, 0, 0, Czerwony[2][1]); 		// dolny srodkowy
	Rysuj_Kwadracik(0, 0.21, 0.31, 0, 0, 0, Czerwony[0][1]); 		// gorny srodkowy
	Rysuj_Kwadracik(-0.21, -0.21, 0.31, 0, 0, 0, Czerwony[2][0]); 	//lewy dolny
	Rysuj_Kwadracik(0.21, -0.21, 0.31, 0, 0, 0, Czerwony[2][2]); 	// prawy dolny 
	Rysuj_Kwadracik(-0.21, 0.21, 0.31, 0, 0, 0, Czerwony[0][0]); 	// lewy gorny
	Rysuj_Kwadracik(0.21, 0.21, 0.31, 0, 0, 0, Czerwony[0][2]); 	// prawy gorny
	
	
	//############################ Bia³y  #############################
	glFrontFace(GL_CCW);
    Rysuj_Kwadracik(0, 0.31, 0, 90, 0, 0, Bialy[1][1]); 			// srodek
	Rysuj_Kwadracik(-0.21, 0.31, 0, 90, 0, 0, Bialy[1][0]); 		// lewy srodkowy
	Rysuj_Kwadracik(0.21, 0.31, 0, 90, 0, 0, Bialy[1][2]); 			// prawy srodkowy 
	Rysuj_Kwadracik(0, 0.31, 0.21, 90, 0, 0, Bialy[2][1]); 			// dolny srodkowy
	Rysuj_Kwadracik(0, 0.31, -0.21, 90, 0, 0, Bialy[0][1]); 		// gorny srodkowy
	Rysuj_Kwadracik(-0.21, 0.31, 0.21, 90, 0, 0, Bialy[2][0]); 		// lewy dolny
	Rysuj_Kwadracik(0.21, 0.31, 0.21, 90, 0, 0, Bialy[2][2]); 		// prawy dolny 
	Rysuj_Kwadracik(-0.21, 0.31, -0.21, 90, 0, 0, Bialy[0][0]); 	// lewy gorny
	Rysuj_Kwadracik(0.21, 0.31, -0.21, 90, 0, 0, Bialy[0][2]); 		// prawy gorny
	
	//############################ Niebieski  #############################
	glFrontFace(GL_CW);
    Rysuj_Kwadracik(0.31, 0, 0, 0, 0, 90, Niebieski[1][1]); 		// srodek
	Rysuj_Kwadracik(0.31, 0, 0.21, 0, 0, 90, Niebieski[1][0]); 		// lewy srodkowy
	Rysuj_Kwadracik(0.31, 0, -0.21, 0, 0, 90, Niebieski[1][2]); 	// prawy srodkowy 
	Rysuj_Kwadracik(0.31, -0.21, 0, 0, 0, 90, Niebieski[2][1]); 	// dolny srodkowy
	Rysuj_Kwadracik(0.31, 0.21, 0, 0, 0, 90, Niebieski[0][1]); 		// gorny srodkowy
	Rysuj_Kwadracik(0.31, -0.21, 0.21, 0, 0, 90, Niebieski[2][0]); 	// lewy dolny
	Rysuj_Kwadracik(0.31, -0.21, -0.21, 0, 0, 90, Niebieski[2][2]); // prawy dolny 
	Rysuj_Kwadracik(0.31, 0.21, 0.21, 0, 0, 90, Niebieski[0][0]); 	// lewy gorny
	Rysuj_Kwadracik(0.31, 0.21, -0.21, 0, 0, 90, Niebieski[0][2]); 	// prawy gorny	
	

	//############################ Pomarañczowy  #############################
	glFrontFace(GL_CCW);
    Rysuj_Kwadracik(0, 0, -0.31, 0, 0, 0, Pomaranczowy[1][1]); 			// srodek
	Rysuj_Kwadracik(-0.21, 0, -0.31, 0, 0, 0, Pomaranczowy[1][0]); 		// lewy srodkowy
	Rysuj_Kwadracik(0.21, 0, -0.31, 0, 0, 0, Pomaranczowy[1][2]); 		// prawy srodkowy 
	Rysuj_Kwadracik(0, -0.21, -0.31, 0, 0, 0, Pomaranczowy[0][1]); 		// gorny srodkowy
	Rysuj_Kwadracik(0, 0.21, -0.31, 0, 0, 0, Pomaranczowy[2][1]); 		// dolny srodkowy
	Rysuj_Kwadracik(-0.21, -0.21, -0.31, 0, 0, 0, Pomaranczowy[0][0]); 	// lewy gorny
	Rysuj_Kwadracik(0.21, -0.21, -0.31, 0, 0, 0, Pomaranczowy[0][2]); 	// prawy gorny
	Rysuj_Kwadracik(-0.21, 0.21, -0.31, 0, 0, 0, Pomaranczowy[2][0]); 	// lewy dolny
	Rysuj_Kwadracik(0.21, 0.21, -0.31, 0, 0, 0, Pomaranczowy[2][2]); 	// prawy dolny
	
	//############################  ¯ó³ty #############################
	glFrontFace(GL_CW);
    Rysuj_Kwadracik(0, -0.31, 0, 90, 0, 0, Zolty[1][1]); 			// srodek
	Rysuj_Kwadracik(-0.21, -0.31, 0, 90, 0, 0, Zolty[1][0]); 		// lewy srodkowy
	Rysuj_Kwadracik(0.21, -0.31, 0, 90, 0, 0, Zolty[1][2]); 		// prawy srodkowy 
	Rysuj_Kwadracik(0, -0.31, 0.21, 90, 0, 0, Zolty[0][1]); 		// gorny srodkowy
	Rysuj_Kwadracik(0, -0.31, -0.21, 90, 0, 0, Zolty[2][1]); 		// dolny srodkowy
	Rysuj_Kwadracik(-0.21, -0.31, 0.21, 90, 0, 0, Zolty[0][0]); 	// lewy gorny
	Rysuj_Kwadracik(0.21, -0.31, 0.21, 90, 0, 0, Zolty[0][2]); 		// prawy gorny 
	Rysuj_Kwadracik(0.21, -0.31, -0.21, 90, 0, 0, Zolty[2][2]);		//prawy dolny
	Rysuj_Kwadracik(-0.21, -0.31, -0.21, 90, 0, 0, Zolty[2][0]);	//lewy dolny

	//############################  Zielony #############################
	glFrontFace(GL_CCW);
    Rysuj_Kwadracik(-0.31, 0, 0, 0, 0, 90, Zielony[1][1]); 			// srodek
	Rysuj_Kwadracik(-0.31, 0, 0.21, 0, 0, 90, Zielony[1][2]); 		// prawy srodkowy
	Rysuj_Kwadracik(-0.31, 0, -0.21, 0, 0, 90, Zielony[1][0]);		// lewy srodkowy
	Rysuj_Kwadracik(-0.31, -0.21, 0, 0, 0, 90, Zielony[2][1]);		// dolny srodkowy
	Rysuj_Kwadracik(-0.31, 0.21, 0, 0, 0, 90, Zielony[0][1]); 		// gorny srodkowy
	Rysuj_Kwadracik(-0.31, -0.21, 0.21, 0, 0, 90, Zielony[2][2]); 	// prawy dolny
	Rysuj_Kwadracik(-0.31, -0.21, -0.21, 0, 0, 90, Zielony[2][0]); 	// lewy dolny 
	Rysuj_Kwadracik(-0.31, 0.21, 0.21, 0, 0, 90, Zielony[0][2]);	// prawy gorny
	Rysuj_Kwadracik(-0.31, 0.21, -0.21, 0, 0, 90, Zielony[0][0]);	// lewy gorny

    glPopMatrix (); 
	
    glFlush();
    glutSwapBuffers();  
} //Scena_Kostka()

void obrocMacierzLewo(RGB tab[3][3])
{
	RGB tmp[3][3];
	for(int i = 0; i<3; ++i)
		for(int j = 0; j<3; ++j)
			tmp[i][j] = tab[i][j];

	for(int i = 0; i<3; ++i)
		for(int j = 0; j<3; ++j)
			tab[i][j] = tmp[j][2-i];
}
void obrocMacierzPrawo(RGB tab[3][3])
{
	RGB tmp[3][3];
	for(int i = 0; i<3; ++i)
		for(int j = 0; j<3; ++j)
			tmp[i][j] = tab[i][j];

	for(int i = 0; i<3; ++i)
		for(int j = 0; j<3; ++j)
			tab[i][j] = tmp[2-j][i];
}
void obrocMacierzPrawo(RGB tab[3][3], int ileRazy)
{
	for(int i=0; i<ileRazy; ++i)
		obrocMacierzPrawo(tab);
}

void obrocMacierzLewo(RGB tab[3][3], int ileRazy)
{
	for(int i=0; i<ileRazy; ++i)
		obrocMacierzLewo(tab);
}
void kopiujWektory(RGB wektor1[3], RGB wektor2[3], RGB wektor3[3], RGB wektor4[3],
	RGB tmp1[3], RGB tmp2[3], RGB tmp3[3], RGB tmp4[3])
{
	for(int i=0; i<3; ++i)
	{
		tmp1[i] = wektor1[i];
		tmp2[i] = wektor2[i];
		tmp3[i] = wektor3[i];
		tmp4[i] = wektor4[i];
	}
}
void obrocSrodek(RGB wektor1[3], RGB wektor2[3], RGB wektor3[3], RGB wektor4[3])
{
	RGB tmp1[3], tmp2[3], tmp3[3], tmp4[3];
	kopiujWektory(wektor1, wektor2, wektor3, wektor4, tmp1, tmp2, tmp3, tmp4);
	kopiujWektory(tmp4, tmp1, tmp2, tmp3, wektor1, wektor2, wektor3, wektor4);
}

void obrocPasek(RGB wektor1[3], RGB wektor2[3], RGB wektor3[3], RGB wektor4[3], bool lewo)
{
	RGB tmp1[3], tmp2[3], tmp3[3], tmp4[3];
	kopiujWektory(wektor1, wektor2, wektor3, wektor4, tmp1, tmp2, tmp3, tmp4);
	
	if(lewo)
		for(int i=0; i<3; ++i)
		{
			wektor1[i] = tmp4[i];
			wektor2[i] = tmp1[2-i];
			wektor3[i] = tmp2[i];
			wektor4[i] = tmp3[2-i];
		}
	else // w prawo
		for(int i=0; i<3; ++i)
		{
			wektor1[i] = tmp2[2-i];
			wektor2[i] = tmp3[i];
			wektor3[i] = tmp4[2-i];
			wektor4[i] = tmp1[i];
		}	
}

void Klawiatura(unsigned char znak, int a, int b)
{	
	if(GLUT_ACTIVE_ALT == glutGetModifiers()) // w prawo
		switch (znak)
		{
    	case 'd': //biala
			obrocMacierzLewo	(Bialy); 
			obrocMacierzLewo	(Niebieski); 
			obrocMacierzLewo	(Niebieski);
			obrocPasek			(Pomaranczowy[2], Zielony[0], Czerwony[0], Niebieski[2], true); 
			obrocMacierzPrawo	(Niebieski); 
			obrocMacierzPrawo	(Niebieski);
			break;
		case 's': // czerwona
			obrocMacierzLewo	(Czerwony); 
			obrocMacierzLewo	(Zielony); 
			obrocMacierzLewo	(Niebieski);
			obrocPasek			(Bialy[2], Zielony[0], Zolty[0], Niebieski[2], true); 
			obrocMacierzPrawo	(Zielony); 
			obrocMacierzPrawo	(Niebieski);
			break; 
    	case 'a': //zolta
			obrocMacierzLewo	(Zolty); 
			obrocMacierzLewo	(Zielony); 
			obrocMacierzLewo	(Zielony);
			obrocPasek			(Czerwony[2], Zielony[0], Pomaranczowy[0], Niebieski[2], true); 
			obrocMacierzPrawo	(Zielony); 
			obrocMacierzPrawo	(Zielony);
			break;
    	case 'f': //pomaranczowy
			obrocMacierzLewo(Pomaranczowy);
			obrocMacierzPrawo(Zielony); obrocMacierzPrawo(Niebieski);
			obrocPasek(Zolty[2], Zielony[0], Bialy[0], Niebieski[2], true);
			obrocMacierzLewo(Zielony); obrocMacierzLewo(Niebieski);
			break;
		case 'w': //zielony
			obrocMacierzLewo(Zielony); 
			obrocMacierzLewo(Bialy); obrocMacierzPrawo(Pomaranczowy);
			obrocMacierzPrawo(Zolty); obrocMacierzLewo(Czerwony);
			obrocPasek(Bialy[2], Pomaranczowy[0], Zolty[0], Czerwony[2], true);
			obrocMacierzPrawo(Bialy); obrocMacierzLewo(Pomaranczowy);
			obrocMacierzLewo(Zolty); obrocMacierzPrawo(Czerwony);
			break;
		case 'x': //niebieski
			obrocMacierzLewo(Niebieski);
			obrocMacierzPrawo(Bialy); obrocMacierzLewo(Czerwony);
			obrocMacierzLewo(Zolty); obrocMacierzPrawo(Pomaranczowy);
			obrocPasek(Bialy[2], Czerwony[0], Zolty[0], Pomaranczowy[2], true);
			obrocMacierzLewo(Bialy); obrocMacierzPrawo(Czerwony);
			obrocMacierzPrawo(Zolty); obrocMacierzLewo(Pomaranczowy);
			break;
		case 'e': //srodek 1
			obrocMacierzPrawo(Czerwony); obrocMacierzPrawo(Bialy);
			obrocMacierzPrawo(Pomaranczowy); obrocMacierzPrawo(Zolty);
			obrocSrodek(Czerwony[1], Zolty[1], Pomaranczowy[1], Bialy[1]);
			obrocMacierzLewo(Czerwony); obrocMacierzLewo(Bialy);
			obrocMacierzLewo(Pomaranczowy); obrocMacierzLewo(Zolty);
			break;
		case 'c': //srodek 2
			obrocMacierzLewo(Pomaranczowy, 2);
			obrocSrodek(Czerwony[1], Zielony[1], Pomaranczowy[1], Niebieski[1]);
			obrocMacierzPrawo(Pomaranczowy, 2);
			break;
		} 
	else // w lewo
		switch (znak)
		{
    	case 'd': //biala
			obrocMacierzPrawo(Bialy); 
			obrocMacierzLewo(Niebieski); obrocMacierzLewo(Niebieski);
			obrocPasek(Pomaranczowy[2], Zielony[0], Czerwony[0], Niebieski[2], false); 
			obrocMacierzPrawo(Niebieski); obrocMacierzPrawo(Niebieski);
			break;
		case 's': // czerwona
			obrocMacierzPrawo(Czerwony);
			obrocMacierzLewo(Zielony); obrocMacierzLewo(Niebieski);
			obrocPasek(Bialy[2], Zielony[0], Zolty[0], Niebieski[2], false); 
			obrocMacierzPrawo(Zielony); obrocMacierzPrawo(Niebieski);
			break; 
    	case 'a': //zolta
			obrocMacierzPrawo(Zolty); 
			obrocMacierzLewo(Zielony); obrocMacierzLewo(Zielony);
			obrocPasek(Czerwony[2], Zielony[0], Pomaranczowy[0], Niebieski[2], false); 
			obrocMacierzPrawo(Zielony); obrocMacierzPrawo(Zielony);
			break;
    	case 'f': //pomaranczowy
			obrocMacierzPrawo(Pomaranczowy);
			obrocMacierzPrawo(Zielony); obrocMacierzPrawo(Niebieski);
			obrocPasek(Zolty[2], Zielony[0], Bialy[0], Niebieski[2], false);
			obrocMacierzLewo(Zielony); obrocMacierzLewo(Niebieski);
			break;
		case 'w': //zielony
        	obrocMacierzPrawo(Zielony); 
			obrocMacierzLewo(Bialy); obrocMacierzPrawo(Pomaranczowy);
			obrocMacierzPrawo(Zolty); obrocMacierzLewo(Czerwony);
			obrocPasek(Bialy[2], Pomaranczowy[0], Zolty[0], Czerwony[2], false);
			obrocMacierzPrawo(Bialy); obrocMacierzLewo(Pomaranczowy);
			obrocMacierzLewo(Zolty); obrocMacierzPrawo(Czerwony);
			break;
		case 'x': //niebieski
			obrocMacierzPrawo(Niebieski);
			obrocMacierzPrawo(Bialy); obrocMacierzLewo(Czerwony);
			obrocMacierzLewo(Zolty); obrocMacierzPrawo(Pomaranczowy);
			obrocPasek(Bialy[2], Czerwony[0], Zolty[0], Pomaranczowy[2], false);
			obrocMacierzLewo(Bialy); obrocMacierzPrawo(Czerwony);
			obrocMacierzPrawo(Zolty); obrocMacierzLewo(Pomaranczowy);
			break;
		case 'e': //srodek 1
			obrocMacierzPrawo(Czerwony); obrocMacierzPrawo(Bialy);
			obrocMacierzPrawo(Pomaranczowy); obrocMacierzPrawo(Zolty);
			obrocSrodek(Czerwony[1], Bialy[1], Pomaranczowy[1], Zolty[1]);
			obrocMacierzLewo(Czerwony); obrocMacierzLewo(Bialy);
			obrocMacierzLewo(Pomaranczowy); obrocMacierzLewo(Zolty);
			break;
		case 'c': //srodek 2
			obrocMacierzLewo(Pomaranczowy, 2);
			obrocSrodek(Czerwony[1], Niebieski[1], Pomaranczowy[1], Zielony[1]);
			obrocMacierzPrawo(Pomaranczowy, 2);
			break;
		} 
} //Klawiatura()

void Mysz(int przycisk, int stan, int x, int y)
{
	if(stan == GLUT_DOWN)
	{		
			xMysz -= x;
			yMysz += y;
	}
	else
	{
		xMysz = xTMP;
		yMysz = yTMP;
	} 	
} //Mysz() - przyciski

void Mysz(int x, int y)
{
			xTMP 	= (xMysz + x); 	
			yTMP 	= (yMysz - y);

		xAngle 	= (xTMP/5)%360; 	
		if(abs(xAngle)>179)
			xAngle = xAngle - 360;
		
	
		yAngle 	= (yTMP/5)%360;
		if(abs(yAngle)>179)
			yAngle = yAngle - 360;
		
		cout 	<< xAngle		<< " " 		<< yAngle
				<< endl;
} //Mysz() przytrzymanie
void Menu(int parametr)
{
    okno = parametr;
    if(parametr == 3)
        exit(0);
}

void Skalowanie(int width, int height)
{
	if(width > height)
		glViewport((width - height)/2, 0, height, height);
	else
	glViewport(0, (height-width)/2, width, width);
	Scena_Kostka();
} // Skalowanie() 

int main(int argc, char *argv[])
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Kostka rubika");
    glutDisplayFunc(Scena_Kostka);
	glutReshapeFunc(Skalowanie);
 	
	glutMouseFunc(Mysz);
	glutMotionFunc(Mysz);
    glutKeyboardFunc(Klawiatura); 
   
    glutIdleFunc(Scena_Kostka);
	glutMainLoop(); 
    return EXIT_SUCCESS;
}
