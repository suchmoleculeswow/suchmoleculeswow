#include <QApplication>

#include <memory>

#include <boost/filesystem.hpp>
#include <boost/log/trivial.hpp>

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

const std::string NUMBERS_PATH{"/data/numbers.csv"};

int main(int argc, char *argv[]) {
#ifndef ENABLE_SUCH_WOW_TESTS

  boost::filesystem::path p(DATA_PATH);
  p.append(NUMBERS_PATH);
  if (!boost::filesystem::exists(p)) {
    BOOST_LOG_TRIVIAL(fatal)
        << "numbers.csv is not in the current working dir.";
    return -1;
  }

  std::unique_ptr<loaders::DataLoader> loader =
      loaders::LoaderFactory::get_loader(loaders::LoaderFactory::Backend::CSV);
  std::unique_ptr<models::DataModel> data_model = loader->load(p.string());
  controllers::DataController data_controller(std::move(data_model));

  QApplication a(argc, argv);
  gui::MainWindow w(data_controller);
  w.show();

  return a.exec();
#else
  return ::boost::unit_test::unit_test_main(&init_function, argc, argv);
#endif
}
