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
{
    CreateLayout();
}

void OutputWidget::CreateLayout()
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    QWidget* spacer = new QWidget;
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layout->addWidget(l_UP_North_South.data());
    layout->addWidget(l_DOWN_North_South.data());
    layout->addWidget(l_WIND_North_South.data());
    layout->addWidget(new QWidget());

    layout->addWidget(l_UP_East_West.data());
    layout->addWidget(l_DOWN_East_West.data());
    layout->addWidget(l_WIND_East_West.data());
    layout->addWidget(new QWidget());

    layout->addWidget(l_fall_time.data());    

    layout->addWidget(l_Integral.data());

    layout->addWidget(new QWidget());
    layout->addWidget(l_FINAL_North_South.data());
    layout->addWidget(l_FINAL_East_West.data());

    layout->addWidget(spacer);

    setLayout(layout);
}
