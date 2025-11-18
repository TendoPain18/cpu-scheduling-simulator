#pragma once
#include "..\Data_Structures\LinkedList.h"
#include "../Data_Structures/SharedClasses/Pair.h"
#include "../Data_Structures/LinkedList.h"


class Process
{
	int PID;
	int ProcessorID;
	int Arrival_Time;

	int CPU_Time;
	int CPU_Time_Left;
	int Termination_Time = 0;
	int Respose_Time = 0;
	int Turn_Around_Time = 0;
	int Waiting_Time = 0;

	LinkedList<Pair<int, int>>* IO_pairs;

	bool Started = false;
	Process* Child;


public:
	friend ostream& operator << (ostream&, const Process*);
	friend ostream& operator << (ostream&, const Process&);



Process(int ID, int AT,int CT, LinkedList<Pair<int, int>>* IO_Pairs)
	{
		PID = ID;
		Arrival_Time = AT;
		CPU_Time = CT;
		IO_pairs = IO_Pairs;
		CPU_Time_Left = CPU_Time;
	}
	/////////////////////////////////////////////////////////////////////////////////////////
	int Get_PID()
	{
		return PID;
	}

	Process* Get_Child()
	{
		return Child;
	}

	int Get_Arrival_time()
	{
		return Arrival_Time;
	}

	bool Check_CPU_Time_Left(int STL)
	{
		if (CPU_Time_Left < STL)
		{
			return true;
		}
		return false;
	}

	bool Check_Waiting_Time(int MaxW)
	{
		if (Waiting_Time > MaxW)
		{
			return true;
		}
		return false;
	}

	int Get_Turn_Arround_Time()
	{
		if (Is_Finished())
		{
			return Termination_Time - Arrival_Time;
		}
		return 0;
	}

	int Get_Time_Till_Leaving()
	{
		int t = CPU_Time - CPU_Time_Left;
		if (!IO_pairs->isEmpty())
		{
			int temp = IO_pairs->GetNodeAt(0)->getItem().left - t;
			return temp;
		}
		return CPU_Time_Left;
	}

	Pair<int, int> Get_Next_IO_Pair()
	{
		Pair<int, int> temp;
		IO_pairs->DeleteFirst(temp);
		return temp;
	}
	///////////////////////////////////////////////////////////////////////////////////////////
	bool Need_IO_Now(int Current_Time)
	{
		if (!(IO_pairs->isEmpty()))
		{
			if (IO_pairs->GetNodeAt(0)->getItem().left == (CPU_Time - CPU_Time_Left))
			{
				return true;
			}
		}
		return false;
	}

	bool Is_Finished()
	{
		if (CPU_Time_Left == 0)
		{
			return true;
		}
		return false;
	}

	bool Is_Arrived(int Current_Time)
	{
		if (Current_Time == Arrival_Time)
		{
			return true;
		}
		return false;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////
	void Update_Process(const int& time , bool running)
	{
		if (!Started)
		{
			Respose_Time = time - Arrival_Time;
			Started = true;
		}
		if (running)
		{
			CPU_Time_Left--;
			if (Is_Finished())
			{
				Termination_Time = time;
			}
		}
		else
		{
			Waiting_Time++;
		}
	}

	void Update_Process_IO()
	{
		Pair<int, int> temp = (IO_pairs)->GetNodeAt(0)->getItem();
		temp.right--;
		(IO_pairs)->GetNodeAt(0)->setItem(temp);
	}

	void Fork_Process()
	{

	}

	~Process()
	{

	}




	int get_remaining_IO() const
	{
		if (!IO_pairs->isEmpty())
		{
			int temp = (IO_pairs)->GetNodeAt(0)->getItem().right;
			return temp;
		}
		return 0;
	}

	bool remove_first_IO()
	{
		Pair<int, int> temp;
		return IO_pairs[0].DeleteFirst(temp);
	}

	int getWT()
	{
		return Waiting_Time;
	}

};


inline ostream& operator << (ostream& out, const Process* P)
{
	out << P->PID << "LC(" << P->CPU_Time_Left << ")" << "LIO(" << P->get_remaining_IO() << ")" << "W(" << P->Waiting_Time << ")";
	return out;
}

inline ostream& operator << (ostream& out, const Process& P)
{
	out << P.PID << "LC(" << P.CPU_Time_Left << ")" << "LIO(" << P.get_remaining_IO() << ")" << "W(" << P.Waiting_Time << ")";
	return out;
}