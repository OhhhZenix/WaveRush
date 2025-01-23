#pragma once

#include <stdbool.h>

struct EngineContext {
	void* window;
	void* renderer;
	bool should_close;
	bool keys[258];
};

extern struct EngineContext context;
