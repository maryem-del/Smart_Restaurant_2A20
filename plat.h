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
    plat(int,QString,int,QDateTime);
    int get_code_plat(){return codeplat;}
    QString get_matiere(){return matiere;}
    int get_cout(){return cout;}
    QString get_time();

    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel *afficher();
    bool modifier(int,QString,int,QDateTime);

private:
    int codeplat;
    QString matiere;
    int cout;
    QDateTime jours;
};

#endif // PLAT_H
