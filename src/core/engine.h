#pragma once

#include <stdbool.h>

struct EngineContext {
	void* window;
	void* renderer;
	bool should_close;
};

extern struct EngineContext context;
