#include "Statement.h"

Statement::Statement()	
{ 
	Text = "";
	Selected = false;
	ID = count++;
	Connected = false;
	
}

void Statement::SetSelected(bool s )
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


void Statement::unselectstat()
{
	Selected = false;

}

int Statement::GetID()
{
	return ID;
}


bool Statement::GetConnected()
{
	return Connected;
}

int Statement::Getcount()
{
	return count;
}

Connector* Statement::getPconn()
{
	return pConn;
}

Connector* Statement::GetNo_Conn()
{
	return No_Conn;
}

Connector* Statement::GetYes_Conn()
{
	return Yes_Conn;
}

string Statement::getText()
{
	return Text;

}

string Statement::getLHS()
{
	return LHS;
}

string Statement::getRHS()
{
	return RHS;
}

string Statement::getRHS1()
{
	return RHS1;
}

string Statement::getOP()
{
	return OP;
}

string Statement::getRHS2()
{
	return RHS2;

}

string Statement::getvar()
{
	return VAR;

}
int Statement::count = 0;

Connector* Statement::Getconnect()
{
	return NULL;
}
