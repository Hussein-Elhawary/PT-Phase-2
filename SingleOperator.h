#pragma once
#include "Statements/Statement.h"
class SingleOperator : public Statement
{
	string LHS;	//Left Handside of the assignment (name of a variable)
	string RHS1;	//Right Handside (Value)
	string OP;       
	string RHS2;

	Connector* pConn;	//Simple Assignment Stat. has one Connector to next statement

	Point Inlet;	//A point where connections enters this statement 
	Point Outlet;	//A point a connection leaves this statement

	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();

public:
	SingleOperator(Point Lcorner, string LeftHS = "", string RightHS1 = "" , string op ="", string RightHS2 ="");

	void setLHS(const string& L);
	void setRHS1(const string& R1);
	void setOP(const string& op);
	void setRHS2(const string& R2);
	Point getInlet();
	Point getOutlet();

	virtual void Draw(Output* pOut) const;
	//virtual void PrintInfo(Output* pOut);
	virtual Point getstatmentposition();
	virtual Connector* Getconnect();
	virtual void Save(ofstream& OutFile);	//Save the Statement parameters to a file

};

