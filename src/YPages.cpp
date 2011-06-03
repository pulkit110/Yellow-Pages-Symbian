// YPages.cpp

#include <eikstart.h>
#include "YPagesApplication.h"

// Create application object, return a pointer to it

EXPORT_C CApaApplication* NewApplication() 
{
    return (static_cast<CApaApplication*>(new CYPagesApplication));
}

// Executble entry point of application
GLDEF_C TInt E32Main()
{
	return EikStart::RunApplication( NewApplication );
}
