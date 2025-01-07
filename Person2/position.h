#ifndef POSITION_H
#define POSITION_H

#include <QString>

class Employer;

class Position
{
    friend class Employer;
public:
    QString toString()const;
    Position();
    Position(QString name, QString description);
private:
    QString m_Name;
    QString m_Description;
};

#endif // POSITION_H
