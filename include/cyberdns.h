

#ifndef CYBERDNS_H
#define CYBERDNS_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

//class CyberExpert;
class CyberPC; //Forward deceleration

class CyberDNS
{
private:
    std::map<const std::string, CyberPC &> cyber_DNS_;	//Hash map to hold PC names and 
    //std::map<const std::string, CyberExpert &> Expert_Map;


public:
    ~CyberDNS();
    CyberDNS();
	void AddPC(CyberPC & cyber_pc_);

	CyberPC & GetCyberPC(const std::string & cyber_pc_name) const;
	std::vector<std::string> GetCyberPCList(); 		// Return list of PC's as a vector of strings.
													// All access to PC objects should use this function
													// Do not store pointers elsewhere!
    void inputComp(std::string XML_PATH_COMP);
    void inputNet(std::string XML_PATH_NET);
    void inputEvents(std::string XML_PATH_EVENTS);
};

#endif
