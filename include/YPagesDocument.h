#include <akndoc.h>

/*
 * The Application Document Class : This class handles the non-GUI data aspects of the 
 * application - the application data. It also instantiates the application's UI class.
 * 
 * Derived from CAknDocument
 */
class CYPagesDocument : public CAknDocument {
	public:
		/*
		 * Constructor for CYPagesDocument
		 */
		CYPagesDocument(CEikApplication& aApp): CAknDocument(aApp) { }
    
	private: 
		/*
		 * Funcion to create CYPagesAppUi object
		 */
		CEikAppUi* CreateAppUiL();
};
