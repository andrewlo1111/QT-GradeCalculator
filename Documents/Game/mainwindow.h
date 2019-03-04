#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <vector>

class Unit
{
public:
    Unit():unit_type("Unit"),attack(1),defense(1),done(false){}
    void move();
    void defend();
    void attack_enemy(Unit other_unit);
protected:
    std::string unit_type;
    double attack;
    double defense;
private:
    bool done = false;

};

class Villager:Unit
{
public:
    Villager();
    void build();

};

class Warrior:Unit
{
public:
    Warrior();
};

class Archer:Unit
{
public:
    Archer();
};

class Knight:Unit
{
public:
    Knight();
};



class  Building
{
public:
    Building(): building_type("Building"), durability(2) {}
  protected:
    std::string building_type;
    int durability;

};

class Farm:Building
{
public:
    Farm();
};

class Mine:Building
{
public:
    Mine();
};

class TownCenter:Building
{
public:
    TownCenter();
};

class Player
{
public:
    Player();
    void create_unit(std::string unit_type); //might need to be a string intsead of unit
    int get_unit_list_size();
    std::vector<int>& get_unit_list();


private:
    int money;
    int food;
    int mine_count;
    int farm_count;
    std::vector<int> unit_list;

};




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
