#include "csvloader.h"

#include <istream>
#include <vector>

#include <boost/filesystem.hpp>
#include <boost/log/trivial.hpp>
#include <boost/tokenizer.hpp>

#include "datamodel.h"

///////////////////////////////////////////////////////////////////////////////
typedef boost::tokenizer<boost::escaped_list_separator<char>> Tokenizer;
bool parse_csv(const boost::filesystem::path& path,
               std::vector<float>& raw_values, uint32_t& rows, uint32_t& cols) {
  std::ifstream in(path.string());
  if (!in.is_open()) {
    return false;
  }

  std::string line;
  while (getline(in, line)) {
    Tokenizer tokens(line);
    std::transform(tokens.begin(), tokens.end(), std::back_inserter(raw_values),
                   [](const std::string& s) -> float { return std::stof(s); });

    rows++;
    cols = std::distance(tokens.begin(), tokens.end());
  }

  return true;
}

///////////////////////////////////////////////////////////////////////////////
std::unique_ptr<DataModel> CSVLoader::load(const std::string& path) {
  std::vector<float> raw_values;
  uint32_t rows = 0;
  uint32_t cols = 0;

  boost::filesystem::path p(path);

  if (!boost::filesystem::exists(p)) {
    BOOST_LOG_TRIVIAL(error) << "Path does not exist.";
    return std::make_unique<DataModel>(std::move(raw_values), rows, cols);
  }

  if (!parse_csv(path, raw_values, rows, cols)) {
    BOOST_LOG_TRIVIAL(error) << "Could not parse CSV file.";
    return std::make_unique<DataModel>(std::move(raw_values), rows, cols);
  }

  return std::make_unique<DataModel>(std::move(raw_values), rows, cols);
}

///////////////////////////////////////////////////////////////////////////////
CSVLoader::~CSVLoader() {}
