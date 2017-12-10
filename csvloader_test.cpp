#include "csvloader.h"
#include "datamodel.h"
#include "loaderfactory.h"

#include <fstream>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(CSVLoaderTestSuite)

///////////////////////////////////////////////////////////////////////////////
struct CSVCreatorValid {
  CSVCreatorValid() : path_{"numbers.csv"} {
    BOOST_TEST_MESSAGE("setup csv fixture");

    std::ofstream ofs(path_, std::ofstream::out);
    ofs << 1.0f << "," << 1.1 << std::endl;
    ofs << 2.0f << "," << 2.1 << std::endl;

    ofs.close();
  }

  ~CSVCreatorValid() { BOOST_TEST_MESSAGE("teardown csv fixture"); }

  const std::string path_;
};

///////////////////////////////////////////////////////////////////////////////
struct CSVCreatorInvalid {
  CSVCreatorInvalid() : path_{"invalid.csv"} {
    BOOST_TEST_MESSAGE("setup invalid csv fixture");

    std::ofstream ofs(path_, std::ofstream::out);
    ofs << "such"
        << "wow" << std::endl;

    ofs.close();
  }

  ~CSVCreatorInvalid() { BOOST_TEST_MESSAGE("teardown invalid csv fixture"); }

  const std::string path_;
};

///////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(PathDoesNotExistTest) {
  std::unique_ptr<DataLoader> loader =
      LoaderFactory::get_loader(LoaderFactory::Backend::CSV);
  std::unique_ptr<DataModel> data_model = loader->load("suchfile.wow");
  BOOST_CHECK_EQUAL(data_model->size(), 0);
}

///////////////////////////////////////////////////////////////////////////////
BOOST_FIXTURE_TEST_CASE(InvalidParseTest, CSVCreatorInvalid) {
  std::unique_ptr<DataLoader> loader =
      LoaderFactory::get_loader(LoaderFactory::Backend::CSV);
  BOOST_CHECK_THROW(loader->load(path_), std::invalid_argument);
}

///////////////////////////////////////////////////////////////////////////////
BOOST_FIXTURE_TEST_CASE(ValidParseTest, CSVCreatorValid) {
  std::unique_ptr<DataLoader> loader =
      LoaderFactory::get_loader(LoaderFactory::Backend::CSV);
  std::unique_ptr<DataModel> data_model = loader->load(path_);

  BOOST_CHECK_EQUAL(data_model->rows(), 2);
  BOOST_CHECK_EQUAL(data_model->cols(), 2);
  BOOST_CHECK_EQUAL(data_model->size(), 4);
}

BOOST_AUTO_TEST_SUITE_END()
