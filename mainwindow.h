#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QtMath>

#include "inputwidget.h"
#include "outputwidget.h"
#include "integral.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void CreateLayout();

    QScopedPointer<InputWidget> input_;
    QScopedPointer<OutputWidget> output_;
    QScopedPointer<QPushButton> calculate_res;

    d_in in;
    d_out out;

public slots:
    void CalculateResult();

};

#endif // MAINWINDOW_H
