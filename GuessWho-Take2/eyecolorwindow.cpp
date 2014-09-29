#include "eyecolorwindow.h"
#include <QtGui>

EyeColorWindow::EyeColorWindow(QWidget *parent)
    : QDialog(parent){
    // Sets up 3 questions about the eye color
    QRadioButton *question1 = new QRadioButton(tr("&Brown eyes?"));
    question1->setStyleSheet("QRadioButton{color: white}");

    QRadioButton *question2 = new QRadioButton(tr("B&lue eyes?"));
    question2->setStyleSheet("QRadioButton{color: white}");

    QRadioButton *question3 = new QRadioButton(tr("&Green eyes?"));
    question3->setStyleSheet("QRadioButton{color: white}");

    // Sets up the label / question being asked
    label = new QLabel(tr("Does the character have..."));
    label->setStyleSheet("QLabel{color: white}");

    // Creates a button box with Ok and Cancel buttons
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    // Creates the layout for the Eye Color window
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label, 2, Qt::AlignVCenter);
    layout->addWidget(question1, 1, Qt::AlignTop);
    layout->addWidget(question2, 1, Qt::AlignTop);
    layout->addWidget(question3, 1, Qt::AlignTop);
    layout->addWidget(buttonBox, 1, Qt::AlignBottom);
    setLayout(layout);

    setWindowTitle(tr("Eye Color Questions"));
    setFixedSize(400,200);
}

EyeColorWindow::~EyeColorWindow(){}

