#ifndef EMPLOYER_H
#define EMPLOYER_H

#include <QString>
#include <QVector>

class Person;
class Position;

class Employer
{
public:
    Employer();
    Employer (QString name, QString market);
    bool hire(Person& person, const Position& pos);
    QString toString()const;
    void createPosition(QString name, QString description);
private:
    QString m_Name;
    QString m_Market;
    QVector<Position> m_positions;
    QVector<Person*> m_personsEmployed;
};

#endif // EMPLOYER_H
