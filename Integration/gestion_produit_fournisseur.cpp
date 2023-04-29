#include "gestion_produit_fournisseur.h"
#include "ui_gestion_produit_fournisseur.h"
#include <QDebug>
#include <QApplication>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "smtphakim.h"
#include "arduino.h"
#include <QMediaPlayer>
#include <QSystemTrayIcon>
#include <fstream>
#include <QtWidgets>
#include <QPrintDialog>
#include <QPrinter>
#include <QFile>
#include <QFileDialog>
#include"QPdfWriter"
#include "stat_fournisseur.h"
#include "QrCode.hpp"


using namespace std;
gestion_produit_fournisseur::gestion_produit_fournisseur(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::gestion_produit_fournisseur)
{
    ui->setupUi(this);
    initFileDirectory();
    initPushButton();
    initColorComboBox();
    initStatusBar();

    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));

    Player = new QMediaPlayer(this);
    //ui->stackedWidget->setCurrentIndex(4);
    int ret= ard.connect_arduino();
    switch(ret)
    {case(0):
        qDebug() << "arduino is available and cooneted to  : "<<ard.getarduino_port_name();
        break;
     case(1):
        qDebug()<< "arduino is available but not conected to : "<< ard.getarduino_port_name();
        break;
     case(-1):
        qDebug()<<"arduino is no available ";
        break;
    }
    ui->tabWidget_2->setCurrentIndex(0);
    ui->comboBox_2->setModel(tabproduit.affecter_fournisseur());


    QObject::connect(ard.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()) );
}

gestion_produit_fournisseur::~gestion_produit_fournisseur()
{
    delete ui;
}

// ===================================
//			Qt Slots
// ===================================

/*
* When user open a program, by default, these buttons are disabled.
* enableButton() is a function to enable generateButton and clearButton
* if user enter any text in userTextInput textbox.
*/
void gestion_produit_fournisseur::enableButton() {
    ui->generateButton->setEnabled(!(ui->userTextInput->toPlainText().isEmpty()));
    ui->clearButton->setEnabled(!(ui->userTextInput->toPlainText().isEmpty()));
}

/*
* This function enables user to select a directory.
* By default, the dialog appear with current directory.
* Update file directory lineEdit and shows in the program.
*/
void gestion_produit_fournisseur::selectDirectory() {
    dir = QFileDialog::getExistingDirectory(this, tr("Select Directory"), QDir::currentPath());
    ui->lineEdit_fileDirectory->setText(dir);
}

/*
* Function to receive a text from userTextInput textbox.
* qrcodegen library will tranforms a text into QR Code as SVG format.
* Then, save generated SVG XML as a file, doneDialog will be appeared.
*/
void gestion_produit_fournisseur::generateQR() {
    // Convert from QString to const char*
    QString msgfromtextbox = ui->userTextInput->toPlainText();
    std::string stringtext = msgfromtextbox.toStdString();
    const char *text = stringtext.c_str();

    // Encode text into SVG XML format
    const qrcodegen::QrCode::Ecc &errCorLvl = qrcodegen::QrCode::Ecc::LOW;
    const qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(text, errCorLvl);

    // Save SVG XML into file
    ofstream myfile;
    myfile.open(dir.toStdString() + "/" + stringtext +".svg");
    myfile << qr.toSvgString(gestion_produit_fournisseur::getBorderSize(), gestion_produit_fournisseur::getColor()) << std::endl;
    myfile.close();

    // Display doneDialog
    gestion_produit_fournisseur::doneDialog();


}
void gestion_produit_fournisseur::doneDialog() {
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    QString msg = "Done!\n\nText to be encoded: \n" + ui->userTextInput->toPlainText();
    msgBox.setText(msg);
    msgBox.exec();
}
/*
* A function to quit an application.
*/
void gestion_produit_fournisseur::exitApp() {
    QApplication::exit();
}

// ===================================
//			Getter Functions
// ===================================

