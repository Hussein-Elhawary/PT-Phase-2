#include "CondStatement.h"
#include <sstream>

using namespace std;

CondStatement::CondStatement(Point Lcorner, string LeftHS, string op,string RightHS)
{
	LHS = LeftHS;
	RHS = RightHS;
	OP = op;
	type = "rhombus";
	
	UpdateStatementText();

	LeftCorner = Lcorner;

	Yes_Conn = NULL;	//No connectors yet
	No_Conn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Yes_Outlet.x = LeftCorner.x;
	Yes_Outlet.y = LeftCorner.y + UI.ASSGN_HI/2;

	No_Outlet.x = LeftCorner.x + UI.ASSGN_WDTH;
	No_Outlet.y = LeftCorner.y + UI.ASSGN_HI / 2;
}

void CondStatement::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}

void CondStatement::setRHS(const string& R)
{
	RHS = R;
	UpdateStatementText();
}

void CondStatement::setOP(const string& m)
{
	if (m == "==" || m == "<" || m == "<=" || m == ">" || m == ">=" || "!=")
	{
		OP = m;
		UpdateStatementText();
	}
}

void CondStatement::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawCondtionalStat(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}


//This function should be called when LHS or RHS changes
void CondStatement::UpdateStatementText()
{
	if (LHS == "")	//No left handside ==>statement have no valid text yet
		Text = "  ";
	else
	{
		//Build the statement text: Left handside then equals then right handside
		ostringstream T;
		T << LHS << OP << RHS;
		Text = T.str();
	}
}

Point CondStatement::getstatmentposition()
{
	LeftCorner.y - UI.ASSGN_HI / 2;
	return LeftCorner;

}