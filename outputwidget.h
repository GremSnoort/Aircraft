#ifndef OUTPUTWIDGET_H
#define OUTPUTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QScopedPointer>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>

class OutputWidget : public QWidget
{
    Q_OBJECT
public:
    explicit OutputWidget(QWidget *parent = nullptr);

    void CreateLayout();

    QScopedPointer<QLabel> l_UP_North_South;
    QScopedPointer<QLabel> l_UP_East_West;
    QScopedPointer<QLabel> l_fall_time;
    QScopedPointer<QLabel> l_DOWN_North_South;
    QScopedPointer<QLabel> l_DOWN_East_West;

    QScopedPointer<QLabel> l_Integral;
    QScopedPointer<QLabel> l_WIND_North_South;
    QScopedPointer<QLabel> l_WIND_East_West;

signals:

public slots:
};

#endif // OUTPUTWIDGET_H