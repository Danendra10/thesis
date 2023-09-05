#ifndef MAIN_HPP_
#define MAIN_HPP_
#define YAML_CPP_STATIC_DEFINE

// #pragma once
#include "robot.hpp"
#include "vec_attr.hpp"
#include "vec_repl.hpp"
#include "yaml-cpp/yaml.h"
#include "opencv2/opencv.hpp"

#include <iostream>
#include <filesystem>
#include <fstream>

int max_attr_field_radius;
int max_repl_field_radius;

int potentialFieldInit();
int potentialFieldRoutine();
int LoadConfig();
int clearLogFile();

#endif