#ifndef CSVLOADER_H
#define CSVLOADER_H

#include <memory>

#include <loaders/dataloader.h>

namespace models {
class DataModel;
}

/*!
    \class CSVLoader
    \brief Concrete implementation of the DataLoader interface.

    Provides functionality for loading data from a CSV file.

    \warning Does not support CSV headers.
*/
namespace loaders {
class CSVLoader : public DataLoader {
 public:
  CSVLoader() = default;

  std::unique_ptr<models::DataModel> load(const std::string& path);
  ~CSVLoader();
};
}

#endif  // CSVLOADER_H
