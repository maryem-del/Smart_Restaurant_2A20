#include "connection.h"
#include "QSqlDatabase"
//test tuto GIT
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet_2A");//inserer le nom de la source de données ODBC
db.setUserName("fakher");//inserer nom de l'utilisateur
db.setPassword("fakher");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
