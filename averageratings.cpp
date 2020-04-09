#include "averageratings.h"

double AverageRatings::calculateAverage()
{
    double result = 0;
    for(int i=0;i<quantityRatings;i++)
    {
        result += ratings.top();
        ratings.pop();
    }

    return result/quantityRatings;
}

void AverageRatings::setRatings(QVector<RatingForm*>forms)
{
    for(int i=0;i<quantityRatings;i++)
    {
        ratings.push(forms[i]->getValueLineText());
    }
}
