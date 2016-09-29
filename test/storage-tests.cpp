#include "test.h"

#include <iostream>
#include <map>

#include "tensor.h"
#include "format.h"
#include "util.h"

#include "packed_tensor.h"

using namespace std;

TEST(storage, d) {
  Format format("d");

  Tensor<double, 1> vec1(format);
  ASSERT_EQ(1u, vec1.getOrder());
  vec1.insert({0}, 1.0);
  vec1.pack();

  Tensor<double, 5> vec5(format);
  vec5.insert({4}, 2.0);
  vec5.insert({1}, 1.0);
  vec5.pack();
  std::cout << vec5 << std::endl;

  auto vec5p = vec5.getPackedTensor();
  ASSERT_EQ(5u, vec5p->getNnz());

//  ASSERT_FLOAT_EQ(0.0, vec5(0));
//  ASSERT_FLOAT_EQ(1.0, vec5(1));
//  ASSERT_FLOAT_EQ(0.0, vec5(2));
//  ASSERT_FLOAT_EQ(0.0, vec5(3));
//  ASSERT_FLOAT_EQ(2.0, vec5(4));
}

TEST(storage, s) {
  Format format("s");

  std::map<int, double> vec1Vals;
  vec1Vals[0] = 1.0;

  Tensor<double, 1> vec1(format);
  ASSERT_EQ(1u, vec1.getOrder());
//  ASSERT_EQ(0, vec1.numNonZeroes());

  for (auto& val : vec1Vals) {
    vec1.insert({val.first}, val.second);
  }
  vec1.pack();
//  ASSERT_EQ(0, vec1.numNonZeroes());

//  for (auto& nonZero : vec1.nonZeroes()) {
//    ASSERT_FLOAT_EQ(vec1Vals[nonZero.getCoord()], vec1Vals[nonZero.getVal()]);
//  }


  std::map<int, double> vec5Vals;
  vec5Vals[1] = 1.0;
  vec5Vals[4] = 2.0;

//  Tensor<double> vec1(format, 5);
//  ASSERT_EQ(0, vec1.numNonZeroes());

//  for (auto& val : vec1Vals) {
//    std::cout << val.first << ": " << val.second << std::endl;
//    vec1(val.first) = val.second;
//  }
//  ASSERT_EQ(0, vec1.numNonZeroes());

//  for (auto& nonZero : vec1.nonZeroes()) {
//    ASSERT_FLOAT_EQ(vec1Vals[nonZero.getCoord()], vec1Vals[nonZero.getVal()]);
//  }
}