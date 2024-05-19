#include "getweight.h"
#include "ui_getweight.h"

#include <QDebug>

GetWeight::GetWeight(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetWeight)
{
    ui->setupUi(this);
}

GetWeight::~GetWeight()
{
    delete ui;
}

void GetWeight::on_btnWeight_clicked()
{
   QString res = ui->inputWeight->toPlainText();
   weight = res.toInt();
   if (weight == 0) weight = 1;
   if (weight < 0) weight = abs(weight);
   accept();
}

