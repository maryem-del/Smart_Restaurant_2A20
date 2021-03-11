#include "plat.h"
#include "connection.h"
#include <QString>
#include <QSqlQuery>
#include<QSqlQueryModel>
plat::plat()
{
    codeplat=0;
    cout=0;
    matiere="";
}

plat::plat(int codeplat,QString matiere,int cout,QDateTime jours)
{
    this->codeplat=codeplat;
    this->matiere=matiere;
    this->cout=cout;
    this->jours=jours;
}

bool plat::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(codeplat);
    QString ress=QString::number(cout);
    query.prepare("INSERT INTO plat(codeplat,matiere,cout,jours)""VALUES(:codeplat,:matiere,:cout,:jours)");
    query.bindValue(":codeplat",res);
    query.bindValue(":matiere",matiere);
    query.bindValue(":cout",ress);
    query.bindValue(":jours",jours);
    return query.exec();

}

bool plat::supprimer(int i)
{
    QSqlQuery query;
    QString res=QString::number(i);
    query.prepare("DELETE FROM plat where codeplat=:codeplat");
    query.bindValue(":codeplat",res);
    return query.exec();
}

QSqlQueryModel *plat::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from plat");
    model->setHeaderData(0,Qt::Horizontal,"codeplat");
    model->setHeaderData(1,Qt::Horizontal,"matiere");
    model->setHeaderData(2,Qt::Horizontal,"cout");
    model->setHeaderData(4,Qt::Horizontal,"jours");
    return model ;
}

bool plat::modifier(int codeplat,QString matiere,int cout,QDateTime jours)
{
    QSqlQuery query;
    query.prepare("UPDATE plat SET codeplat=:codeplat,matiere=:matiere,cout=:cout,jours=:jours WHERE codeplat=:codeplat");
    QString res= QString::number(codeplat);
    QString ress=QString::number(cout);
    query.bindValue(":codeplat",res);
    query.bindValue(":matiere",matiere);
    query.bindValue(":cout",ress);
    query.bindValue(":jours",jours);
    return query.exec();
}