/*
* Get current index from combobox_color and return its color in std::string format
* By default, it have 14 colors to choose. (Color palette from Android Material Design)
@return Hex color code without '#' symbol
*/
std::string gestion_produit_fournisseur::getColor() {
    // Get current index from comboBox_color
    int index = ui->comboBox_color->currentIndex();

    // Return the color from index
    switch (index) {
    case 0: return "000000"; break;	// Black (Default)
    case 1: return "F44336"; break;	// Red
    case 2: return "E91E63"; break; // Pink
    case 3: return "9C27B0"; break; // Purple
    case 4: return "673AB7"; break; // Deep Purple
    case 5: return "3F51B5"; break; // Indigo
    case 6: return "2196F3"; break; // Blue
    case 7: return "00BCD4"; break; // Cyan
    case 8: return "009688"; break; // Teal
    case 9: return "4CAF50"; break; // Green
    case 10: return "FF9800"; break; // Orange
    case 11: return "FF5722"; break; // Deep Orange
    case 12: return "795548"; break; // Brown
    case 13: return "4B4B4B"; break; // Grey
    }
}

int gestion_produit_fournisseur::getBorderSize() { return ui->spinBox_borderSize->value(); }
/*
* A function to initialize file directory lineEdit.
@param dir	current path (system default)
*/
void gestion_produit_fournisseur::initFileDirectory() {
    // File directory
    dir = QDir::currentPath();
    ui->lineEdit_fileDirectory->setText(dir);
}

/*
* A function to initialize all pushButton.
*/
void gestion_produit_fournisseur::initPushButton() {
    // Push Button
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(exitApp()));
    connect(ui->userTextInput, SIGNAL(textChanged()), this, SLOT(enableButton()));
    connect(ui->generateButton, SIGNAL(clicked()), this, SLOT(generateQR()));
    connect(ui->browseButton, SIGNAL(clicked()), this, SLOT(selectDirectory()));
}

/*
* Colorize each color in comboBox_color combobox.
* First parameter represent the index of comboBox_color.
*/
void gestion_produit_fournisseur::initColorComboBox() {
    ui->comboBox_color->setItemData(1, QBrush(QColor(244, 67, 54)), Qt::TextColorRole); // Red
    ui->comboBox_color->setItemData(2, QBrush(QColor(233, 30, 99)), Qt::TextColorRole); // Pink
    ui->comboBox_color->setItemData(3, QBrush(QColor(156, 39, 176)), Qt::TextColorRole); // Purple
    ui->comboBox_color->setItemData(4, QBrush(QColor(103, 58, 183)), Qt::TextColorRole); // Deep Purple
    ui->comboBox_color->setItemData(5, QBrush(QColor(63, 81, 181)), Qt::TextColorRole); // Indigo
    ui->comboBox_color->setItemData(6, QBrush(QColor(33, 150, 243)), Qt::TextColorRole); // Blue
    ui->comboBox_color->setItemData(7, QBrush(QColor(0, 188, 212)), Qt::TextColorRole); // Cyan
    ui->comboBox_color->setItemData(8, QBrush(QColor(0, 150, 136)), Qt::TextColorRole); // Teal
    ui->comboBox_color->setItemData(9, QBrush(QColor(76, 175, 80)), Qt::TextColorRole); // Green
    ui->comboBox_color->setItemData(10, QBrush(QColor(255, 152, 0)), Qt::TextColorRole); // Orange
    ui->comboBox_color->setItemData(11, QBrush(QColor(255, 87, 34)), Qt::TextColorRole); // Deep Orange
    ui->comboBox_color->setItemData(12, QBrush(QColor(121, 85, 72)), Qt::TextColorRole); // Brown
    ui->comboBox_color->setItemData(13, QBrush(QColor(75, 75, 75)), Qt::TextColorRole); // Grey
}

/*
* A function to initialize status bar.
* Tooltip is a help text which tell user the function of each section of the program.
*/
void gestion_produit_fournisseur::initStatusBar() {
    // Status Bar

    // Tooltip
;
    ui->generateButton->setStatusTip("Click to generate a QR Code.");
    ui->exitButton->setStatusTip("Exit an application.");
}

void gestion_produit_fournisseur::update_label()
{
    data=ard.read_from_arduino();

    qDebug() << data;
    //QString retour = QTextCodec::codecForMib(1015)->toUnicode(data);
        // QString::fromStdString(data.toStdString());
   QString retour=QString(data);
   retour.chop(2);
    //QList <QString> ahla;
   qDebug() << retour;
ui->tableView_4->setModel(tabproduit.recherchep(retour));
     //if(((retour !="Error: not a valid qrcode") ||(retour !="Error: not a v") ||(retour !="alid qrcode") ) && (retour == "1 QR-codes found:\r\n") )
    /*     if(retour !="Error: not a valid qrcode")
    {
         ui->update_arduino->setText(retour);
    ui->tableView_4->setModel(tabproduit.recherchep(retour));
    qDebug() << retour;
    }
    //else (ui->update_arduino->setText(retour));
*/
     //ui->tableView_4->setModel(tabproduit.recherchep(retour));
  ui->update_arduino->setText("attendez s'il vous plaît");
}

