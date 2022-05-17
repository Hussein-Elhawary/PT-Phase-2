#pragma once
#include "Statements/Statement.h"
class CondStatement : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	string OP;  //operation 
	string RHS;	//Right Handside (Variable)

	Connector* Yes_Conn;    // yes connector 
	Connector* No_Conn;	//no connector

	Point Inlet;	//A point where connections enters this statement 
	Point Yes_Outlet;	//A point a yes connection leaves this statement
	Point No_Outlet;	//A point a no connection leaves this statement

	//Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();

public:
	CondStatement(Point Lcorner, string LeftHS = "",string op="", string RightHS = "");

	void setLHS(const string& L);
	void setRHS(const string& R);
	void setOP(const string& R);

	virtual Point getstatmentposition();
	virtual void Draw(Output* pOut) const;
	Point getInlet();
	Point getOutlet();
	virtual Connector* GetYes_Conn();
	virtual Connector* GetNo_Conn(); 
	Point getOutletyes();
	Point getOutletno();
	virtual void Save(ofstream& OutFile);	//Save the Statement parameters to a file
	Statement* getCopy();
	Point getLeftCorner();
	string getRHS();
	string getLHS();
	string getOP();
};

