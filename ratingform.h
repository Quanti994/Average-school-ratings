#ifndef RATINGFORM_H
#define RATINGFORM_H

#include <QWidget>

namespace Ui {
class RatingForm;
}

class RatingForm : public QWidget
{
    Q_OBJECT

public:
    explicit RatingForm(QWidget *parent = nullptr);
    ~RatingForm();

private:
    Ui::RatingForm *ui;
};

#endif // RATINGFORM_H
