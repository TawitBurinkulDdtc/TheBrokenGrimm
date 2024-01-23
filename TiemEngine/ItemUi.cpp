
#include "ItemUi.h"
#include "GameEngine.h"
#include "SquareMeshVbo.h"



//#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll

ItemUi::ItemUi(){
	//SoundEngine = createIrrKlangDevice();
}

void ItemUi::Interact(){  // pos.x-(size.x/2)

		/*if (SoundEngine) {
			SoundEngine->play2D("Bamboo.ogg", false);
			//printf("\nButton.cpp press working well");
			////SoundEngine->drop(); // Release resources
		}
		else {
			// Handle the case when the sound engine creation fails
			printf("\nFailed to create the sound engine");
		}*/
		Interacted = true;
}

void ItemUi::gone(){}






