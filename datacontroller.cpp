#include "datacontroller.h"

#include <algorithm>

#include "datamodel.h"

///////////////////////////////////////////////////////////////////////////////
DataController::DataController(std::unique_ptr<DataModel> data_model,
                               QObject* parent)
    : QObject(parent),
      data_model_{std::move(data_model)},
      result_watcher_{},
      result_{} {}

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
  emit result_available(result_.result());
}
