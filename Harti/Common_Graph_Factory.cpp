#include "stdafx.h"
#include "Common_Graph_Factory.h"
#include "DAG_Graph.h"
#include "Tree_Graph.h"
#include "Complete_Graph.h"
#include "Linear_Graph.h"
#include "Normal_Graph.h"


Common_Graph * Common_Graph_Factory::Create_Common_Graph(char * s)
{
	if (strcmp(s, "DAG") == 0)
		return new DAG_Graph();
	if (strcmp(s, "Tree") == 0)
		return  new Tree_Graph();
	if (strcmp(s, "Normal") == 0)
		return new Normal_Graph();
	if (strcmp(s, "Linear") == 0)
		return  new Linear_Graph();
	if (strcmp(s, "Complete") == 0)
		return  new Complete_Graph();
	return NULL;
}
