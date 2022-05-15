#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.width = 1000;
	UI.height = 700;
	UI.wx = 15;
	UI.wy = 15;

	UI.AppMode = DESIGN;	//Design Mode is the default mode

	UI.StBrWdth = 50;		//Status Bar Height
	UI.TlBrWdth = 50;		//Tool Bar Height
	UI.MnItWdth = 50;

	UI.DrawClr = BLUE;
	UI.HiClr = RED;
	UI.MsgClr = RED;

	UI.ASSGN_WDTH = 150;
	UI.ASSGN_HI = 50;

	////Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Programming Techniques Project");

	pWind->SetPen(RED, 3); ///////*****************
	CreateDesignToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput()
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y)
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar()
{
	pWind->DrawLine(0, UI.height - UI.StBrWdth, UI.width, UI.height - UI.StBrWdth);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the Design Menu
void Output::CreateDesignToolBar()
{
	UI.AppMode = DESIGN;	//Design Mode
	int i = 0;

	pWind->SetPen(RED, 2.5);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.TlBrWdth);
	
	//fill the tool bar 
	//You can draw the tool bar icons in any way you want.
	pWind->DrawImage("images\\exit.jpg", 0, 0);//here to input image in the tool bar
	pWind->DrawImage("images\\start.jpg", 50, 0);
	pWind->DrawImage("images\\read1.jpg", 100, 0);     
	pWind->DrawImage("images\\write1.jpg", 150, 0);	
	pWind->DrawImage("images\\assign.jpg", 200, 0);
	pWind->DrawImage("images\\condition.jpg", 250, 0);
	pWind->DrawImage("images\\connector.jpg", 300, 0);
	pWind->DrawImage("images\\end.jpg", 350, 0);
	pWind->DrawImage("images\\select.jpg", 400, 0);		
	pWind->DrawImage("images\\copy.jpg", 450, 0);
	pWind->DrawImage("images\\cut.jpg", 500, 0);
	pWind->DrawImage("images\\paste.jpg", 550, 0);
	pWind->DrawImage("images\\save.jpg", 600, 0);
	pWind->DrawImage("images\\edit.jpg", 650, 0);
	pWind->DrawImage("images\\move.jpg", 700, 0);
	pWind->DrawImage("images\\zoomout.jpg", 750, 0);
	pWind->DrawImage("images\\zoomin.jpg", 800, 0);
	pWind->DrawImage("images\\del.jpg", 850, 0);		 
	pWind->DrawImage("images\\gotosim.jpg", 900, 0);
	


	//Draw a line under the toolbar
	pWind->DrawLine(0, UI.TlBrWdth, UI.width, UI.TlBrWdth);
	//here to draw line in the tool bar around images
	pWind->DrawLine(50, UI.TlBrWdth, 50, 0);
	pWind->DrawLine(100, UI.TlBrWdth, 100, 0);
	pWind->DrawLine(150, UI.TlBrWdth, 150, 0);
	pWind->DrawLine(200, UI.TlBrWdth, 200, 0);
	pWind->DrawLine(250, UI.TlBrWdth, 250, 0);
	pWind->DrawLine(300, UI.TlBrWdth, 300, 0);
	pWind->DrawLine(350, UI.TlBrWdth, 350, 0);
	pWind->DrawLine(400, UI.TlBrWdth, 400, 0);
	pWind->DrawLine(450, UI.TlBrWdth, 450, 0);
	pWind->DrawLine(500, UI.TlBrWdth, 500, 0);
	pWind->DrawLine(550, UI.TlBrWdth, 550, 0);
	pWind->DrawLine(600, UI.TlBrWdth, 600, 0);
	pWind->DrawLine(650, UI.TlBrWdth, 650, 0);
	pWind->DrawLine(700, UI.TlBrWdth, 700, 0);
	pWind->DrawLine(750, UI.TlBrWdth, 750, 0);
	pWind->DrawLine(800, UI.TlBrWdth, 800, 0);
	pWind->DrawLine(850, UI.TlBrWdth, 850, 0);
	pWind->DrawLine(900, UI.TlBrWdth, 900, 0);
	pWind->DrawLine(900, UI.TlBrWdth, 900, 0);
	pWind->DrawLine(950, UI.TlBrWdth, 950, 0);
	pWind->DrawLine(0, 0, UI.width, 0);
}

