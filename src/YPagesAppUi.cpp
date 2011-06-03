// YPages_ui.cpp

#include "YPagesAppUi.h"
#include "YPagesForm.h"
#include "YPagesForm1.h"
#include <e32cons.h> 

/*
 * Construct an object of CYPagesAppView Class.
 */
void CYPagesAppUi::ConstructL()
{
    BaseConstructL(EAknEnableSkin);
	
    iAppView = CYPagesAppView::NewL(ClientRect());
	iCoeEnv->ReadResource(iAppView->iDisplayText,R_EXAMPLE_TEXT);  
}

/*
 * Destructor for CYPagesAppUi
 */
CYPagesAppUi::~CYPagesAppUi()
{
    delete iAppView;
}

/*
 * Function to handle commands sent from the application's GUI controls.
 */
void CYPagesAppUi::HandleCommandL(TInt aCommand)
{
    switch(aCommand)
    {
        case EAknSoftkeyExit:
		case EEikCmdExit:

            Exit();
            break;

        case EYPagesDialog:
            CYPagesForm* form = CYPagesForm::NewL(iAppView->iDisplayText,iAppView->iTextColor);
            form->ExecuteLD(R_YPAGES_DIALOG);
            break;
      default:
		; 								// Do nothing

    }
}

/*
 * Function to handle the change of layout.
 */
void CYPagesAppUi::HandleResourceChangeL( TInt aType )
{
    CAknAppUi::HandleResourceChangeL( aType );
    if ( aType==KEikDynamicLayoutVariantSwitch ) {
        iAppView->SetRect( ClientRect() );
    }
}