void gestion_produit_fournisseur::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}

void gestion_produit_fournisseur::sendMail()
{

    Smtphakim* smtp = new Smtphakim(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void gestion_produit_fournisseur::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}


void gestion_produit_fournisseur::on_tabWidget_2_currentChanged(int index)
{
    ui->produit_2->setModel(tabproduit.afficherp());
    ui->tableView->setModel(tabproduit.afficherp());
    ui->tableView_2->setModel(tabproduit.afficherp());
    ui->tableView_mailing->setModel(tabproduit.mailing());
    QString ref=ui->idmodif->currentText();
    QSqlQueryModel *mod= new QSqlQueryModel();
    mod->setQuery("select REF from PRODUIT ");
    ui->idmodif->setModel(mod);
    QSqlQuery q;
    q.prepare("select * from PRODUIT where REF = '"+ref+"'");
    if(q.exec())
    {
        while(q.next())
        {
            ui->lineEdit_5->setText(q.value(1).toString());
            ui->lineEdit_6->setText(q.value(2).toString());
            ui->lineEdit_7->setText(q.value(3).toString());
            ui->comboBox_4->setCurrentText(q.value(4).toString());
        }
    }
}

void gestion_produit_fournisseur::on_tabWidget_3_currentChanged(int index)
{
    ui->fournisseurtable->setModel(tabfour.afficherf());
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select MATRICULE from FOURNISSEUR");
    ui->comboBox_mat->setModel(model);
    ui->tableView_3->setModel(tabfour.afficherf());
}

void gestion_produit_fournisseur::on_ajout_clicked()
{
    QString ref=ui->lineEdit_ref->text();
    QString nom=ui->lineEdit_nom->text();
    int prix=ui->lineEdit_prix->text().toInt();
    int stock=ui->lineEdit_stock->text().toInt();
    int x=0;
    QString m_f=ui->comboBox_2->currentText();

    string str_prix=to_string(prix);

    string str_stock= to_string(stock);
    if(ref=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("la refernce est vide"), QMessageBox::Ok);
              x++;
    }
    else if(nom=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("la nom est vide"), QMessageBox::Ok);
              x++;
    }
    else if(x==0)
    {
        produit p(ref,nom,m_f,stock,prix);
        bool t=p.ajouterp();
        if(t)
        {
            QMessageBox::information(nullptr, QObject::tr("produit ajouter"),
                              QObject::tr("base de données mise à jour"), QMessageBox::Ok);
            ui->lineEdit_ref->clear();
            ui->lineEdit_nom->clear();
            ui->lineEdit_prix->clear();
            ui->lineEdit_stock->clear();
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                    notifyIcon->show();
                    notifyIcon->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/My work/rs/logo.png"));
                    notifyIcon->setVisible("C:/Users/ASUS/OneDrive/Desktop/QT/My work/rs/logo.png");

                    notifyIcon->showMessage("GESTION produit  ","produit ajouter",QSystemTrayIcon::Information,15000);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                        QObject::tr("Veuillez réessayer"), QMessageBox::Ok);

        }
    }
}

void gestion_produit_fournisseur::on_modif_clicked()
{
    QString ref=ui->idmodif->currentText();
    QString nom=ui->lineEdit_5->text();
    int stock=ui->lineEdit_6->text().toInt();
    int prix=ui->lineEdit_7->text().toInt();
    int x=0;
    if(ref=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("la refernce est vide"), QMessageBox::Ok);
              x++;
    }
    else if(nom=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("la nom est vide"), QMessageBox::Ok);
              x++;
    }
    else if(x==0)
    {
        produit p(ref,nom,stock,prix);
        bool t=p.modifierp(ref);
        if(t)
        {
            QMessageBox::information(nullptr, QObject::tr("produit modifier"),
                              QObject::tr("base de données mise à jour"), QMessageBox::Ok);
            ui->idmodif->clear();
            ui->lineEdit_5->clear();
            ui->lineEdit_6->clear();
            ui->lineEdit_7->clear();
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                    notifyIcon->show();
                    notifyIcon->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/My work/rs/logo.png"));
                    notifyIcon->setVisible("C:/Users/ASUS/OneDrive/Desktop/QT/My work/rs/logo.png");

                    notifyIcon->showMessage("GESTION produit  ","produit modifier",QSystemTrayIcon::Information,15000);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                        QObject::tr("Veuillez réessayer"), QMessageBox::Ok);
            ui->idmodif->clear();
            ui->lineEdit_5->clear();
            ui->lineEdit_6->clear();
            ui->lineEdit_7->clear();
        }
    }


}

