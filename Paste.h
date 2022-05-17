#pragma once
#include "Actions/Action.h"
#include "Statements/Statement.h"
class Paste :
    public Action
{
private:
    Point PastePoint;
    Statement* Pasted;
public:
    Paste(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
};

