#include "Write.h"
#include <sstream>

using namespace std;

Write::Write(Point Lcorner, string var)
{
	type = "writeparallelogram";
	VAR = var;

	UpdateStatementText();

	LeftCorner = Lcorner;

	pConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}

void Write::setVAR(const string& var)
{
	VAR = var;
	UpdateStatementText();
}



void Write::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawWrite(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}


//This function should be called when LHS or RHS changes
void Write::UpdateStatementText()
{
	if (VAR == "")	//No left handside ==>statement have no valid text yet
		Text = " ";
	else
	{
		//Build the statement text: Left handside then equals then right handside
		ostringstream T;
		T << VAR;
		Text = T.str();
	}
}

Point Write::getstatmentposition()
{
	Point center;
	center.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	center.y = LeftCorner.y + UI.ASSGN_HI / 2;
	return center;

}

Point  Write::getInlet()
{
	Point Inletr = Inlet;

	return Inletr;
}

Point  Write::getOutlet()
{
	Point Outletr = Outlet;
	return Outletr;
}

Connector* Write::Getconnect()
{
	return pConn;
}

void Write::Save(ofstream& OutFile)
{
	OutFile << "WRITE" << "           " << ID << "  " << LeftCorner.x << "  " << LeftCorner.y << "  " << VAR << endl;
	
}
