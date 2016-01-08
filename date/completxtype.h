#ifndef COMPLETXTYPE_H
#define COMPLETXTYPE_H

#include"date.h"

class CompletxType : public Date
{
public:
    CompletxType();
    virtual CompletxType *clone();
};

#endif // COMPLETXTYPE_H
