#ifndef AVERAGERATINGS_H
#define AVERAGERATINGS_H
#include <QMainWindow>
#include <stack>
#include <vector>
#include "ratingform.h"

class AverageRatings
{
    int quantityRatings;
    std::stack<double>ratings;

public:
    AverageRatings(): quantityRatings(0){};
    inline void setQuantityRatings(int a){quantityRatings=a;}
    void setRatings(QVector<RatingForm*>forms);
    double calculateAverage();
};

#endif // AVERAGERATINGS_H
