//#pragma once
//
//#include "Processor.h"
//
//class SJF_Processor : public Processor
//{
//	Priority_Queue<Process*> RDY; // priorty queue
//	void Print_Processor(ostream& out) override
//	{
//		out << "(" << RDY.size() << "): ";
//		out << RDY;
//	}
//
//	void Add_Next_Process_To_Run() override
//	{
//		RunningProcess = nullptr;
//		if (!RDY.isEmpty())
//		{
//			RDY.dequeue(RunningProcess);
//		}
//	}
//public:
//	
//	SJF_Processor() : Processor("SJF ") {}
//
//	void Update(const int& time) override
//	{
//		if (time == 0)
//		{
//			Add_Next_Process_To_Run();
//			return;
//		}
//		if (RunningProcess)
//		{
//			RunningProcess->Update_Process(time, true);
//		}
//		//for (int i = 0; i < RDY.GetSize(); i++)
//		//{
//		//	RDY[i]->Update_Process(time, false);
//		//}
//	}
//
//	bool Add_Process_To_RDY(Process* p, const int& time) override
//	{
//		int t = p->Get_Time_Till_Leaving(time);
//		Pair<Process*, int> x;
//		x.left = p;
//		x.right = t * -1;
//		RDY.enqueue(x);
//		Length = Length + t;
//		return true;
//	}
//
//	~SJF_Processor()
//	{
//	
//	}
//};