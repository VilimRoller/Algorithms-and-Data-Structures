#include "gtest/gtest.h"
#include "Timer.h"

class TimerTest : public ::testing::Test {
protected:
	void SetUp() override {
		timer_1_.Start();
		timer_2_.Start();

		for (int i = 0; i < 100000; ++i)
			int j = i + 1;

		timer_2_.Stop();
		timer_1_.Stop();
	}

	void TearDown() override {}

	Timer timer_1_;
	Timer timer_2_;
};

TEST_F(TimerTest, MeasuringTime) {
	EXPECT_GE(timer_1_.GetMeasuredTimeInMicroseconds(), timer_2_.GetMeasuredTimeInMicroseconds());
	EXPECT_GE(timer_1_.GetMeasuredTimeInMiliseconds(), timer_2_.GetMeasuredTimeInMiliseconds());
	EXPECT_GE(timer_1_.GetMeasuredTimeInSeconds(), timer_2_.GetMeasuredTimeInSeconds());
}

TEST_F(TimerTest, TimeUnits) {
	EXPECT_LE(timer_1_.GetMeasuredTimeInSeconds(), timer_2_.GetMeasuredTimeInMiliseconds());
	EXPECT_LE(timer_1_.GetMeasuredTimeInMiliseconds(), timer_2_.GetMeasuredTimeInMicroseconds());
}