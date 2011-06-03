// YPages_app.cpp

#include "YPagesApplication.h"

/*
 * Function to create a pointer to Document Class.
 */
CApaDocument* CYPagesApplication::CreateDocumentL()
{  
    return new(ELeave) CYPagesDocument(*this);
}

/*
 * Function to return the Uid
 */
TUid CYPagesApplication::AppDllUid() const
{
    return KUidYPagesApp;
}

