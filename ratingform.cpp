#include "ratingform.h"
#include "ui_ratingform.h"
#include <QValidator>

RatingForm::RatingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RatingForm)
{
    ui->setupUi(this);
    QRegExp rx("1|1,5|1,75|2|2,5|2,75|3|3,5|3,75|4|4,5|4,75|5|5,5|5,75|6");   //ustawienie dozwolonych znaków (tutaj tylko oceny zwykłe,+,-)
    QValidator *validator = new QRegExpValidator(rx,this);                    //utworzenie RegEx Validatora
    ui->lineEdit->setValidator(validator);                                    //przypisanie validatora do widgetu
    stateLineEdit = false;
}

RatingForm::~RatingForm()
{
    delete ui;
}

bool RatingForm::checkState()
{
    return stateLineEdit;
}
void RatingForm::on_lineEdit_editingFinished()
{
    if(ui->lineEdit->text()==NULL) stateLineEdit = false; else stateLineEdit = true;
}

double RatingForm::getValueLineText()
{
    double value = ui->lineEdit->text().toDouble();
    return value;
}
