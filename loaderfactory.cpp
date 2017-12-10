#include "loaderfactory.h"

#include "csvloader.h"

///////////////////////////////////////////////////////////////////////////////
std::unique_ptr<DataLoader> LoaderFactory::get_loader(
    const LoaderFactory::Backend backend) {
  switch (backend) {
    case Backend::CSV:
      return std::make_unique<CSVLoader>();
      break;
    case Backend::XML:
    default:
      return nullptr;
  }
}
