#include "mainwindow.h"
#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextStream cout(stdout);

    unsigned int answer = 0;
    do
    {
        int factArg = 0;
        int fact(1);
        factArg = QInputDialog::getInt(0, "Factorial Calculator", "Factorial of", 1);
        cout<<"User selected"<<factArg<<Qt::endl;

        unsigned int i = 2u;

        while(i < factArg)
        {
            fact = fact * i;
            ++i;
        }

        QString response = QString(" The factorial of %1 is %2. \n %3").arg(factArg).arg(fact).arg("Do you want to compute another one?");
        answer = QMessageBox::question(0, "Play Again", response, QMessageBox::Yes | QMessageBox::No);

    }while(answer == QMessageBox::Yes);

    return a.exec();
}
