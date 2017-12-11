#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <commands/add.h>
#include <controllers/datacontroller.h>

namespace gui {
///////////////////////////////////////////////////////////////////////////////
MainWindow::MainWindow(controllers::DataController& data_controller,
                       QWidget* parent)
    : QMainWindow{parent},
      ui{new Ui::MainWindow},
      data_controller_{data_controller} {
  ui->setupUi(this);
  setup_connections();
  setup_sliders();
}

///////////////////////////////////////////////////////////////////////////////
MainWindow::~MainWindow() { delete ui; }

///////////////////////////////////////////////////////////////////////////////
void MainWindow::on_lowerBoundSlider_changed(int value) {
  ui->lowerBoundCurVal->setText(QString::number(value));

  update_lower_bound_range(value, data_controller_.size());
}

///////////////////////////////////////////////////////////////////////////////
void MainWindow::on_upperBoundSlider_changed(int value) {
  ui->upperBoundCurVal->setText(QString::number(value));

  data_controller_.reduce_range(
      controllers::DataController::RangeCommand<commands::Add>(),
      ui->lowerBoundSlider->value(), value);
}

///////////////////////////////////////////////////////////////////////////////
void MainWindow::on_result_available(float result) {
  ui->resultValueLabel->setText(QString::number(result));
}

///////////////////////////////////////////////////////////////////////////////
void MainWindow::setup_connections() {
  connect(ui->lowerBoundSlider, &QSlider::valueChanged, this,
          &MainWindow::on_lowerBoundSlider_changed);
  connect(ui->upperBoundSlider, &QSlider::valueChanged, this,
          &MainWindow::on_upperBoundSlider_changed);
  connect(&data_controller_, &controllers::DataController::result_available,
          this, &MainWindow::on_result_available);
}

///////////////////////////////////////////////////////////////////////////////
void MainWindow::setup_sliders() {
  ui->lowerBoundMaxVal->setText(QString::number(data_controller_.size()));
  ui->lowerBoundSlider->setMaximum(data_controller_.size());

  ui->upperBoundMaxVal->setText(QString::number(data_controller_.size()));
  ui->upperBoundSlider->setMaximum(data_controller_.size());
}

///////////////////////////////////////////////////////////////////////////////
void MainWindow::update_lower_bound_range(int first, int last) {
  ui->upperBoundSlider->setRange(first, last);
  ui->upperBoundMinVal->setText(QString::number(first));
}
}