void gestion_produit_fournisseur::on_tableView_activated(const QModelIndex &index)
{
    int val=ui->tableView->model()->data(index).toInt();
    if(tabproduit.supprmierp(val))
    {
        QMessageBox::information(nullptr, QObject::tr("produit supprimer"),
                          QObject::tr("base de données mise à jour"), QMessageBox::Ok);
        //ui->stackedWidget->setCurrentIndex(1);
        ui->tableView->setModel(tabproduit.afficherp());
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                notifyIcon->show();
                notifyIcon->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/My work/rs/logo.png"));
                notifyIcon->setVisible("C:/Users/ASUS/OneDrive/Desktop/QT/My work/rs/logo.png");

                notifyIcon->showMessage("GESTION produit ","produit supprimer",QSystemTrayIcon::Information,15000);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Veuillez réessayer"), QMessageBox::Ok);
    }
}

void gestion_produit_fournisseur::on_produit_2_activated(const QModelIndex &index)
{
    QString val=ui->produit_2->model()->data(index).toString();
    QSqlQuery q;
    q.prepare("SELECT * FROM PRODUIT WHERE REF = '"+val+"' OR NOM = '"+val+"' OR STOCK = '"+val+"' OR PRIX = '"+val+"' ");
    if(q.exec())
    {
        while(q.next())
        {   QSqlQueryModel *mod= new QSqlQueryModel();
            mod->setQuery("select REF from PRODUIT WHERE REF ='"+val+"' ");
            ui->idmodif->setModel(mod);
            ui->tabWidget_2->setCurrentIndex(1);
            ui->lineEdit_5->setText(q.value(1).toString());
            ui->lineEdit_6->setText(q.value(2).toString());
            ui->lineEdit_7->setText(q.value(3).toString());
            ui->comboBox_4->setCurrentText(q.value(4).toString());
        }
    }
}

void gestion_produit_fournisseur::on_trie_clicked()
{
    ui->produit_2->setModel(tabproduit.triep());
}

void gestion_produit_fournisseur::on_cherchp_cursorPositionChanged(int arg1, int arg2)
{
    QString ref=ui->cherchp->text();
    ui->produit_2->setModel(tabproduit.recherchep(ref));
}

void gestion_produit_fournisseur::on_cherchep_clicked()
{
    QString m=ui->recherche->text();
    ui->fournisseurtable->setModel(tabfour.cherchef(m));
}

void gestion_produit_fournisseur::on_pushButton_2_clicked()
{
    ui->tableView_mailing->setModel(tabproduit.mailing());
    ui->tabWidget_2->setCurrentIndex(4);

}

void gestion_produit_fournisseur::on_ajoutf_clicked()
{
    QString matricule =ui->lineEdit_m->text();
    QString nom=ui->lineEdit_n->text();
    QString adresse=ui->lineEdit_a->text();
    QString email=ui->lineEdit_e->text();
    int tel=ui->lineEdit_t->text().toInt();
     int x=0;
    string str_tel = to_string(tel);
    string m = email.toStdString();
    if(matricule=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("la matricule est vide"), QMessageBox::Ok);
              x++;
    }
    else if(nom=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("le nom est vide"), QMessageBox::Ok);
              x++;
    }
    else if(adresse=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("l'adress est vide"), QMessageBox::Ok);
              x++;
    }
    else if(m.find("@gmail.com")== std:: string::npos)
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Email must end with @gmail.com"), QMessageBox::Ok);
              x++;
    }
    else if(str_tel.length()!=8)
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Phone number must be composed of 8 numbers"), QMessageBox::Ok);
              x++;
    }
    else if(x==0)
    {
        fournisseur f(matricule,nom,adresse,email,tel);
        bool t=f.ajouterf();
        if(t)
        {
            QMessageBox::information(nullptr, QObject::tr("fournisseur ajouter"),
                              QObject::tr("base de données mise à jour"), QMessageBox::Ok);
            ui->lineEdit_m->clear();
            ui->lineEdit_n->clear();
            ui->lineEdit_a->clear();
            ui->lineEdit_e->clear();
            ui->lineEdit_t->clear();
            //ui->stackedWidget->setCurrentIndex(0);
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                    notifyIcon->show();
                    notifyIcon->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/My work/rs/logo.png"));
                    notifyIcon->setVisible("C:/Users/ASUS/OneDrive/Desktop/QT/My work/rs/logo.png");

                    notifyIcon->showMessage("GESTION fournisseur ","fournisseur ajouter",QSystemTrayIcon::Information,15000);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                        QObject::tr("Veuillez réessayer"), QMessageBox::Ok);
        }
    }

}

