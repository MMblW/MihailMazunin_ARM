#include <QFile>
#include <QTextStream>
#include <QColorDialog>
#include <QDebug>
#include "mainclass.h"
#include "ui_mainclass.h"

MainClass::MainClass(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainClass)
{
    ui->setupUi(this);
    connect(ui -> SetRawButton,
            &QPushButton::clicked,
            this,
            &MainClass::SetRawColor
            );
}

void MainClass::SetRawColor()
{
//    QString filename = "Save.txt";
//    QFile SaveFile(filename);
    QColor RawColor = QColorDialog::getColor();
//    if (SaveFile.open(QIODevice::WriteOnly | QIODevice::Text))
//    {
        qDebug() << RawColor.HexArgb;
//        QTextStream stream(&SaveFile);
//        stream << "Hfplfdfnhb";
//        SaveFile.close();
//    }
    SetNewColor(RawColor);
}

void MainClass::SetNewColor(QColor RawColor)
{

}

MainClass::~MainClass()
{
    delete ui;
}

