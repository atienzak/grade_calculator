#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    totalHomeworkScore(0),
    midterm1Score(0),
    midterm2Score(0),
    finalScore(0),
    finalGrade(0)

{
    ui->setupUi(this);
    setWindowTitle("Grade Calculator");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculateScore()
{
    resetScores(); // in case calculate button is pressed again and again

    totalHomeworkScore += ui->spin1->value();
    totalHomeworkScore += ui->spin2->value();
    totalHomeworkScore += ui->spin3->value();
    totalHomeworkScore += ui->spin4->value();
    totalHomeworkScore += ui->spin5->value();
    totalHomeworkScore += ui->spin6->value();
    totalHomeworkScore += ui->spin7->value();
    totalHomeworkScore += ui->spin8->value();
    totalHomeworkScore += ui->spin9->value();
    totalHomeworkScore += ui->spin10->value();

    midterm1Score = ui->spinm1->value();
    midterm2Score = ui->spinm2->value();
    finalScore = ui->spinf->value();

    if (ui->schema1button->isChecked())
    {
        calculateGradeSchema1();
    }
    else if (ui->schema2button->isChecked())
    {
        calculateGradeSchema2();
    }

    showGrade();


}

void MainWindow::calculateGradeSchema1()
{
    if ((ui->courseMenu->itemText(ui->courseMenu->currentIndex()) == "PIC 10C"))
    {
        finalGrade = ((totalHomeworkScore/10.0)*.25 + midterm1Score *.20 + midterm2Score *.20 + finalScore * .35);
    }
    else if ((ui->courseMenu->itemText(ui->courseMenu->currentIndex()) == "PIC 10A"))
    {
        finalGrade = ((totalHomeworkScore/10.0)*.10 + midterm1Score *.15 + midterm2Score *.15 + finalScore * .60);
    }
}

void MainWindow::calculateGradeSchema2()
{
 if ((ui->courseMenu->itemText(ui->courseMenu->currentIndex()) == "PIC 10C"))
 {
    if (midterm1Score >= midterm2Score)
        finalGrade = ((totalHomeworkScore/10)*.25 + midterm1Score *.30 + finalScore * .45);
    else
        finalGrade = ((totalHomeworkScore/10)*.25 + midterm2Score *.30 + finalScore * .45);
 }
 else if ((ui->courseMenu->itemText(ui->courseMenu->currentIndex()) == "PIC 10A"))
 {
        return; // only one schema for pic10A
 }
}

void MainWindow::resetScores()
{
    totalHomeworkScore = 0;
    midterm1Score = 0;
    midterm2Score = 0;
}

void MainWindow::showGrade() const
{
    if (finalGrade >= 97)
    {
        QString temp = QString::number(finalGrade) + " A+ ";
        ui->gradetotalshow->setText(temp);
    }

    else if (finalGrade >= 93)
    {
        QString temp = QString::number(finalGrade) + " A ";
        ui->gradetotalshow->setText(temp);
    }
    else if (finalGrade >= 90)
    {
        QString temp = QString::number(finalGrade) + " A- ";
        ui->gradetotalshow->setText(temp);
    }
    else if (finalGrade >= 87)
    {
        QString temp = QString::number(finalGrade) + " B+ ";
        ui->gradetotalshow->setText(temp);
    }
    else if (finalGrade >= 83)
    {
        QString temp = QString::number(finalGrade) + " B ";
        ui->gradetotalshow->setText(temp);
    }
    else if (finalGrade >= 80)
    {
        QString temp = QString::number(finalGrade) + " B- ";
        ui->gradetotalshow->setText(temp);
    }
    else if (finalGrade >= 77)
    {
        QString temp = QString::number(finalGrade) + " C+ ";
        ui->gradetotalshow->setText(temp);
    }

    else if (finalGrade >= 73)
    {
        QString temp = QString::number(finalGrade) + " C ";
        ui->gradetotalshow->setText(temp);
    }
    else if (finalGrade >= 70)
    {
        QString temp = QString::number(finalGrade) + " C- ";
        ui->gradetotalshow->setText(temp);
    }
    else if (finalGrade < 70)
    {
        QString temp = QString::number(finalGrade) + " Not Passing ";
        ui->gradetotalshow->setText(temp);
    }

}

void MainWindow::on_courseMenu_currentIndexChanged(const QString &arg1)
{
    //there is only one schema for the class PIC 10A
    if ((ui->courseMenu->itemText(ui->courseMenu->currentIndex()) == "PIC 10A"))
    {
        ui->labelschema1->setText("Schema: 10% HW + 15% M1 + 15% M2 + 60% F");
        ui->labelschema2->setText("");

        ui->schema2button->setEnabled(false);
        ui->schema1button->setChecked(true);
    }
    // go back to default settings with PIC 10C
    else if ((ui->courseMenu->itemText(ui->courseMenu->currentIndex()) == "PIC 10C"))
    {
        ui->labelschema1->setText("Schema 1: 25% HW + 20% M1 + 20% M2 + 35% F");
        ui->labelschema2->setText("Schema 2: 25% HW + 30% Highest M + 45% F");

        ui->schema1button->setChecked(false);
        ui->schema2button->setEnabled(true);
    }
    Q_UNUSED(arg1);
}
