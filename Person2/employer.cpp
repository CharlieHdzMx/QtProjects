#include "employer.h"
#include "person.h"
#include "position.h"

Employer::Employer(): m_Name("Empty"), m_Market("Empty"), m_positions(), m_personsEmployed()
{
    /* No inicialization.*/
}

Employer::Employer(QString name, QString market): m_Name(name), m_Market(market), m_positions(), m_personsEmployed()
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

void Employer::createPosition(QString name, QString description)
{
    Position pos(name,description);
    m_positions.append(pos);
}
