
#include "InteractableObject.h"
#include "GameEngine.h"
#include "SquareMeshVbo.h"


InteractableObject::InteractableObject() {

}



bool InteractableObject::GetClick(float mouseX, float mouseY) {
	if ((mouseX > pos.x - (size.x / 2) && mouseX < pos.x + (size.x / 2) && mouseY > pos.y - (-size.y / 2) && mouseY < pos.y + (-size.y / 2))) {  //- size.y cause program problem
		return true;
	}
	else{
		return false;
	}
}



//for testing bug in GetClick
/*   
	std::cout << "Mouse pos: " << mouseX << " a " << mouseY << std::endl;
	std::cout << "Button pos: " << pos.x << " b " << pos.y << std::endl;
	std::cout << "Button size: " << size.x << " c " << size.y << std::endl;

	std::cout << "info:\n x> " << pos.x - (size.x / 2) << " x< " << pos.x + (size.x / 2) << std::endl;
	std::cout << " y> " << pos.y + (size.y / 2) << " y <" << pos.y - (size.y / 2) << "\n \n----" << std::endl;
*/

