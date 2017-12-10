#include <controllers/datacontroller.h>

#include <chrono>
#include <thread>

#include <models/datamodel.h>

namespace controllers {
///////////////////////////////////////////////////////////////////////////////
DataController::DataController(std::unique_ptr<models::DataModel> data_model,
                               QObject* parent)
    : QObject(parent),
      data_model_{std::move(data_model)},
      result_watcher_{},
      result_{},
      sleep_milliseconds_(200) {
  setup_connections();
}

///////////////////////////////////////////////////////////////////////////////
size_t DataController::size() const { return data_model_->size(); }

///////////////////////////////////////////////////////////////////////////////
DataController::~DataController() {}

///////////////////////////////////////////////////////////////////////////////
void DataController::setup_connections() {
  QObject::connect(&result_watcher_, &QFutureWatcher<void>::finished, this,
                   &DataController::on_watcher_result_ready);
}

///////////////////////////////////////////////////////////////////////////////
void DataController::on_watcher_result_ready() {
  std::this_thread::sleep_for(std::chrono::milliseconds(sleep_milliseconds_));
  emit result_available(result_.result());
}
}
