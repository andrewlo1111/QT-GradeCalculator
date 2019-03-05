#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), hw_scores(0),
    midterm1(0), midterm2(0), final(0),
    SchemaA(true),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(int i=0;i<8;i++)
    {
        hw_scores.push_back(0);
    }

    QObject::connect(ui->HW1Spin, SIGNAL(valueChanged(int)), this, SLOT(updateHW1(int)));
    QObject::connect(ui->HW2Spin, SIGNAL(valueChanged(int)), this, SLOT(updateHW2(int)));
    QObject::connect(ui->HW3Spin, SIGNAL(valueChanged(int)), this, SLOT(updateHW3(int)));
    QObject::connect(ui->HW4Spin, SIGNAL(valueChanged(int)), this, SLOT(updateHW4(int)));
    QObject::connect(ui->HW5Spin, SIGNAL(valueChanged(int)), this, SLOT(updateHW5(int)));
    QObject::connect(ui->HW6Spin, SIGNAL(valueChanged(int)), this, SLOT(updateHW6(int)));
    QObject::connect(ui->HW7Spin, SIGNAL(valueChanged(int)), this, SLOT(updateHW7(int)));
    QObject::connect(ui->HW8Spin, SIGNAL(valueChanged(int)), this, SLOT(updateHW8(int)));

}

unsigned int MainWindow::get_num_hw()
{
    return hw_scores.size();
}


void MainWindow::updateScore()
{

    unsigned int num_of_hw = get_num_hw();
    int lowest_hw_score = hw_scores[0];
    for(unsigned int i=1;i<num_of_hw;i++)
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
    double max_hw_total = 20 * (num_of_hw - 1);
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


void MainWindow::updateClass(int selected_class)
{
    if(selected_class == 1)
    {
        QSlider *HW9Slider = new QSlider;
        QSpinBox *HW9SpinBox = new QSpinBox;
        QLabel *HW9Label = new QLabel("HW9");

        hw_scores.push_back(0);
        extra_slider = HW9Slider;
        extra_spin = HW9SpinBox;
        extra_label = HW9Label;

        HW9Slider->setMaximum(20);
        HW9SpinBox->setMaximum(20);

        QObject::connect(HW9Slider, SIGNAL(valueChanged(int)), HW9SpinBox, SLOT(setValue(int)));
        QObject::connect(HW9SpinBox, SIGNAL(valueChanged(int)), HW9Slider, SLOT(setValue(int)));
        QObject::connect(HW9Slider, SIGNAL(valueChanged(int)), this, SLOT(updateHW9(int)));
    }

    if(selected_class == 0 && hw_scores.size() > 8)
    {
        hw_scores.pop_back();
        extra_slider->close();
        extra_spin->close();
        extra_label->close();
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

void MainWindow::updateHW9(int new_value)
{
    hw_scores[8] = new_value;
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
