#include <iostream>
#include "clsLoginScreen.h"
#include "clsRegisterLoginScreen.h"

using namespace std;

int main()
{
	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{

			break;
		}
	}

	

}


