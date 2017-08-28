#ifndef JOB_H
#define JOB_H
#include <string>

class Job {
private: 
	int duration; //duration of job
	int cpuRequired; // cpus required
	int startTick; // start time (tick)
	std::string name; // job name
	int durationLeft = 0; //duration left to process

public: 
	//gets
	int getDuration() const 
	{
		return duration;
	}

	int getDurationLeft() const
	{
		return durationLeft;
	}

	int getCpu() const
	{
		return cpuRequired;
	}

	int getStartTick() const
	{
		return startTick;
	}

	std::string getName() const {
		return name;
	}
	//sets
	void setDuration(int value) {
		duration = value;
	}

	void setDurationLeft(int value) {
		durationLeft = value;
	}

	void setCpu(int value) {
		cpuRequired = value;
	}

	void setStartTick(int value) {
		startTick = value;
	}

	void setName(std::string value) {
		name = value;
	}

	//template
	Job(std::string name, int cpuRequired, int duration, int startTick) {
		setName(name);
		setCpu(cpuRequired);
		setDuration(duration);
		setStartTick(startTick);
	}

	//comparators...given.
	friend bool operator<(const Job &left, const Job &right)
	{
		return left.getDuration() < right.getDuration();
	}

	friend bool operator>(const Job &left, const Job &right)
	{
		return left.getDuration() > right.getDuration();
	}

	friend bool operator==(const Job &left, const Job &right)
	{
		return left.getDuration() == right.getDuration();
	}
	
};
#endif