void Output::CreateSimulationToolBar()
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	///TODO: add code to create the simulation tool bar
	//SIMUATION Mode
	pWind->SetPen(RED, 2.5);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.TlBrWdth);
	//fill the tool bar 
	//You can draw the tool bar icons in any way you want.
	//here to input image in the tool bar
	pWind->DrawImage("images\\exit.jpg", 0, 0);
	pWind->DrawImage("images\\run.jpg", 50, 0);				
	pWind->DrawImage("images\\stepbysteprun.jpg", 100, 0);  
	pWind->DrawImage("images\\flowtocode.jpg", 150, 0);		
	pWind->DrawImage("images\\returntodesign.jpg", 200, 0);	




	//Draw a line under the toolbar
	//pWind->DrawLine(0, UI.TlBrWdth, UI.width, UI.TlBrWdth);
	//here to draw line in the tool bar around images
	pWind->DrawLine(50, UI.TlBrWdth, 50, 0);
	pWind->DrawLine(100, UI.TlBrWdth, 100, 0);
	pWind->DrawLine(150, UI.TlBrWdth, 150, 0);
	pWind->DrawLine(200, UI.TlBrWdth, 200, 0);
	pWind->DrawLine(250, UI.TlBrWdth, 250, 0);
	

	pWind->DrawLine(0, 0, UI.width, 0);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StBrWdth, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea()
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.TlBrWdth, UI.width, UI.height - UI.StBrWdth);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgClr, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Times New Romans");   //formatting font style from arial
	pWind->DrawString(10, UI.height - (int)(UI.StBrWdth / 1.5), msg);
}

//======================================================================================//
//								Statements Drawing Functions							//
//======================================================================================//

//Draw assignment statement and write the "Text" on it
void Output::ClickCheck(Point& Left, int width, int height)
{
	while ((Left.y<UI.TlBrWdth) || (Left.y + height > UI.height - UI.StBrWdth) || (Left.x + width > UI.width - 20) || (Left.x - width / 2 < 0 + 1))	//checks if the user clicks on the toolbar or the status bar
	{
		ClearStatusBar();	//First clear the status bar
		pWind->DrawString(10, UI.height - (int)(UI.StBrWdth / 1.5), "Please press in a valid area (not on status bar nor on the toolbar and inside the screen)");
		pWind->WaitMouseClick(Left.x, Left.y);
		ClearStatusBar();
		if (Left.x > 0 && Left.x < UI.MnItWdth && Left.y > 0 && Left.y < UI.TlBrWdth)
		{
			int Zahar = 1;
			exit(Zahar);		//this temrinates code if exit is pressed
		}

	}

}
void Output::DrawAssign(Point Left, int width, int height, string Text, bool Selected)
{
	

	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr, 3);	//use normal color
	width += 3 * size(Text);
	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 3 - 2 * size(Text), Left.y + height / 4, Text);

}


void Output::DrawCondtionalStat(Point Left, int width, int height, string Text, bool Selected)
{
	

	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr, 3);	//use normal color

	//Draw the statement block Roumbus
	width += 3 * size(Text);
	height += 3 * size(Text);
	// entering the coordinates of the rhombus vertices
	int pointsX[4];
	int pointsY[4];
	pointsX[0] = Left.x;
	pointsY[0] = Left.y;
	pointsX[1] = Left.x + width / 2;
	pointsY[1] = Left.y + height / 2;
	pointsX[2] = Left.x;
	pointsY[2] = Left.y + height;
	pointsX[3] = Left.x - width / 2;
	pointsY[3] = Left.y + height / 2;
	int vertices = 4;
	drawstyle dsStyle = FILLED;
	pWind->DrawPolygon(pointsX, pointsY, vertices, dsStyle);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x - 3.5 * size(Text), Left.y + height / 2 - 10, Text);

}

void Output::DrawStart(Point Left, int width, int height, bool Selected)
{
	

	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr, 3);	//use normal color


	pWind->DrawEllipse(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 3, Left.y + height / 3, " Start");
}

void Output::DrawEnd(Point Left, int width, int height, bool Selected)
{
	

	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr, 3);	//use normal color


	pWind->DrawEllipse(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 2.5, Left.y + height / 3, "End");

}

