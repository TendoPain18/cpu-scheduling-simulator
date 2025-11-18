#pragma once

#include "../Data_Structures/LinkedList.h"
#include "../Data_Structures/Array.h"
#include "../Data_Structures/LinkedQueue.h"
#include "../Data_Structures/Priority_Queue.h"
#include "../Process/Process.h"
#include "../Process/Process.h"


#include <iostream>
using namespace std;

class Processor {
protected:
	int Length = 0;
	string type;
	Process* RunningProcess;


	Processor(string type)
	{
		this->type = type;
	}

	virtual void Print_Processor(ostream&) = 0;

public:
	friend ostream& operator << (ostream&, Processor&);

	virtual void Update(const int& time) = 0;
	virtual bool Add_Process_To_RDY(Process* p, const int&) = 0;
	virtual Process* Remove_Curent_RUN() = 0;
	virtual void If_RUN_Is_Empty_Add_Next() = 0;


	bool Check_IO(int Current_time)
	{
		if (RunningProcess)
		{
			if (RunningProcess->Need_IO_Now(Current_time))
			{	
				return true;
			}
		}
		return false;
	}


	bool Check_Runnuig_process_If_Finished()
	{
		if (RunningProcess)
		{
			if (RunningProcess->Is_Finished())
			{
				return true;
			}
		}
		return false;
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	string getType() { return this->type; }
	int Get_Time_Expected_To_Finish() {	return Length; }
	Process* Get_Runnung() { return RunningProcess; }
};

inline ostream& operator << (ostream& out, Processor& P)
{
	P.Print_Processor(out);
	return out;
}



