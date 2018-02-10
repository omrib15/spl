
#include "../include/cyberdns.h"
#include "../include/cyberpc.h"
#include <iostream>
#include <string>


using namespace std;

    CyberDNS::CyberDNS(){}

	void CyberDNS::AddPC(CyberPC & cyber_pc_){
	    cout<<"Adding to server: "<< cyber_pc_.getName()<<endl;
        cyber_DNS_.insert(pair<string,CyberPC &>(cyber_pc_.getName(),cyber_pc_));
        cout<<cyber_pc_.getName()<<" connected to server"<<endl;
	}

	CyberPC & CyberDNS::GetCyberPC(const string & cyber_pc_name) const{
        return cyber_DNS_.at(cyber_pc_name);
	}

	vector<string> CyberDNS::GetCyberPCList() {

	    vector<string> pc_list;
        map<string,CyberPC &>::iterator it;
        
        for(it = cyber_DNS_.begin(); it!= cyber_DNS_.end(); ++it ){
            pc_list.push_back(it->first);
        }
        return pc_list;

	}

	CyberDNS::~CyberDNS(){ ///destructor
        for( map<string, CyberPC &>::iterator it = cyber_DNS_.begin(); it != cyber_DNS_.end(); ++it){ //delete all the computers
            delete &(it->second);
        }
        cyber_DNS_.clear();//delete the server
    
	}
	     





