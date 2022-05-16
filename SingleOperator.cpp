#include "SingleOperator.h"
#include <sstream>

using namespace std;

SingleOperator::SingleOperator(Point Lcorner, string LeftHS , string RightHS1 , string op , string RightHS2 )
{
	type = "rectangle";
	LHS = LeftHS;
	RHS1 = RightHS1;
	OP = op;
	RHS2 = RightHS2;

	UpdateStatementText();

	LeftCorner = Lcorner;

	pConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}

void SingleOperator::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}

void SingleOperator::setRHS1(const string& R1)
{
	RHS1 = R1;
	UpdateStatementText();
}

void SingleOperator::setRHS2(const string& R2)
{
	RHS2 = R2;
	UpdateStatementText();
}

void SingleOperator::setOP(const string& op)
{
	if (op == "+" || op == "-" || op == "*" || op == "/")
	{
		OP = op;
		UpdateStatementText();
	}
}


void SingleOperator::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssign(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}


//This function should be called when LHS or RHS changes
void SingleOperator::UpdateStatementText()
{
	if (LHS == "")	//No left handside ==>statement have no valid text yet
		Text = "    = ";
	else
	{
		//Build the statement text: Left handside then equals then right handside
		ostringstream T;
		T << LHS << " = " << RHS1 << OP << RHS2;
		Text = T.str();
	}
}

Point SingleOperator::getstatmentposition()
{
	Point center;
	center.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	center.y = LeftCorner.y + UI.ASSGN_HI / 2;
	return center;
}

Connector* SingleOperator::Getconnect()
{
	return pConn;
}

void SingleOperator::Save(ofstream& OutFile)
{
	OutFile << "SNGLOP" << "  " << ID << "  " << LeftCorner.x << "  " << LeftCorner.y << "  " << LHS << "  " << RHS1 << "  " << OP << "  " << RHS2 << "  " << endl;
}

Point SingleOperator::getInlet()
{
	Point Inletr = Inlet;

	return Inletr;
}

Point SingleOperator::getOutlet()
{
	Point Outletr = Outlet;
	return Outletr;
}