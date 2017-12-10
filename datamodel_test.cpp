#include "datamodel.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(DataModelTestSuite)

///////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(EmptyDataTest) {
  std::vector<float> dummy;
  DataModel test_object(dummy, 0, 0);

  BOOST_CHECK_EQUAL(test_object.cols(), 0);
  BOOST_CHECK_EQUAL(test_object.rows(), 0);
  BOOST_CHECK_EQUAL(test_object.size(), 0);
}

///////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(OneRowTest) {
  std::vector<float> one_row(10);
  DataModel test_object(one_row, 1, 10);

  BOOST_CHECK_EQUAL(test_object.cols(), 10);
  BOOST_CHECK_EQUAL(test_object.rows(), 1);
  BOOST_CHECK_EQUAL(test_object.size(), 10);
}

///////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(OneColumnTest) {
  std::vector<float> one_col(10);
  DataModel test_object(one_col, 10, 1);

  BOOST_CHECK_EQUAL(test_object.cols(), 1);
  BOOST_CHECK_EQUAL(test_object.rows(), 10);
  BOOST_CHECK_EQUAL(test_object.size(), 10);
}

BOOST_AUTO_TEST_SUITE_END()
