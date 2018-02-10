#include "../include/cyberexpert.h"
#include <string>
using namespace std;

CyberExpert::CyberExpert(string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_):
    cyber_expert_name_(cyber_expert_name_),cyber_expert_work_time_(cyber_expert_work_time_),cyber_expert_rest_time_(cyber_expert_rest_time_),
    cyber_expert_efficiency_(cyber_expert_efficiency_){
    	counter = cyber_expert_work_time_;//expert set up for working first.
        isWorking=true;//expert set up for working first.
    }

  	const string CyberExpert::getName(){
    	return cyber_expert_name_;
    }

    int CyberExpert::getCounter(){
    	return counter;
    }

    void CyberExpert::setCounter(int value){
        counter = value;
    }

    int CyberExpert::getEfficiency(){
        return cyber_expert_efficiency_;
    }

    void CyberExpert::Clean(CyberPC & cyber_pc){
        cyber_pc.Disinfect();
    }

    int CyberExpert::getRestTime(){
        return cyber_expert_rest_time_;
    }
    int CyberExpert::getWorkTime(){
        return cyber_expert_work_time_;
    }
    bool CyberExpert::getIsWorking(){
        return isWorking;
    }
    void CyberExpert::setIsWorking(bool value){
        isWorking = value;
    }
    CyberExpert::~CyberExpert(){
    }
