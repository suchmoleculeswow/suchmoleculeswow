#include <QApplication>
#include "mainwindow.h"

#ifdef ENABLE_SUCH_WOW_TESTS
#include <boost/test/unit_test.hpp>

bool init_function() { return true; }
#endif

int main(int argc, char *argv[]) {
#ifndef ENABLE_SUCH_WOW_TESTS
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return a.exec();

  return 0;

#else
  return ::boost::unit_test::unit_test_main(&init_function, argc, argv);
#endif
}
