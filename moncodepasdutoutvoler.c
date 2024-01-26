#include "c:\TestComplete\Connected Apps\C++\script.h"
...
using namespace TestComplete;
void Test()
{
 /* We used the COleInit variable rather than
      the CoInitializeEx and CoUninitialize API functions. */
  COleInit g;

  var wrd;
  /* The GetObject method returns a reference to the desired COM server.
     It performs the actions, similar to those below:
      IDispatch * wrdVar;
      GUID WrdClass;
      CLSIDFromProgID(L"Word.Application", &WrdClass);
      CoCreateInstance(WrdClass, NULL, CLSCTX_LOCAL_SERVER, IID_IDispatch, (void **)&wrdVar);
      wrd = wrdVar; */
  wrd.GetObject(L"Word.Application");

 /* The following code performs some operations with the COM Server */
  wrd["Visible"] = true;
  wrd["Documents"]["Add"]();
  wrd["Selection"]["InsertAfter"]("Hello, world!");
}
