#include <QApplication>

#include <memory>

#include "datacontroller.h"
#include "dataloader.h"
#include "datamodel.h"
#include "loaderfactory.h"
#include "mainwindow.h"

#ifdef ENABLE_SUCH_WOW_TESTS
#include <boost/test/unit_test.hpp>

bool init_function() { return true; }
#endif

static const std::string DATA_PATH{"numbers.csv"};

int main(int argc, char *argv[]) {
#ifndef ENABLE_SUCH_WOW_TESTS

  std::unique_ptr<DataLoader> loader =
      LoaderFactory::get_loader(LoaderFactory::Backend::CSV);
  std::unique_ptr<DataModel> data_model = loader->load(DATA_PATH);
  DataController data_controller(std::move(data_model));

  QApplication a(argc, argv);
  MainWindow w(data_controller);
  w.show();

  return a.exec();
#else
  return ::boost::unit_test::unit_test_main(&init_function, argc, argv);
#endif
}
