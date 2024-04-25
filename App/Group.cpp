#include "Group.h"

void Group::serialize(salticidae::DataStream &data) const
{
	data << this->size;
	for (int i = 0; i < this->group.size(); i++)
	{
		data << this->group[i];
	}
}

void Group::unserialize(salticidae::DataStream &data)
{
	data >> this->size;
	for (int i = 0; i < this->group.size(); i++)
	{
		data >> this->group[i];
	}
}

Group::Group()
{
	this->size = 0;
	std::vector<ReplicaID> group;
	this->group = group;
}

Group::Group(std::vector<ReplicaID> group)
{
	this->size = group.size();
	this->group = group;
}

std::vector<ReplicaID> Group::getGroup()
{
	return this->group;
}

std::string Group::toPrint()
{
	std::string textGroup = "";
	for (int i = 0; i < this->size; i++)
	{
		textGroup += std::to_string(this->group[i]);
		if (i != this->size - 1)
		{
			textGroup += " ";
		}
	}
	std::string text = "";
	text += "GROUP[";
	text += std::to_string(this->size);
	text += "-";
	text += textGroup;
	text += "]";
	return text;
}

std::string Group::toString()
{
	std::string text = "";
	text += std::to_string(this->size);
	for (int i = 0; i < this->size; i++)
	{
		text += std::to_string(this->group[i]);
	}
	return text;
}
