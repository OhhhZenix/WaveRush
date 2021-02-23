#pragma once

struct PositionComponent
{
	float X = 0.0f;
	float Y = 0.0f;
	float Z = 0.0f;

	PositionComponent() = default;
	PositionComponent(const PositionComponent&) = default;
};