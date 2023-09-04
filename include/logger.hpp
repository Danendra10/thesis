#ifndef LOGGER_HPP_
#define LOGGER_HPP_
#include <string>

using namespace std;

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"

char log_dir[128];

void SaveLog(const char *msg, ...);

void Logger(const char *color, const char *msg, ...)
{
    SaveLog(msg);
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[100];
    sprintf(buffer, "[%d-%d-%d %d:%d:%d] => ", 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday, ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
    msg = strcat(buffer, msg);
    va_list args;
    va_start(args, msg);
    printf("%s", color);
    vprintf(msg, args);
    printf("%s", RESET);
    va_end(args);
}

void SaveLog(const char *msg, ...)
{
    char buffer[100];
    time_t now = time(0);
    tm *ltm = localtime(&now);
    sprintf(buffer, "[%d-%d-%d %d:%d:%d] => ", 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday, ltm->tm_hour, ltm->tm_min, ltm->tm_sec);

    va_list args;
    va_start(args, msg);
    vsprintf(buffer + strlen(buffer), msg, args);
    va_end(args);

    FILE *fp = fopen(log_dir, "a");
    fprintf(fp, "%s", buffer);
    fclose(fp);
}

#endif