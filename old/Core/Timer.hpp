#pragma once

class Timer {
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

	[[nodiscard]] bool IsStarted() const;

	[[nodiscard]] bool IsPaused() const;
};