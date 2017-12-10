#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class DataController;

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(DataController& data_controller, QWidget* parent = 0);
  ~MainWindow();

 public slots:
  void on_lowerBoundSlider_changed(int value);
  void on_upperBoundSlider_changed(int value);
  void on_result_available(float result);

 private:
  void setup_connections();
  void setup_sliders();
  void update_lower_bound_range(int first, int last);

  Ui::MainWindow* ui;
  DataController& data_controller_;
};

#endif  // MAINWINDOW_H
