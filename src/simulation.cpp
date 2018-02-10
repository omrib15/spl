#include "../include/simulation.h"
#include <iostream>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/foreach.hpp>

using namespace std;
using boost::property_tree::ptree;

std::map<const std::string, CyberExpert &> Expert_Map;//map of all the experts
int timeToTerminate=-1;//whet termination event will happent it will change
int day(0);
vector<string> pc_List;
bool terminationCalled = false;

void simulate(CyberDNS & server, std::string text){  
	
    ptree pt;
    
    pc_List = server.GetCyberPCList();

    read_xml( text, pt  );


    BOOST_FOREACH( ptree::value_type const& v, pt ) {//loop for reading the events
            if(terminationCalled) break; // if it's termination day, don't read anymore events
                cout<<"Day : "<<day<<endl;
                if( v.first == "hack" ){ //hack event
                    string name = v.second.get<string>("computer");
                    string wormName = v.second.get<string>("wormName");
                    int wormDormancy = v.second.get<int>("wormDormancy");
                    string wormOs = v.second.get<string>("wormOs");
                    cout<< "        Hack occured on "<< name<<endl;
                    
                    CyberWorm *worm = new CyberWorm(wormOs,wormName,wormDormancy);
                    (server.GetCyberPC(name)).Infect(*worm);
                    delete worm;
                    
                }

                if( v.first == "clock-in" ) //clock-in event
                {
                    string name = v.second.get<string>("name");
                    int workTime = v.second.get<int>("workTime");
                    int restTime = v.second.get<int>("restTime");
                    int efficiency = v.second.get<int>("efficiency");
                    cout<<"        "<< name << " clocked in"<< endl;
                    CyberExpert * expert = new CyberExpert(name,workTime,restTime,efficiency);
                    Expert_Map.insert(pair<string,CyberExpert &>(expert->getName(),*expert)); 
                    
                   
                }

            if( v.first == "termination") //termination event
            {
                
                terminationCalled = true;
                timeToTerminate = v.second.get<int>("time");
            }
            expertsWork(server, pc_List); // after reading today's event, continue the workflow
        
    }

    while(day <= timeToTerminate)
    { // after reading a termination event, the for_each loop will break. yet
        //we want to continue the workflow until termination day
        cout<<"Day : "<<day<<endl;
        expertsWork(server, pc_List);
    }

    for(map<string, CyberExpert &>::iterator deleter = Expert_Map.begin(); deleter != Expert_Map.end(); ++deleter)
        {//clear experts map by deleting every expert and then clearing the map
        delete &(deleter->second);
        }
    Expert_Map.clear();

      
}
void expertsWork(CyberDNS & server, vector<string> pc_List)
{
    vector<string>::iterator PCit = pc_List.begin();//iterator the will run on the pc list
    for(map<string,CyberExpert &>::iterator it = Expert_Map.begin(); it!= Expert_Map.end(); ++it )
    {//running on all the experts 

        if(!((it->second).getIsWorking()))  //resting
        {
            if(((it->second).getCounter())>0)//keep resting for another day
                (it->second).setCounter(((it->second).getCounter())-1);
            if (((it->second).getCounter())==0) //that was his last rest day and tomorrow he will go back to work
            {
                cout<<"        "<<it->first<<" is back to work"<<endl;
                (it->second).setIsWorking(true);
                (it->second).setCounter((it->second).getWorkTime());
            }

                     
        }
        else //working
        {
            if(   (((it->second).getCounter())>0) || (((it->second).getRestTime())==0))
                {//still working for another day or if the expert never rest
                    (it->second).setCounter(((it->second).getCounter())-1);                
                    for(int i = (it->second).getEfficiency() ; i > 0  and PCit != pc_List.end() ; i = i -1) 
                    {
                        cout <<"        "<< it->first<<" examining "<<*PCit<<endl;
                        (it->second).Clean(server.GetCyberPC(*PCit)); 
                        if(PCit!=pc_List.end())
                        { //if all the computers are checked we will go out from the loop but workind days will stiil be counted
                                     ++PCit;
                        }
                    } //end of work day

                    if(((it->second).getCounter())==0) //if finished his work days
                    {
                        cout<<"        "<<it->first<<" is taking a break"<<endl;
                        (it->second).setCounter((it->second).getRestTime());
                        (it->second).setIsWorking(false);
                    }
                
                }
        }

                    
    }
    for(vector<string>::iterator it = pc_List.begin() ; it != pc_List.end() ; ++it){ //activate Run function on all the computers
          (server.GetCyberPC(*it)).Run(server);   
        }
    day++;

}



 

























