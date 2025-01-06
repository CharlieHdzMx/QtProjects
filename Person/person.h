#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include "position.h"
#include "employer.h"

class Person
{
public:
    Person();
    Person(QString name);
    QString toString()const;
    Position getPosition() const;
    void setPosition(const Position &newPosition);

    Employer getEmployer() const;
    void setEmployer(const Employer &newEmployer);

    bool IsEmployed() const;
    void setIsEmployed(bool newIsEmployed);

private:
    QString m_Name;
    bool m_IsEmployed;
    Position m_Position;
    Employer m_Employer;
};

#endif // PERSON_H
