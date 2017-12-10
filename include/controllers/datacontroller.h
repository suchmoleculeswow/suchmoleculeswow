#ifndef DATACONTROLLER_H
#define DATACONTROLLER_H

#include <memory>

#include <QFuture>
#include <QFutureWatcher>
#include <QObject>

#include <commands/command.h>

namespace models {
class DataModel;
}

namespace controllers {
/*!
    \class DataController
    \brief Provides an interface to handle async operations on the data model.

    It makes use of Qt's QtConcurrent library to execute commands
   asynchronously.
    Since no callbacks are provided you need to use Qt's slots functionality to
   connect
    to the provided results_available signal.

    \todo Currently there's a hack implemented to slow down the emitting signal.
    Ideally a decorator would be provided for the method or the class.
*/
class DataController : public QObject {
  Q_OBJECT
 public:
  DataController(std::unique_ptr<models::DataModel> data_model,
                 QObject* parent = 0);

  template <typename Command>
  void reduce_range(int first, int last);

  size_t size() const;

  ~DataController();

 signals:
  /// This signal is delayed by sleep_milliseconds.
  /// A better way to do it would have been to wrap this object in a decorator.
  void result_available(float result);

 private:
  void setup_connections();
  void on_watcher_result_ready();

  std::unique_ptr<models::DataModel> data_model_;

  QFutureWatcher<void> result_watcher_;
  QFuture<float> result_;
  const int sleep_milliseconds_;
};
}

#include "datacontroller.inl"

#endif  // DATACONTROLLER_H
