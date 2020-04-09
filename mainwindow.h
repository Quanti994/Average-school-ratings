#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ratingform.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include "averageratings.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QVector<RatingForm*>ratingForms;
    QVBoxLayout *boxLayout;
    AverageRatings *wAverage;
    QString message;
    bool errorFlag;
    void showMessage(QString text);
    void checkValueLineText();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void layoutRefresh(QVector<RatingForm*>&forms);

private slots:
    void on_quantityBox_valueChanged(int arg1);
    void on_averageButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
