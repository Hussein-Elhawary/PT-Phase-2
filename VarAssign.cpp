#include "VarAssign.h"
#include <sstream>

using namespace std;

VarAssign::VarAssign(Point Lcorner, string LeftHS, string RightHS)
{
	type = "rectangle";
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
	return LeftCorner;
}