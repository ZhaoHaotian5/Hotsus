#ifndef GROUP_H
#define GROUP_H

#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "salticidae/stream.h"
#include "config.h"
#include "types.h"

class Group
{
private:
	unsigned int size;
	std::vector<ReplicaID> group;

public:
	void serialize(salticidae::DataStream &data) const;
	void unserialize(salticidae::DataStream &data);

	Group();
	Group(std::vector<ReplicaID> group);

	std::vector<ReplicaID> getGroup();

	std::string toPrint();
	std::string toString();
};

#endif
