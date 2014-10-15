#include "hairwindow.h"
#include <QtGui>
#include <iostream>
using namespace std;

HairWindow::HairWindow(QWidget *parent)
    : QDialog(parent){
    // Creates the label for hair questions
    hairColorLabel = new QLabel(tr("Is your character's hair color..."));
    hairColorLabel->setStyleSheet("QLabel{color: white}");

    // Sets up choices for hair color
    question1 = new QRadioButton(tr("Blonde?"));
    question1->setStyleSheet("QRadioButton{color: white}");

    question2 = new QRadioButton(tr("Brown?"));
    question2->setStyleSheet("QRadioButton{color: white}");

    question3 = new QRadioButton(tr("Black?"));
    question3->setStyleSheet("QRadioButton{color: white}");

    question4 = new QRadioButton(tr("White/Gray?"));
    question4->setStyleSheet("QRadioButton{color: white}");

    // Creates a button box with Ok and Cancel buttons
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(isAccepted()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QVBoxLayout *hairColorLayout = new QVBoxLayout;
    hairColorLayout->addWidget(hairColorLabel, 2, Qt::AlignVCenter);
    hairColorLayout->addWidget(question1, 1, Qt::AlignTop);
    hairColorLayout->addWidget(question2, 1, Qt::AlignTop);
    hairColorLayout->addWidget(question3, 1, Qt::AlignTop);
    hairColorLayout->addWidget(question4, 1, Qt::AlignTop);
    hairColorLayout->addWidget(buttonBox, 1, Qt::AlignBottom);
    setLayout(hairColorLayout);

    setWindowTitle(tr("Hair Questions"));
    setFixedSize(400, 300);
}

HairWindow::~HairWindow(){}

void HairWindow::isAccepted(){
    // Example for communication with the Game Manager class
    // Replace with variables once class is created
    if (question1->isChecked()){
        cout << "Blonde hair" << endl;
        close();
    }
    else if (question2->isChecked()){
        cout << "Brown hair" << endl;
        close();
    }
    else if (question3->isChecked()){
        cout << "Black hair" << endl;
        close();
    }
    else if (question4->isChecked()){
        cout << "White/gray hair" << endl;
        close();
    }
    else
        close();
}
