#include <QApplication>

#include <memory>

#include <controllers/datacontroller.h>
#include <loaders/dataloader.h>
#include <loaders/loaderfactory.h>
#include <models/datamodel.h>

/// Hack, I don't want to put it in includes, and
/// I don't want to set the include path in sources.
/// Ideally I would have a lib project and a gui object, but it's not worth it.
#include "src/gui/mainwindow.h"

#ifdef ENABLE_SUCH_WOW_TESTS
#include <boost/test/unit_test.hpp>

bool init_function() { return true; }
#endif

static const std::string DATA_PATH{"numbers.csv"};

int main(int argc, char *argv[]) {
#ifndef ENABLE_SUCH_WOW_TESTS

  std::unique_ptr<loaders::DataLoader> loader =
      loaders::LoaderFactory::get_loader(loaders::LoaderFactory::Backend::CSV);
  std::unique_ptr<models::DataModel> data_model = loader->load(DATA_PATH);
  controllers::DataController data_controller(std::move(data_model));

  QApplication a(argc, argv);
  gui::MainWindow w(data_controller);
  w.show();

  return a.exec();
#else
  return ::boost::unit_test::unit_test_main(&init_function, argc, argv);
#endif
}
