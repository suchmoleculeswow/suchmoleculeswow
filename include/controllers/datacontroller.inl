#ifndef DATACONTROLLER_INL
#define DATACONTROLLER_INL

#include <QtConcurrent/QtConcurrent>

#include <commands/command.h>
#include <models/datamodel.h>

namespace controllers {
///////////////////////////////////////////////////////////////////////////////
template <typename C>
void DataController::reduce_range(RangeCommand<C>, int first, int last) {
  auto worker = [=]() -> float {

    auto range_first = data_model_->cbegin() + first;
    auto range_last = data_model_->cbegin() + last;

    return std::accumulate(range_first, range_last,
                           RangeCommand<C>::init_value(),
                           RangeCommand<C>::invoke);
  };
  result_ = QtConcurrent::run(worker);
  result_watcher_.setFuture(result_);
}
}

#endif  // DATACONTROLLER_INL
