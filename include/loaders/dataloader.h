#ifndef DATALOADER_H
#define DATALOADER_H

#include <memory>

namespace models {
class DataModel;
}

/*!
    \class DataLoader
    \brief Abstract class, provides an interface for implementing loaders.
*/
namespace loaders {
class DataLoader {
 public:
  DataLoader() = default;

  virtual std::unique_ptr<models::DataModel> load(const std::string& path) = 0;
  virtual ~DataLoader() = 0;
};
}

#endif  // DATALOADER_H
