#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->averageText->clear();
    errorFlag = false;
    wAverage = new AverageRatings();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_quantityBox_valueChanged(int arg1)
{
    if(arg1==0) ui->averageButton->setEnabled(false); else ui->averageButton->setEnabled(true);

    layoutRefresh(ratingForms);
    boxLayout = ui->mainLayout;

    for(int i=0;i<arg1;i++)
    {
        auto w = new RatingForm(this);
        ratingForms.push_back(w);
        boxLayout->addWidget(ratingForms[i]);
    }

    wAverage->setQuantityRatings(arg1);
}

void MainWindow::layoutRefresh(QVector<RatingForm *> &forms)
{
    boxLayout = ui->mainLayout;

    for(int i=0;i<forms.size();i++)
    {
       boxLayout->removeWidget(forms[i]) ;
       delete forms[i];
    }

    forms.clear();
}

void MainWindow::on_averageButton_clicked()
{
    checkValueLineText();

    if(errorFlag==false)
    {

        wAverage->setRatings(ratingForms);
        ui->averageText->setText(QString::number(wAverage->calculateAverage()));
        ui->quantityBox->setValue(0);
    }
}

void MainWindow::showMessage(QString text)
{
    QMessageBox errBox;
    errBox.setText(text);
    errBox.exec();
}

void MainWindow::checkValueLineText()
{
    for(int i=0;i<ratingForms.size();i++)
    {
        if(!ratingForms[i]->checkState())
        {
            showMessage("Nie wprowadzono wszystkich ocen!");
            errorFlag = true;
            break;
        } else errorFlag = false;
    }
}
