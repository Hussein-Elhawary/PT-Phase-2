#include "SmplAssign.h"
#include <sstream>

using namespace std;

SmplAssign::SmplAssign(Point Lcorner, string LeftHS, double RightHS)
{
	LHS = LeftHS;
	RHS = RightHS;
	type = "smplrectangle";
	UpdateStatementText();

	LeftCorner = Lcorner;
	
	pConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH /2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;	
}

void SmplAssign::setLHS(const string &L)
{
	LHS = L;
	UpdateStatementText();
}

void SmplAssign::setRHS(double R)
{
	RHS = R;
	UpdateStatementText();
}


void SmplAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssign(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	
}


//This function should be called when LHS or RHS changes
void SmplAssign::UpdateStatementText()
{
	if(LHS=="")	//No left handside ==>statement have no valid text yet
		Text = "    = ";
	else
	{
		//Build the statement text: Left handside then equals then right handside
		ostringstream T;
		T<<LHS<<" = "<<RHS;	
		Text = T.str();	 
	}
}

Point SmplAssign::getstatmentposition()
{
	Point center;
	center.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	center.y = LeftCorner.y + UI.ASSGN_HI / 2;
	return center;
}

Point  SmplAssign::getInlet()
{
	Point Inletr = Inlet;

	return Inletr;
}

Point  SmplAssign::getOutlet()
{
	Point Outletr = Outlet;
	return Outletr;
}

Connector* SmplAssign::Getconnect()
{
	return pConn;
}

void SmplAssign::Save(ofstream& OutFile)
{
	OutFile << "SMPLASSIGN" << "       " << ID << "  " << LeftCorner.x << "  " << LeftCorner.y << "  " << LHS << "  " << RHS << "  " << endl;
}

string SmplAssign::getLHS()
{
	return LHS;
}

double SmplAssign::getRHS()
{
	return RHS;
}

Statement* SmplAssign::getCopy()
{
	return new SmplAssign(LeftCorner, LHS, RHS);
}
