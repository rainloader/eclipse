/*
 * UIController.cpp
 *
 *  Created on: 2013. 6. 3.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#include "UIController.h"

/**/#include <iostream>

UIController::UIController() {
	// TODO Auto-generated constructor stub

}

UIController::~UIController() {
	// TODO Auto-generated destructor stub
}

int UIController::initState() {
	std::vector<std::string> menuList = std::vector<std::string>();
	menuList.push_back("1. Run server with default setting");
	menuList.push_back("2. Configure setting");
	menuList.push_back("3. Terminate program");

	int choice = menuControl(menuList);
	return 0;
}

int UIController::menuControl(std::vector<std::string> menuList){
	for(int i=0; i<menuList.size(); i++){
		//print menu
		std::cout << menuList[i];
	}
	int choice = -1;
	std::cin >> choice;
	return choice;
}
