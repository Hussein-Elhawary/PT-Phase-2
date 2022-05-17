#pragma once
#include "Statements/Statement.h"

class End : public Statement
{
private:



	Point  Inlet;	//A point a connection leaves this statement

	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();


public:
	End(Point Lcorner);
	virtual void Draw(Output* pOut) const;
	virtual Point getstatmentposition();
	Point getInlet();
	Point getOutlet();
	virtual Connector* Getconnect();
	virtual void Save(ofstream& OutFile);	//Save the Statement parameters to a file

};

