#include "../include/cyberpc.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;




CyberPC::CyberPC(string cyber_pc_os, string cyber_pc_name):
     cyber_pc_os_(cyber_pc_os),cyber_pc_name_(cyber_pc_name){
        if(cyber_worm_ != NULL){
            delete cyber_worm_;
            cyber_worm_ = NULL;
        }
}

const string CyberPC::getName(){
    return cyber_pc_name_;
}

void CyberPC::AddConnection(string  second_pc){
    cyber_pc_connections_.push_back(second_pc);

    

}

void CyberPC::Infect(CyberWorm & worm){
    if(cyber_pc_os_ == worm.getWormOs()){//match os
        cout<<"             "<<getName() <<" infected by "<< worm.getWormName()<<endl;
        cout<<"        "<<getName()<<": Worm "<< worm.getWormName() <<" is dormant"<<endl;
        if (cyber_worm_ != NULL){//if the computer was already infected
            delete cyber_worm_;
        }
            cyber_worm_ = new CyberWorm(worm);
            cyber_pc_time_to_infect_=worm.getTime();

    }
    else //no match os
        cout<<"             Worm "<<worm.getWormName()<<" is incompatible with "<<getName()<<endl;

}


void CyberPC::Run(const CyberDNS & server){ 
    if(cyber_worm_!=NULL) //the computer is infected
    {
        if(cyber_pc_time_to_infect_ > 0)//worm is still dormant
            cyber_pc_time_to_infect_--;
        else //if the time to infect has come, infect all connected pc's
        { 
            cout<<"        "<<cyber_pc_name_<< " is infecting..."<<endl;
            for(vector<string>::iterator it = cyber_pc_connections_.begin(); it!= cyber_pc_connections_.end();
                ++it){
                (server.GetCyberPC(*it)).Infect(*cyber_worm_);
            }
            
        }
    }
}
							
void CyberPC::Disinfect(){
    if(cyber_worm_!=NULL) 
        cout <<"             worm "<<cyber_worm_->getWormName()<<" succesfully removed from "<<cyber_pc_name_<<endl;
    delete cyber_worm_;
    cyber_worm_ = NULL;

}

CyberPC::~CyberPC(){
    if(cyber_worm_ != NULL){
        delete cyber_worm_;
        cyber_worm_ = NULL;
    }

}

