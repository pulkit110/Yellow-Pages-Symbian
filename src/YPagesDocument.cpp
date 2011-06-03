// YPages_doc.cpp

#include "YPagesDocument.h"
#include "YPagesAppUi.h"

/*
 *  Create the application user interface, and return a pointer to it;
 *   the framework takes ownership of this object 
 */
CEikAppUi* CYPagesDocument::CreateAppUiL()
{       
	return new (ELeave) CYPagesAppUi; 
}

