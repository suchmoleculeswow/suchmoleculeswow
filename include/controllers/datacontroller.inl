#ifndef DATACONTROLLER_INL
#define DATACONTROLLER_INL

#include <QtConcurrent/QtConcurrent>

#include <models/datamodel.h>

namespace controllers {
///////////////////////////////////////////////////////////////////////////////
template <typename Command>
void DataController::reduce_range(int first, int last) {
  auto worker = [=]() -> float {

    models::DataModel::DataCIt range_first = data_model_->cbegin() + first;
    models::DataModel::DataCIt range_last = data_model_->cbegin() + last;

    return std::accumulate(range_first, range_last, Command::init_value(),
                           Command::invoke);
  };
  result_ = QtConcurrent::run(worker);
  result_watcher_.setFuture(result_);
}
}

#endif  // DATACONTROLLER_INL
