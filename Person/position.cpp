#include "position.h"

Position::Position() {}

Position::Position(QString name, QString description): m_Name(name), m_Description(description)
{
    /* No inicialization.*/
}

QString Position::toString() const
{
    return QString("Position Name: %1, Position Description: %2").arg(m_Name).arg(m_Description);
}
