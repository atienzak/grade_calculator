#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected slots:
    void calculateScore();


private slots:
    void on_courseMenu_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    int totalHomeworkScore;
    int midterm1Score;
    int midterm2Score;
    int finalScore;

    double finalGrade;


    void calculateGradeSchema1();
    void calculateGradeSchema2();
    void resetScores();
    void showGrade() const;

};


#endif // MAINWINDOW_H
