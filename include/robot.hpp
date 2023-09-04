#ifndef ROBOT_HPP_
#define ROBOT_HPP_

#include <vector>

using namespace std;

#define OWN_ROBOT 1
#define ENEMY_ROBOT 0

typedef struct fVec3
{
    float x;
    float y;
    float z;
};

typedef struct iVec3
{
    int x;
    int y;
    int z;
};

/**
 * @param pose: The pose of the robot
 * @param vel: The velocity of the robot
 * @param type: The type of the robot, is it enemy or own
 */
typedef struct Robot
{
    fVec3 pose;
    fVec3 vel;
    uint8_t type;
};

#endif