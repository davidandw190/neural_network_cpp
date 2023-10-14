//
// Created by davidandw190 on 10/14/23.
//
#pragma once

#ifndef NEURAL_NETWORK_CPP_GLOBALCONSTANTS_H
#define NEURAL_NETWORK_CPP_GLOBALCONSTANTS_H

#include <chrono>

constexpr unsigned short SCREEN_HEIGHT = 512;
constexpr unsigned short SCREEN_WIDTH = 512;
constexpr unsigned char SCREEN_RESIZE = 1;

constexpr std::chrono::microseconds FRAME_DURATION(16667);

constexpr unsigned char NEURON_SHAPE_RADIUS = 32;

#endif //NEURAL_NETWORK_CPP_GLOBALCONSTANTS_H
