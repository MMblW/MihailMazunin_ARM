#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QMainWindow>

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
    void SetNewColor(QColor);
private:
    Ui::MainClass *ui;
};
#endif // MAINCLASS_H
