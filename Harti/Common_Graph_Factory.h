#pragma once

#ifndef COMMON_GRAPH_FACTORY_H
#define COMMON_GRAPH_FACTORY_H
#include "Common_Graph.h"

class Common_Graph_Factory
{
	Common_Graph_Factory() = delete;
public:
	static Common_Graph * Create_Common_Graph(char *s);
};
#endif // !COMMON_GRAPH_FACTORY_H
