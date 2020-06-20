#ifndef __SIMPLE_UTILS_STOP_WATCH_IMPL_HH__
#define __SIMPLE_UTILS_STOP_WATCH_IMPL_HH__

#include <chrono>

namespace simple_utils {
	class StopWatchImpl {
	public:
		StopWatchImpl();
		~StopWatchImpl() = default;
		void Tik();
		double Tok();
	private:
		std::chrono::high_resolution_clock::time_point start_;
		std::chrono::high_resolution_clock::time_point stop_;
	};
};

#endif // !__SIMPLE_UTILS_STOP_WATCH_IMPL_HH__