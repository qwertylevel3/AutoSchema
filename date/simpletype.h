#ifndef SIMPLETYPE_H
#define SIMPLETYPE_H

#include"date.h"

class SimpleType : public Date
{
public:
    SimpleType();
    virtual SimpleType *clone();
};

#endif // SIMPLETYPE_H
