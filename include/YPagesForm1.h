#include <YPagesForm.rsg>
#include <akndialog.h>				// Include file for Dialog
#include <aknform.h>				// Include file for form
/*
 * CYPagesForm1 Class : This class creates and manages the form for selecting category.
 */
class CYPagesForm1 : public CAknForm {
	public:
		/*
		 * Function to create a new object of CYPagesForm class.
		 */
		static CYPagesForm1* NewL(TDes& aText,TInt& aColor);

	private:
		/*
		 * Constructor for CYPagesForm Class.
		 * (Inherited from CAknForm)
		 */
		CYPagesForm1(TDes& aText,TInt& aColor);
	    
		/*
		 * Initialize the MenuPane for the form.
		 */
		void DynInitMenuPaneL(TInt aResourceId, CEikMenuPane* aMenuPane);
		
		/*
		 * Save Form data, function to be executed when save option is selected. 
		 * Creates the second form which allows for selecting the category.
		 */
		TBool SaveFormDataL();
		
		/*
		 * Initialize the Layout for the form.
		 */
		void  PreLayoutDynInitL();
	
		TDes& iText;
		TInt& iColor;
};
