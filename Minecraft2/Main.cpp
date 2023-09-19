#include <iostream>
#include "Core.h"



int main() 
{
    std::cout << "Starting Program!" << std::endl;
	Core singleton = Core::GetInstance();
	singleton.InitModules();
	singleton.Run();
	std::cout << "Program Ended" << std::endl;
	

	
}