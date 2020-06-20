#ifndef __SIMPLE_UTILS_STOP_WATCH_HH__
#define __SIMPLE_UTILS_STOP_WATCH_HH__

#include <memory>

namespace simple_utils {
    // ǰ������
    class StopWatchImpl;

    // ����ȫ��ʵ��ϸ��
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
