#include "outputwidget.h"

OutputWidget::OutputWidget(QWidget *parent)
    : QWidget(parent)
    , l_UP_North_South(new QLabel("North-South UP: -", this))
    , l_UP_East_West(new QLabel("East-West UP: -", this))
    , l_fall_time(new QLabel("Fall time: -", this))
    , l_DOWN_North_South(new QLabel("North-South DOWN: -", this))
    , l_DOWN_East_West(new QLabel("East-West DOWN: -", this))
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

void OutputWidget::CreateLayout()
{
    QGridLayout* layout = new QGridLayout(this);
    QWidget* spacer = new QWidget;
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layout->addWidget(l_UP_North_South.data(), 0, 0);
    layout->addWidget(l_DOWN_North_South.data(), 1, 0);
    layout->addWidget(l_WIND_North_South.data(), 2, 0);

    layout->addWidget(l_UP_East_West.data(), 0, 1);
    layout->addWidget(l_DOWN_East_West.data(), 1, 1);
    layout->addWidget(l_WIND_East_West.data(), 2, 1);
    layout->addWidget(new QWidget(), 3, 0);
    layout->addWidget(new QWidget(), 3, 1);

    layout->addWidget(l_fall_time.data(), 4, 0);
    layout->addWidget(l_Integral.data(), 4, 1);
    layout->addWidget(new QWidget(), 5, 0);
    layout->addWidget(new QWidget(), 5, 1);

    layout->addWidget(l_FINAL_North_South.data(), 6, 0);
    layout->addWidget(l_FINAL_East_West.data(), 6, 1);
    layout->addWidget(new QWidget(), 7, 0);
    layout->addWidget(new QWidget(), 7, 1);

    layout->addWidget(l_ANSWER_value.data(), 8, 0);
    layout->addWidget(l_ANSWER_destination.data(), 9, 0);
    l_ANSWER_value.data()->setStyleSheet("color : red; font: 75 14pt;");
    l_ANSWER_destination.data()->setStyleSheet("color : red; font: 75 14pt;");

    layout->addWidget(spacer);

    setLayout(layout);
}
