#include "genderwindow.h"
#include <QtGui>
#include <iostream>
using namespace std;

GenderWindow::GenderWindow(QWidget *parent)
    : QDialog(parent){
    // Sets up the label for the gender questions
    label = new QLabel(tr("Is the character..."));
    label->setStyleSheet("QLabel{color: white}");

    // Sets up 2 gender choices
    question1 = new QRadioButton(tr("&Male?"));
    question1->setStyleSheet("QRadioButton{color: white}");

    question2 = new QRadioButton(tr("&Female?"));
    question2->setStyleSheet("QRadioButton{color: white}");

    // Creates a button box with Ok and Cancel buttons
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(isAccepted()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    // Creates the layout for the Gender window
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label, 2, Qt::AlignVCenter);
    layout->addWidget(question1, 1, Qt::AlignTop);
    layout->addWidget(question2, 1, Qt::AlignTop);
    layout->addWidget(buttonBox, 1, Qt::AlignBottom);
    setLayout(layout);

    setWindowTitle(tr("Gender Questions"));
    setFixedSize(400,200);
}

GenderWindow::~GenderWindow(){}

void GenderWindow::isAccepted(){
    // Example for communication with the Game Manager class
    // Replace with variables once class is created
    if (question1->isChecked()){
        cout << "Male" << endl;
        close();
    }
    else if (question2->isChecked()){
        cout << "Female" << endl;
        close();
    }
    else
        close();
}

