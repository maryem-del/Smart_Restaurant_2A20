#include "ingredient.h"
#include "connection.h"
#include <QString>
#include <QSqlQuery>
#include<QSqlQueryModel>

ingredient::ingredient()
{
    codeingredient=0;
    prix=0;
    QString nombre_place="";
    quantite=0;
}

ingredient::ingredient(int codeingredient,QString type,int prix,int quantite)
{
    this->codeingredient=codeingredient;
    this->type=type;
    this->prix=prix;
    this->quantite=quantite;
}

bool ingredient::ajouter2()
{
    QSqlQuery query;
    QString res=QString::number(codeingredient);
    QString ress=QString::number(prix);
    QString resss=QString::number(quantite);
    query.prepare("INSERT INTO ingredient(codeingredient,type,prix,quantite)""VALUES(:codeingredient,:type,:prix,:quantite)");
    query.bindValue(":codeingredient",res);
    query.bindValue(":type",type);
    query.bindValue(":prix",ress);
    query.bindValue(":quantite",resss);
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
    model->setHeaderData(3,Qt::Horizontal,"quantite");
    return model ;
}

bool ingredient::modifier2(int codeingredient,QString type,int prix,int quantite)
{
    QSqlQuery query;
    query.prepare("UPDATE ingredient SET codeingredient=:codeingredient,type=:type,prix=:prix,quantite=:quantite WHERE codeingredient=:codeingredient");
    QString res= QString::number(codeingredient);
    QString ress=QString::number(prix);
    QString resss=QString::number(quantite);
    query.bindValue(":codeingredient",res);
    query.bindValue(":type",type);
    query.bindValue(":prix",ress);
    query.bindValue(":quantite",resss);
    return query.exec();
}

QSqlQueryModel * ingredient::trier_codeingredient()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * from ingredient ORDER BY codeingredient");
    model->setHeaderData(0,Qt::Horizontal,"codeingredient");
    model->setHeaderData(1,Qt::Horizontal,"type");
    model->setHeaderData(2,Qt::Horizontal,"prix");
    model->setHeaderData(3,Qt::Horizontal,"quantite");
    return model;
}
