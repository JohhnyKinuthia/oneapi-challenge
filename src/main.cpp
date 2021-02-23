//==============================================================
// Copyright © 2020, Intel Corporation. All rights reserved.
//
// SPDX-License-Identifier: MIT
// =============================================================

// located in $ONEAPI_ROOT/compiler/latest/linux/include/sycl/
#include <iostream>
#include <cmath>
#include <vector>
#include "Coordinate.h"
# define PI           3.14159265358979323846 /* pi */
# define EARTH_RADIUS_M 6371.8e3

using namespace cl::sycl;

//forward declaration
float haversineDistance(Coordinate& p1, Coordinate& p2);
float degToRad(float degrees); //convert degrees to radians

int main() {
  // create GPU device selector
  gpu_selector device_selector;
  //Coordinate of our traffic light
  Coordinate traffic_light{-1.3001967522200055, 36.77425089144588}; //Ngong Rd, Nairobi

  //Get data from connected mobile devices(to be added later)
  //Sample data for now
  std::vector<Coordinate> coordinates;
  Coordinate p1{0, 0}, p2{0, 0};
  Coordinate p3{51.5, 0}, p4{38.8, -77.1};
  std::cout << haversineDistance(p1, p2) << endl;
  std::cout << haversineDistance(p3, p4)/1000<< endl;
  std::cout << PI << '\n';
  // create a buffer
  constexpr int num = 16;
  auto R = range<1>{ num };
  buffer<int> A{ R };

  // create a kernel
  class ExampleKernel;
  queue q{device_selector };
  q.submit([&](handler& h) {
    auto out = A.get_access<access::mode::write>(h);
    h.parallel_for<ExampleKernel>(R, [=](id<1> idx) { out[idx] = idx[0]; });
  });

  // consume result
  auto result = A.get_access<access::mode::read>();
  for (int index = 0; index < num; ++index) {
    std::cout << result[index] << "\n";
  }

  return (EXIT_SUCCESS);
}

float haversineDistance(Coordinate& p1, Coordinate& p2)
//Returns the approximate distance between two points using haversine algorithm
{
        float lat_diff = degToRad(p2.latitude() - p1.latitude());
        float long_diff = degToRad(p2.longitude() - p1.longitude());
        double lat1 = degToRad(p1.latitude());
        double lat2 = degToRad(p2.latitude());

        float a = sin(lat_diff/2) * sin(lat_diff/2) +
                sin(long_diff/2) * sin(long_diff/2) * cos(lat1) * cos(lat2);
        float c = 2 * atan2(sqrt(a), sqrt(1-a));
        return EARTH_RADIUS_M * c;
}


float degToRad(float degrees)
{
        return degrees * PI / 180;
}

