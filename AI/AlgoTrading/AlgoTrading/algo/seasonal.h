#ifndef SEASONAL_H
#define SEASONAL_H

#include <QVector>
#include <QDateTime>

class Seasonal
{
public:
    Seasonal();

    /*
      Contructor for Seasonal class
      @param season the number of periods in a season
      */
    Seasonal(int season);

    /*
      Update the Season with a new datapoint
      @param timestamp timestamp of the data
      @param data can be either price or volume
      */
    void update(QDateTime timestamp, double data);

    /*
      Set the length of the season
      @param season number of periods in a season
      */
    void setSeason(int season);

    /*
      Get the seasonal indicies for an additive model
      @return QVector<double> of the same length as the season length
      */
    QVector<double> getAddIndicies();

    /*
      Get the seasonal indicies for an multiplicative model
      @return QVector<double> of the same length as the season length
      */
    QVector<double> getMultIndicies();

    /*
      Seed the seasonal indicies
      @param seed QVector<double> of period length
      */
    void seedIndicies(QVector<double> seed);

private:
    QVector<double> addIndicies;
    QVector<double> multiIndicies;
};

#endif // SEASONAL_H
