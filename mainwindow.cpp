#include "mainwindow.h"
#include "ui_mainwindow.h"

///////////////////////////////////////////////////////////////////////////////
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setup_connections();
}

///////////////////////////////////////////////////////////////////////////////
MainWindow::~MainWindow() { delete ui; }

///////////////////////////////////////////////////////////////////////////////
void MainWindow::on_lowerBoundSlider_changed(int value) {
  ui->lowerBoundCurVal->setText(QString::number(value));

  /// TODO: get max value from some data controller.
  update_lower_bound_range(value, 100);
}

///////////////////////////////////////////////////////////////////////////////
void MainWindow::on_upperBoundSlider_changed(int value) {
  ui->upperBoundCurVal->setText(QString::number(value));
}

///////////////////////////////////////////////////////////////////////////////
void MainWindow::setup_connections() {
  connect(ui->lowerBoundSlider, &QSlider::valueChanged, this,
          &MainWindow::on_lowerBoundSlider_changed);
  connect(ui->upperBoundSlider, &QSlider::valueChanged, this,
          &MainWindow::on_upperBoundSlider_changed);
}

///////////////////////////////////////////////////////////////////////////////
void MainWindow::update_lower_bound_range(int first, int last) {
  ui->upperBoundSlider->setRange(first, last);
  ui->upperBoundMinVal->setText(QString::number(first));
}
