#include "Start.h"
#include <sstream>

using namespace std;

Start::Start(Point Lcorner)
{
	Inlet = NULL;
	type = "ellipse";
	LeftCorner = Lcorner;

	pConn = NULL;	//No connectors yet

	Outlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}




void Start::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawStart(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Selected);

}

void Start::UpdateStatementText()
{
}


Point Start::getstatmentposition()
{
	LeftCorner.x + UI.ASSGN_WDTH / 2;
	LeftCorner.y + UI.ASSGN_HI / 2;
	return LeftCorner;

}

Point Start::getInlet()
{
	Point Inletr = Inlet;

	return Inletr;
}

Point Start::getOutlet()
{
	Point Outletr = Outlet;
	return Outletr;
}