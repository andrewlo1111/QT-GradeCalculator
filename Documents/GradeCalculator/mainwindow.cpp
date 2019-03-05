#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), hw_scores(0),
    midterm1(0), midterm2(0), final(0),
    SchemaA(true),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

unsigned int MainWindow::get_num_hw()
{
    return hw_scores.size();
}


void MainWindow::updateScore()
{
    unsigned int num_of_hw = get_num_hw();
    int lowest_hw_score = hw_scores[0];
    for(unsigned int i=0;i<num_of_hw;i++)
    {
        if(hw_scores[i] < lowest_hw_score)
        {
            lowest_hw_score = hw_scores[i];
        }
    }

    double hw_total = 0;
    for(unsigned int i=0;i<num_of_hw;i++)
    {
        hw_total += hw_scores[i];
    }

    hw_total -= lowest_hw_score;    //dropping lowest score
    double max_hw_total = 20 * num_of_hw;
    double hw_grade = (hw_total / max_hw_total) * 100;
    double final_score;
    if(SchemaA == true)
    {
        final_score = .25 * hw_grade + .2* (midterm1 + midterm2) + .35 * final;
        QString text("Final Grade: " + QString::number(final_score) + "%");
        ui->final_grade->setText(text);
    }
    else
    {
        double higher_midterm = static_cast<double>(midterm1);
        if(midterm1< midterm2)
        {
            higher_midterm = static_cast<double>(midterm2);
        }
        final_score = .25 * hw_grade + .3 * higher_midterm + .45 * final;
        QString text("Final Grade: " + QString::number(final_score) + "%");
        ui->final_grade->setText(text);
    }



}

void MainWindow::updateHW1(int new_value)
{
    hw_scores[0] = new_value;
    updateScore();
}

void MainWindow::updateHW2(int new_value)
{
    hw_scores[1] = new_value;
    updateScore();
}

void MainWindow::updateHW3(int new_value)
{
    hw_scores[2] = new_value;
    updateScore();
}

void MainWindow::updateHW4(int new_value)
{
    hw_scores[3] = new_value;
    updateScore();
}

void MainWindow::updateHW5(int new_value)
{
    hw_scores[4] = new_value;
    updateScore();
}

void MainWindow::updateHW6(int new_value)
{
    hw_scores[5] = new_value;
    updateScore();
}

void MainWindow::updateHW7(int new_value)
{
    hw_scores[6] = new_value;
    updateScore();
}

void MainWindow::updateHW8(int new_value)
{
    hw_scores[7] = new_value;
    updateScore();
}


void MainWindow::selectSchemaA()
{
    SchemaA = true;
    updateScore();
}

void MainWindow::selectSchemaB()
{
    SchemaA= false;
    updateScore();
}

MainWindow::~MainWindow()
{
    delete ui;
}
