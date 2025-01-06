#include "mainwindow.h"
#include <QApplication>
#include <QTextStream>
#include <QString>

#include "person.h"
#include "position.h"
#include "employer.h"

QTextStream cout(stdout);

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Person person1("Frank");
    Person person2("Anne");

    cout<<person1.toString()<<Qt::endl;
    cout<<person2.toString()<<Qt::endl;

    Employer employer1("Amex","Banks");
    Position pos1("Manager","Manager activities");

    employer1.hire(person1,pos1);

    cout<<person1.toString()<<Qt::endl;
    cout<<person2.toString()<<Qt::endl;

    // MainWindow w;
    // w.show();
    return a.exec();
}
