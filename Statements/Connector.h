#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "..\GUI\UI_Info.h"
#include "..\GUI\output.h"
#include "Statement.h"
class Statement;

class Connector  	//a connector that connects two statements (Source & Destination)
{
private:
	Statement *SrcStat;	//The source statement of the connector
	Statement *DstStat;	//The destination statement of the connector
	Point Start;	//Start point of the connector
	Point End;		//End point of the connector

public:
	Connector(Statement* Src, Statement* Dst);
	Connector(Point startc, Point endc);
	Point getInlet();
	Point getOutlet();
	void		setSrcStat(Statement *Src);
	Statement*	getSrcStat();	
	void		setDstStat(Statement *Dst);
	Statement*	getDstStat();

	void setStartPoint(Point P);
	Point getStartPoint();

	void setEndPoint(Point P);
	Point getEndPoint();

	void Draw(Output* pOut) const;
	virtual void UpdateStatementText();
	virtual Point getstatmentposition();
	virtual void getconnectorcords(Point& Startg, Point& Endg);

};

#endif