void gestion_produit_fournisseur::on_fournisseurtable_activated(const QModelIndex &index)
{
    QString val=ui->fournisseurtable->model()->data(index).toString();
    QSqlQuery q;
    q.prepare("select * from FOURNISSEUR where matricule = '"+val+"'");
    if(q.exec())
    {
        //ui->stackedWidget->setCurrentIndex(11);
        while(q.next())
        {
            ui->comboBox_mat->setCurrentText(q.value(0).toString());
            ui->lineEdit_nf->setText(q.value(1).toString());
            ui->lineEdit_numf->setText(q.value(4).toString());
            ui->lineEdit_ad->setText(q.value(2).toString());
            ui->lineEdit_mail->setText(q.value(3).toString());

        }
    }


}

void gestion_produit_fournisseur::on_pushButton_3_clicked()
{
    ui->fournisseurtable->setModel(tabfour.trief());
}

void gestion_produit_fournisseur::on_recherche_cursorPositionChanged(int arg1, int arg2)
{
    QString m=ui->recherche->text();
    ui->fournisseurtable->setModel(tabfour.cherchef(m));
}

void gestion_produit_fournisseur::on_rech_clicked()
{
    QString m=ui->recherche->text();
    ui->fournisseurtable->setModel(tabfour.cherchef(m));
}

void gestion_produit_fournisseur::on_pushButton_9_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");

     QString system_date = QDateTime::currentDateTime().toString("yyyy/MM/dd");
                 QString strStream;
                           QTextStream out(&strStream);
                           const int rowCount = ui->fournisseurtable->model()->rowCount();
                           const int columnCount = ui->fournisseurtable->model()->columnCount();

                           out <<  "<html>\n"
                           "<head>\n"

                                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                            <<  QString("<title %1 </title>\n").arg("strTitle")
                                            <<  "</head> \n"
                                            "<body bgcolor=#cc0000 link=#5000A0 >\n"

                                            "<align='right'> " << system_date << "</align>"

                                            "<center> <img src='C:/Users/ASUS/OneDrive/Desktop/cours/expl/gestion_produit_fournisseur/rs/logo.png'></img></br><H1>E-pastry</H1></br><H2> Fournisseur </H2 <hr> <table  border-collapse: collapse; cellspacing=0 cellpadding=2>\n";

                           // headers
                           out << "<thead><tr bgcolor=#f0f0f0 text-align: center;> <th>Numero</th>";
                           out<<"<cellspacing=10 cellpadding=3>";
                           for (int column = 0; column < columnCount; column++)
                               if (!ui->fournisseurtable->isColumnHidden(column))
                                   out << QString("<th>%1</th>").arg(ui->fournisseurtable->model()->headerData(column, Qt::Horizontal).toString());
                           out << "</tr></thead>\n";

                           // data table
                           for (int row = 0; row < rowCount; row++) {
                               out << "<tr text-align: center;> <td bkcolor=0 text-align: center;>" << row+1 <<"</td>";
                               for (int column = 0; column < columnCount; column++) {
                                   if (!ui->fournisseurtable->isColumnHidden(column)) {
                                       QString data = ui->fournisseurtable->model()->data(ui->fournisseurtable->model()->index(row, column)).toString().simplified();
                                       out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                   }
                               }
                               out << "</tr>\n";
                           }
                           out <<  "</table></br> </center>\n"
                                           "</body>\n"
                                            "</html>\n";
                                    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }


                                   QPrinter printer (QPrinter::PrinterResolution);
                                    printer.setOutputFormat(QPrinter::PdfFormat);
                                   printer.setPaperSize(QPrinter::A4);
                                  printer.setOutputFileName(fileName);

                                   QTextDocument doc;
                                    doc.setHtml(strStream);
                                    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                                    doc.print(&printer);
                                      ui->fournisseurtable->setModel(tabfour.afficherf());
}

