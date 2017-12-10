#include "dataloader.h"

#include <memory>

#include <boost/core/ignore_unused.hpp>

#include "datamodel.h"

///////////////////////////////////////////////////////////////////////////////
std::unique_ptr<DataModel> DataLoader::load(const std::string& path) {
  boost::ignore_unused(path);
  std::vector<float> dummy;
  return std::make_unique<DataModel>(std::move(dummy), 0.0f, 0.0f);
}

///////////////////////////////////////////////////////////////////////////////
DataLoader::~DataLoader() {}
