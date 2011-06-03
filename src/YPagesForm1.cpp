// dialog.cpp

#include "YPagesForm.h"							// Include file for CYPagesForm
#include "YPagesForm1.h"							// Include file for CYPagesForm1
#include "YPages.hrh"						// Include file for App Uid
#include "eikedwin.h"
#include <AknPopupFieldText.h> 				// Include file for CAknPopupFieldText
#include <avkon.rsg> 						// Include file for R_AVKON_FORM_MENUPANE
#include <eikmenup.h> 						// Include file for CEikMenuPane
#include <aknmessagequerydialog.h> 			// Include file for CAknMessageQueryDialog
#include <aknnotewrappers.h> 				// Include file for CAknInformationNote
#include <f32file.h>						// Include file for file i/o
#include <s32file.h>						// Include file for file i/o

const TInt KNumCities=4;					// Constant for number of cities in app.

/*
 * Function to create a new object of CYPagesForm1 class.
 */
CYPagesForm1* CYPagesForm1::NewL(TDes& aText,TInt& aColor)
{
	CYPagesForm1* self = new (ELeave) CYPagesForm1(aText, aColor);
	CleanupStack::PushL(self);
	self->ConstructL();
	CleanupStack::Pop(self);
	return self;
}


/*
 * Constructor for CYPagesForm1 Class.
 * (Inherited from CAknForm)
 */
CYPagesForm1::CYPagesForm1(TDes& aText, TInt& aColor) : iText(aText),iColor(aColor)
{
}

/*
 * Initialize the Layout for the form1.
 */
void CYPagesForm1::PreLayoutDynInitL()
{    
    CAknPopupFieldText* popupFieldText = static_cast <CAknPopupFieldText*> (ControlOrNull(EYPagesPopup));
	if (popupFieldText)
	{
		popupFieldText->SetCurrentValueIndex (0);
	}	
}

/*	 
 * Initialize the MenuPane for the form.
 */
 void CYPagesForm1::DynInitMenuPaneL(TInt aResourceId, CEikMenuPane* aMenuPane)
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
 TBool CYPagesForm1::SaveFormDataL()
{  
    CAknPopupFieldText* popupFieldText = static_cast <CAknPopupFieldText*> (ControlOrNull(EYPagesPopup));
 	if (popupFieldText) {		
		TInt categoryIndex = popupFieldText->CurrentValueIndex();
		TBuf <30> KMyTextFile;
		KMyTextFile.Format(_L("D:\\YPages\\%d%d.txt"), iColor, categoryIndex);
		
		RFs fileServer;
 	    User :: LeaveIfError (fileServer.Connect());
 	    RFile file;
 	    User::LeaveIfError(file.Open(fileServer, KMyTextFile, EFileRead|EFileStreamText));
 	    CleanupClosePushL(file);
 	    
 	    TFileText fileText;
 	    fileText.Set(file);
 	    
 	    TBuf<100> buffer;
 	    buffer = _L("");

 	    RBuf rBuf;
 	    rBuf.Create(buffer);
 	    rBuf.CleanupClosePushL();
 	    
 	  
 	    TInt err = KErrNone;
 	    while(err != KErrEof) {
 			err = fileText.Read(buffer);
 	    
 			if ((err != KErrNone) && (err != KErrEof)) {
 				User :: Leave(err);
 			}
 			if (KErrNone == err) {
 				rBuf.ReAllocL(rBuf.Length() + buffer.Length()+2);
 				rBuf.Append(buffer);
 				rBuf.Append(_L("\n"));
 			}
 	    }
 	    CAknMessageQueryDialog* dlg = CAknMessageQueryDialog::NewL(rBuf);
 	    dlg->PrepareLC(R_ABOUT_HEADING_PANE);
   	    dlg->SetHeaderTextL(_L(""));  
   	    dlg->RunLD();
 	    		     
 	    CleanupStack::PopAndDestroy(&rBuf);
 	    CleanupStack::PopAndDestroy(&file);
 	    
 	    fileServer.Close();

 	
 	}

        

 	return ETrue;
 }
