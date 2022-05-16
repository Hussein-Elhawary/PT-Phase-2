#pragma once
#include "Statements/Statement.h"
class VarAssign : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	string RHS;	//Right Handside (Variable)

	Connector* pConn;	//variable Assignment Stat. has one Connector to next statement

	Point Inlet;	//A point where connections enters this statement 
	Point Outlet;	//A point a connection leaves this statement

	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();

public:
	VarAssign(Point Lcorner, string LeftHS = "", string RightHS = "");

	void setLHS(const string& L);
	void setRHS(const string& R);

	virtual void Draw(Output* pOut) const;
	Point getstatmentposition();
	Point getInlet();
	Point getOutlet();
	
};

