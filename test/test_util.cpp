#include "yacx/Options.hpp"
#include "yacx/util.hpp"

#include <catch2/catch.hpp>
#include <string>
#include <vector>

using yacx::type_of, yacx::load;

// TEST_CASE("Vectors can be comma seperated",
//          "[yacx::to_comma_seperated]") {
//  std::vector<std::string> string_vec{"andre", "hasan", "jona", "felix"};
//  std::vector<int> int_vec{1, 2, 3, 4, 5};
//  std::vector<int> empty_vec;
//
//  REQUIRE(to_comma_separated(string_vec.begin(), string_vec.end()) ==
//          "andre, hasan, jona, felix");
//  string_vec.pop_back();
//  REQUIRE(to_comma_separated(string_vec.begin(), string_vec.end()) ==
//          "andre, hasan, jona");
//  REQUIRE(to_comma_separated(int_vec.begin(), int_vec.end()) ==
//          "1, 2, 3, 4, 5");
//  REQUIRE(to_comma_separated(empty_vec.begin(), empty_vec.end()) == "");
//}

TEST_CASE("Displays the type of a variable", "[yacx::type_of]") {
  std::vector<int> vec;
  unsigned long long llui;
  yacx::Options options;

  #if defined(__clang__)
  #elif defined(__GNUC__) || defined(__GNUG__)
  REQUIRE(type_of(vec) == "std::vector<int, std::allocator<int> >");
  REQUIRE(type_of(options) == "yacx::Options");
  REQUIRE(type_of(llui) == "unsigned long long");
  #elif defined(_MSC_VER)
  REQUIRE(type_of(vec) == "class std::vector<int,class std::allocator<int> >");
  REQUIRE(type_of(options) == "class yacx::Options");
  REQUIRE(type_of(llui) == "unsigned __int64");
  #endif
  
  
}

TEST_CASE("load file to std::string", "[yacx::load]") {
  std::string kernel{
      "extern \"C\" __global__\n"
      "void saxpy(float a, float *x, float *y, float *out, size_t n) {\n"
      "  size_t tid = blockIdx.x * blockDim.x + threadIdx.x;\n"
      "  if (tid < n) {\n"
      "    out[tid] = a * x[tid] + y[tid];\n"
      "  }\n"
      "}\n"};

  REQUIRE(load("examples/kernels/saxpy.cu") == kernel);
}
