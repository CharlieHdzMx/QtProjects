#include "person.h"

const QString NoEmployerString = "No employer yet";
const QString NoPositionString = "No Position yet";


Person::Person(): m_Name("No Person Name"), m_IsEmployed(false), m_Position(), m_Employer()
{
    /* No inicialization.*/
}

Person::Person(QString name): m_Name(name), m_IsEmployed(false), m_Position(), m_Employer()
{
    /* No inicialization.*/
}

QString Person::toString() const
{
    QString retVal = m_Name + QString((m_IsEmployed)?" Employed":" NotEmployed");
    if(m_IsEmployed)
    {
        retVal += m_Position.toString() + m_Employer.toString();
    }
    else
    {
        retVal += NoEmployerString + NoPositionString;
    }
    return retVal;
}

Position Person::getPosition() const
{
    return m_Position;
}

void Person::setPosition(const Position &newPosition)
{
    m_Position = newPosition;
}

Employer Person::getEmployer() const
{
    return m_Employer;
}

void Person::setEmployer(const Employer &newEmployer)
{
    m_Employer = newEmployer;
}

bool Person::IsEmployed() const
{
    return m_IsEmployed;
}

void Person::setIsEmployed(bool newIsEmployed)
{
    m_IsEmployed = newIsEmployed;
}
