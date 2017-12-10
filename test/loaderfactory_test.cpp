#include <loaders/dataloader.h>
#include <loaders/loaderfactory.h>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(LoaderFactoryTestSuite)

///////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(InvalidBackend) {
  std::unique_ptr<loaders::DataLoader> loader =
      loaders::LoaderFactory::get_loader(
          static_cast<loaders::LoaderFactory::Backend>(UINT8_MAX));
  BOOST_CHECK(!loader);
}

///////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(UnsupportedBackend) {
  std::unique_ptr<loaders::DataLoader> loader =
      loaders::LoaderFactory::get_loader(loaders::LoaderFactory::Backend::XML);
  BOOST_CHECK(!loader);
}

///////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(SupportedBackend) {
  std::unique_ptr<loaders::DataLoader> loader =
      loaders::LoaderFactory::get_loader(loaders::LoaderFactory::Backend::CSV);
  BOOST_CHECK(loader);
}

BOOST_AUTO_TEST_SUITE_END()
