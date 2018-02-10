#ifndef CYBER_PC
#define CYBER_PC
#include <iostream>
#include <string>
#include "cyberworm.h"
#include "cyberdns.h"

class CyberPC
{
private:
    const std::string cyber_pc_os_;
    const std::string cyber_pc_name_;
    std::vector<std::string> cyber_pc_connections_;
    CyberWorm * cyber_worm_ = NULL;
    int cyber_pc_time_to_infect_;
    CyberPC();

public:
    ~CyberPC();
    CyberPC(std::string cyber_pc_os, std::string cyber_pc_name);
    const std::string getName();
	void AddConnection(std::string  second_pc);					// Add a connection to this PC
	void Infect(CyberWorm & worm); 								// Add a worm to this PC
	void Run(const CyberDNS & server); 							// Activate PC and infect others if worm is active
	void Disinfect();											// called by cyber expert, disinfect PC
	

};


#endif
