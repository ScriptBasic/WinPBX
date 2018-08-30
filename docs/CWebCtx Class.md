# CWebCtx Class

Wrapper class to embed instances of the **WebBrowser** control in our application using an OLE Container (**CAxHost** class) to host it.

It also provides methods to connect and disconnect to the events fired by the **WebBrowser** control, set event handlers (pointers to callback procedures) for both the **DWebBrowser2** and **IDocHostUIHandler2** interfaces, a method to navigate to a URL, and function to get references to the OLE Container class and the **IWebBrowser2** interface.

The file **AfxExDisp.bi** provides declarations to call the methods of the **WebBrowser** interfaces using abstract methods.

The **WebBrowser** events sink class is provided in the file **CWebBrowserEvents.inc**, and the **DocHostUIHandler** events sink class is provided in the file **CDocHostUIHandler2.inc**.

**Include file**: CWebCtx.inc.

### CAXHOST_AMBIENTDISP Structure

Contains information the ambient properties of the **CAxHost** control.

```
TYPE CAXHOST_AMBIENTDISP
   Font AS IFontDisp PTR
   BackColor AS LONG = &hFFFFFF
   ForeColor AS LONG = 0
   LocaleID AS LONG = LOCALE_USER_DEFAULT
   Silent AS VARIANT_BOOL = -1
   UIDead AS VARIANT_BOOL = 0
   DisplayAsDefault AS VARIANT_BOOL = 0
   SupportMnemonics AS VARIANT_BOOL = -1
   OffLineIfNoConnected AS VARIANT_BOOL = -1
   DlCtFlags AS LONG = 0
END TYPE
```
