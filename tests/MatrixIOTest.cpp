#include "matrixIO.hpp"
#include <boost/test/unit_test.hpp>
#include <fstream>
#include <cstdio>

BOOST_AUTO_TEST_SUITE(MatrixIOTests)

BOOST_AUTO_TEST_CASE(TestOpenData) {
  const std::string filename = "test_matrix_temp.csv";
  const int size = 2;
  
  {
    std::ofstream outfile(filename);
    outfile << "1.0, 2.0\n";
    outfile << "3.0, 4.0\n";
  }

  Eigen::MatrixXd matrix = matrixIO::openData(filename, size);

  BOOST_TEST(matrix.rows() == size);
  BOOST_TEST(matrix.cols() == size);

  BOOST_TEST(matrix(0, 0) == 1.0);
  BOOST_TEST(matrix(0, 1) == 2.0);
  BOOST_TEST(matrix(1, 0) == 3.0);
  BOOST_TEST(matrix(1, 1) == 4.0);

  std::remove(filename.c_str());
}

BOOST_AUTO_TEST_SUITE_END()