#pragma once
#include "Statements/Statement.h"
class Read : public Statement
{
private:
	string VAR;	//Variable in the assignment (name of a variable)

	Connector* pConn;	//Read Stat. has one Connector to next statement

	Point Inlet;	//A point where connections enters this statement 
	Point Outlet;	//A point a connection leaves this statement

	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();

public:
	Read(Point Lcorner, string var = "");
	void setVAR(const string& var);

	virtual void Draw(Output* pOut) const; 
	virtual Point getstatmentposition();
	Point getInlet();
	Point getOutlet();
	virtual Connector* Getconnect();
	virtual void Save(ofstream& OutFile);	//Save the Statement parameters to a file

};

