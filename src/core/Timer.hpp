#pragma once

class Timer
{
 private:
	int m_StartTime;
	int m_PausedTime;
	bool m_Started;
	bool m_Paused;

 public:
	Timer();

	void Start();

	void Stop();

	void Pause();

	void Unpause();

	int GetTicks();

	bool IsStarted() const;

	bool IsPaused() const;
};