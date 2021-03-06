#ifndef HOWTOWINDOW_H
#define HOWTOWINDOW_H

#include <QDialog>

class QLabel;
class QDialogButtonBox;

class HowToWindow : public QDialog
{
public:
    explicit HowToWindow(QWidget *parent = 0);
    ~HowToWindow();

private:
    QLabel *howToLabel;
    QLabel *howToText;
    QLabel *specificsLabel;
    QLabel *specificsText;
    QDialogButtonBox *buttonBox;
};
#endif // HOWTOWINDOW_H
