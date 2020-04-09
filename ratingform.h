#ifndef RATINGFORM_H
#define RATINGFORM_H
#include <QWidget>

namespace Ui {
class RatingForm;
}

class RatingForm : public QWidget
{
    Q_OBJECT
    Ui::RatingForm *ui;
    bool stateLineEdit;
public:
    explicit RatingForm(QWidget *parent = nullptr);
    ~RatingForm();
    bool checkState();
    double getValueLineText();
private slots:
    void on_lineEdit_editingFinished();
};

#endif // RATINGFORM_H
