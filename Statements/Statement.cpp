#include "Statement.h"

Statement::Statement()	
{ 
	Text = "";
	Selected = false;	
	
}

void Statement::SetSelected(bool s)
{	Selected = s; }

bool Statement::IsSelected() const
{	return Selected; }

string Statement::gettype()
{
	return type;
}
int Statement::getheight()
{
	return height;
}

int Statement::getwidth()
{
	return width;
}

Point Statement::getstatmentposition()
{
	//not working yet
	Point x(0, 1);
	return x;
}
Point Statement::getInlet()
{

	return Inlet;
}

Point Statement::getOutlet()
{

	return Outlet;
}

Point Statement::getOutletyes()
{
	return NULL;
}

Point Statement::getOutletno()
{
	return NULL;
}

//Connector* Statement::Getconnect()
//{
//	return NULL;
//}


void Statement::unselectstat()
{
	Selected = false;

}