#include "main.hpp"

int main()
{
    if (potentialFieldInit() == -1)
    {
        printf("Error on potentialFieldInit");
        return -1;
    }
    DrawField(field_, kri_field);
    AddLine(line_, kri_field);
    AddGoalPost(goal_post_home, kri_field);
    AddGoalPost(goal_post_away, kri_field);
    AddMiddleLine(field_, line_, kri_field);
    AddMiddleCircle(line_, kri_field);
    DrawRobot(robot_1_own, kri_field);

    AddText("Home", kri_field, 50, 30);
    AddText("Away", kri_field, 1200, 30);

    imshow("kri_field", kri_field);
    waitKey(0);
    return 1;
}

int potentialFieldInit()
{
    filesystem::path log_directory = filesystem::current_path() / "../log/logger.log";
    log_dir = log_directory.string();

    field_.length_x = 800;
    field_.length_y = 1300;

    line_.start_point_x = 50;
    line_.start_point_y = 50;
    line_.end_point_x = field_.length_x - 50;
    line_.end_point_y = field_.length_y - 50;

    goal_post_home.start_point_x = field_.length_x / 2 - 100;
    goal_post_home.start_point_y = line_.start_point_y;
    goal_post_home.end_point_x = field_.length_x / 2 + 100;
    goal_post_home.end_point_y = line_.start_point_y - 50;

    goal_post_away.start_point_x = field_.length_x / 2 - 100;
    goal_post_away.start_point_y = line_.end_point_y;
    goal_post_away.end_point_x = field_.length_x / 2 + 100;
    goal_post_away.end_point_y = line_.end_point_y + 50;

    if (clearLogFile() == -1)
        return -1;
    if (LoadConfig() == -1)
        return -1;

    return 1;
}

int clearLogFile()
{
    // clear log file if size > 500MB
    filesystem::path log_directory = filesystem::current_path() / "../log/logger.log";
    try
    {
        // Check if the log file exists
        if (filesystem::exists(log_directory))
        {
            // Get the file size in bytes
            std::uintmax_t fileSize = filesystem::file_size(log_directory);

            // Check if the file size exceeds 500MB (500 * 1024 * 1024 bytes)
            if (fileSize > 500 * 1024 * 1024)
            {
                // Open the log file in truncate mode to clear its contents
                std::ofstream logFile(log_directory, std::ios::trunc);

                if (logFile.is_open())
                {
                    logFile.close();
                    Logger(GREEN, "Log file cleared.");
                    return 0; // Success
                }
                else
                {
                    Logger(RED, "Error clearing the log file.");
                    return -1; // Error
                }
            }
            else
            {
                Logger(GREEN, "Log file size is within the limit, current size: %f MB", (double)fileSize / 1024 / 1024);
                return 1; // File size is within the limit
            }
        }
        else
        {
            Logger(RED, "Log file does not exist.");
            return -1; // Error
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error while checking/clearing the log file: " << e.what() << std::endl;
        return -1; // Error
    }
}

int LoadConfig()
{
    try
    {
        filesystem::path cfg_dir = filesystem::current_path() / "../cfg/config.yaml";
        YAML::Node static_cfg = YAML::LoadFile(cfg_dir.c_str());
        max_attr_field_radius = static_cfg["Potential"]["max_attr_field_radius"].as<int>();
        max_repl_field_radius = static_cfg["Potential"]["max_repl_field_radius"].as<int>();

        Logger(GREEN, "===================================================");
        Logger(GREEN, "Config Loaded with:");
        Logger(GREEN, "Max Attr Field Radius: %d", max_attr_field_radius);
        Logger(GREEN, "Max Repl Field Radius: %d", max_repl_field_radius);
        Logger(GREEN, "===================================================");
        return 0;
    }
    catch (const std::exception &e)
    {
        Logger(RED, "Error on LoadConfig: %s", e.what());
        return -1;
    }
}