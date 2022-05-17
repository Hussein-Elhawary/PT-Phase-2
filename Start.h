#pragma once
#include "Statements/Statement.h"
class Start : public Statement
{
private:
	

	Connector* pConn;	//Start Stat. has one Connector to next statement

	Point Outlet;	//A point a connection leaves this statement

	//Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();
	

public:
	Start(Point Lcorner);
	void Draw(Output* pOut) const;
	virtual Point getstatmentposition();
	Point getInlet();
	Point getOutlet();
	virtual Connector* Getconnect();
	virtual void Save(ofstream& OutFile);	//Save the Statement parameters to a file
	Statement* getCopy();
};

