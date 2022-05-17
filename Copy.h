#pragma once
#include "Actions/Action.h"
#include "Statements/Statement.h"
class Copy :
    public Action
{
protected:
    Statement* Copied;
    Point LeftCorner;
public:
    Copy(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
};