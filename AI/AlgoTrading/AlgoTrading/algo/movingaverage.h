#ifndef MOVINGAVERAGE_H
#define MOVINGAVERAGE_H

#include <QList>
#include <QQueue>
#include <QDateTime>

class MovingAverage
{
public:
    MovingAverage();
    MovingAverage(int);

    void update(QDateTime, int);
    void update(QDateTime, int, int);

    void setWeights(int ...);

private:
    struct dataPoint {
        QDateTime time;
        int volume;
        int price;
    };

    QList<int> weights;

    QQueue<dataPoint> data;
};

#endif // MOVINGAVERAGE_H
