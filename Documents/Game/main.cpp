#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QComboBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow display_window;



    QLabel *food_disp = new QLabel("Food: 100");
    QLabel *money_disp = new QLabel("Money: 100");
    QLabel *farm_disp = new QLabel("Farm Count: 0");
    QLabel *mine_disp = new QLabel("Mine Count: 0");
    QComboBox *unit_list = new QComboBox;

    unit_list->addItem("hello");
    unit_list->addItem("bye");

    QVBoxLayout *layout = new QVBoxLayout;
    layout ->addWidget(food_disp);
    layout->addWidget(money_disp);
    layout->addWidget(farm_disp);
    layout->addWidget(mine_disp);
    layout->addWidget(unit_list);


    QWidget *player_window = new QWidget;
    player_window->setWindowTitle("PlayerWindow");
    player_window->setLayout(layout);
    player_window->setGeometry(200,200,200,200);


    display_window.show();
    player_window->show();

    return a.exec();
}
