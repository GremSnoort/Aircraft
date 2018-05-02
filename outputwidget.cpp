#include "outputwidget.h"

OutputWidget::OutputWidget(QWidget *parent)
    : QWidget(parent)
    , l_UP_North_South(new QLabel("North-South UP: -", this))
    , l_UP_East_West(new QLabel("East-West UP: -", this))
    , l_UPr(new QLabel("UP result: -", this))

    , l_fall_time(new QLabel("Fall time: -", this))

    , l_DOWN_North_South(new QLabel("North-South DOWN: -", this))
    , l_DOWN_East_West(new QLabel("East-West DOWN: -", this))
    , l_DOWNr(new QLabel("DOWN result: -", this))

    , l_Integral(new QLabel("Integral: - ", this))
    , l_WIND_North_South(new QLabel("North-South WIND: -", this))
    , l_WIND_East_West(new QLabel("East-West WIND: -", this))

    , l_FINAL_North_South(new QLabel("North-South FINAL: -", this))
    , l_FINAL_East_West(new QLabel("East-West FINAL: -", this))
    , l_ANSWER_value(new QLabel("ANSWER: -", this))
    , l_ANSWER_destination(new QLabel("In Destination: -", this))
{
    CreateLayout();
}

void OutputWidget::SetOutput(d_out out)
{
    l_UP_North_South.data()->setText(QString(tr("North-South UP: %1").arg(out.up_north_south)));
    l_UP_East_West.data()->setText(QString(tr("East-West UP: %1").arg(out.up_east_west)));
    l_UPr.data()->setText(QString(tr("UP result: %1").arg(out.up_res)));

    l_fall_time.data()->setText(QString(tr("Fall time: %1").arg(out.fall_time)));

    l_DOWN_North_South.data()->setText(QString(tr("North-South DOWN: %1").arg(out.down_north_south)));
    l_DOWN_East_West.data()->setText(QString(tr("East-West DOWN: %1").arg(out.down_east_west)));
    l_DOWNr.data()->setText(QString(tr("DOWN result: %1").arg(out.down_res)));

    l_Integral.data()->setText(QString(tr("Integral: %1").arg(out.integral)));
    l_WIND_North_South.data()->setText(QString(tr("North-South WIND: %1").arg(out.wind_north_south)));
    l_WIND_East_West.data()->setText(QString(tr("East-West WIND: %1").arg(out.wind_east_west)));

    l_FINAL_North_South.data()->setText(QString(tr("North-South FINAL: %1").arg(out.final_north_south)));
    l_FINAL_East_West.data()->setText(QString(tr("East-West FINAL: %1").arg(out.final_east_west)));

    l_ANSWER_value.data()->setText(QString(tr("ANSWER: %1").arg(out.value)));
    l_ANSWER_destination.data()->setText(QString(tr("In Destination: %1 grad").arg(out.destination)));
}

void OutputWidget::CreateLayout()
{
    QGridLayout* layout = new QGridLayout(this);
    QWidget* spacer = new QWidget;
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layout->addWidget(l_UP_North_South.data(), 0, 0);
    layout->addWidget(l_UP_East_West.data(), 1, 0);
    layout->addWidget(l_UPr.data(), 2, 0);

    layout->addWidget(l_DOWN_North_South.data(), 0, 1);
    layout->addWidget(l_DOWN_East_West.data(), 1, 1);
    layout->addWidget(l_DOWNr.data(), 2, 1);

    layout->addWidget(new QWidget(), 3, 0);
    layout->addWidget(new QWidget(), 3, 1);

    layout->addWidget(l_WIND_North_South.data(), 4, 0);
    layout->addWidget(l_WIND_East_West.data(), 5, 0);
    layout->addWidget(l_Integral.data(), 6, 0);

    layout->addWidget(l_fall_time.data(), 4, 1);
    layout->addWidget(l_FINAL_North_South.data(), 5, 1);
    layout->addWidget(l_FINAL_East_West.data(), 6, 1);

    layout->addWidget(new QWidget(), 7, 0);
    layout->addWidget(new QWidget(), 7, 1);

    layout->addWidget(l_ANSWER_value.data(), 9, 0);
    layout->addWidget(l_ANSWER_destination.data(), 10, 0);

    l_ANSWER_value.data()->setStyleSheet("color : red; font: 75 14pt;");
    l_ANSWER_destination.data()->setStyleSheet("color : red; font: 75 14pt;");

    QLabel *imagelabel = new QLabel(this);
    imagelabel->setPixmap(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/kompass.jpeg"));

    layout->addWidget(imagelabel, 8, 1, 10, 1);
    layout->setRowMinimumHeight(8, 500);
    layout->setRowMinimumHeight(9, 500);
    layout->setRowMinimumHeight(10, 500);

    layout->addWidget(spacer);

    setLayout(layout);
}
