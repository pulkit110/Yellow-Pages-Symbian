#include "YPagesForm.h"							// Include file for CYPagesForm
#include "YPagesForm1.h"							// Include file for CYPagesForm1
#include "YPages.hrh"						// Include file for App Uid
#include "eikedwin.h"
#include <AknPopupFieldText.h> 				// Include file for CAknPopupFieldText
#include <avkon.rsg> 						// Include file for R_AVKON_FORM_MENUPANE
#include <eikmenup.h> 						// Include file for CEikMenuPane
#include <aknnotewrappers.h> 				// Include file for CAknInformationNote
#include <f32file.h>						// Include file for file i/o
#include <s32file.h>						// Include file for file i/o

const TInt KNumCities=4;					// Constant for number of cities in app.

/*
 * Function to create a new object of CYPagesForm class.
 */
CYPagesForm* CYPagesForm::NewL(TDes& aText,TDes& aColor)
{
	CYPagesForm* self = new (ELeave) CYPagesForm(aText, aColor);
	CleanupStack::PushL(self);
	self->ConstructL();
	CleanupStack::Pop(self);
	return self;
}

/*
 * Constructor for CYPagesForm Class.
 * (Inherited from CAknForm)
 */
CYPagesForm::CYPagesForm(TDes& aText, TDes& aColor) : iText(aText),iColor(aColor)
{
}

/*
 * Initialize the Layout for the form.
 */
void CYPagesForm::PreLayoutDynInitL()
{
	TInt currCityIndex = 0;					// TInt for storing index of City.
   
	CAknPopupFieldText* popupFieldText = static_cast <CAknPopupFieldText*> (ControlOrNull(EYPagesPopup));
	if (popupFieldText) {
		popupFieldText->SetCurrentValueIndex (currCityIndex);
	}
}

/*	 
 * Initialize the MenuPane for the form.
 */
 void CYPagesForm::DynInitMenuPaneL(TInt aResourceId, CEikMenuPane* aMenuPane)
{
	CAknForm::DynInitMenuPaneL(aResourceId,aMenuPane);
	
	if (aResourceId == R_AVKON_FORM_MENUPANE) {
		aMenuPane->SetItemDimmed(EAknFormCmdLabel, ETrue);
		aMenuPane->SetItemDimmed(EAknFormCmdAdd, ETrue);
		aMenuPane->SetItemDimmed(EAknFormCmdDelete, ETrue);
		
	}
}
 
 /*
  * Save Form data, function to be executed when save option is selected. 
  * Creates the second form which allows for selecting the category.
  */
TBool CYPagesForm::SaveFormDataL()
{
    _LIT(KMessage,"Error!!");
	CAknPopupFieldText* popupFieldText = static_cast <CAknPopupFieldText*> (ControlOrNull(EYPagesPopup));
	
	if (popupFieldText) {
		if(popupFieldText->CurrentValueIndex()< KNumCities && popupFieldText->CurrentValueIndex()>=0 ) {
			TInt cityIndex;
			cityIndex = popupFieldText->CurrentValueIndex();
			
			CYPagesForm1* form = CYPagesForm1::NewL(iText,cityIndex);
			form->ExecuteLD(R_YPAGES_DIALOG_A);
		} else {
			iEikonEnv->AlertWin(KMessage);
		  }
	}
	
	return ETrue;
}
