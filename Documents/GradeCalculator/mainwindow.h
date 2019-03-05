#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSlider>
#include <QSpinBox>
#include <QLabel>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateHW1(int);
    void updateHW2(int);
    void updateHW3(int);
    void updateHW4(int);
    void updateHW5(int);
    void updateHW6(int);
    void updateHW7(int);
    void updateHW8(int);
    void updateHW9(int);
    void selectSchemaA();
    void selectSchemaB();
    void updateClass(int);

private:
    std::vector<int> hw_scores;
    int midterm1;
    int midterm2;
    int final;
    bool SchemaA;
    QSlider* extra_slider;
    QSpinBox* extra_spin;
    QLabel* extra_label;
    Ui::MainWindow *ui;

    //private functions
    void updateScore();
    unsigned int get_num_hw();
};

#endif // MAINWINDOW_H
