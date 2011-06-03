// YPages_view.cpp

#include "eikenv.h"
#include <coemain.h>
#include "YPagesAppView.h"

/*
 * Create a New Object of CYPagesView class
 */
CYPagesAppView* CYPagesAppView::NewL(const TRect& aRect)
{
    CYPagesAppView* self = CYPagesAppView::NewLC(aRect);
    CleanupStack::Pop(self);
    return self;
}

/*
 * Create a New Object of CYPagesView class and push it on the CleanUp Stack
 */
CYPagesAppView* CYPagesAppView::NewLC(const TRect& aRect)
{
    CYPagesAppView* self = new (ELeave) CYPagesAppView;
    CleanupStack::PushL(self);
    self->ConstructL(aRect);
    return self;
}

/*
 * Construct the window
 */
void CYPagesAppView::ConstructL(const TRect& aRect)
{
    CreateWindowL();
    SetRect(aRect);
    ActivateL();
}

/*
 * Draw the window
 */		
void CYPagesAppView::Draw(const TRect& ) const
{
    CWindowGc& gc = SystemGc();   
    const CFont*     font;
	TRect drawRect = Rect();
		
	gc.Clear();

	font = iEikonEnv->TitleFont();
	gc.UseFont(font);
	TInt   baselineOffset=(drawRect.Height() - font->HeightInPixels())/2;
	gc.SetPenColor(KRgbBlack);
	 
	gc.DrawText(iDisplayText,drawRect,baselineOffset,CGraphicsContext::ECenter, 0);
	
	gc.DiscardFont();
}
