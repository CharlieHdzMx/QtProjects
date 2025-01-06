#include "employer.h"
#include "person.h"
#include "position.h"

Employer::Employer(): m_Name("Empty"), m_Market("Empty")
{
    /* No inicialization.*/
}

Employer::Employer(QString name, QString market): m_Name(name), m_Market(market)
{
    /* No inicialization.*/
}

bool Employer::hire(Person &person, const Position &pos)
{
    person.setPosition(pos);
    person.setEmployer(*this);
    person.setIsEmployed(true);
    return true;
}

QString Employer::toString() const
{
    return QString(" Employer Name: %1, Market Name %2").arg(m_Name).arg(m_Market);
}
