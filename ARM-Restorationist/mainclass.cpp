#include <QGraphicsScene>
#include <QColorDialog>
#include <QDebug>
#include <QString>
#include "mainclass.h"
#include "ui_mainclass.h"

MainClass::MainClass(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainClass)
{
    ui->setupUi(this);

    QGraphicsScene* scene = UpdateLeftRectangle(QColor(255, 255, 255));
    ui->graphicsView->setScene(scene);

    QGraphicsScene* scene_2 = UpdateRightRectangle(QColor(255, 255, 255));
    ui->graphicsView_2->setScene(scene_2);

    QGraphicsScene* scene_3 = UpdateBottomRectangle(QColor(255, 255, 255));
    ui->graphicsView_4->setScene(scene_3);

    connect(ui -> SetRawButton,
            &QPushButton::clicked,
            this,
            &MainClass::SetRawColor);
}

QGraphicsScene* MainClass::UpdateLeftRectangle(QColor color) {
    QGraphicsScene* new_Scene = new QGraphicsScene;
    QBrush brush(color);
    QPen pen(Qt::black);
    QGraphicsRectItem *Rect = new_Scene->addRect(-50, -50, 200, 200, pen, brush);
    return new_Scene;
}

QGraphicsScene* MainClass::UpdateRightRectangle(QColor color) {
    QGraphicsScene* new_Scene = new QGraphicsScene;
    QBrush brush(color);
    QPen pen(Qt::black);
    QGraphicsRectItem *Rect = new_Scene->addRect(-50, -50, 200, 200, pen, brush);
    return new_Scene;
}

QGraphicsScene* MainClass::UpdateBottomRectangle(QColor color) {
    QGraphicsScene* new_Scene = new QGraphicsScene;
    QBrush brush(color);
    QPen pen(Qt::black);
    QGraphicsRectItem *Rect = new_Scene->addRect(-50, -50, 200, 200, pen, brush);
    return new_Scene;
}

void MainClass::SetRawColor()
{
    QGraphicsScene *prev_scene = ui->graphicsView->scene();
    QColor RawColor = QColorDialog::getColor();
    QGraphicsScene *new_Scene = UpdateLeftRectangle(RawColor);
    ui->graphicsView->setScene(new_Scene);
    if(prev_scene) delete prev_scene;
    GetRGBColor(RawColor);
}

void MainClass::SetRGBColor(QColor color)
{
    QGraphicsScene *prev_scene = ui->graphicsView_2->scene();
    QGraphicsScene *new_Scene = UpdateRightRectangle(color);
    ui->graphicsView_2->setScene(new_Scene);
    if(prev_scene) delete prev_scene;
}

void MainClass::GetRGBColor(QColor RawColor)
{
    QRgb rgb = RawColor.rgb();
    int R = qRed(rgb);
    int G = qGreen(rgb);
    int B = qBlue(rgb);
    DoMathsColor(R, G, B);
}