void gestion_produit_fournisseur::on_pushButton_modf_clicked()
{
    QString matricule =ui->comboBox_mat->currentText();
    QString nom=ui->lineEdit_nf->text();
    int tel=ui->lineEdit_numf->text().toInt();
    QString adresse=ui->lineEdit_ad->text();
    QString email=ui->lineEdit_mail->text();
    int x=0;
    string str_tel = to_string(tel);
    string m = email.toStdString();
    if(matricule=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("la matricule est vide"), QMessageBox::Ok);
              x++;
    }
    else if(nom=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("le nom est vide"), QMessageBox::Ok);
              x++;
    }
    else if(adresse=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("l'adress est vide"), QMessageBox::Ok);
              x++;
    }
    else if(m.find("@gmail.com")== std:: string::npos)
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Email must end with @gmail.com"), QMessageBox::Ok);
              x++;
    }
    else if(str_tel.length()!=8)
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Phone number must be composed of 8 numbers"), QMessageBox::Ok);
              x++;
    }
    else if(x==0)
    {
        fournisseur f(matricule,nom,adresse,email,tel);
        bool t=f.modifierf(matricule);
        if(t)
        {
            QMessageBox::information(nullptr, QObject::tr("fournisseur ajouter"),
                              QObject::tr("base de données mise à jour"), QMessageBox::Ok);
            ui->lineEdit_nf->clear();
            ui->lineEdit_numf->clear();
            ui->lineEdit_ad->clear();
            ui->lineEdit_mail->clear();
            //ui->stackedWidget->setCurrentIndex(6);
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                    notifyIcon->show();
                    notifyIcon->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/My work/rs/logo.png"));
                    notifyIcon->setVisible("C:/Users/ASUS/OneDrive/Desktop/QT/My work/rs/logo.png");

                    notifyIcon->showMessage("GESTION fournisseur ","fournisseur ajoute",QSystemTrayIcon::Information,15000);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                        QObject::tr("Veuillez réessayer"), QMessageBox::Ok);
        }
    }

}

void gestion_produit_fournisseur::on_tableView_3_activated(const QModelIndex &index)
{
    QString val=ui->tableView_3->model()->data(index).toString();
    if(tabfour.supprimerf(val))
    {
        QMessageBox::information(nullptr, QObject::tr("produit supprimer"),
                          QObject::tr("base de données mise à jour"), QMessageBox::Ok);
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                notifyIcon->show();
                notifyIcon->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/My work/rs/logo.png"));
                notifyIcon->setVisible("C:/Users/ASUS/OneDrive/Desktop/QT/My work/rs/logo.png");

                notifyIcon->showMessage("GESTION produit ","produit supprimer",QSystemTrayIcon::Information,15000);
        //ui->stackedWidget->setCurrentIndex(1);
        ui->tableView_3->setModel(tabfour.afficherf());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Veuillez réessayer"), QMessageBox::Ok);
    }
   qDebug() << val ;

}

void gestion_produit_fournisseur::on_toolButton_6_clicked()
{
    stat_four =new stat_fournisseur(this);
       stat_four->show();
}

void gestion_produit_fournisseur::on_toolButton_9_clicked()
{
    QString link="https://accounts.google.com/signin/v2/identifier?service=mail&passive=true&rm=false&continue=https%3A%2F%2Fmail.google.com%2Fmail%2F&ss=1&scc=1&ltmpl=default&ltmplcache=2&emr=1&osid=1&flowName=GlifWebSignIn&flowEntry=ServiceLogin";
    QDesktopServices::openUrl(QUrl(link));
}

void gestion_produit_fournisseur::on_tableView_4_activated(const QModelIndex &index)
{
    int test=0;
    QString nom;
    int ref=ui->tableView_4->model()->data(index).toInt();
    QSqlQuery query;
    query.prepare("select STOCK,NOM from PRODUIT where REF = :ref  ");
     query.bindValue(":ref",ref);
    if(query.exec())
    {
        while(query.next())
        {

            test=query.value(0).toInt();
            nom=query.value(1).toString();

        }
    }
    if (test > 10 )
    {
        ard.write_to_arduino("stock s'uffisant");
        qDebug()<< test;
    }
    else
    {
        ard.write_to_arduino("non pas de stock");
        qDebug()<< test;
    }
}

