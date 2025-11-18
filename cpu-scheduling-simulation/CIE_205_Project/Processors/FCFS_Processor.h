#pragma once

#include "Processor.h"

class FCFS_Processor : public Processor
{
	LinkedQueue<Process*> RDY;
	void Print_Processor(ostream& out) override
	{
		out << RDY;
	}


public:
	FCFS_Processor() : Processor("FCFS") { }

	bool Add_Process_To_RDY(Process* p, const int& time) override
	{
		RDY.enqueue(p);
		int t = p->Get_Time_Till_Leaving();
		Length = Length + t;
		return true;
	}

	void If_RUN_Is_Empty_Add_Next()
	{
		if (!RunningProcess)
		{
			RDY.dequeue(RunningProcess);
		}
	}

	Process* Remove_Curent_RUN()
	{
		if (RunningProcess)
		{
			Process* temp = RunningProcess;
			RunningProcess = nullptr;
			int t = temp->Get_Time_Till_Leaving();
			Length = Length - t;
			if (!(RDY.isEmpty()))
			{
				RDY.dequeue(RunningProcess);
			}
			return temp;
		}
		return nullptr;
	}

	bool Remove_Process_From_RDY(Process* p, const int& time)
	{
		int t = p->Get_Time_Till_Leaving();
		Length = Length - t;
		RDY.DeleteNode(p);
		return true;
	}

	bool Remove_Process_From_Processor(Process* p, const int& time)
	{
		if (RunningProcess == p)
		{
			Remove_Curent_RUN();
			return true;
		}
		else
		{
			Remove_Process_From_RDY(p, time);
			return true;
		}
		return false;
	}


	void Update(const int& time) override
	{		
		if (RunningProcess)
		{
			RunningProcess->Update_Process(time, true);
			Length--;
		}

		for (int i = 0; i < RDY.GetSize(); i++)
		{
			RDY[i]->Update_Process(time, false);
		}
	}
	













	Process* Remove_Process_On_Top(const int & time)
	{
		Process* temp;
		RDY.dequeue(temp);
		int t = temp->Get_Time_Till_Leaving();
		Length = Length - t;
		return temp;
	}


	~FCFS_Processor()
	{

	}
};

