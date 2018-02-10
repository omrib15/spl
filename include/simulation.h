#ifndef SIMULATION_H_
#define SIMULATION_H_
#include "../include/cyberpc.h"
#include "../include/cyberdns.h"
#include "../include/cyberexpert.h"

#include <string>
#include <vector>
void simulate(CyberDNS & server, std::string text);
void expertsWork(CyberDNS & server, std::vector<std::string> pc_List);
#endif