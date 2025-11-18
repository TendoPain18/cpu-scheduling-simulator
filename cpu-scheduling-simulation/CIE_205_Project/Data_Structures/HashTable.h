#pragma once

#include "SharedClasses/Pair.h"
#include "../Process/Process.h"
#include "../Processors/Processor.h"

class HashTable
{
	Pair<int, Pair<Process*, Processor*>>* my_array;


public:
	HashTable(int size)
	{
		my_array = new Pair<int, Pair<Process*, Processor*>>[size];
	}

	bool AddToTable(int ID, Process* process,Processor* processor)
	{
		Pair<int, Pair<Process*, Processor*>> temp;
		temp.left = ID;
		temp.right.left = process;
		temp.right.right = processor;
		my_array[ID] = temp;
		return true;
	}

	void Modify(int ID, Processor* new_p)
	{
		my_array[ID].right.right = new_p;
	}

	Process* Find_Process(int ID)
	{
		return my_array[ID].right.left;
	}

	Processor* Find_Processor(int ID)
	{
		return my_array[ID].right.right;
	}


};