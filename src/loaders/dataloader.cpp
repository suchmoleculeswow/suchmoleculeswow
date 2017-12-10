#include <loaders/dataloader.h>

#include <memory>

#include <boost/core/ignore_unused.hpp>

#include <models/datamodel.h>

namespace loaders {
///////////////////////////////////////////////////////////////////////////////
std::unique_ptr<models::DataModel> DataLoader::load(const std::string& path) {
  boost::ignore_unused(path);
  std::vector<float> dummy;
  return std::make_unique<models::DataModel>(std::move(dummy), 0.0f, 0.0f);
}

///////////////////////////////////////////////////////////////////////////////
DataLoader::~DataLoader() {}
}
