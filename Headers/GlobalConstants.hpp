//
// Created by davidandw190 on 10/14/23.
//
#pragma once

#ifndef NEURAL_NETWORK_CPP_GLOBALCONSTANTS_HPP
#define NEURAL_NETWORK_CPP_GLOBALCONSTANTS_HPP

#include <chrono>

constexpr unsigned short SCREEN_HEIGHT = 512;
constexpr unsigned short SCREEN_WIDTH = 512;
constexpr unsigned char SCREEN_RESIZE = 1;

constexpr unsigned short OUTPUTS_HEIGHT = 64;
constexpr unsigned short OUTPUTS_WIDTH = 64;

constexpr unsigned INPUT_NEURONS = 2;
constexpr unsigned OUTPUT_NEURONS = 3;

//The size of the array is the total number of hidden layers. Each element is the number of neurons in each layer.
constexpr std::array<unsigned, 2> HIDDEN_NEURONS = {3, 3};

constexpr std::array<unsigned, 1 + HIDDEN_NEURONS.size()> BIAS_NEURONS = {1, 0, 0};

constexpr unsigned char DECIMAL_DIGITS = 2;
constexpr unsigned char LINE_THICKNESS = 2;

constexpr std::chrono::microseconds FRAME_DURATION(16667);

constexpr unsigned char NEURON_SHAPE_RADIUS = 32;



typedef std::vector<float> vector_1d;
typedef std::vector<std::vector<float>> vector_2d;
typedef std::vector<std::vector<std::vector<float>>> vector_3d;

#endif //NEURAL_NETWORK_CPP_GLOBALCONSTANTS_HPP
