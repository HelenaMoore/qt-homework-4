#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->gBox_buttons->setTitle("Выберите роль:");

    ui->rBtn_doctor->setText("врач");
    ui->rBtn_intern->setText("практикант");
    ui->rBtn_student->setText("студент");

    ui->lb_theme->setText("Выберите тему исследования:");

    ui->cBox_theme->addItems({"Групповой психоанализ", "Гештальт-терапия", "Когнитивно-поведенческая терапия",
                              "Терапия тревожных расстройств", "Трансактный анализ"});

    ui->pBtn_add->setText("Добавить участника");
    ui->pBtn_add->setCheckable(true);

    ui->lb_status->setText("Группа собрана:");

    ui->pBar_level->setMinimum(0);
    ui->pBar_level->setMaximum(10);
    ui->pBar_level->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pBtn_add_toggled(bool checked)
{
    if (!checked)
    {
        ui->pBtn_add->setText("Добавить участника");
    }
    else
    {
        ui->pBtn_add->setText("Участник добавлен");
    }
}

void MainWindow::on_pBtn_add_clicked()
{ 
    int pbar_value = ui->pBar_level->value();
    int pbar_max = ui->pBar_level->maximum();

    if (pbar_value < pbar_max)
    {
        ui->pBar_level->setValue(pbar_value + (pbar_max/10));
    }
    else
    {
         ui->pBar_level->setValue(0);
    }
}
