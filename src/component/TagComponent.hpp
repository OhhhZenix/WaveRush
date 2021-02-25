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
	~TagComponent()
	{
		printf("TagComponent Destroyed\n");
	};

	TagType Value = TagType::Entity;
};