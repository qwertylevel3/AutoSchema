#include "date.h"

Date::Date()
{
    setCheckable(false);
    indexChecked=false;
    resultChecked=false;
    tableNo=-1;
}

Date::~Date()
{
}

void Date::indexCheck(bool c)
{
    indexChecked=c;
//    for(int i=0;i<this->rowCount();i++)
//    {
//        static_cast<Date*>(this->child(i))->indexCheck(c);
//    }
}

void Date::resultCheck(bool c)
{
    resultChecked=c;
//    for(int i=0;i<this->rowCount();i++)
//    {
//        static_cast<Date*>(this->child(i))->resultCheck(c);
//    }
}

