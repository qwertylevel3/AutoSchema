#include "date.h"

Date::Date(Date *p)
    :parent(p)
{
}

Date::~Date()
{
    for(int i=0;i<child.size();i++)
    {
        delete child[i];
    }
}

