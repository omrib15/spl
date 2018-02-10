#include <iostream>
#include <string> 
#include <vector>
#include "../include/cyberdns.h"
#include "../include/computers.h"
#include "../include/simulation.h"


int main(int argc, char *argv[]) {
    CyberDNS *server = new CyberDNS();
    init_Server(*server,"./computers.xml");
    create_Network(*server ,"./network.xml");
    simulate(*server , "./events.xml");  
    
    delete server;
    return 0;

};
