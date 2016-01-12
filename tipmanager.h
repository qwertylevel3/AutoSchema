#ifndef TIPMANAGER_H
#define TIPMANAGER_H

#include"singleton.h"
#include<QString>
#include<QXmlStreamReader>

class TipManager:public Singleton<TipManager>
{
public:
    TipManager();
    void init();
    QString getIndex_eName(){return index_eName;}
    QString getIndex_cName(){return index_cName;}
    QString getIndex_path(){return index_path;}
    QString getIndex_type(){return index_type;}
    QString getIndex_showName(){return index_showName;}
    QString getIndex_participle(){return index_participle;}

    QString getResult_indexName(){return result_indexName;}
    QString getResult_showName(){return result_showName;}
    QString getResult_showDetail(){return result_showDetail;}
private:
    QString index_eName;
    QString index_cName;
    QString index_path;
    QString index_type;
    QString index_showName;
    QString index_participle;

    QString result_indexName;
    QString result_showName;
    QString result_showDetail;

    QXmlStreamReader reader;
};

#endif // TIPMANAGER_H