void Output::DrawConnector(Point Start, Point End, bool Selected)
{
	while (Start.y<UI.TlBrWdth || Start.y > UI.height - UI.StBrWdth || End.y<UI.TlBrWdth || End.y > UI.height - UI.StBrWdth)	//checks if the user clicks on the toolbar or the status bar
	{
		ClearStatusBar();	//First clear the status bar
		pWind->DrawString(10, UI.height - (int)(UI.StBrWdth / 1.5), "Please press start and end again in a valid area (not on status bar nor on the toolbar and inside the screen)");
		pWind->WaitMouseClick(Start.x, Start.y);
		pWind->WaitMouseClick(End.x, End.y);
		if (Start.x > 0 && Start.x < UI.MnItWdth && Start.y > 0 && Start.y < UI.TlBrWdth || End.x > 0 && End.x < UI.MnItWdth && End.y > 0 && End.y < UI.TlBrWdth)
		{
			int Zahar = 1;
			exit(Zahar);	//this temrinates code if exit is pressed
		}

	}

	drawstyle dsStyle = FRAME;
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr, 3);	//use normal color

	pWind->SetPen(BLACK, 2);
	if (abs(Start.x - End.x) < 20)
	{
		End.x = Start.x;
	}
	if (abs(Start.y - End.y) < 20)
	{
		End.y = Start.y;
	}
	pWind->DrawLine(Start.x, Start.y, End.x, Start.y, dsStyle);
	pWind->DrawLine(End.x, Start.y, End.x, End.y, dsStyle);

	// conditions for drawing the arrow head

	if (Start.y < End.y)
	{
		pWind->DrawLine(End.x, End.y, End.x + 10, End.y - 10, dsStyle);
		pWind->DrawLine(End.x, End.y, End.x - 10, End.y - 10, dsStyle);
	}
	else if (Start.y > End.y)
	{
		pWind->DrawLine(End.x, End.y, End.x + 10, End.y + 10, dsStyle);
		pWind->DrawLine(End.x, End.y, End.x - 10, End.y + 10, dsStyle);
	}
	else if (Start.x > End.x)
	{
		pWind->DrawLine(End.x, End.y, End.x + 10, End.y + 10, dsStyle);
		pWind->DrawLine(End.x, End.y, End.x + 10, End.y - 10, dsStyle);
	}
	else
	{
		pWind->DrawLine(End.x, End.y, End.x - 10, End.y - 10, dsStyle);
		pWind->DrawLine(End.x, End.y, End.x - 10, End.y + 10, dsStyle);
	}

}

void Output::DrawRead(Point Left, int width, int height, string Text, bool Selected)
{


	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr, 3);	//use normal color


	//Draw the statement block parallelogram
	string text2 = "Read ";
	Text = text2 + Text;
	width += 4 * size(Text);
	int pointsX[4];
	int pointsY[4];
	pointsX[0] = Left.x;
	pointsY[0] = Left.y;
	pointsX[1] = Left.x + width;
	pointsY[1] = Left.y;
	pointsX[2] = Left.x + (2.0 / 3) * width;
	pointsY[2] = Left.y + height;
	pointsX[3] = Left.x - (1.0 / 3) * width;
	pointsY[3] = Left.y + height;


	int vertices = 4;
	drawstyle dsStyle = FILLED;
	pWind->DrawPolygon(pointsX, pointsY, vertices, dsStyle);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 3 - 5 * size(Text), Left.y + height / 2 - 10, Text);



}
void Output::DrawWrite(Point Left, int width, int height, string Text, bool Selected)
{


	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr, 3);	//use normal color

	//Draw the statement block parallelogram
	string text2 = "Write ";
	Text = text2 + Text;
	width = width + 4 * size(Text);
	int pointsX[4];
	int pointsY[4];
	pointsX[0] = Left.x;
	pointsY[0] = Left.y;
	pointsX[1] = Left.x + width;
	pointsY[1] = Left.y;
	pointsX[2] = Left.x + (2.0 / 3) * width;
	pointsY[2] = Left.y + height;
	pointsX[3] = Left.x - (1.0 / 3) * width;
	pointsY[3] = Left.y + height;


	int vertices = 4;
	drawstyle dsStyle = FILLED;
	pWind->DrawPolygon(pointsX, pointsY, vertices, dsStyle);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 3 - 5 * size(Text), Left.y + height / 2 - 10, Text);
//	pWind->DrawString(Left.x + width / 3 - 5 * size(Text), Left.y + height / 2 - 10, Text);

}


void  Output::WaitMouseClick(int& x, int& y)				//this waits for for mouse click 
{
	pWind->WaitMouseClick(x, y);
}

color Output::Getcolour(int x, int y)
{
	color dummy = pWind->GetColor(x, y);
	return dummy;
}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
