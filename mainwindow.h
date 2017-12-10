#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

 public slots:
  void on_lowerBoundSlider_changed(int value);
  void on_upperBoundSlider_changed(int value);

 private:
  void setup_connections();
  void update_lower_bound_range(int first, int last);

  Ui::MainWindow *ui;
};

#endif  // MAINWINDOW_H
