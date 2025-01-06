#include "date.h"
#include <QString>
#include <QStringList>
#include <time.h>
#include <cmath>
#include <vector>

static const QStringList monthNames=
{
    "Jan","Feb","Mar","Apr","May","Jun","Jul","Ago","Sep","Oct","Dic"
};

static const std::vector<unsigned int> numDaysPerMonth =
{
    30u,28u,31u,30u,31u,30u,31u,30,31u,30u,30u,31u
};

static const QStringList weekNames=
{
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday",
};

const static unsigned int leapYearDays = 366u;
const static unsigned int normalYearsDays = 365u;

unsigned int Date::DaysSinceBaseDate() const
{
    return m_DaysSinceBaseDate;
}

unsigned int Date::ymd2dsbd(unsigned int d, unsigned int m, unsigned int y)
{
    unsigned int accumDays = 0u;

    /* Years*/
    for(unsigned int deltaY = baseYear ; deltaY <= y; deltaY++)
    {
        accumDays += yearsDays(deltaY);
    }
    /* Months*/
    for(unsigned int deltaM = 1u; deltaM <= m; deltaM++)
    {
        accumDays += numDaysPerMonth.at(deltaM - 1u);
    }
    /* Days*/
    accumDays += d;

    return accumDays;
}

void Date::getYMD(unsigned int &d, unsigned int &m, unsigned int &y)
{
    d = 0u;
    m = 0u;
    y = 0u;

    unsigned int remainingDays = m_DaysSinceBaseDate;
    unsigned int currentYearDays = 0u;
    unsigned int currentMonth = 0u;

    while (remainingDays > 0u)
    {
        /* How many days is in this year*/
        currentYearDays = yearsDays(baseYear);
        /* There are still days to sustract from the year,
         *  meaning we need to go to the next year*/
        if(remainingDays >= currentYearDays)
        {
            remainingDays -= currentYearDays;
            y++;
        }
        /* We cannot substract more days for a year, jump to months.*/
        else
        {
            /* Month increment*/
            while(remainingDays >= numDaysPerMonth.at(currentMonth + 1u))
            {
                remainingDays -= numDaysPerMonth.at(currentMonth + 1u);
                currentMonth++;
                m++;
            }

            /* We cannot substract more days for a month, jump to days.*/
            d = remainingDays + 1u;
            remainingDays = 0u;
        }
    }
}

Date::Date(): m_DaysSinceBaseDate(0u)
{

}

Date::Date(unsigned int d, unsigned int m, unsigned int y)
{
    m_DaysSinceBaseDate = ymd2dsbd(d,m,y);
}

void Date::setDate(unsigned int d, unsigned int m, unsigned int y)
{
    m_DaysSinceBaseDate = ymd2dsbd(d,m,y);
}

QString Date::toString(bool brief) const
{
    QString retVal;
    if(false != brief)
    {

    }
    else
    {

    }
    return retVal;
}

void Date::setToToday()
{
    struct tm* tp = nullptr;
    time_t now;
    now = time(0);
    tp = localtime(&now);
    setDate(tp->tm_mday, 1 + tp->tm_mon,  baseYear + tp->tm_year);
}

QString Date::getWeekDay() const
{
    const unsigned int weekdayNumber = (1 + m_DaysSinceBaseDate) % 7u ;
    return weekNames.at(weekdayNumber);
}

bool Date::lessThan(const Date &rhs)
{
    return (m_DaysSinceBaseDate < rhs.DaysSinceBaseDate());
}

bool Date::equals(const Date &rhs)
{
    return (m_DaysSinceBaseDate == rhs.DaysSinceBaseDate());
}

unsigned int Date::daysBetween(const Date &rhs)
{
    const int retVal = m_DaysSinceBaseDate - rhs.DaysSinceBaseDate();
    return abs(retVal);
}

void Date::addDays(unsigned int days)
{
    m_DaysSinceBaseDate += days;
}

bool Date::leapYear(unsigned int y)
{
    return (y % 4 == 0u && y % 100 != 0u)||(y % 400u == 0u);
}

QString Date::monthName(unsigned int m)
{
    return monthNames.at(m + 1);
}

unsigned int Date::yearsDays(unsigned int y)
{
    return (leapYear(y)) ? leapYearDays : normalYearsDays;
}
