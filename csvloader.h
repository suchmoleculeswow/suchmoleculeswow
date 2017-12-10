#ifndef CSVLOADER_H
#define CSVLOADER_H

#include "dataloader.h"

/*!
    \class CSVLoader
    \brief Concrete implementation of the DataLoader interface.

    Provides functionality for loading data from a CSV file.

    \warning Does not support CSV headers.
*/
class CSVLoader : public DataLoader {
 public:
  CSVLoader() = default;

  std::unique_ptr<DataModel> load(const std::string& path);
  ~CSVLoader();
};

#endif  // CSVLOADER_H
