#ifndef DATACONTROLLER_H
#define DATACONTROLLER_H

#include <memory>

#include <QFuture>
#include <QFutureWatcher>
#include <QObject>

class DataModel;

class DataController : public QObject {
  Q_OBJECT
 public:
  DataController(std::unique_ptr<DataModel> data_model, QObject* parent = 0);

  template <typename Func>
  void reduce_range(int first, int last, float init, Func f);

  size_t size() const;

  ~DataController();

 signals:
  void result_available(float result);

 private:
  void setup_connections();
  void on_watcher_result_ready();

  std::unique_ptr<DataModel> data_model_;

  QFutureWatcher<void> result_watcher_;
  QFuture<float> result_;
};

#include "datacontroller.inl"

#endif  // DATACONTROLLER_H
