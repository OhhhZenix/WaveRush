#pragma once

enum class TagType
{
	Entity,
	Player,
	SmartEnemy,
};

struct TagComponent
{
	TagType Value = TagType::Entity;
};