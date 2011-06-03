#include <eikon.hrh>
#include "YPages.hrh"
#include <aknappui.h>
#include "YPagesAppView.h"
#include <YPagesForm.rsg>

/*
 * The UI Class : This class instantiates the application view and handles the commands
 * sent from the application's GUI controls.
 * 
 * Derived from CAknAppUi 
 */
class CYPagesAppUi : public CAknAppUi {
	public:
		/*
		 * Construct an object of CYPagesAppView Class.
		 */
		void ConstructL();
		/*
		 * Destructor for CYPagesAppUi
		 */
		~CYPagesAppUi();

	protected:
		/*
		 * Function to handle the change of layout.
		 */
		void HandleResourceChangeL( TInt aType );

	private:
      
		/*
		 * Function to handle commands sent from the application's GUI controls.
		 */
		void HandleCommandL(TInt aCommand);
		CYPagesAppView* iAppView;			// Pointer to CYPagesAppView.
};
