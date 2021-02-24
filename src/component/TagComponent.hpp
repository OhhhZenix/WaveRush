#pragma once

enum class TagType
{
	Entity,
	Player,
	BasicEnemy,
	SmartEnemy,
	ParticleSystem,
};

struct TagComponent
{
	TagType Value = TagType::Entity;
};