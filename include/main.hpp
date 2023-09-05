#ifndef MAIN_HPP_
#define MAIN_HPP_
#define YAML_CPP_STATIC_DEFINE

#define FIELD_X_LENGTH 800
#define FIELD_Y_LENGTH 1200

#pragma once
#include "robot.hpp"
#include "vec_attr.hpp"
#include "vec_repl.hpp"
#include "draw.hpp"

#include "yaml-cpp/yaml.h"
#include "opencv2/opencv.hpp"

#include <iostream>
#include <filesystem>
#include <fstream>

int max_attr_field_radius;
int max_repl_field_radius;

Mat kri_field = Mat::zeros(FIELD_X_LENGTH + 100, FIELD_Y_LENGTH + 100, CV_8UC3);

Field field_;
Line line_;
GoalPost goal_post_away;
GoalPost goal_post_home;
Robot robot_1_own(0, 0, 90, 0, 0, 0, OWN_ROBOT);

int PotentialFieldInit();
int PotentialFieldRoutine();
int LoadConfig();
int clearLogFile();

#endif