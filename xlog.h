#ifndef __xlog_h__
#define __xlog_h__

#define LOG_RESULT(action, ...) LOG_DBG("%s = %d", #action, action(__VA_ARGS__))
#define ASSERT_RESULT(action, ...)                      \
    {                                                   \
        LOG_DBG("performing: %s", #action); \
        int res = action(__VA_ARGS__);                  \
        __ASSERT(res == 0, "%s got: %d", #action, res); \
    }

#define SUCCESS(action, ...)                      \
    {                                                   \
        int res = action(__VA_ARGS__);                  \
        __ASSERT(res == 0, "unable to [%s] err: %d", #action, res); \
    }

#endif