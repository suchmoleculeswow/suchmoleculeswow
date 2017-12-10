#ifndef LOADERFACTORY_H
#define LOADERFACTORY_H

#include <memory>

class DataLoader;

/*!
    \class LoaderFactory
    \brief Provide support for creating multiple loaders.

    Currently only CSV is supported.
*/
class LoaderFactory {
 public:
  enum class Backend {
    CSV,
    XML,
  };

  static std::unique_ptr<DataLoader> get_loader(const Backend backend);
};

#endif  // LOADERFACTORY_H
