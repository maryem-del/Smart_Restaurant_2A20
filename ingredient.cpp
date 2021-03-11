#include "ingredient.h"
#include "connection.h"
#include <QString>
#include <QSqlQuery>
#include<QSqlQueryModel>

ingredient::ingredient()
{
    codeingredient=0;
    prix=0;
    QString type="";
}

ingredient::ingredient(int codeingredient,QString type,int prix)
{
    this->codeingredient=codeingredient;
    this->type=type;
    this->prix=prix;
}

bool ingredient::ajouter2()
{
    QSqlQuery query;
    QString res=QString::number(codeingredient);
    QString ress=QString::number(prix);
    query.prepare("INSERT INTO ingredient(codeingredient,type,prix)""VALUES(:codeingredient,:type,:prix)");
    query.bindValue(":codeingredient",res);
    query.bindValue(":type",type);
    query.bindValue(":prix",ress);
    return query.exec();
}

bool ingredient::supprimer2(int i)
{
    QSqlQuery query;
    QString res=QString::number(i);
    query.prepare("DELETE FROM ingredient where codeingredient=:codeingredient");
    query.bindValue(":codeingredient",res);
    return query.exec();
}

QSqlQueryModel *ingredient::afficher2()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from ingredient ");
    model->setHeaderData(0,Qt::Horizontal,"codeingredient");
    model->setHeaderData(1,Qt::Horizontal,"type");
    model->setHeaderData(2,Qt::Horizontal,"prix");
    return model ;
}

bool ingredient::modifier2(int codeingredient,QString type,int prix)
{
    QSqlQuery query;
    query.prepare("UPDATE ingredient SET codeingredient=:codeingredient,type=:type,prix=:prix WHERE codeingredient=:codeingredient");
    QString res= QString::number(codeingredient);
    QString ress=QString::number(prix);
    query.bindValue(":codeingredient",res);
    query.bindValue(":type",type);
    query.bindValue(":prix",ress);
    return query.exec();
}


