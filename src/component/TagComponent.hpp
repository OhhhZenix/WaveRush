#pragma once

enum class TagType
{
	Entity,
	Player,
	BasicEnemy,
	SmartEnemy,
};

struct TagComponent
{
	TagType Value = TagType::Entity;
};