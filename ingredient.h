#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<qdatetimeedit.h>
#include<qdatetime.h>
#include <QVariant>
#include <QComboBox>
class ingredient
{
public:
    ingredient();
    ingredient(int,QString,int);
    int get_code_ingredient(){return codeingredient;}
    QString get_type_ingredient(){return type;}
    int get_prix_ingredient(){return prix;}

    bool ajouter2();
    bool supprimer2(int);
    QSqlQueryModel *afficher2();
    bool modifier2(int,QString,int);

private:
    int codeingredient;
    QString type;
    int prix;
};


#endif // INGREDIENT_H
