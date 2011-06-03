#include <YPagesForm.rsg>
#include <akndialog.h>				// Include file for Dialog
#include <aknform.h>				// Include file for form
/*
 * CYPagesForm Class : This Class creates and manages the form for selecting city. 
 */
class CYPagesForm : public CAknForm {

	public:
		/*
		 * Function to create a new object of CYPagesForm class.
		 */
		static CYPagesForm* NewL(TDes& aText,TDes& aColor);

	private:
		/*
		 * Constructor for CYPagesForm Class.
		 * (Inherited from CAknForm)
		 */
		CYPagesForm(TDes& aText,TDes& aColor);
	    
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
		void PreLayoutDynInitL();

		TDes& iText;
		TDes& iColor;
};
