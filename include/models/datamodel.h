#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <cstddef>
#include <cstdint>
#include <iosfwd>
#include <vector>

#include <boost/noncopyable.hpp>

/*!
    \class DataModel
    \brief Provides an unified data representation througout the app.

    It currently models only 2D-float data.

    \todo ideally replaced with something like eigen, or at least the underlying
   data type should be a template
*/
namespace models {
class DataModel : public boost::noncopyable {
 public:
  typedef std::vector<float>::const_iterator DataCIt;

  DataModel(const std::vector<float>& raw_data, const uint32_t rows,
            const uint32_t cols);
  DataModel(const std::vector<float>&& raw_data, const uint32_t rows,
            const uint32_t cols);

  uint32_t rows() const;
  uint32_t cols() const;
  size_t size() const;

  float at(const uint32_t row, const uint32_t col) const;

  DataCIt cbegin() const;
  DataCIt cend() const;

  friend std::ostream& operator<<(std::ostream& os,
                                  const DataModel& data_model);

 private:
  const std::vector<float> raw_data_;
  const uint32_t rows_;
  const uint32_t cols_;
};
}

#endif  // DATAMODEL_H
