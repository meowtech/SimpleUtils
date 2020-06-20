#include "StopWatchImpl.hh"

namespace simple_utils {
	StopWatchImpl::StopWatchImpl()
		: start_(std::chrono::high_resolution_clock::now()),
		stop_() {};

	void StopWatchImpl::Tik() {
		start_ = std::chrono::high_resolution_clock::now();
	}

	double StopWatchImpl::Tok() {
		double interval = 0.0;
		stop_ = std::chrono::high_resolution_clock::now();
		interval = std::chrono::duration<double, std::milli>(stop_ - start_).count();
		// »º´æ
		start_ = stop_;
		return interval;
	}
};