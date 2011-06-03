
#include <eikenv.h>

#include <eikon.hrh>
#include "YPages.hrh"
#include <aknapp.h>
#include "YPagesUid.h"
#include "YPagesDocument.h"

const TUid KUidYPagesApp = {YPAGESUID};					// Define the Uid for our Appp.

/*
 * The Application Class : The main application class that starts the application by
 * instantiating and starting the document class. It also set's the application's UID.
 * 
 * Derived from CAknApplication
 */ 

class CYPagesApplication : public CAknApplication {
private: 
    CApaDocument* CreateDocumentL();			// Function to create a pointer to Document Class.
    TUid AppDllUid() const;						// Function to return the Uid
};
