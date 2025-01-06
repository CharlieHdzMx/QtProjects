#ifndef DATE_H
#define DATE_H

class QString;

const static unsigned int baseYear = 1900u;

class Date
{
private:
    unsigned int m_DaysSinceBaseDate;
    static unsigned int ymd2dsbd(unsigned int d, unsigned int m, unsigned int y);
    void getYMD(unsigned int& d, unsigned int& m, unsigned int& y);
public:
    Date();
    Date(unsigned int d, unsigned int m, unsigned int y);
    void setDate(unsigned int d, unsigned int m, unsigned int y);
    QString toString(bool brief)const;
    void setToToday();
    QString getWeekDay()const;
    bool lessThan(const Date& rhs);
    bool equals(const Date& rhs);
    unsigned int daysBetween(const Date& rhs);
    void addDays(unsigned int days);
    static bool leapYear(unsigned int y);
    static QString monthName(unsigned int m);
    static unsigned int yearsDays(unsigned int y);
    unsigned int DaysSinceBaseDate() const;
};

#endif // DATE_H
