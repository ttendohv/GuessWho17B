#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPushButton;
class QGroupBox;
class QTextBrowser;
class QStackedWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private slots:
    void genderButtonClicked();
    void eyeColorButtonClicked();
    void hairButtonClicked();
    void facialHairButtonClicked();
    void headwearButtonClicked();
    void aboutButtonClicked();
    void startButtonClicked();
    void howToPlayButtonClicked();
    void backToMainMenu();
    //void characterButtonClicked();

private:
    void createCharGroupBox();
    void createQuestionGroupBox();
    void createMiscGroupBox();
    void createYourCharGroupBox();
    void createActions();
    void createMenu();
    void createStatusBar();
    void createGameWidget();
    void createMainMenuWidget();

    enum {NumGridRows = 4, NumGridCols = 6};

    QGroupBox *charGroupBox;
    QGroupBox *questionGroupBox;
    QGroupBox *miscGroupBox;
    QGroupBox *yourCharGroupBox;
    QPushButton *characters[NumGridRows][NumGridCols];
    QPushButton *yourCharacter;
    QAction *exitAct;
    QAction *aboutAct;
    QAction *returnAct;
    QMenu *gameMenu;
    QMenu *aboutMenu;
    QTextBrowser *replyBox;
    QStackedWidget *stack;
    QWidget *mainMenuWidget;
    QWidget *gameWidget;
};
#endif // MAINWINDOW_H
