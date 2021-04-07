#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // son=new QSound(":/new/musicr.wav");

   // son->play();

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
    int quantite =ui->lineEdit_quantiteing->text().toInt();
    ingredient i(codeingredient,type,prix,quantite);
    if(!(ui->lineEdit_code_ing->text().isEmpty() || ui->lineEdit_prix_ing->text().isEmpty() || ui->comboBox->currentText().isEmpty()||ui->lineEdit_quantiteing->text().isEmpty() ))

    { test=i.ajouter2();}

    if(test)
    {

        ui->tableIng->setModel(tmpingredient.afficher2());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter un ingrédient"),
                                 QObject::tr("ingrédient ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
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
    int quantite=ui->lineEdit_quantitemodiing->text().toInt();
    ingredient i(codeingredient,type,prix,quantite);
    bool test=i.modifier2(codeingredient,type,prix,quantite);
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
    int quantite =ui->lineEdit_quantiteplat->text().toInt();
    plat p(codeplat,matiere,cout,jours,quantite);
    if(!(ui->lineEdit_code_plat->text().isEmpty()||ui->lineEdit_matiere->text().isEmpty()||ui->lineEdit_quantiteplat->text().isEmpty() ||ui->lineEdit_cout_plat->text().isEmpty()||ui->dateEdit_2->date().isNull()))

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
    int quantite=ui->lineEdit_quantitemodifplat->text().toInt();
    plat p(codeplat,matiere,cout,jours,quantite);
    bool test=p.modifier(codeplat,matiere,cout,jours,quantite);
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

void MainWindow::on_pushButton_rechercher_clicked()
{
    int codeplat = ui->lineEdit_chercherplat->text().toInt();
    ui->tablePlat->setModel(tmpplat.chercher(codeplat));
}

void MainWindow::on_pushButton_trie_clicked()
{
    bool test = true;
    if (test)
    {
        ui->tableIng->setModel(tmpingredient.trier_codeingredient());
        QMessageBox::information(nullptr, QObject::tr("Trier ingrédient par codeingredient"),
                                 QObject::tr("ingrédient trié.\n"
                                             "Voulez-vous enregistrer les modifications ?"),
                                 QMessageBox::Save
                                     | QMessageBox::Cancel,
                                 QMessageBox::Save);
    }

    else{
        QMessageBox::critical(nullptr, QObject::tr("ingrédient par codeingrédient"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_imprimer_9_clicked()
{
    QPrintPreviewDialog dialog;
    connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(uglyPrint(QPrinter*)));
    dialog.exec();
}

class PrintBorder : public PagePrepare
{
public:
    virtual void preparePage(QPainter *painter);
    static int pageNumber;
};

int PrintBorder::pageNumber = 0;

void PrintBorder::preparePage(QPainter *painter)
{ // print a border on each page
    QRect rec = painter->viewport();
    painter->setPen(QPen(QColor(0, 0, 0), 1));
    painter->drawRect(rec);
    painter->translate(10, painter->viewport().height() - 10);
    painter->drawText(0, 0, QString("Page %1").arg(pageNumber));


    pageNumber += 1;
}

void MainWindow::uglyPrint(QPrinter *printer) {

    // ---------------- death-to-designers example Res------------------

    QPainter uglyPainter;
    if(!uglyPainter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    TablePrinter uglyTablePrinter(&uglyPainter, printer);
    QVector<int> colStretch = QVector<int>() << 2 << 5 << 10 <<5 <<2;
    uglyTablePrinter.setPen(QPen(QColor(0, 100, 255), 3, Qt::DotLine)); // pen for borders
    uglyTablePrinter.setHeaderColor(Qt::darkBlue);
    uglyTablePrinter.setContentColor(Qt::red);
    QFont font1; // font for headers
    font1.setBold(true);
    QFont font2; // font for content
    font2.setItalic(true);
    uglyTablePrinter.setHeadersFont(font1);
    uglyTablePrinter.setContentFont(font2);
    PrintBorder *printB = new PrintBorder;
    printB->pageNumber = 1;
    uglyTablePrinter.setPagePrepare(printB);
    QVector<QString> headers = QVector<QString>() << "codeplat" << "matiere" << "cout" << "jours"<<"quantite";
    uglyPainter.setPen(QPen(Qt::darkCyan));
    uglyPainter.drawText(uglyPainter.viewport().width()/2 - 40, 40, "TABLE Plat MODULE MARYEM");
    uglyPainter.translate(0, 60); // start print point
    uglyTablePrinter.setCellMargin(10, 5, 5, 5);
    uglyTablePrinter.setPageMargin(100, 40, 40, 40);
    if(!uglyTablePrinter.printTable(ui->tablePlat->model(), colStretch, headers)) {
        qDebug() << uglyTablePrinter.lastError();
    }
    uglyPainter.end();
    delete printB;
}
void MainWindow::print(QPrinter *printer) {

    // ------------------ simplest example Res --------------------------

    QPainter painter;
    if(!painter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    // print table
    TablePrinter tablePrinter(&painter, printer);
    QVector<int> columnStretch = QVector<int>() << 2 << 5 << 10 << 15;
    if(!tablePrinter.printTable(ui->tablePlat->model(), columnStretch)) {
        qDebug() << tablePrinter.lastError();
    }
    painter.end();
}

void MainWindow::on_pushButton_stat_clicked()
{
    secDialog = new SecDialog(this);
    secDialog ->show();
}

void MainWindow::on_pushButton_clicked()
{
    hide();
    login login;
    login.setModal(true);
    login.exec();


}

void MainWindow::on_pushButton_4_clicked()
{

        QPrintPreviewDialog dialog;
        connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(print(QPrinter*)));
        dialog.exec();
    }

