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
//        qDebug() << RawColor.HexArgb;
//        QTextStream stream(&SaveFile);
//        stream << "Hfplfdfnhb";
//        SaveFile.close();
//    }
    SetRGBColor(RawColor);
}

void MainClass::SetRGBColor(QColor RawColor)
{
    QRgb rgb = RawColor.rgb();
    int R = qRed(rgb);
    int G = qGreen(rgb);
    int B = qBlue(rgb);
    if (R < 255 && G < 255 && B < 255)
    {
        QColor NewColor;
        NewColor = DoMathsColor(R, G, B);
    }
    else
    {
        qDebug() << "Выбранный цвет не нуждается в реставрации!";
    }
}

void MainClass::DoMathsColor(int R, int G, int B)
{
    int mx = R;
    if (G > mx) { mx = G; }
    if (B > mx) { mx = B; }
    double TempCol = mx;
    double koef = 255 / TempCol;
    TempCol = R * koef;
    int NewR = TempCol;
    TempCol = G * koef;
    int NewG = TempCol;
    TempCol = B * koef;
    int NewB = TempCol;
    qDebug() << NewR << " " << NewG << " " << NewB << " - Читай сюда";
}

MainClass::~MainClass()
{
    delete ui;
}

