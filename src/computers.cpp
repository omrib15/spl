#include "../include/computers.h"
#include "../include/cyberpc.h"
#include <string>
#include <iostream>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/foreach.hpp>
using namespace std;
using boost::property_tree::ptree;

void init_Server(CyberDNS & server , std::string text) {
        ptree pt;
        read_xml( text, pt  );
        BOOST_FOREACH( ptree::value_type const& v, pt ) {
            if( v.first == "computer" ){
                string name = v.second.get<string>("name");
                string os = v.second.get<string>("os");
                CyberPC *comp = new CyberPC(os,name);
               // cout<<comp->getName()<<endl;
                server.AddPC(*comp);
            }

        }
}

void create_Network(CyberDNS & server,std::string text){
        ptree pt;
        read_xml( text, pt  );
        BOOST_FOREACH( ptree::value_type const& v, pt ) {
            if( v.first == "wire" ){
                string pointA = v.second.get<string>("pointA");
                string pointB = v.second.get<string>("pointB");
                cout<<"connecting "<<pointA<<" to "<<pointB<<endl;
                (server.GetCyberPC(pointA)).AddConnection(pointB);
                cout<<"     "<< pointA<< " connected to "<<pointB<<endl;
                (server.GetCyberPC(pointB)).AddConnection(pointA);
                cout<<"     "<< pointB<< " connected to "<<pointA<<endl;

           }
        }
    }