void gestion_produit_fournisseur::on_comboBox_mat_currentIndexChanged(const QString &arg1)
{
    QString val=ui->comboBox_mat->currentText();
    QSqlQuery q;
    q.prepare("select * from FOURNISSEUR where matricule = '"+val+"'");
    if(q.exec())
    {
        while(q.next())
        {
            ui->lineEdit_nf->setText(q.value(1).toString());
            ui->lineEdit_numf->setText(q.value(4).toString());
            ui->lineEdit_ad->setText(q.value(2).toString());
            ui->lineEdit_mail->setText(q.value(3).toString());

        }
    }
}

void gestion_produit_fournisseur::on_idmodif_currentIndexChanged(const QString &arg1)
{
    QString val=ui->idmodif->currentText();
    QSqlQuery q;
    q.prepare("select * from produit where ref='"+val+"'");
    if(q.exec())
    {
        while(q.next())
        {
            ui->lineEdit_5->setText(q.value(1).toString());
            ui->lineEdit_6->setText(q.value(2).toString());
            ui->lineEdit_7->setText(q.value(3).toString());
            ui->comboBox_4->setCurrentText(q.value(4).toString());
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Veuillez réessayer"), QMessageBox::Ok);
    }
}
void gestion_produit_fournisseur::on_stop_clicked()
{
    Player->stop();
}

void gestion_produit_fournisseur::on_start_clicked()
{
    Player->setMedia(QUrl::fromLocalFile("C:/Users/ASUS/Music/Kalash - Mwaka Moon ft. Damso.mp3"));
    Player->play();
    qDebug() << Player->errorString();
}

void gestion_produit_fournisseur::on_horizontalSlider_sliderMoved(int position)
{
    Player->setVolume(position);
}

void gestion_produit_fournisseur::on_pushButton_5_clicked()
{
    openFile();
}

void gestion_produit_fournisseur::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");

     QString system_date = QDateTime::currentDateTime().toString("yyyy/MM/dd");
                 QString strStream;
                           QTextStream out(&strStream);
                           const int rowCount = ui->produit_2->model()->rowCount();
                           const int columnCount = ui->produit_2->model()->columnCount();

                           out <<  "<html>\n"
                           "<head>\n"

                                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                            <<  QString("<title %1 </title>\n").arg("strTitle")
                                            <<  "</head> \n"
                                            "<body bgcolor=#cc0000 link=#5000A0 >\n"

                                            "<align='right'> " << system_date << "</align>"

                                            "<center> <img src='C:/i/capture.png'></img></br><H1>E-pastry</H1></br><H2> Fournisseur </H2 <hr> <table  border-collapse: collapse; cellspacing=0 cellpadding=2>\n";

                           // headers
                           out << "<thead><tr bgcolor=#f0f0f0 text-align: center;> <th>Numero</th>";
                           out<<"<cellspacing=10 cellpadding=3>";
                           for (int column = 0; column < columnCount; column++)
                               if (!ui->produit_2->isColumnHidden(column))
                                   out << QString("<th>%1</th>").arg(ui->produit_2->model()->headerData(column, Qt::Horizontal).toString());
                           out << "</tr></thead>\n";

                           // data table
                           for (int row = 0; row < rowCount; row++) {
                               out << "<tr text-align: center;> <td bkcolor=0 text-align: center;>" << row+1 <<"</td>";
                               for (int column = 0; column < columnCount; column++) {
                                   if (!ui->produit_2->isColumnHidden(column)) {
                                       QString data = ui->produit_2->model()->data(ui->produit_2->model()->index(row, column)).toString().simplified();
                                       out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                   }
                               }
                               out << "</tr>\n";
                           }
                           out <<  "</table></br> </center>\n"
                                           "</body>\n"
                                            "</html>\n";
                                    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }


                                   QPrinter printer (QPrinter::PrinterResolution);
                                    printer.setOutputFormat(QPrinter::PdfFormat);
                                   printer.setPaperSize(QPrinter::A4);
                                  printer.setOutputFileName(fileName);

                                   QTextDocument doc;
                                    doc.setHtml(strStream);
                                    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                                    doc.print(&printer);
                                      ui->produit_2->setModel(tabproduit.afficherp());
}
