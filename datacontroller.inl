#ifndef DATACONTROLLER_INL
#define DATACONTROLLER_INL

#include <QtConcurrent/QtConcurrent>

#include "datamodel.h"

///////////////////////////////////////////////////////////////////////////////
template <typename Func>
void DataController::reduce_range(int first, int last, float init, Func f) {
  auto worker = [=]() -> float {

    DataModel::DataCIt range_first = data_model_->cbegin() + first;
    DataModel::DataCIt range_last = data_model_->cbegin() + last;

    return std::accumulate(range_first, range_last, init, f);
  };
  result_ = QtConcurrent::run(worker);
  result_watcher_.setFuture(result_);
}

#endif  // DATACONTROLLER_INL
