#include "End.h"
#include <sstream>

using namespace std;

End::End(Point Lcorner)
{
	Outlet = NULL;
	type = "ellipse";
	LeftCorner = Lcorner;

	pConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;
}




void End::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawEnd(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI,Selected);

}

void End::UpdateStatementText()
{
}

Point End::getstatmentposition()
{
	LeftCorner.x + UI.ASSGN_WDTH / 2;
	LeftCorner.y + UI.ASSGN_HI / 2;
	return LeftCorner ;

}

Point End::getInlet()
{
	Point Inletr = Inlet;

	return Inletr;
}

Point End::getOutlet()
{
	Point Outletr = Outlet;
	return Outletr;
}