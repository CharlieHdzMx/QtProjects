#ifndef POSITION_H
#define POSITION_H

#include <QString>

class Position
{
public:
    Position();
    Position(QString name, QString description);
    QString toString()const;
private:
    QString m_Name;
    QString m_Description;
};

#endif // POSITION_H
