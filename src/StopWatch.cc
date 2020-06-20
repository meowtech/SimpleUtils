#include "StopWatch.hh"
#include "StopWatchImpl.hh"

namespace simple_utils {
	StopWatch::StopWatch() : impl_(std::make_unique<StopWatchImpl>()) {};
	StopWatch::~StopWatch() = default;
	void StopWatch::Tik() {
		impl_->Tik();
	}
	double StopWatch::Tok() {
		return impl_->Tok();
	}
};

