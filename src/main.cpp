//==============================================================
// Copyright © 2020, Intel Corporation. All rights reserved.
//
// SPDX-License-Identifier: MIT
// =============================================================

// located in $ONEAPI_ROOT/compiler/latest/linux/include/sycl/
#include <iostream>
#include <cmath>
#include <array>
#include <random>
#include "Coordinate.h"
# define PI           3.14159265358979323846 /* pi */
# define EARTH_RADIUS_M 6371.8e3

using namespace cl::sycl;

constexpr int N = 200; //sample number of vehicles on the road
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
  std::array<Coordinate, N> host_coordinates;
  default_random_engine generator;
  //random coordinate generator within Nairobi
  uniform_real_distribution<float> lat_distribution(-1.3107271220657644, -1.2736576954765284);
  uniform_real_distribution<float> long_distribution(36.65426546691808, 36.99964813694435);
  for(int i = 0; i<N; ++i) {
  	host_coordinates = Coordinate{lat_distribution(generator), long_distribution(generator)};
  }
  // create a buffer
  auto R = range<1>{ N };
  buffer<Coordinate> A{ R };

  // create a kernel
  class ExampleKernel;
  queue q{device_selector };
  q.submit([&](handler& h) {
    auto out = A.get_access<access::mode::write>(h);
    h.parallel_for<ExampleKernel>(R, [=](id<1> idx) { 
		    out[idx] = idx[0]; 
    });
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
//Is this allowed inside a SYCL call?
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

