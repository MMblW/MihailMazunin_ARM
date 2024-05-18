#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QMainWindow>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class MainClass; }
QT_END_NAMESPACE

class MainClass : public QMainWindow
{
    Q_OBJECT

public:
    MainClass(QWidget *parent = nullptr);
    ~MainClass();
public slots:
    void SetRawColor();
    void GetRGBColor(QColor);
    void SetRGBColor(QColor);
    void DoMathsColor(int R, int G, int B);
    void CountIngridients(double CleanR, double CleanG, double CleanB, int Accuracy);
    void SetCountLabels(int Ing1, int Ing2, int Ing3, int Ing4, int Ing5, int Ing6);
private:
    Ui::MainClass *ui;
    QGraphicsScene* UpdateLeftRectangle(QColor color);
    QGraphicsScene* UpdateRightRectangle(QColor color);
    QGraphicsScene* UpdateBottomRectangle(QColor color);
};
#endif // MAINCLASS_H
