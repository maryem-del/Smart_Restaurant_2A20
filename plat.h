#ifndef PLAT_H
#define PLAT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<qdatetimeedit.h>
#include<qdatetime.h>
#include <QVariant>
#include <QComboBox>
class plat
{
public:
    plat();
    plat(int,QString,int,QDateTime,int);
    int get_code_plat(){return codeplat;}
    QString get_matiere(){return matiere;}
    int get_cout(){return cout;}
    QString get_time();
    int get_quantite(){return quantite;}

    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel *afficher();
    bool modifier(int,QString,int,QDateTime,int);
    QSqlQueryModel * chercher(int);


private:
    int codeplat;
    QString matiere;
    int cout;
    QDateTime jours;
    int quantite;
};

#endif // PLAT_H
