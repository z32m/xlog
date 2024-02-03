#ifndef __xlog_h__
#define __xlog_h__

#include <xglob.h>
#include <zephyr/logging/log.h>

#define LOG_RESULT(action, ...) LOG_DBG("%s = %d", #action, action(__VA_ARGS__))

#define ASSERT_NOT_NULL(action, value) __ASSERT(value != NULL, "%s got: NULL", #action);

#define ASSERT_RESULT(action, ...)                      \
    {                                                   \
        LOG_DBG("performing: %s", #action);             \
        int res = action(__VA_ARGS__);                  \
        __ASSERT(res == 0, "%s got: %d", #action, res); \
    }

#define SURE(action, ...)                                           \
    {                                                               \
        int res = action(__VA_ARGS__);                              \
        __ASSERT(res == 0, "unable to [%s] err: %d", #action, res); \
    }

#define ENSURE(action, ...)                                         \
    {                                                               \
        int res = action(__VA_ARGS__);                              \
        __ASSERT(res != 0, "unable to [%s] err: %d", #action, res); \
    }

#define fallback(n, s, ...)                                                  \
    {                                                                        \
        int err = s(__VA_ARGS__);                                            \
        if (err)                                                             \
        {                                                                    \
            LOG_ERR("%s:%s err=%d", #s, STRINGY(ARGN(n, __VA_ARGS__)), err); \
            return err;                                                      \
        }                                                                    \
    }

#define fallbacks(s, ...) fallback(s, s, __VA_ARGS__)

#endif