void MainClass::CountIngridients(double CleanR, double CleanG, double CleanB, int Accuracy)
{
    const double Ing1[3] = {255, 0, 200};
    const double Ing2[3] = {0, 220, 255};
    const double Ing3[3] = {0, 255, 110};
    const double Ing4[3] = {255, 255, 0};
    const double Ing5[3] = {50, 50, 50};
    const double Ing6[3] = {240, 240, 240};
    double k = 0;
    double Ings[6] = {0, 0, 0, 0, 0, 0};
    double PrevCol[3] = {0, 0, 0};
    int TempIndex = 0;
    for (int i = 1; i <= Accuracy; i++)
    {
        k = abs(CleanR - (PrevCol[0] + Ing1[0]/i)) + abs(CleanG - (PrevCol[1] + Ing1[1]/i)) + abs(CleanB - (PrevCol[2] + Ing1[2]/i));
        TempIndex = 0;
        if (abs(CleanR - (PrevCol[0] + Ing2[0]/i)) + abs(CleanG - (PrevCol[1] + Ing2[1]/i)) + abs(CleanB - (PrevCol[2] + Ing2[2]/i)) < k)
        {
            k = abs(CleanR - (PrevCol[0] + Ing2[0]/i)) + abs(CleanG - (PrevCol[1] + Ing2[1]/i)) + abs(CleanB - (PrevCol[2] + Ing2[2]/i));
            TempIndex = 1;
        }
        if (abs(CleanR - (PrevCol[0] + Ing3[0]/i)) + abs(CleanG - (PrevCol[1] + Ing3[1]/i)) + abs(CleanB - (PrevCol[2] + Ing3[2]/i)) < k)
        {
            k = abs(CleanR - (PrevCol[0] + Ing3[0]/i)) + abs(CleanG - (PrevCol[1] + Ing3[1]/i)) + abs(CleanB - (PrevCol[2] + Ing3[2]/i));
            TempIndex = 2;
        }
        if (abs(CleanR - (PrevCol[0] + Ing4[0]/i)) + abs(CleanG - (PrevCol[1] + Ing4[1]/i)) + abs(CleanB - (PrevCol[2] + Ing4[2]/i)) < k)
        {
            k = abs(CleanR - (PrevCol[0] + Ing4[0]/i)) + abs(CleanG - (PrevCol[1] + Ing4[1]/i)) + abs(CleanB - (PrevCol[2] + Ing4[2]/i));
            TempIndex = 3;
        }
        if (abs(CleanR - (PrevCol[0] + Ing5[0]/i)) + abs(CleanG - (PrevCol[1] + Ing5[1]/i)) + abs(CleanB - (PrevCol[2] + Ing5[2]/i)) < k)
        {
            k = abs(CleanR - (PrevCol[0] + Ing5[0]/i)) + abs(CleanG - (PrevCol[1] + Ing5[1]/i)) + abs(CleanB - (PrevCol[2] + Ing5[2]/i));
            TempIndex = 4;
        }
        if (abs(CleanR - (PrevCol[0] + Ing6[0]/i)) + abs(CleanG - (PrevCol[1] + Ing6[1]/i)) + abs(CleanB - (PrevCol[2] + Ing6[2]/i)) < k)
        {
            TempIndex = 5;
        }
        Ings[TempIndex]++;
        PrevCol[0] = (Ings[0] * Ing1[0] + Ings[1] * Ing2[0] + Ings[2] * Ing3[0] + Ings[3] * Ing4[0] + Ings[4] * Ing5[0] + Ings[5] * Ing6[0])/(i+1);
        PrevCol[1] = (Ings[0] * Ing1[1] + Ings[1] * Ing2[1] + Ings[2] * Ing3[1] + Ings[3] * Ing4[1] + Ings[4] * Ing5[1] + Ings[5] * Ing6[1])/(i+1);
        PrevCol[2] = (Ings[0] * Ing1[2] + Ings[1] * Ing2[2] + Ings[2] * Ing3[2] + Ings[3] * Ing4[2] + Ings[4] * Ing5[2] + Ings[5] * Ing6[2])/(i+1);
        if (i == Accuracy)
        {
            PrevCol[0] = (Ings[0] * Ing1[0] + Ings[1] * Ing2[0] + Ings[2] * Ing3[0] + Ings[3] * Ing4[0] + Ings[4] * Ing5[0] + Ings[5] * Ing6[0])/i;
            PrevCol[1] = (Ings[0] * Ing1[1] + Ings[1] * Ing2[1] + Ings[2] * Ing3[1] + Ings[3] * Ing4[1] + Ings[4] * Ing5[1] + Ings[5] * Ing6[1])/i;
            PrevCol[2] = (Ings[0] * Ing1[2] + Ings[1] * Ing2[2] + Ings[2] * Ing3[2] + Ings[3] * Ing4[2] + Ings[4] * Ing5[2] + Ings[5] * Ing6[2])/i;
        }
    }
    SetCountLabels(Ings[0], Ings[1], Ings[2], Ings[3], Ings[4], Ings[5]);
    QColor color(PrevCol[0], PrevCol[1], PrevCol[2]);
    QGraphicsScene *prev_scene = ui->graphicsView_4->scene();
    QGraphicsScene *new_Scene = UpdateBottomRectangle(color);
    ui->graphicsView_4->setScene(new_Scene);
    if(prev_scene) delete prev_scene;
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
    QColor color(NewR, NewG, NewB);
    SetRGBColor(color);
    CountIngridients(NewR, NewG, NewB, ui->spinBox->value());
}

void MainClass::SetCountLabels(int Ing1, int Ing2, int Ing3, int Ing4, int Ing5, int Ing6)
{
    QString Str = " - " + QString::number(Ing1);
    ui->Ing1_Count->setText(Str);
    Str = " - " + QString::number(Ing2);
    ui->Ing2_Count->setText(Str);
    Str = " - " + QString::number(Ing3);
    ui->Ing3_Count->setText(Str);
    Str = " - " + QString::number(Ing4);
    ui->Ing4_Count->setText(Str);
    Str = " - " + QString::number(Ing5);
    ui->Ing5_Count->setText(Str);
    Str = " - " + QString::number(Ing6);
    ui->Ing6_Count->setText(Str);
}

MainClass::~MainClass()
{
    delete ui;
}

