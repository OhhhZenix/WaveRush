#include "core/input.h"

#include "core/engine.h"

bool IsKeyDown(uint32_t key) {
	return context.keys[key];
}
