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
    quantite=0;
}

plat::plat(int codeplat,QString matiere,int cout,QDateTime jours,int quantite)
{
    this->codeplat=codeplat;
    this->matiere=matiere;
    this->cout=cout;
    this->jours=jours;
    this->quantite=quantite;
}

bool plat::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(codeplat);
    QString ress=QString::number(cout);
    QString resss=QString::number(quantite);
    query.prepare("INSERT INTO plat(codeplat,matiere,cout,jours,quantite)""VALUES(:codeplat,:matiere,:cout,:jours,:quantite)");
    query.bindValue(":codeplat",res);
    query.bindValue(":matiere",matiere);
    query.bindValue(":cout",ress);
    query.bindValue(":jours",jours);
    query.bindValue(":quantite",resss);
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
    model->setHeaderData(5,Qt::Horizontal,"quantite");
    return model ;
}

bool plat::modifier(int codeplat,QString matiere,int cout,QDateTime jours,int quantite)
{
    QSqlQuery query;
    query.prepare("UPDATE plat SET codeplat=:codeplat,matiere=:matiere,cout=:cout,jours=:jours,quantite=:quantite WHERE codeplat=:codeplat");
    QString res= QString::number(codeplat);
    QString ress=QString::number(cout);
    QString resss=QString::number(quantite);
    query.bindValue(":codeplat",res);
    query.bindValue(":matiere",matiere);
    query.bindValue(":cout",ress);
    query.bindValue(":jours",jours);
    query.bindValue(":quantite",resss);
    return query.exec();
}

QSqlQueryModel *  plat::chercher(int codeplat)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString::number(codeplat);
    model->setQuery("SELECT * FROM plat WHERE (codeplat LIKE '"+res+"' ) ");
    return  model;

}
