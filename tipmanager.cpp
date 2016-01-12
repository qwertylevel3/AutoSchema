#include "tipmanager.h"
#include<QMessageBox>
#include<QFile>

TipManager::TipManager()
{

}

void TipManager::init()
{
    QString fileName("tip.xml");

    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(0,("open error"),
                             ("无法打开tip.xml文件"),
                             QMessageBox::Ok);
        return;
    }

    reader.setDevice(&file);

    reader.readNextStartElement();

    while(!reader.atEnd())
    {
        reader.readNextStartElement();

        if(reader.name().toString()=="index_eName")
        {
            index_eName=reader.readElementText();
        }
        if(reader.name().toString()=="index_cName")
        {
            index_cName=reader.readElementText();
        }
        if(reader.name().toString()=="index_path")
        {
            index_path=reader.readElementText();
        }
        if(reader.name().toString()=="index_type")
        {
            index_type=reader.readElementText();
        }
        if(reader.name().toString()=="index_showName")
        {
            index_showName=reader.readElementText();
        }
        if(reader.name().toString()=="index_participle")
        {
            index_participle=reader.readElementText();
        }


        if(reader.name().toString()=="result_indexName")
        {
            result_indexName=reader.readElementText();
        }
        if(reader.name().toString()=="result_showName")
        {
            result_showName=reader.readElementText();
        }
        if(reader.name().toString()=="result_showDetail")
        {
            result_showDetail=reader.readElementText();
        }
        //reader.readNextStartElement();
    }
}

