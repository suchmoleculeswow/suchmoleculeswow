#include <models/datamodel.h>

#include <iostream>

namespace models {
///////////////////////////////////////////////////////////////////////////////
DataModel::DataModel(const std::vector<float>& raw_data, const uint32_t rows,
                     const uint32_t cols)
    : raw_data_{raw_data}, rows_{rows}, cols_{cols} {}

///////////////////////////////////////////////////////////////////////////////
DataModel::DataModel(const std::vector<float>&& raw_data, const uint32_t rows,
                     const uint32_t cols)
    : raw_data_{raw_data}, rows_{rows}, cols_{cols} {}

///////////////////////////////////////////////////////////////////////////////
uint32_t DataModel::rows() const { return rows_; }

///////////////////////////////////////////////////////////////////////////////
uint32_t DataModel::cols() const { return cols_; }

///////////////////////////////////////////////////////////////////////////////
size_t DataModel::size() const { return raw_data_.size(); }

///////////////////////////////////////////////////////////////////////////////
float DataModel::at(const uint32_t row, const uint32_t col) const {
  return raw_data_[row * cols_ + col];
}

///////////////////////////////////////////////////////////////////////////////
DataModel::DataCIt DataModel::cbegin() const { return raw_data_.cbegin(); }

///////////////////////////////////////////////////////////////////////////////
DataModel::DataCIt DataModel::cend() const { return raw_data_.cend(); }

///////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, const DataModel& data_model) {
  const uint32_t rows = data_model.rows();
  const uint32_t cols = data_model.cols();

  for (uint32_t i = 0; i < rows; i++) {
    for (uint32_t j = 0; j < cols; j++) {
      os << data_model.at(i, j) << " ";
    }
    os << std::endl;
  }

  return os;
}
}
