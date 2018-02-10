#ifndef CYBER_EXPERT
#define CYBER_EXPERT
#include <iostream>

#include <vector>
#include "cyberpc.h"


class CyberExpert
{
private:
	const std::string 	cyber_expert_name_;
    const int cyber_expert_work_time_;
    const int cyber_expert_rest_time_;
    const int cyber_expert_efficiency_;
    CyberExpert(); 
    int counter;//counts the days left for resting/working
    bool isWorking;//if the expert is working now = true, else = false

public:
    int getEfficiency();
    int getWorkTime();
    void setCounter(int value);
	int getCounter();
    int getRestTime();
    bool getIsWorking();
    void setIsWorking(bool value);
    ~CyberExpert();
    const std::string getName();
    CyberExpert(std::string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_);
 	void Clean(CyberPC & cyber_pc);
	
};


#endif
