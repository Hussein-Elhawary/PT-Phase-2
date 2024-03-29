#include "Connector.h"

Connector::Connector(Statement* Src, Statement* Dst)	
//When a connector is created, it must have a source statement and a destination statement
//There are no free connectors in the folwchart
{
	SrcStat = Src;
	DstStat = Dst;
	selected = false;
}

Connector::Connector(Point startc, Point endc)
{
	Start = startc;
	End = endc;
	selected = false;
}

void Connector::setSrcStat(Statement *Src)
{	SrcStat = Src;	}

Statement* Connector::getSrcStat()
{	return SrcStat;	}

void Connector::setDstStat(Statement *Dst)
{	DstStat = Dst;	}

Statement* Connector::getDstStat()
{	return DstStat;	}


void Connector::setStartPoint(Point P)
{	Start = P;	}

Point Connector::getStartPoint()
{	return Start;	}

void Connector::setEndPoint(Point P)
{	End = P;	}

Point Connector::getEndPoint()
{	return End;	}

void Connector::Draw(Output* pOut) const
{
	///TODO: Call output to draw a connector from SrcStat to DstStat on the output window
	pOut->DrawConnector(Start, End,selected);
}

void Connector::UpdateStatementText()
{
	//hussein says this still not done

}

Point Connector::getstatmentposition()
{
	return Start;

}
void Connector::unselectconn()
{
	selected = false;

}

void Connector::SetSelected(bool s)
{
	selected = s;

}

void Connector::Save(ofstream& OutFile)
{
	OutFile << SrcStat->GetID() << "  " << DstStat->GetID() << "  " << endl;
}

void Connector::getconnectorcords(Point& Startg, Point& Endg)
{
	Startg = Start;
	Endg = End;

}