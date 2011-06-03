#include <eikdialg.h>

/*
 * The Application View Class : The root GUI control, this class implements the main window
 * and acts as a container for the other application controls.
 * 
 * Derived from CCoeControl
 */ 
class CYPagesAppView : public CCoeControl {
	public:
		/*
		 * Create a New Object of CYPagesView class
		 */
		static CYPagesAppView* NewL(const TRect& aRect);
		
		/*
		 * Create a New Object of CYPagesView class and push it on the CleanUp Stack
		 */
		static CYPagesAppView* CYPagesAppView::NewLC(const TRect& aRect);
		
		/*
		 * Construct the window
		 */
		void ConstructL(const TRect& aRect);

	private:
		/*
		 * Draw the window
		 */
		void Draw(const TRect&) const;
	public:
		TBuf<100> iDisplayText;
		TBuf<100> iTextColor;
};
