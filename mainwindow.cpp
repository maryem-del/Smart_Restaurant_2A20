#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  //  son=new QSound(":/surrender-natalie-taylor-lyrics.mp3");//.wav
    //son->play();

    ui->tablePlat->setModel(tmpplat.afficher());
    ui->tableIng->setModel(tmpingredient.afficher2());

    ui->stackedWidget->setCurrentIndex(1);
    ui->comboBox->addItem("salé");
    ui->comboBox->addItem("sucré");

    ui->comboBox2->addItem("salé");
    ui->comboBox2->addItem("sucré");



    model = new QSqlTableModel;
    model->select();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_2_clicked()
{
    close();

}

void MainWindow::on_pushButton_3_clicked()
{
    close();

}

void MainWindow::afficher()
{

    Connection c;
    QSqlQueryModel* modal = new QSqlQueryModel();
    QSqlQuery* qry=new QSqlQuery(c.get_db());
    qry->prepare("SELECT* from plat");
    qry->exec();
    modal->setQuery(*qry);
    ui->tablePlat->setModel(modal);
}

void MainWindow::afficher2()
{

    Connection c;
    QSqlQueryModel* modal = new QSqlQueryModel();
    QSqlQuery* qry=new QSqlQuery(c.get_db());
    qry->prepare("SELECT* from ingredient");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableIng->setModel(modal);
}


void MainWindow::on_ajouter_ing_clicked()
{

    bool test;
    int codeingredient = ui->lineEdit_code_ing->text().toInt();
    QString type=ui->comboBox->currentText();
    int prix = ui->lineEdit_prix_ing->text().toInt();
    ingredient i(codeingredient,type,prix);
    //controle de saisie
    if(!(ui->lineEdit_code_ing->text().isEmpty() || ui->lineEdit_prix_ing->text().isEmpty() || ui->comboBox->currentText().isEmpty() ))

    { test=i.ajouter2();}

    if(test)
    {

        ui->tableIng->setModel(tmpingredient.afficher2());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter un ingrédient"),
                                 QObject::tr("ingrédient ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    //error
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un ingrédient"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_modifier_2_clicked()
{
    int codeingredient = ui->lineEdit_code_ingmodifier->text().toInt();
    int prix=ui->lineEdit_nouv_prix->text().toInt();
    QString type=ui->comboBox2->currentText(); //comboBox2
    ingredient i(codeingredient,type,prix);
    bool test=i.modifier2(codeingredient,type,prix);
    if(test)
    {
        ui->tableIng->setModel(tmpingredient.afficher2());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier un ingrédient !"),
                                 QObject::tr(" ingrédient modifiée ! \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }

    else {

        QMessageBox::critical(nullptr, QObject::tr("Modifier un ingrédient"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_supprimer_2_clicked()
{
        int codeingredient = ui->lineEdit_code_ingsupp->text().toInt();
        bool test = tmpingredient.supprimer2(codeingredient);
        if (test)
        {
            ui->tableIng->setModel(tmpingredient.afficher2());
            QMessageBox::information(nullptr, QObject::tr("Supprimer un ingrédient !"),
                                     QObject::tr(" ingrédient suprimé ! \n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
        }

        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Suppimer un ingrédient"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }

void MainWindow::on_ajouter_plat_clicked()
{
    bool test;
    int codeplat = ui->lineEdit_code_plat->text().toInt();
    QString matiere=ui->lineEdit_matiere->text();
    int cout=ui->lineEdit_cout_plat->text().toInt();
    QDateTime jours=ui->dateEdit_2->dateTime();
    plat p(codeplat,matiere,cout,jours);
    if(!(ui->lineEdit_code_plat->text().isEmpty()||ui->lineEdit_matiere->text().isEmpty()||ui->lineEdit_cout_plat->text().isEmpty()||ui->dateEdit_2->date().isNull()))

    {test=p.ajouter();}
    if(test)
    {

        ui->tablePlat->setModel(tmpplat.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter un plat"),
                                 QObject::tr("plat ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un plat"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_modifierplat_clicked()
{
    QString matiere= ui->lineEdit_nouvmat->text();  //lineEdit_nouv_nom
    int codeplat = ui->lineEdit_codeplatmodif->text().toInt(); //lineEdit_id_eventmodif
    int cout=ui->lineEdit_nouvcout->text().toInt(); //lineEdit_nouv_idsalle
    QDateTime jours=ui->dateEdit_3->dateTime();
    plat p(codeplat,matiere,cout,jours);
    bool test=p.modifier(codeplat,matiere,cout,jours);
    if(test)
    {
        ui->tablePlat->setModel(tmpplat.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier un plat !"),
                                 QObject::tr(" plat modifiée ! \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }

    else {

        QMessageBox::critical(nullptr, QObject::tr("Modifier un plat"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void MainWindow::on_supprimerplat_clicked()
{
    int codeplat = ui->lineEdit_codeplatsupp->text().toInt();
    bool test = tmpplat.supprimer(codeplat);
    if (test)
    {
        ui->tablePlat->setModel(tmpplat.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un plat !"),
                                 QObject::tr(" plat suprimé ! \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Suppimer un plat"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
