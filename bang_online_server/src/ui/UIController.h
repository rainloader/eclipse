/*
 * UIController.h
 *
 *  Created on: 2013. 6. 3.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#ifndef UICONTROLLER_H_
#define UICONTROLLER_H_

#include <string>
#include <vector>

class UIController {
public:
	UIController();
	~UIController();

	int initState();


private:
	int menuControl(std::vector<std::string> menuList);
	void gotoxy(int x, int y);
};

#endif /* UICONTROLLER_H_ */
