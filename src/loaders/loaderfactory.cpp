#include <loaders/loaderfactory.h>

#include <boost/log/trivial.hpp>

#include <loaders/dataloader.h>

#include "csvloader.h"

namespace loaders {
///////////////////////////////////////////////////////////////////////////////
std::unique_ptr<DataLoader> LoaderFactory::get_loader(
    const LoaderFactory::Backend backend) {
  switch (backend) {
    case Backend::CSV:
      return std::make_unique<CSVLoader>();
      break;
    case Backend::XML:
    default:
      BOOST_LOG_TRIVIAL(warning) << "Selected loader backend is not available.";
      return nullptr;
  }
}
}
