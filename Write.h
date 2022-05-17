#pragma once
#include "Statements/Statement.h"
class Write : public Statement
{
private:
	string VAR;	//object in the assignment (name of a variable)

	Connector* pConn;	//Write Stat. has one Connector to next statement

	Point Inlet;	//A point where connections enters this statement 
	Point Outlet;	//A point a connection leaves this statement

	//Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();
	virtual Point getstatmentposition();

public:
	Write(Point Lcorner, string obj = "");
	void setVAR(const string& L);
	virtual void Draw(Output* pOut) const;
	Point getInlet();
	Point getOutlet();
	virtual Connector* Getconnect();
	virtual void Save(ofstream& OutFile) ;	//Save the Statement parameters to a file
	Statement* getCopy();
	string getVAR();
};

