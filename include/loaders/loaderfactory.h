#ifndef LOADERFACTORY_H
#define LOADERFACTORY_H

#include <memory>

/*!
    \class LoaderFactory
    \brief Provide support for creating multiple loaders.

    Currently only CSV is supported.
*/
namespace loaders {
class DataLoader;

class LoaderFactory {
 public:
  enum class Backend {
    CSV,
    XML,
  };

  static std::unique_ptr<DataLoader> get_loader(const Backend backend);
};
}

#endif  // LOADERFACTORY_H
