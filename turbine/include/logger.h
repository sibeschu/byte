#pragma once

#include "defines.h"
#include <cstdarg>
#include <cstdio>

#define LOGGER_ENABLED 1

enum log_level {
    LOG_LEVEL_FATAL = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARN = 2,
    LOG_LEVEL_INFO = 3,
    LOG_LEVEL_DEBUG = 4,
} log_level;

static inline void _logger_output(enum log_level level, const char* message, const char* file, u16 line, ...)
{
  const char* error_levels[5] = {"[FATAL]", "[ERROR]", "[WARN]", "[INFO]", "[DEBUG]"};

  fprintf(stderr, "%s[%s:%d] ", error_levels[level], file, line);

  va_list args;
  va_start(args, line);
  vfprintf(stderr, message, args);
  va_end(args);
  fputc('\n', stderr);
}

#if LOGGER_ENABLED == 1
#   define TRB_FATAL(message, ...) _logger_output(LOG_LEVEL_FATAL, message, __FILE__, __LINE__, ##__VA_ARGS__);
#   define TRB_ERROR(message, ...) _logger_output(LOG_LEVEL_ERROR, message, __FILE__, __LINE__, ##__VA_ARGS__);
#   define TRB_WARN(message, ...) _logger_output(LOG_LEVEL_WARN, message, __FILE__, __LINE__, ##__VA_ARGS__);
#   define TRB_INFO(message, ...) _logger_output(LOG_LEVEL_INFO, message, __FILE__, __LINE__, ##__VA_ARGS__);
#   define TRB_DEBUG(message, ...) _logger_output(LOG_LEVEL_DEBUG, message, __FILE__, __LINE__, ##__VA_ARGS__);
#else
#   define TRB_FATAL(message, ...)
#   define TRB_ERROR(message, ...)
#   define TRB_WARN(message, ...)
#   define TRB_INFO(message, ...)
#endif