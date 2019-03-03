#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow display_window;
    QWidget *player_window = new QWidget;
    player_window->setWindowTitle("PlayerWindow");
    display_window.show();
    player_window->show();

    return a.exec();
}
