#pragma once

enum class TagType
{
	Entity,
	Player,
};

struct TagComponent
{
	TagType Value = TagType::Entity;
};