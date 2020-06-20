#ifndef __SIMPLE_UTILS_STOP_WATCH_HH__
#define __SIMPLE_UTILS_STOP_WATCH_HH__

#include <memory>

namespace simple_utils {
    // 前置声明
    class StopWatchImpl;

    // 隐藏全部实现细节
    class StopWatch {
    public:
        StopWatch();
        ~StopWatch();
        void Tik();
        double Tok();
    private:
        std::unique_ptr<StopWatchImpl> impl_;
    };
};

#endif // ! __SIMPLE_UTILS_STOP_WATCH_HH__
