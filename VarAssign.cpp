#include "VarAssign.h"
#include <sstream>

using namespace std;

VarAssign::VarAssign(Point Lcorner, string LeftHS, string RightHS)
{
	type = "varrectangle";
	LHS = LeftHS;
	RHS = RightHS;

	UpdateStatementText();

	LeftCorner = Lcorner;

	pConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}

void VarAssign::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}

void VarAssign::setRHS(const string& R)
{
	RHS = R;
	UpdateStatementText();
}


void VarAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssign(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}


//This function should be called when LHS or RHS changes
void VarAssign::UpdateStatementText()
{
	if (LHS == "")	//No left handside ==>statement have no valid text yet
		Text = "    = ";
	else
	{
		//Build the statement text: Left handside then equals then right handside
		ostringstream T;
		T << LHS << " = " << RHS;
		Text = T.str();
	}
}

Point VarAssign::getstatmentposition()
{
	Point center;
	center.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	center.y = LeftCorner.y + UI.ASSGN_HI / 2;
	return center;
}

Point VarAssign::getInlet()
{
	Point Inletr = Inlet;

	return Inletr;
}

Point VarAssign::getOutlet()
{
	Point Outletr = Outlet;
	return Outletr;
}

Connector* VarAssign::Getconnect()
{
	return pConn;
}

void VarAssign::Save(ofstream& OutFile)
{
	OutFile << "VARASSIGN" << "       " << ID << "  " << LeftCorner.x << "  " << LeftCorner.y << "  " << LHS << "  " << RHS << "  " << endl;

}


Statement* VarAssign::getCopy()
{
	return new VarAssign(LeftCorner, LHS, RHS);
}

string VarAssign::getLHS()
{
	return LHS;
}

string VarAssign::getRHS()
{
	return RHS;
}