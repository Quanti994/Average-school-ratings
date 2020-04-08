#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->averageText->clear();
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

    average.setQuantity(arg1);
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
