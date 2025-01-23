#pragma once

#include <stdbool.h>

struct App {
	void* window;
	void* renderer;
	bool should_close;
};

extern struct App context;
