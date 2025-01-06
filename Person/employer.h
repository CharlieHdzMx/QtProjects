#ifndef EMPLOYER_H
#define EMPLOYER_H

#include <QString>

class Person;
class Position;

class Employer
{
public:
    Employer();
    Employer (QString name, QString market);
    bool hire(Person& person, const Position& pos);
    QString toString()const;
private:
    QString m_Name;
    QString m_Market;
};

#endif // EMPLOYER_H
