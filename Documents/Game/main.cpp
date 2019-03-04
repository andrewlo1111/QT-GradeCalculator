#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QComboBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow display_window;



    QLabel *food_disp1 = new QLabel("Food: 100");
    QLabel *money_disp1 = new QLabel("Money: 100");
    QLabel *farm_disp1 = new QLabel("Farm Count: 0");
    QLabel *mine_disp1 = new QLabel("Mine Count: 0");
    QComboBox *unit_list1 = new QComboBox;

    QLabel *food_disp2 = new QLabel("Food: 100");
    QLabel *money_disp2 = new QLabel("Money: 100");
    QLabel *farm_disp2 = new QLabel("Farm Count: 0");
    QLabel *mine_disp2 = new QLabel("Mine Count: 0");
    QComboBox *unit_list2 = new QComboBox;

    unit_list1->addItem("hello");
    unit_list1->addItem("bye");

    QVBoxLayout *layout1 = new QVBoxLayout;
    layout1 ->addWidget(food_disp1);
    layout1->addWidget(money_disp1);
    layout1->addWidget(farm_disp1);
    layout1->addWidget(mine_disp1);
    layout1->addWidget(unit_list1);

    QVBoxLayout *layout2 = new QVBoxLayout;
    layout2 ->addWidget(food_disp2);
    layout2->addWidget(money_disp2);
    layout2->addWidget(farm_disp2);
    layout2->addWidget(mine_disp2);
    layout2->addWidget(unit_list2);

    QWidget *player_window1 = new QWidget;
    player_window1->setWindowTitle("Player1 Window");
    player_window1->setLayout(layout1);
    player_window1->setGeometry(200,200,200,200);

    QWidget *player_window2 = new QWidget;
    player_window2->setWindowTitle("Player2 Window");
    player_window2->setLayout(layout2);
    player_window2->setGeometry(200,200,200,200);

    display_window.show();
    player_window1->show();
    player_window2->show();

    return a.exec();
}
