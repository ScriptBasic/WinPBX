' ########################################################################################
' Microsoft Windows
' File: System20.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: System
' Version: 2.0, Locale ID = 0
' Description: System
' Path: c:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\System.tlb
' Library GUID: {BEE4BFEC-6683-3E67-9167-3C0CBC68F40A}
' ########################################################################################

#INCLUDE THIS ONCE
%SYSTEM20_INC = 1

#INCLUDE ONCE "mscorlib20.inc"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {3E3F971A-A80D-3468-A9EB-3113CE46D13A}
$PROGID_SystemCodeArgumentReferenceExpression = "System.CodeDom.CodeArgumentReferenceExpression"
' CLSID = {24B3BCED-984A-340B-923C-C9B39D94D5A9}
$PROGID_SystemCodeArrayCreateExpression = "System.CodeDom.CodeArrayCreateExpression"
' CLSID = {8C0BC333-6F03-3228-8B5C-31C8627DAAB3}
$PROGID_SystemCodeArrayIndexerExpression = "System.CodeDom.CodeArrayIndexerExpression"
' CLSID = {E4350CAA-27C9-320E-AC79-71294ABDA592}
$PROGID_SystemCodeAssignStatement = "System.CodeDom.CodeAssignStatement"
' CLSID = {1AB6B26C-A339-3B51-9308-44CA3A05F873}
$PROGID_SystemCodeAttachEventStatement = "System.CodeDom.CodeAttachEventStatement"
' CLSID = {06E6FAA2-7623-396A-B9F1-75D31A17CF27}
$PROGID_SystemCodeAttributeArgument = "System.CodeDom.CodeAttributeArgument"
' CLSID = {424720CD-671F-329D-80DF-FA8BCD9EA9CD}
$PROGID_SystemCodeAttributeArgumentCollection = "System.CodeDom.CodeAttributeArgumentCollection"
' CLSID = {C0BA0202-2FF3-3E0A-952A-B570B1371DB2}
$PROGID_SystemCodeAttributeDeclaration = "System.CodeDom.CodeAttributeDeclaration"
' CLSID = {3A8E937E-C560-3779-A423-B645BAD276A1}
$PROGID_SystemCodeAttributeDeclarationCollection = "System.CodeDom.CodeAttributeDeclarationCollection"
' CLSID = {3A9E7044-FBD0-3E23-82AE-F0DFB86C0C4E}
$PROGID_SystemCodeBaseReferenceExpression = "System.CodeDom.CodeBaseReferenceExpression"
' CLSID = {30776C84-E88E-330D-8CE2-B5BF1E48427D}
$PROGID_SystemCodeBinaryOperatorExpression = "System.CodeDom.CodeBinaryOperatorExpression"
' CLSID = {DE2AE793-C1C1-3C33-8B9C-0D8F90301860}
$PROGID_SystemCodeCastExpression = "System.CodeDom.CodeCastExpression"
' CLSID = {548F7954-B3FD-39E0-9A30-9D8FC9443C0E}
$PROGID_SystemCodeCatchClause = "System.CodeDom.CodeCatchClause"
' CLSID = {2077ECF3-61C8-3CC5-9E45-721189A88E03}
$PROGID_SystemCodeCatchClauseCollection = "System.CodeDom.CodeCatchClauseCollection"
' CLSID = {E1845F73-C0CC-3B6B-B913-6E43F42D8BA1}
$PROGID_SystemCodeChecksumPragma = "System.CodeDom.CodeChecksumPragma"
' CLSID = {F3E7E9C5-E63A-3F3B-A4F8-096E82664819}
$PROGID_SystemCodeComment = "System.CodeDom.CodeComment"
' CLSID = {F69F43D6-EF83-3723-8839-519D2421E927}
$PROGID_SystemCodeCommentStatement = "System.CodeDom.CodeCommentStatement"
' CLSID = {C12A8292-F24A-3BA8-94E6-EB3206D225E2}
$PROGID_SystemCodeCommentStatementCollection = "System.CodeDom.CodeCommentStatementCollection"
' CLSID = {25A5D609-4D61-3C52-A3E1-49EF93066FD1}
$PROGID_SystemCodeCompileUnit = "System.CodeDom.CodeCompileUnit"
' CLSID = {1BA2DE2F-EE39-3628-968F-0E12705013C4}
$PROGID_SystemCodeConditionStatement = "System.CodeDom.CodeConditionStatement"
' CLSID = {2A7A02A4-408D-32C6-B5E2-BC4B57399B0C}
$PROGID_SystemCodeConstructor = "System.CodeDom.CodeConstructor"
' CLSID = {5AECB7A2-5797-3BFF-9B86-FC4CB9AE4F41}
$PROGID_SystemCodeDefaultValueExpression = "System.CodeDom.CodeDefaultValueExpression"
' CLSID = {92FB692E-211C-33DA-BE48-05B690D3F00B}
$PROGID_SystemCodeDelegateCreateExpression = "System.CodeDom.CodeDelegateCreateExpression"
' CLSID = {D79B10B1-16A3-3A23-A606-CE1227F3765A}
$PROGID_SystemCodeDelegateInvokeExpression = "System.CodeDom.CodeDelegateInvokeExpression"
' CLSID = {5FEA4BE0-D7FC-3DAF-877E-16F181F18BAE}
$PROGID_SystemCodeDirectionExpression = "System.CodeDom.CodeDirectionExpression"
' CLSID = {6B405F7D-01CA-3595-A65B-34CB0168ACA0}
$PROGID_SystemCodeDirective = "System.CodeDom.CodeDirective"
' CLSID = {ED78C3FA-AB56-353C-98BB-9280D3404C81}
$PROGID_SystemCodeDirectiveCollection = "System.CodeDom.CodeDirectiveCollection"
' CLSID = {DFF5C8A1-425F-305D-AE85-10C9DD7704C3}
$PROGID_SystemCodeEntryPointMethod = "System.CodeDom.CodeEntryPointMethod"
' CLSID = {E396945B-2690-377E-A992-12775D444CD7}
$PROGID_SystemCodeEventReferenceExpression = "System.CodeDom.CodeEventReferenceExpression"
' CLSID = {F4267FE0-72E6-34E2-9093-17DEA43078C1}
$PROGID_SystemCodeExpression = "System.CodeDom.CodeExpression"
' CLSID = {26D06C1F-81BA-33C3-BDE2-49747AA83A11}
$PROGID_SystemCodeExpressionCollection = "System.CodeDom.CodeExpressionCollection"
' CLSID = {ABC8FC89-D640-32FC-9E9F-04410010E5EC}
$PROGID_SystemCodeExpressionStatement = "System.CodeDom.CodeExpressionStatement"
' CLSID = {E2F01F29-A264-387B-AE29-A273AC89EEE7}
$PROGID_SystemCodeFieldReferenceExpression = "System.CodeDom.CodeFieldReferenceExpression"
' CLSID = {148E03E0-C74E-3D67-BD3A-B27995F9AC49}
$PROGID_SystemCodeGotoStatement = "System.CodeDom.CodeGotoStatement"
' CLSID = {4D19B9BB-0979-38BE-B438-29997E58C2D1}
$PROGID_SystemCodeIndexerExpression = "System.CodeDom.CodeIndexerExpression"
' CLSID = {421C8130-0316-3993-801D-E6BE3A159BAA}
$PROGID_SystemCodeIterationStatement = "System.CodeDom.CodeIterationStatement"
' CLSID = {4975B127-5464-3E9E-B4AA-D6DF3721189A}
$PROGID_SystemCodeLabeledStatement = "System.CodeDom.CodeLabeledStatement"
' CLSID = {17575EA6-BE56-381E-88E7-74B376743E77}
$PROGID_SystemCodeLinePragma = "System.CodeDom.CodeLinePragma"
' CLSID = {E401E3C7-2646-37C7-A37A-BA115D000FAA}
$PROGID_SystemCodeMemberEvent = "System.CodeDom.CodeMemberEvent"
' CLSID = {ACDCDF3A-21DC-37E3-9253-CD26CAEC0B58}
$PROGID_SystemCodeMemberField = "System.CodeDom.CodeMemberField"
' CLSID = {812E9B72-2CCC-364B-9EB8-DA8F4EAE724F}
$PROGID_SystemCodeMemberMethod = "System.CodeDom.CodeMemberMethod"
' CLSID = {D459C868-9174-353A-BB17-F2166E83FE24}
$PROGID_SystemCodeMemberProperty = "System.CodeDom.CodeMemberProperty"
' CLSID = {62AC67B4-2088-3DB7-9A80-154EFE9C6CAF}
$PROGID_SystemCodeMethodInvokeExpression = "System.CodeDom.CodeMethodInvokeExpression"
' CLSID = {36AE2637-C0A4-3214-8A93-AEE1CABD540E}
$PROGID_SystemCodeMethodReferenceExpression = "System.CodeDom.CodeMethodReferenceExpression"
' CLSID = {031A6B24-BFAA-3D76-B6DA-59C9C469A0FB}
$PROGID_SystemCodeMethodReturnStatement = "System.CodeDom.CodeMethodReturnStatement"
' CLSID = {D4985194-80E5-36FE-8B95-8CD2E35E5FF5}
$PROGID_SystemCodeNamespaceCollection = "System.CodeDom.CodeNamespaceCollection"
' CLSID = {7A168834-5605-30DB-8274-6B21E621A955}
$PROGID_SystemCodeNamespaceImportCollection = "System.CodeDom.CodeNamespaceImportCollection"
' CLSID = {88D0C986-398A-3A31-9349-B0736357C40B}
$PROGID_SystemCodeObject = "System.CodeDom.CodeObject"
' CLSID = {F3BA98C3-39CF-3C2D-ADA5-75BD63D7AF08}
$PROGID_SystemCodeObjectCreateExpression = "System.CodeDom.CodeObjectCreateExpression"
' CLSID = {7FD9E7C0-B133-302F-A3A1-42167780CB62}
$PROGID_SystemCodeParameterDeclarationExpressionCollection = "System.CodeDom.CodeParameterDeclarationExpressionCollection"
' CLSID = {6C1E6791-0558-3CD3-AAB8-C90A2B03EF5F}
$PROGID_SystemCodePrimitiveExpression = "System.CodeDom.CodePrimitiveExpression"
' CLSID = {9703F066-9C59-32C4-86B2-570E97AB75F2}
$PROGID_SystemCodePropertyReferenceExpression = "System.CodeDom.CodePropertyReferenceExpression"
' CLSID = {395C1A4D-AABB-3415-B527-8CB694777B84}
$PROGID_SystemCodePropertySetValueReferenceExpression = "System.CodeDom.CodePropertySetValueReferenceExpression"
' CLSID = {932861EC-65C4-30F0-905D-905B9CE98979}
$PROGID_SystemCodeRegionDirective = "System.CodeDom.CodeRegionDirective"
' CLSID = {F38B3709-9B63-32E6-9CFB-07991C40717F}
$PROGID_SystemCodeRemoveEventStatement = "System.CodeDom.CodeRemoveEventStatement"
' CLSID = {AF2DF285-73D3-3623-AEAB-1CDBCF75A9D0}
$PROGID_SystemCodeSnippetCompileUnit = "System.CodeDom.CodeSnippetCompileUnit"
' CLSID = {509AF058-A0E5-32E6-AE00-15F8209D31F9}
$PROGID_SystemCodeSnippetExpression = "System.CodeDom.CodeSnippetExpression"
' CLSID = {880287BC-D3A4-3113-B8D1-6538B7C19E97}
$PROGID_SystemCodeSnippetStatement = "System.CodeDom.CodeSnippetStatement"
' CLSID = {0FAC5DAB-AD52-38BF-854E-FD3059369C44}
$PROGID_SystemCodeSnippetTypeMember = "System.CodeDom.CodeSnippetTypeMember"
' CLSID = {10A98D9F-994D-3762-89B4-2116A95063EE}
$PROGID_SystemCodeStatement = "System.CodeDom.CodeStatement"
' CLSID = {A531374E-FA08-36C6-AF96-31C684EEFC08}
$PROGID_SystemCodeStatementCollection = "System.CodeDom.CodeStatementCollection"
' CLSID = {21206362-562F-3F08-8F06-4BCFD2C95F29}
$PROGID_SystemCodeThisReferenceExpression = "System.CodeDom.CodeThisReferenceExpression"
' CLSID = {A2F81DED-8536-3C27-9759-BA3EAC94D0A2}
$PROGID_SystemCodeThrowExceptionStatement = "System.CodeDom.CodeThrowExceptionStatement"
' CLSID = {CB3BF2D6-DB22-31DF-A6F4-E3707972E10C}
$PROGID_SystemCodeTryCatchFinallyStatement = "System.CodeDom.CodeTryCatchFinallyStatement"
' CLSID = {7544623F-E6DE-3918-9E10-29AAF16E560B}
$PROGID_SystemCodeTypeConstructor = "System.CodeDom.CodeTypeConstructor"
' CLSID = {A0BD9913-B07D-32C3-8DF1-AA998B3FB10E}
$PROGID_SystemCodeTypeDeclarationCollection = "System.CodeDom.CodeTypeDeclarationCollection"
' CLSID = {6FBC1E34-565D-3721-B5C0-5C796540481F}
$PROGID_SystemCodeTypeDelegate = "System.CodeDom.CodeTypeDelegate"
' CLSID = {69DCE654-E184-38E5-BFD6-E0EB6F592A11}
$PROGID_SystemCodeTypeMember = "System.CodeDom.CodeTypeMember"
' CLSID = {85D435C5-7AF6-30E9-8A0B-C978737C2849}
$PROGID_SystemCodeTypeMemberCollection = "System.CodeDom.CodeTypeMemberCollection"
' CLSID = {FB6A595A-B5DD-3361-8842-70E806D73573}
$PROGID_SystemCodeTypeOfExpression = "System.CodeDom.CodeTypeOfExpression"
' CLSID = {6019C9D4-84CB-33BC-9E79-25F21172C33B}
$PROGID_SystemCodeTypeParameterCollection = "System.CodeDom.CodeTypeParameterCollection"
' CLSID = {F3DE25AC-25ED-374C-8805-4B6456FA0CB2}
$PROGID_SystemCodeTypeReference = "System.CodeDom.CodeTypeReference"
' CLSID = {3F2E333C-9A04-33AC-95C7-7B0015BEB345}
$PROGID_SystemCodeTypeReferenceCollection = "System.CodeDom.CodeTypeReferenceCollection"
' CLSID = {8871C106-C8BA-37A0-ADE2-E4AEBEC7E3C9}
$PROGID_SystemCodeTypeReferenceExpression = "System.CodeDom.CodeTypeReferenceExpression"
' CLSID = {943B4474-D661-344E-AD1B-1A1F3C8EA01A}
$PROGID_SystemCodeVariableDeclarationStatement = "System.CodeDom.CodeVariableDeclarationStatement"
' CLSID = {39ABD141-93AE-397A-9E98-6F2E50124CEC}
$PROGID_SystemCodeVariableReferenceExpression = "System.CodeDom.CodeVariableReferenceExpression"
' CLSID = {B3B21824-D0F3-3815-847F-228660E2A20E}
$PROGID_Systemcomponent = "System.ComponentModel.Component"
' CLSID = {67114ED5-9F2A-3A0A-8C7A-746FDA064488}
$PROGID_SystemDesignerVerbCollection = "System.ComponentModel.Design.DesignerVerbCollection"
' CLSID = {F3FA95A9-C5F9-3EF9-80C6-91275015C770}
$PROGID_SystemMarshalByValueComponent = "System.ComponentModel.MarshalByValueComponent"
' CLSID = {75992C48-BF7A-3B44-AC68-A946CFFDB2BF}
$PROGID_SystemTypeConverter = "System.ComponentModel.TypeConverter"
' CLSID = {82840BE1-D273-11D2-B94A-00600893B17A}
$PROGID_SystemPerformanceCounterManager = "System.Diagnostics.PerformanceCounterManager"
' CLSID = {7D458845-B4B8-30CB-B2AD-FC4960FCDF81}
$PROGID_SystemWebClient = "System.Net.WebClient"
' CLSID = {430D1273-C3E9-3632-9988-389C81849C00}
$PROGID_SystemWebHeaderCollection = "System.Net.WebHeaderCollection"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_SystemAttributeCollection = GUID$("{4309D526-F739-3BE3-B89C-4F6DDE852C14}")
$CLSID_SystemCodeDomProvider = GUID$("{5FAD3639-1A4D-3BDC-A4A5-C59E36165F5B}")
$CLSID_SystemCodeNamespace = GUID$("{DD1C0C7A-BC95-339A-8321-9DBF4803CAF4}")
$CLSID_SystemCodeNamespaceImport = GUID$("{B0B32470-44A6-3DBC-BDB2-CE024F966088}")
$CLSID_SystemCodeParameterDeclarationExpression = GUID$("{6ACD3B02-EF29-31B9-8958-45B47BAD4A00}")
$CLSID_SystemCodeTypeDeclaration = GUID$("{2B708A48-52D8-3049-9565-6BA42EE2BE17}")
$CLSID_SystemCodeTypeParameter = GUID$("{E5E30108-7A5B-398F-B50C-09793C6299E1}")
$CLSID_SystemCommandID = GUID$("{E60178F7-1512-389F-9CA6-084DF14CF596}")
$CLSID_SystemComponentChangedEventArgs = GUID$("{06CBA6E8-112A-32BA-A7BF-7DCFE0404931}")
$CLSID_SystemComponentChangedEventHandler = GUID$("{01157188-EB62-312D-AEA6-14332A2AEBF9}")
$CLSID_SystemComponentChangingEventArgs = GUID$("{834C5649-9074-33F5-AB36-716D4AE08E9E}")
$CLSID_SystemComponentChangingEventHandler = GUID$("{D296EB38-ADD4-3FBE-8CF5-03CBD74DDB74}")
$CLSID_SystemComponentCollection = GUID$("{9653003F-5A61-33CB-86E6-1BA38CED5DF8}")
$CLSID_SystemComponentEventArgs = GUID$("{CB919E0F-1205-37EC-AC02-38B51390629F}")
$CLSID_SystemComponentEventHandler = GUID$("{C001B07F-6B98-359A-8F0A-652F82BD81E1}")
$CLSID_SystemComponentRenameEventArgs = GUID$("{F41E1B27-1C7C-3620-9662-BF72882E3F7E}")
$CLSID_SystemComponentRenameEventHandler = GUID$("{819762B6-DC8A-3A36-B063-82BC2EE44168}")
$CLSID_SystemDesignerLoader = GUID$("{AD44E49C-2DED-33BD-83A6-9EB9C6C66F39}")
$CLSID_SystemDesignerTransactionCloseEventArgs = GUID$("{C5D1EAB9-E039-399E-A709-9A0A7107A610}")
$CLSID_SystemDesignerTransactionCloseEventHandler = GUID$("{54BF09CE-0DB6-3D92-AA2D-546AD897EF59}")
$CLSID_SystemDesignerVerb = GUID$("{5231CCD9-DABB-3FDE-AD29-8FD3D382C248}")
$CLSID_SystemEventDescriptor = GUID$("{52964536-AFDA-35C2-8C8B-903C2519AD4E}")
$CLSID_SystemEventDescriptorCollection = GUID$("{C657A06C-7655-32F7-8CC8-9A3BDC803487}")
$CLSID_SystemMemberDescriptor = GUID$("{670B0D04-DAD1-39A7-9043-B0B58CCB46E6}")
$CLSID_SystemMenuCommand = GUID$("{5C719461-3A18-33D0-B3E1-33F169085C21}")
$CLSID_SystemPropertyDescriptor = GUID$("{D40E4E6F-4692-3438-B4CC-7E423473B2C1}")
$CLSID_SystemServiceCreatorCallback = GUID$("{E90ADE71-CAC0-3F72-834E-CD39F93670EE}")
$CLSID_SystemStandardOleMarshalObject = GUID$("{0EF62602-E19F-3DF5-BE17-A43AAF6BA008}")
$CLSID_SystemCodeArgumentReferenceExpression = GUID$("{3E3F971A-A80D-3468-A9EB-3113CE46D13A}")
$CLSID_SystemCodeArrayCreateExpression = GUID$("{24B3BCED-984A-340B-923C-C9B39D94D5A9}")
$CLSID_SystemCodeArrayIndexerExpression = GUID$("{8C0BC333-6F03-3228-8B5C-31C8627DAAB3}")
$CLSID_SystemCodeAssignStatement = GUID$("{E4350CAA-27C9-320E-AC79-71294ABDA592}")
$CLSID_SystemCodeAttachEventStatement = GUID$("{1AB6B26C-A339-3B51-9308-44CA3A05F873}")
$CLSID_SystemCodeAttributeArgument = GUID$("{06E6FAA2-7623-396A-B9F1-75D31A17CF27}")
$CLSID_SystemCodeAttributeArgumentCollection = GUID$("{424720CD-671F-329D-80DF-FA8BCD9EA9CD}")
$CLSID_SystemCodeAttributeDeclaration = GUID$("{C0BA0202-2FF3-3E0A-952A-B570B1371DB2}")
$CLSID_SystemCodeAttributeDeclarationCollection = GUID$("{3A8E937E-C560-3779-A423-B645BAD276A1}")
$CLSID_SystemCodeBaseReferenceExpression = GUID$("{3A9E7044-FBD0-3E23-82AE-F0DFB86C0C4E}")
$CLSID_SystemCodeBinaryOperatorExpression = GUID$("{30776C84-E88E-330D-8CE2-B5BF1E48427D}")
$CLSID_SystemCodeCastExpression = GUID$("{DE2AE793-C1C1-3C33-8B9C-0D8F90301860}")
$CLSID_SystemCodeCatchClause = GUID$("{548F7954-B3FD-39E0-9A30-9D8FC9443C0E}")
$CLSID_SystemCodeCatchClauseCollection = GUID$("{2077ECF3-61C8-3CC5-9E45-721189A88E03}")
$CLSID_SystemCodeChecksumPragma = GUID$("{E1845F73-C0CC-3B6B-B913-6E43F42D8BA1}")
$CLSID_SystemCodeComment = GUID$("{F3E7E9C5-E63A-3F3B-A4F8-096E82664819}")
$CLSID_SystemCodeCommentStatement = GUID$("{F69F43D6-EF83-3723-8839-519D2421E927}")
$CLSID_SystemCodeCommentStatementCollection = GUID$("{C12A8292-F24A-3BA8-94E6-EB3206D225E2}")
$CLSID_SystemCodeCompileUnit = GUID$("{25A5D609-4D61-3C52-A3E1-49EF93066FD1}")
$CLSID_SystemCodeConditionStatement = GUID$("{1BA2DE2F-EE39-3628-968F-0E12705013C4}")
$CLSID_SystemCodeConstructor = GUID$("{2A7A02A4-408D-32C6-B5E2-BC4B57399B0C}")
$CLSID_SystemCodeDefaultValueExpression = GUID$("{5AECB7A2-5797-3BFF-9B86-FC4CB9AE4F41}")
$CLSID_SystemCodeDelegateCreateExpression = GUID$("{92FB692E-211C-33DA-BE48-05B690D3F00B}")
$CLSID_SystemCodeDelegateInvokeExpression = GUID$("{D79B10B1-16A3-3A23-A606-CE1227F3765A}")
$CLSID_SystemCodeDirectionExpression = GUID$("{5FEA4BE0-D7FC-3DAF-877E-16F181F18BAE}")
$CLSID_SystemCodeDirective = GUID$("{6B405F7D-01CA-3595-A65B-34CB0168ACA0}")
$CLSID_SystemCodeDirectiveCollection = GUID$("{ED78C3FA-AB56-353C-98BB-9280D3404C81}")
$CLSID_SystemCodeEntryPointMethod = GUID$("{DFF5C8A1-425F-305D-AE85-10C9DD7704C3}")
$CLSID_SystemCodeEventReferenceExpression = GUID$("{E396945B-2690-377E-A992-12775D444CD7}")
$CLSID_SystemCodeExpression = GUID$("{F4267FE0-72E6-34E2-9093-17DEA43078C1}")
$CLSID_SystemCodeExpressionCollection = GUID$("{26D06C1F-81BA-33C3-BDE2-49747AA83A11}")
$CLSID_SystemCodeExpressionStatement = GUID$("{ABC8FC89-D640-32FC-9E9F-04410010E5EC}")
$CLSID_SystemCodeFieldReferenceExpression = GUID$("{E2F01F29-A264-387B-AE29-A273AC89EEE7}")
$CLSID_SystemCodeGotoStatement = GUID$("{148E03E0-C74E-3D67-BD3A-B27995F9AC49}")
$CLSID_SystemCodeIndexerExpression = GUID$("{4D19B9BB-0979-38BE-B438-29997E58C2D1}")
$CLSID_SystemCodeIterationStatement = GUID$("{421C8130-0316-3993-801D-E6BE3A159BAA}")
$CLSID_SystemCodeLabeledStatement = GUID$("{4975B127-5464-3E9E-B4AA-D6DF3721189A}")
$CLSID_SystemCodeLinePragma = GUID$("{17575EA6-BE56-381E-88E7-74B376743E77}")
$CLSID_SystemCodeMemberEvent = GUID$("{E401E3C7-2646-37C7-A37A-BA115D000FAA}")
$CLSID_SystemCodeMemberField = GUID$("{ACDCDF3A-21DC-37E3-9253-CD26CAEC0B58}")
$CLSID_SystemCodeMemberMethod = GUID$("{812E9B72-2CCC-364B-9EB8-DA8F4EAE724F}")
$CLSID_SystemCodeMemberProperty = GUID$("{D459C868-9174-353A-BB17-F2166E83FE24}")
$CLSID_SystemCodeMethodInvokeExpression = GUID$("{62AC67B4-2088-3DB7-9A80-154EFE9C6CAF}")
$CLSID_SystemCodeMethodReferenceExpression = GUID$("{36AE2637-C0A4-3214-8A93-AEE1CABD540E}")
$CLSID_SystemCodeMethodReturnStatement = GUID$("{031A6B24-BFAA-3D76-B6DA-59C9C469A0FB}")
$CLSID_SystemCodeNamespaceCollection = GUID$("{D4985194-80E5-36FE-8B95-8CD2E35E5FF5}")
$CLSID_SystemCodeNamespaceImportCollection = GUID$("{7A168834-5605-30DB-8274-6B21E621A955}")
$CLSID_SystemCodeObject = GUID$("{88D0C986-398A-3A31-9349-B0736357C40B}")
$CLSID_SystemCodeObjectCreateExpression = GUID$("{F3BA98C3-39CF-3C2D-ADA5-75BD63D7AF08}")
$CLSID_SystemCodeParameterDeclarationExpressionCollection = GUID$("{7FD9E7C0-B133-302F-A3A1-42167780CB62}")
$CLSID_SystemCodePrimitiveExpression = GUID$("{6C1E6791-0558-3CD3-AAB8-C90A2B03EF5F}")
$CLSID_SystemCodePropertyReferenceExpression = GUID$("{9703F066-9C59-32C4-86B2-570E97AB75F2}")
$CLSID_SystemCodePropertySetValueReferenceExpression = GUID$("{395C1A4D-AABB-3415-B527-8CB694777B84}")
$CLSID_SystemCodeRegionDirective = GUID$("{932861EC-65C4-30F0-905D-905B9CE98979}")
$CLSID_SystemCodeRemoveEventStatement = GUID$("{F38B3709-9B63-32E6-9CFB-07991C40717F}")
$CLSID_SystemCodeSnippetCompileUnit = GUID$("{AF2DF285-73D3-3623-AEAB-1CDBCF75A9D0}")
$CLSID_SystemCodeSnippetExpression = GUID$("{509AF058-A0E5-32E6-AE00-15F8209D31F9}")
$CLSID_SystemCodeSnippetStatement = GUID$("{880287BC-D3A4-3113-B8D1-6538B7C19E97}")
$CLSID_SystemCodeSnippetTypeMember = GUID$("{0FAC5DAB-AD52-38BF-854E-FD3059369C44}")
$CLSID_SystemCodeStatement = GUID$("{10A98D9F-994D-3762-89B4-2116A95063EE}")
$CLSID_SystemCodeStatementCollection = GUID$("{A531374E-FA08-36C6-AF96-31C684EEFC08}")
$CLSID_SystemCodeThisReferenceExpression = GUID$("{21206362-562F-3F08-8F06-4BCFD2C95F29}")
$CLSID_SystemCodeThrowExceptionStatement = GUID$("{A2F81DED-8536-3C27-9759-BA3EAC94D0A2}")
$CLSID_SystemCodeTryCatchFinallyStatement = GUID$("{CB3BF2D6-DB22-31DF-A6F4-E3707972E10C}")
$CLSID_SystemCodeTypeConstructor = GUID$("{7544623F-E6DE-3918-9E10-29AAF16E560B}")
$CLSID_SystemCodeTypeDeclarationCollection = GUID$("{A0BD9913-B07D-32C3-8DF1-AA998B3FB10E}")
$CLSID_SystemCodeTypeDelegate = GUID$("{6FBC1E34-565D-3721-B5C0-5C796540481F}")
$CLSID_SystemCodeTypeMember = GUID$("{69DCE654-E184-38E5-BFD6-E0EB6F592A11}")
$CLSID_SystemCodeTypeMemberCollection = GUID$("{85D435C5-7AF6-30E9-8A0B-C978737C2849}")
$CLSID_SystemCodeTypeOfExpression = GUID$("{FB6A595A-B5DD-3361-8842-70E806D73573}")
$CLSID_SystemCodeTypeParameterCollection = GUID$("{6019C9D4-84CB-33BC-9E79-25F21172C33B}")
$CLSID_SystemCodeTypeReference = GUID$("{F3DE25AC-25ED-374C-8805-4B6456FA0CB2}")
$CLSID_SystemCodeTypeReferenceCollection = GUID$("{3F2E333C-9A04-33AC-95C7-7B0015BEB345}")
$CLSID_SystemCodeTypeReferenceExpression = GUID$("{8871C106-C8BA-37A0-ADE2-E4AEBEC7E3C9}")
$CLSID_SystemCodeVariableDeclarationStatement = GUID$("{943B4474-D661-344E-AD1B-1A1F3C8EA01A}")
$CLSID_SystemCodeVariableReferenceExpression = GUID$("{39ABD141-93AE-397A-9E98-6F2E50124CEC}")
$CLSID_Systemcomponent = GUID$("{B3B21824-D0F3-3815-847F-228660E2A20E}")
$CLSID_SystemDesignerVerbCollection = GUID$("{67114ED5-9F2A-3A0A-8C7A-746FDA064488}")
$CLSID_SystemMarshalByValueComponent = GUID$("{F3FA95A9-C5F9-3EF9-80C6-91275015C770}")
$CLSID_SystemTypeConverter = GUID$("{75992C48-BF7A-3B44-AC68-A946CFFDB2BF}")
$CLSID_SystemPerformanceCounterManager = GUID$("{82840BE1-D273-11D2-B94A-00600893B17A}")
$CLSID_SystemWebClient = GUID$("{7D458845-B4B8-30CB-B2AD-FC4960FCDF81}")
$CLSID_SystemWebHeaderCollection = GUID$("{430D1273-C3E9-3632-9988-389C81849C00}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_SystemIComponent = GUID$("{B86E59F2-F1E2-389D-B5F1-C55307C8106E}")
$IID_SystemIComponentChangeService = GUID$("{2FEF0210-9EBD-32C0-9BFD-24841AC0FCF7}")
$IID_SystemIContainer = GUID$("{61D9C50C-4AAD-3539-AF82-4F36C19D77C8}")
$IID_SystemIDesigner = GUID$("{6EEF3D0D-305A-3DF4-9830-8C2B40E1C4BF}")
$IID_SystemIDesignerHost = GUID$("{EEC98CD8-EF5B-3B60-82C9-86F616F6BB20}")
$IID_SystemIEventBindingService = GUID$("{1A19D89E-F4FE-3E8E-B7EC-05D4E592F3F6}")
$IID_SystemIMenuCommandService = GUID$("{DF651C5D-783E-3789-901F-A962B7587E69}")
$IID_SystemIRootDesigner = GUID$("{2CC5E562-6C14-34A6-9D0B-E6FF949AE8FB}")
$IID_SystemISelectionService = GUID$("{297A65BE-5080-3F7F-AD19-B0D05D6F2327}")
$IID_SystemIServiceContainer = GUID$("{6BA96B42-7FDD-3223-BF52-7FE677B92815}")
$IID_SystemISite = GUID$("{C4E1006A-9D98-3E96-A07E-921725135C28}")
$IID_SystemITypeDescriptorContext = GUID$("{5CBAE170-8759-3B8A-B919-E12FB86AD1F3}")
$IID__SystemAttributeCollection = GUID$("{6F971E04-B06A-3DD0-B6F5-622826693454}")
$IID__SystemCodeArgumentReferenceExpression = GUID$("{A52B85C6-5370-35C9-A04A-04A92013862C}")
$IID__SystemCodeArrayCreateExpression = GUID$("{F7955E55-7F3B-3277-AA0C-F62AA615676D}")
$IID__SystemCodeArrayIndexerExpression = GUID$("{732748F5-5256-327B-A7E5-2000B07F21B3}")
$IID__SystemCodeAssignStatement = GUID$("{E2024DE0-DC21-305D-8761-6C31F2177FB0}")
$IID__SystemCodeAttachEventStatement = GUID$("{F7BC47E9-706C-3AA7-B1BA-8AB95188FA11}")
$IID__SystemCodeAttributeArgument = GUID$("{02EFD952-FF8C-3B72-8C33-739A506D53D9}")
$IID__SystemCodeAttributeArgumentCollection = GUID$("{FE84E484-A7EC-3D15-B5E2-EDC2DE2DB42E}")
$IID__SystemCodeAttributeDeclaration = GUID$("{EF72D021-2C6D-3E33-9442-574BFD6E0871}")
$IID__SystemCodeAttributeDeclarationCollection = GUID$("{7E9ACA22-637C-3F88-A931-AAF36A4F9A6B}")
$IID__SystemCodeBaseReferenceExpression = GUID$("{45E29CA6-670A-3B13-9557-4E5903056BF3}")
$IID__SystemCodeBinaryOperatorExpression = GUID$("{A22929C9-D301-3F5B-98B7-844FDBA1DEDF}")
$IID__SystemCodeCastExpression = GUID$("{90BED8ED-21E3-31FE-8F02-C929BA4FB0AC}")
$IID__SystemCodeCatchClause = GUID$("{609C7788-BDB0-364C-92E3-FC16AC613430}")
$IID__SystemCodeCatchClauseCollection = GUID$("{FF5E1CD9-0478-34A4-9B9C-7C80BCB1A725}")
$IID__SystemCodeChecksumPragma = GUID$("{7EB20114-E822-358C-BDAB-DCF9E5090F23}")
$IID__SystemCodeComment = GUID$("{C94F39B3-436F-3711-9CB0-91C6299B62A2}")
$IID__SystemCodeCommentStatement = GUID$("{0C13F8B9-F2E0-3918-A33E-3E491BDC529E}")
$IID__SystemCodeCommentStatementCollection = GUID$("{E34CEB72-8F86-333D-AEDA-069221DF6A1A}")
$IID__SystemCodeCompileUnit = GUID$("{6F20C263-AF67-380F-A482-9A21F7599748}")
$IID__SystemCodeConditionStatement = GUID$("{69904B31-5FB5-39BF-83B0-5DDFA1F26D71}")
$IID__SystemCodeConstructor = GUID$("{5A33C771-806E-337D-AE1F-66B523FC49BF}")
$IID__SystemCodeDefaultValueExpression = GUID$("{EA9E1DD2-EF9A-3570-AE1A-2F625F594C3B}")
$IID__SystemCodeDelegateCreateExpression = GUID$("{D14E12C1-E1D1-3B74-A3AF-021A5A268FBE}")
$IID__SystemCodeDelegateInvokeExpression = GUID$("{6F6C3482-8900-36EA-B621-943534E82C73}")
$IID__SystemCodeDirectionExpression = GUID$("{11EDAF3B-144E-32C8-8BE0-81D40A950656}")
$IID__SystemCodeDirective = GUID$("{767E752E-2315-35CF-9652-7FC46AE870D3}")
$IID__SystemCodeDirectiveCollection = GUID$("{EEFBDD27-4904-3E90-ACFC-624164CB45DD}")
$IID__SystemCodeDomProvider = GUID$("{61059E8D-1DD2-3F4B-A4C5-D566B8968FFB}")
$IID__SystemCodeEntryPointMethod = GUID$("{7CD4EF19-27EB-399E-8ED2-C6647A99C03E}")
$IID__SystemCodeEventReferenceExpression = GUID$("{35872687-5A11-34D7-85AB-865830A3BDEE}")
$IID__SystemCodeExpression = GUID$("{AD377794-864F-3421-9FB8-C684BBC1BC02}")
$IID__SystemCodeExpressionCollection = GUID$("{AF72CC74-2275-362A-9141-A4A79D596F39}")
$IID__SystemCodeExpressionStatement = GUID$("{CEA240AF-60C5-3C69-9DA1-DA3F9A6D7B3C}")
$IID__SystemCodeFieldReferenceExpression = GUID$("{82D57B2B-C639-32A0-89B4-62A0C29DD64E}")
$IID__SystemCodeGotoStatement = GUID$("{8F1BAED9-52EC-3545-9CF0-6ED71A76A5CA}")
$IID__SystemCodeIndexerExpression = GUID$("{C92C323F-8601-34D4-A2D6-F5E2653DB456}")
$IID__SystemCodeIterationStatement = GUID$("{B16F7137-C0E7-3ECF-9652-FB1EA947E44E}")
$IID__SystemCodeLabeledStatement = GUID$("{56699CCA-FD8D-3AD2-9643-149BAD87FD60}")
$IID__SystemCodeLinePragma = GUID$("{1B52DED6-92F3-3B4F-851C-AB1F647582A3}")
$IID__SystemCodeMemberEvent = GUID$("{E1A7EA9F-5D43-3FA9-AFBC-9A2BFDA84B65}")
$IID__SystemCodeMemberField = GUID$("{EEF50D17-7AA6-3E14-96C6-DD90FE5BAA1E}")
$IID__SystemCodeMemberMethod = GUID$("{95C2EE26-4247-3DDC-8056-97353F10DE8F}")
$IID__SystemCodeMemberProperty = GUID$("{802E2ACC-A7F8-3CA9-9114-F49998BEBE6E}")
$IID__SystemCodeMethodInvokeExpression = GUID$("{FFE1F142-85CF-3353-8512-EE73775E9C4C}")
$IID__SystemCodeMethodReferenceExpression = GUID$("{CBDF02F4-A9F4-33C0-8B24-275008890DCB}")
$IID__SystemCodeMethodReturnStatement = GUID$("{851D821B-1E0C-3E91-832D-BA593523F566}")
$IID__SystemCodeNamespace = GUID$("{31ED1DCB-C007-3F96-8809-4D5E3540A7C1}")
$IID__SystemCodeNamespaceCollection = GUID$("{F5E54F16-ADE3-3B5D-8B05-1F9803557905}")
$IID__SystemCodeNamespaceImport = GUID$("{34418787-726B-3E74-AEED-C01397FC707D}")
$IID__SystemCodeNamespaceImportCollection = GUID$("{4C545457-76D7-3C56-B277-6A9E86D1046F}")
$IID__SystemCodeObject = GUID$("{EE499EFD-22E2-3740-A64A-2AB010099C01}")
$IID__SystemCodeObjectCreateExpression = GUID$("{CFE5E5E9-745F-348B-A7E6-38A46D1A20E0}")
$IID__SystemCodeParameterDeclarationExpression = GUID$("{EE96565B-2B1A-33C6-BA07-B63158F1C8C4}")
$IID__SystemCodeParameterDeclarationExpressionCollection = GUID$("{05192769-7D6A-3C8C-94C2-DFA668F61088}")
$IID__SystemCodePrimitiveExpression = GUID$("{175BB49A-4CBE-38B3-8C6C-1B0145EDABB7}")
$IID__SystemCodePropertyReferenceExpression = GUID$("{F8D64802-F9B7-3095-A641-D31E6E9F87B1}")
$IID__SystemCodePropertySetValueReferenceExpression = GUID$("{2EE13FA1-8A02-3573-9AC9-4FEBD2CEAB45}")
$IID__SystemCodeRegionDirective = GUID$("{26AE5CC6-CCFD-3906-8B68-16E5EEFABB10}")
$IID__SystemCodeRemoveEventStatement = GUID$("{853BC437-CA6E-375D-BCBB-818E917D9691}")
$IID__SystemCodeSnippetCompileUnit = GUID$("{C7D34CF6-CF82-38B0-BF67-EB36DA63AE6E}")
$IID__SystemCodeSnippetExpression = GUID$("{9F3E3CD1-8082-31E9-851C-3E177E56A87B}")
$IID__SystemCodeSnippetStatement = GUID$("{B4B00613-C48B-3FA9-B8F6-A527EC6F21C3}")
$IID__SystemCodeSnippetTypeMember = GUID$("{575BF8D0-7A9D-39EB-81F9-AA2BEBA890FA}")
$IID__SystemCodeStatement = GUID$("{B125774D-EF66-382B-878D-2D916999B0D2}")
$IID__SystemCodeStatementCollection = GUID$("{4B9A5032-4B8C-3DE6-997C-C38B4B3AF26A}")
$IID__SystemCodeThisReferenceExpression = GUID$("{3B4A1A6B-8E65-355D-B93A-E6AB753B2401}")
$IID__SystemCodeThrowExceptionStatement = GUID$("{12350E95-6F4E-30F0-9343-72F1C64380A0}")
$IID__SystemCodeTryCatchFinallyStatement = GUID$("{8FD0F76A-29BF-3982-8335-C9B44ABF31C3}")
$IID__SystemCodeTypeConstructor = GUID$("{261AD877-0F22-33DE-9A3A-31F5DA424B30}")
$IID__SystemCodeTypeDeclaration = GUID$("{7AA363E1-FA53-31EB-BE4A-1EB4838264F3}")
$IID__SystemCodeTypeDeclarationCollection = GUID$("{BE0ECED3-5F0D-310A-B352-7D1ADF28F8EC}")
$IID__SystemCodeTypeDelegate = GUID$("{455090AB-5C44-3F4F-8EED-CCC90A3112B5}")
$IID__SystemCodeTypeMember = GUID$("{8068AE1D-26CB-3DB6-97CD-ED83DE116C5A}")
$IID__SystemCodeTypeMemberCollection = GUID$("{F943231E-6192-33A0-9CA3-D6ED0E4F323D}")
$IID__SystemCodeTypeOfExpression = GUID$("{12CBCE8E-75FF-312F-81B9-7FBC6212090B}")
$IID__SystemCodeTypeParameter = GUID$("{B6ED2127-296F-3B31-AEB5-E2101E98D746}")
$IID__SystemCodeTypeParameterCollection = GUID$("{6E814F1F-C349-3766-B55D-87C9B0232B20}")
$IID__SystemCodeTypeReference = GUID$("{B6D972C6-022B-3F91-9655-E288E9D32C55}")
$IID__SystemCodeTypeReferenceCollection = GUID$("{68A04561-D0A0-3EEB-B904-462DC4EB5531}")
$IID__SystemCodeTypeReferenceExpression = GUID$("{726BB04D-2C4C-3E3D-A01A-31448DB063DD}")
$IID__SystemCodeVariableDeclarationStatement = GUID$("{4192A87C-5C57-3879-8624-AF5CA2ED9EB2}")
$IID__SystemCodeVariableReferenceExpression = GUID$("{54B54936-A71C-3A45-B982-2C484E7BCF86}")
$IID__SystemCommandID = GUID$("{FC50598B-2406-33D2-BA9A-CFBEA52BC05A}")
$IID__SystemComponent = GUID$("{06565C0F-C465-37DE-896F-9864BC0BFC96}")
$IID__SystemComponentChangedEventArgs = GUID$("{A8FEF1C6-D434-3686-A4DE-B68E8EABB509}")
$IID__SystemComponentChangedEventHandler = GUID$("{0451C390-1F90-341D-9278-B9FF2636D67D}")
$IID__SystemComponentChangingEventArgs = GUID$("{B78CBAA3-37DF-31C9-ABD2-CDCB1A7FBA9F}")
$IID__SystemComponentChangingEventHandler = GUID$("{7F8C2DA3-D337-334F-92E9-87BE9BDC6070}")
$IID__SystemComponentCollection = GUID$("{42F00C62-F454-3A38-AF9E-35D4E2BDFDAC}")
$IID__SystemComponentEventArgs = GUID$("{438E8DCF-6875-305F-8CA5-40DBB15782A6}")
$IID__SystemComponentEventHandler = GUID$("{290B355D-80D3-3AFA-96AB-B4D395729374}")
$IID__SystemComponentRenameEventArgs = GUID$("{DA5D7739-9522-3E28-9AB7-7C2D7D27C63A}")
$IID__SystemComponentRenameEventHandler = GUID$("{BA2DF049-DA87-3BD1-97B0-7904B59ADF7E}")
$IID__SystemDesignerLoader = GUID$("{43BE964C-1B4A-3D1F-9D94-8185A1E6CB7B}")
$IID__SystemDesignerTransactionCloseEventArgs = GUID$("{3924A637-C2C4-3558-945F-279B5AC39ED9}")
$IID__SystemDesignerTransactionCloseEventHandler = GUID$("{4543D155-EE6A-3529-BC8D-CF0E866B6B0B}")
$IID__SystemDesignerVerb = GUID$("{7C41B90E-52FB-3E54-8B03-EBE0BF172C84}")
$IID__SystemDesignerVerbCollection = GUID$("{AC3BDDA4-25B8-3321-A1C0-7C37BBF2DDED}")
$IID__SystemEventDescriptor = GUID$("{95B6A563-4A39-37A2-91D7-04B8ECDD1B66}")
$IID__SystemEventDescriptorCollection = GUID$("{4C933253-83F2-35B6-961A-0780FF1BAF7C}")
$IID__SystemMarshalByValueComponent = GUID$("{35F38044-2017-3E05-BA83-1B87CC0D49C7}")
$IID__SystemMemberDescriptor = GUID$("{F55EFA91-812E-3C6E-998F-3598E93FB8A7}")
$IID__SystemMenuCommand = GUID$("{1FF238CE-6190-3750-A34F-05F02B7315A6}")
$IID__SystemPerformanceCounterManager = GUID$("{A9809E7D-42F8-3284-82CF-AB5F863A29AA}")
$IID__SystemPropertyDescriptor = GUID$("{FE5060F8-212F-3A4F-8FA8-DB2E14588C49}")
$IID__SystemServiceCreatorCallback = GUID$("{BE380BEC-79F2-3876-B510-FA2FE43B7EB7}")
$IID__SystemStandardOleMarshalObject = GUID$("{05F3D6C7-D4D1-37EB-AC35-63347B838A23}")
$IID__SystemTypeConverter = GUID$("{05241989-96C5-3BF9-AB9B-37E261C1B8F8}")
$IID__SystemWebClient = GUID$("{85B4A627-7552-3AA6-8A1C-A213C5788FEC}")
$IID__SystemWebHeaderCollection = GUID$("{B97E84F2-FAB2-340D-8D49-2AC85CF5C0EC}")

' ========================================================================================
' CodeBinaryOperatorType enum
' IID: {6B9BD067-5139-3CE3-AE24-5615A986F79D}
' ========================================================================================

%CodeBinaryOperatorType_Add                             = 0            ' &H0
%CodeBinaryOperatorType_Assign                          = 5            ' &H5
%CodeBinaryOperatorType_BitwiseAnd                      = 10           ' &HA
%CodeBinaryOperatorType_BitwiseOr                       = 9            ' &H9
%CodeBinaryOperatorType_BooleanAnd                      = 12           ' &HC
%CodeBinaryOperatorType_BooleanOr                       = 11           ' &HB
%CodeBinaryOperatorType_Divide                          = 3            ' &H3
%CodeBinaryOperatorType_GreaterThan                     = 15           ' &HF
%CodeBinaryOperatorType_GreaterThanOrEqual              = 16           ' &H10
%CodeBinaryOperatorType_IdentityEquality                = 7            ' &H7
%CodeBinaryOperatorType_IdentityInequality              = 6            ' &H6
%CodeBinaryOperatorType_LessThan                        = 13           ' &HD
%CodeBinaryOperatorType_LessThanOrEqual                 = 14           ' &HE
%CodeBinaryOperatorType_Modulus                         = 4            ' &H4
%CodeBinaryOperatorType_Multiply                        = 2            ' &H2
%CodeBinaryOperatorType_Subtract                        = 1            ' &H1
%CodeBinaryOperatorType_ValueEquality                   = 8            ' &H8

' ========================================================================================
' FieldDirection enum
' IID: {7CCBDCC1-88E8-35D7-818D-9A6E372D25D9}
' ========================================================================================

%FieldDirection_In                                      = 0            ' &H0
%FieldDirection_Out                                     = 1            ' &H1
%FieldDirection_Ref                                     = 2            ' &H2

' ========================================================================================
' CodeRegionMode enum
' IID: {27A77204-53F0-3FF2-94F1-6333D971A18A}
' ========================================================================================

%CodeRegionMode_End                                     = 2            ' &H2
%CodeRegionMode_None                                    = 0            ' &H0
%CodeRegionMode_Start                                   = 1            ' &H1

' ========================================================================================
' MemberAttributes enum
' IID: {94177E79-0237-35FF-8AE6-28E95E88CC20}
' ========================================================================================

%MemberAttributes_Abstract                              = 1            ' &H1
%MemberAttributes_AccessMask                            = 61440        ' &HF000
%MemberAttributes_Assembly                              = 4096         ' &H1000
%MemberAttributes_Const                                 = 5            ' &H5
%MemberAttributes_Family                                = 12288        ' &H3000
%MemberAttributes_FamilyAndAssembly                     = 8192         ' &H2000
%MemberAttributes_FamilyOrAssembly                      = 16384        ' &H4000
%MemberAttributes_Final                                 = 2            ' &H2
%MemberAttributes_New                                   = 16           ' &H10
%MemberAttributes_Overloaded                            = 256          ' &H100
%MemberAttributes_Override                              = 4            ' &H4
%MemberAttributes_Private                               = 20480        ' &H5000
%MemberAttributes_Public                                = 24576        ' &H6000
%MemberAttributes_ScopeMask                             = 15           ' &HF
%MemberAttributes_Static                                = 3            ' &H3
%MemberAttributes_VTableMask                            = 240          ' &HF0

' ========================================================================================
' CodeTypeReferenceOptions enum
' IID: {2773CA65-4339-3590-B02E-309720217D42}
' ========================================================================================

%CodeTypeReferenceOptions_GenericTypeParameter          = 2            ' &H2
%CodeTypeReferenceOptions_GlobalReference               = 1            ' &H1

' ========================================================================================
' DesignerSerializationVisibility enum
' IID: {AC5C943A-C585-311B-A920-33C6CCE59F2F}
' ========================================================================================

%DesignerSerializationVisibility_Content                = 2            ' &H2
%DesignerSerializationVisibility_Hidden                 = 0            ' &H0
%DesignerSerializationVisibility_Visible                = 1            ' &H1

' ========================================================================================
' ViewTechnology enum
' IID: {147806C0-8433-37E6-AF1A-D2099BCD4917}
' ========================================================================================

%ViewTechnology_Default                                 = 2            ' &H2
%ViewTechnology_Passthrough                             = 0            ' &H0
%ViewTechnology_WindowsForms                            = 1            ' &H1

' ========================================================================================
' SelectionTypes enum
' IID: {09E15F97-DE72-37CF-9785-183D90044942}
' ========================================================================================

%SelectionTypes_Add                                     = 64           ' &H40
%SelectionTypes_Auto                                    = 1            ' &H1
%SelectionTypes_Click                                   = 16           ' &H10
%SelectionTypes_MouseDown                               = 4            ' &H4
%SelectionTypes_MouseUp                                 = 8            ' &H8
%SelectionTypes_Normal                                  = 1            ' &H1
%SelectionTypes_Primary                                 = 16           ' &H10
%SelectionTypes_Remove                                  = 128          ' &H80
%SelectionTypes_Replace                                 = 2            ' &H2
%SelectionTypes_Toggle                                  = 32           ' &H20
%SelectionTypes_Valid                                   = 31           ' &H1F

' ########################################################################################
' Interface name = ITypeDescriptorContext
' IID = {5CBAE170-8759-3B8A-B919-E12FB86AD1F3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%SystemITypeDescriptorContext_INTERFACE_DEFINED)
    %SystemITypeDescriptorContext_INTERFACE_DEFINED = 1

INTERFACE SystemITypeDescriptorContext $IID_SystemITypeDescriptorContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Container <1610743808> ( _              ' VTable offset = 28
   ) AS SystemIContainer                                ' __retval_out IContainer **pRetVal
   ' =====================================================================================
   PROPERTY GET Instance <1610743809> ( _               ' VTable offset = 32
   ) AS VARIANT                                         ' __retval_out VARIANT *pRetVal
   ' =====================================================================================
   PROPERTY GET PropertyDescriptor <1610743810> ( _     ' VTable offset = 36
   ) AS IDispatch                                       ' __retval_out _PropertyDescriptor **pRetVal
   ' =====================================================================================
   METHOD OnComponentChanging <1610743811> ( _          ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pRetVal
   ' =====================================================================================
   METHOD OnComponentChanged <1610743812> ( _           ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __SystemITypeDescriptorContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IComponent
' IID = {B86E59F2-F1E2-389D-B5F1-C55307C8106E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%SystemIComponent_INTERFACE_DEFINED)
    %SystemIComponent_INTERFACE_DEFINED = 1

INTERFACE SystemIComponent $IID_SystemIComponent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Site <1610743808> ( _                   ' VTable offset = 28
   ) AS SystemISite                                     ' __retval_out ISite **pRetVal
   ' =====================================================================================
   PROPERTY SET putref_Site <1610743808> ( _            ' VTable offset = 32
     BYVAL pRetVal AS SystemISite _                     ' __in ISite *pRetVal
   )                                                    ' void
   ' =====================================================================================
   METHOD add_Disposed <1610743810> ( _                 ' VTable offset = 36
     BYVAL value AS IDispatch _                         ' __in _EventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD remove_Disposed <1610743811> ( _              ' VTable offset = 40
     BYVAL value AS IDispatch _                         ' __in _EventHandler *value
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __SystemIComponent_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISite
' IID = {C4E1006A-9D98-3E96-A07E-921725135C28}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%SystemISite_INTERFACE_DEFINED)
    %SystemISite_INTERFACE_DEFINED = 1

INTERFACE SystemISite $IID_SystemISite

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET component <1610743808> ( _              ' VTable offset = 28
   ) AS SystemIComponent                                ' __retval_out IComponent **pRetVal
   ' =====================================================================================
   PROPERTY GET Container <1610743809> ( _              ' VTable offset = 32
   ) AS SystemIContainer                                ' __retval_out IContainer **pRetVal
   ' =====================================================================================
   PROPERTY GET DesignMode <1610743810> ( _             ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pRetVal
   ' =====================================================================================
   PROPERTY GET name <1610743811> ( _                   ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pRetVal
   ' =====================================================================================
   PROPERTY SET name <1610743811> ( _                   ' VTable offset = 44
     BYVAL pRetVal AS WSTRING _                         ' __in BSTR pRetVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __SystemISite_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IContainer
' IID = {61D9C50C-4AAD-3539-AF82-4F36C19D77C8}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%SystemIContainer_INTERFACE_DEFINED)
    %SystemIContainer_INTERFACE_DEFINED = 1

INTERFACE SystemIContainer $IID_SystemIContainer

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Add <1610743808> ( _                          ' VTable offset = 28
     BYVAL component AS SystemIComponent _              ' __in IComponent *component
   )                                                    ' void
   ' =====================================================================================
   METHOD Add_2 <1610743809> ( _                        ' VTable offset = 32
     BYVAL component AS SystemIComponent _              ' __in IComponent *component
   , BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Components <1610743810> ( _             ' VTable offset = 36
   ) AS IDispatch                                       ' __retval_out _ComponentCollection **pRetVal
   ' =====================================================================================
   METHOD Remove <1610743811> ( _                       ' VTable offset = 40
     BYVAL component AS SystemIComponent _              ' __in IComponent *component
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __SystemIContainer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDesigner
' IID = {6EEF3D0D-305A-3DF4-9830-8C2B40E1C4BF}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%SystemIDesigner_INTERFACE_DEFINED)
    %SystemIDesigner_INTERFACE_DEFINED = 1

INTERFACE SystemIDesigner $IID_SystemIDesigner

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET component <1610743808> ( _              ' VTable offset = 28
   ) AS SystemIComponent                                ' __retval_out IComponent **pRetVal
   ' =====================================================================================
   PROPERTY GET Verbs <1610743809> ( _                  ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out _DesignerVerbCollection **pRetVal
   ' =====================================================================================
   METHOD DoDefaultAction <1610743810> ( _              ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD Initialize <1610743811> ( _                   ' VTable offset = 40
     BYVAL component AS SystemIComponent _              ' __in IComponent *component
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __SystemIDesigner_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDesignerHost
' IID = {EEC98CD8-EF5B-3B60-82C9-86F616F6BB20}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%SystemIDesignerHost_INTERFACE_DEFINED)
    %SystemIDesignerHost_INTERFACE_DEFINED = 1

INTERFACE SystemIDesignerHost $IID_SystemIDesignerHost

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Loading <1610743808> ( _                ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pRetVal
   ' =====================================================================================
   PROPERTY GET InTransaction <1610743809> ( _          ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pRetVal
   ' =====================================================================================
   PROPERTY GET Container <1610743810> ( _              ' VTable offset = 36
   ) AS SystemIContainer                                ' __retval_out IContainer **pRetVal
   ' =====================================================================================
   PROPERTY GET RootComponent <1610743811> ( _          ' VTable offset = 40
   ) AS SystemIComponent                                ' __retval_out IComponent **pRetVal
   ' =====================================================================================
   PROPERTY GET RootComponentClassName <1610743812> ( _ ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pRetVal
   ' =====================================================================================
   PROPERTY GET TransactionDescription <1610743813> ( _ ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pRetVal
   ' =====================================================================================
   METHOD add_Activated <1610743814> ( _                ' VTable offset = 52
     BYVAL value AS IDispatch _                         ' __in _EventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD remove_Activated <1610743815> ( _             ' VTable offset = 56
     BYVAL value AS IDispatch _                         ' __in _EventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD add_Deactivated <1610743816> ( _              ' VTable offset = 60
     BYVAL value AS IDispatch _                         ' __in _EventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD remove_Deactivated <1610743817> ( _           ' VTable offset = 64
     BYVAL value AS IDispatch _                         ' __in _EventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD add_LoadComplete <1610743818> ( _             ' VTable offset = 68
     BYVAL value AS IDispatch _                         ' __in _EventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD remove_LoadComplete <1610743819> ( _          ' VTable offset = 72
     BYVAL value AS IDispatch _                         ' __in _EventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD add_TransactionClosed <1610743820> ( _        ' VTable offset = 76
     BYVAL value AS IDispatch _                         ' __in _DesignerTransactionCloseEventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD remove_TransactionClosed <1610743821> ( _     ' VTable offset = 80
     BYVAL value AS IDispatch _                         ' __in _DesignerTransactionCloseEventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD add_TransactionClosing <1610743822> ( _       ' VTable offset = 84
     BYVAL value AS IDispatch _                         ' __in _DesignerTransactionCloseEventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD remove_TransactionClosing <1610743823> ( _    ' VTable offset = 88
     BYVAL value AS IDispatch _                         ' __in _DesignerTransactionCloseEventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD add_TransactionOpened <1610743824> ( _        ' VTable offset = 92
     BYVAL value AS IDispatch _                         ' __in _EventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD remove_TransactionOpened <1610743825> ( _     ' VTable offset = 96
     BYVAL value AS IDispatch _                         ' __in _EventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD add_TransactionOpening <1610743826> ( _       ' VTable offset = 100
     BYVAL value AS IDispatch _                         ' __in _EventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD remove_TransactionOpening <1610743827> ( _    ' VTable offset = 104
     BYVAL value AS IDispatch _                         ' __in _EventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD Activate <1610743828> ( _                     ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateComponent <1610743829> ( _              ' VTable offset = 112
     BYVAL componentClass AS SystemType _               ' __in _Type *componentClass
   ) AS SystemIComponent                                ' __retval_out IComponent **pRetVal
   ' =====================================================================================
   METHOD CreateComponent_2 <1610743830> ( _            ' VTable offset = 116
     BYVAL componentClass AS SystemType _               ' __in _Type *componentClass  <interface>
   , BYVAL name AS WSTRING _                            ' __in BSTR name
   ) AS SystemIComponent                                ' __retval_out IComponent **pRetVal
   ' =====================================================================================
   METHOD CreateTransaction <1610743831> ( _            ' VTable offset = 120
   ) AS IUnknown                                        ' __retval_out IUnknown **pRetVal
   ' =====================================================================================
   METHOD CreateTransaction_2 <1610743832> ( _          ' VTable offset = 124
     BYVAL description AS WSTRING _                     ' __in BSTR description
   ) AS IUnknown                                        ' __retval_out IUnknown **pRetVal
   ' =====================================================================================
   METHOD DestroyComponent <1610743833> ( _             ' VTable offset = 128
     BYVAL component AS SystemIComponent _              ' __in IComponent *component
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDesigner <1610743834> ( _                  ' VTable offset = 132
     BYVAL component AS SystemIComponent _              ' __in IComponent *component
   ) AS SystemIDesigner                                 ' __retval_out IDesigner **pRetVal
   ' =====================================================================================
   METHOD GetType <1610743835> ( _                      ' VTable offset = 136
     BYVAL typeName AS WSTRING _                        ' __in BSTR typeName
   ) AS SystemType                                      ' __retval_out _Type **pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __SystemIDesignerHost_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IComponentChangeService
' IID = {2FEF0210-9EBD-32C0-9BFD-24841AC0FCF7}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%SystemIComponentChangeService_INTERFACE_DEFINED)
    %SystemIComponentChangeService_INTERFACE_DEFINED = 1

INTERFACE SystemIComponentChangeService $IID_SystemIComponentChangeService

   INHERIT IDispatch

   ' =====================================================================================
   METHOD add_ComponentAdded <1610743808> ( _           ' VTable offset = 28
     BYVAL value AS IDispatch _                         ' __in _ComponentEventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD remove_ComponentAdded <1610743809> ( _        ' VTable offset = 32
     BYVAL value AS IDispatch _                         ' __in _ComponentEventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD add_ComponentAdding <1610743810> ( _          ' VTable offset = 36
     BYVAL value AS IDispatch _                         ' __in _ComponentEventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD remove_ComponentAdding <1610743811> ( _       ' VTable offset = 40
     BYVAL value AS IDispatch _                         ' __in _ComponentEventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD add_ComponentChanged <1610743812> ( _         ' VTable offset = 44
     BYVAL value AS IDispatch _                         ' __in _ComponentChangedEventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD remove_ComponentChanged <1610743813> ( _      ' VTable offset = 48
     BYVAL value AS IDispatch _                         ' __in _ComponentChangedEventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD add_ComponentChanging <1610743814> ( _        ' VTable offset = 52
     BYVAL value AS IDispatch _                         ' __in _ComponentChangingEventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD remove_ComponentChanging <1610743815> ( _     ' VTable offset = 56
     BYVAL value AS IDispatch _                         ' __in _ComponentChangingEventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD add_ComponentRemoved <1610743816> ( _         ' VTable offset = 60
     BYVAL value AS IDispatch _                         ' __in _ComponentEventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD remove_ComponentRemoved <1610743817> ( _      ' VTable offset = 64
     BYVAL value AS IDispatch _                         ' __in _ComponentEventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD add_ComponentRemoving <1610743818> ( _        ' VTable offset = 68
     BYVAL value AS IDispatch _                         ' __in _ComponentEventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD remove_ComponentRemoving <1610743819> ( _     ' VTable offset = 72
     BYVAL value AS IDispatch _                         ' __in _ComponentEventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD add_ComponentRename <1610743820> ( _          ' VTable offset = 76
     BYVAL value AS IDispatch _                                  ' __in _ComponentRenameEventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD remove_ComponentRename <1610743821> ( _       ' VTable offset = 80
     BYVAL value AS IDispatch _                                  ' __in _ComponentRenameEventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD OnComponentChanged <1610743822> ( _           ' VTable offset = 84
     BYVAL component AS VARIANT _                       ' __in VARIANT component
   , BYVAL member AS IDispatch _                        ' __in _MemberDescriptor *member
   , BYVAL oldValue AS VARIANT _                        ' __in VARIANT oldValue
   , BYVAL newValue AS VARIANT _                        ' __in VARIANT newValue
   )                                                    ' void
   ' =====================================================================================
   METHOD OnComponentChanging <1610743823> ( _          ' VTable offset = 88
     BYVAL component AS VARIANT _                       ' __in VARIANT component
   , BYVAL member AS IDispatch _                        ' __in _MemberDescriptor *member
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __SystemIComponentChangeService_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IServiceContainer
' IID = {6BA96B42-7FDD-3223-BF52-7FE677B92815}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%SystemIServiceContainer_INTERFACE_DEFINED)
    %SystemIServiceContainer_INTERFACE_DEFINED = 1

INTERFACE SystemIServiceContainer $IID_SystemIServiceContainer

   INHERIT IDispatch

   ' =====================================================================================
   METHOD AddService <1610743808> ( _                   ' VTable offset = 28
     BYVAL serviceType AS SystemType _                  ' __in _Type *serviceType
   , BYVAL serviceInstance AS VARIANT _                 ' __in VARIANT serviceInstance
   )                                                    ' void
   ' =====================================================================================
   METHOD AddService_2 <1610743809> ( _                 ' VTable offset = 32
     BYVAL serviceType AS SystemType _                  ' __in _Type *serviceType
   , BYVAL serviceInstance AS VARIANT _                 ' __in VARIANT serviceInstance
   , BYVAL promote AS INTEGER _                         ' __in VARIANT_BOOL promote
   )                                                    ' void
   ' =====================================================================================
   METHOD AddService_3 <1610743810> ( _                 ' VTable offset = 36
     BYVAL serviceType AS SystemType _                  ' __in _Type *serviceType
   , BYVAL callback AS IDispatch _                      ' __in _ServiceCreatorCallback *callback
   )                                                    ' void
   ' =====================================================================================
   METHOD AddService_4 <1610743811> ( _                 ' VTable offset = 40
     BYVAL serviceType AS SystemType _                  ' __in _Type *serviceType
   , BYVAL callback AS IDispatch _                      ' __in _ServiceCreatorCallback *callback
   , BYVAL promote AS INTEGER _                         ' __in VARIANT_BOOL promote
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveService <1610743812> ( _                ' VTable offset = 44
     BYVAL serviceType AS SystemType _                  ' __in _Type *serviceType
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveService_2 <1610743813> ( _              ' VTable offset = 48
     BYVAL serviceType AS SystemType _                  ' __in _Type *serviceType
   , BYVAL promote AS INTEGER _                         ' __in VARIANT_BOOL promote
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __SystemIServiceContainer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventBindingService
' IID = {1A19D89E-F4FE-3E8E-B7EC-05D4E592F3F6}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%SystemIEventBindingService_INTERFACE_DEFINED)
    %SystemIEventBindingService_INTERFACE_DEFINED = 1

INTERFACE SystemIEventBindingService $IID_SystemIEventBindingService

   INHERIT IDispatch

   ' =====================================================================================
   METHOD CreateUniqueMethodName <1610743808> ( _       ' VTable offset = 28
     BYVAL component AS SystemIComponent _              ' __in IComponent *component
   , BYVAL e AS IDispatch _                             ' __in _EventDescriptor *e
   ) AS WSTRING                                         ' __retval_out BSTR *pRetVal
   ' =====================================================================================
   METHOD GetCompatibleMethods <1610743809> ( _         ' VTable offset = 32
     BYVAL e AS IDispatch _                             ' __in _EventDescriptor *e
   ) AS SystemICollection                               ' __retval_out ICollection **pRetVal
   ' =====================================================================================
   METHOD GetEvent <1610743810> ( _                     ' VTable offset = 36
     BYVAL property AS IDispatch _                      ' __in _PropertyDescriptor *property
   ) AS IDispatch                                       ' __retval_out _EventDescriptor
   ' =====================================================================================
   METHOD GetEventProperties <1610743811> ( _           ' VTable offset = 40
     BYVAL events AS IDispatch _                        ' __in _EventDescriptorCollection *events
   ) AS IUnknown                                        ' __retval_out IUnknown **pRetVal
   ' =====================================================================================
   METHOD GetEventProperty <1610743812> ( _             ' VTable offset = 44
     BYVAL Ie AS Dispatch _                             ' __in _EventDescriptor *e
   ) AS IDispatch                                       ' __retval_out _PropertyDescriptor **pRetVal
   ' =====================================================================================
   METHOD ShowCode <1610743813> ( _                     ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pRetVal
   ' =====================================================================================
   METHOD ShowCode_2 <1610743814> ( _                   ' VTable offset = 52
     BYVAL lineNumber AS LONG _                         ' __in long lineNumber
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pRetVal
   ' =====================================================================================
   METHOD ShowCode_3 <1610743815> ( _                   ' VTable offset = 56
     BYVAL component AS SystemIComponent _              ' __in IComponent *component
   , BYVAL e AS IDispatch _                             ' __in_EventDescriptor *e
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __SystemIEventBindingService_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMenuCommandService
' IID = {DF651C5D-783E-3789-901F-A962B7587E69}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%SystemIMenuCommandService_INTERFACE_DEFINED)
    %SystemIMenuCommandService_INTERFACE_DEFINED = 1

INTERFACE SystemIMenuCommandService $IID_SystemIMenuCommandService

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Verbs <1610743808> ( _                  ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out _DesignerVerbCollection **pRetVal
   ' =====================================================================================
   METHOD AddCommand <1610743809> ( _                   ' VTable offset = 32
     BYVAL command AS IDispatch _                       ' __in _MenuCommand *
   )                                                    ' void
   ' =====================================================================================
   METHOD AddVerb <1610743810> ( _                      ' VTable offset = 36
     BYVAL verb AS IDispatch _                          ' __in _DesignerVerb *verb
   )                                                    ' void
   ' =====================================================================================
   METHOD FindCommand <1610743811> ( _                  ' VTable offset = 40
     BYVAL CommandID AS IDispatch _                     ' __in _CommandID *CommandID
   ) AS IDispatch                                       ' __retval_out _MenuCommand **pRetVal
   ' =====================================================================================
   METHOD GlobalInvoke <1610743812> ( _                 ' VTable offset = 44
     BYVAL CommandID AS IDispatch _                     ' __in _CommandID *CommandID
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pRetVal
   ' =====================================================================================
   METHOD RemoveCommand <1610743813> ( _                ' VTable offset = 48
     BYVAL command AS IDispatch _                       ' __in _MenuCommand *command
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveVerb <1610743814> ( _                   ' VTable offset = 52
     BYVAL verb AS IDispatch _                          ' __in _DesignerVerb *verb
   )                                                    ' void
   ' =====================================================================================
   METHOD ShowContextMenu <1610743815> ( _              ' VTable offset = 56
     BYVAL menuID AS IDispatch _                        ' __in _CommandID *menuID
   , BYVAL x AS LONG _                                  ' __in long x
   , BYVAL y AS LONG _                                  ' __in long y
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __SystemIMenuCommandService_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRootDesigner
' IID = {2CC5E562-6C14-34A6-9D0B-E6FF949AE8FB}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%SystemIRootDesigner_INTERFACE_DEFINED)
    %SystemIRootDesigner_INTERFACE_DEFINED = 1

INTERFACE SystemIRootDesigner $IID_SystemIRootDesigner

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET SupportedTechnologies <1610743808> ( _  ' VTable offset = 28
   ) AS DWORD                                           ' __retval_out VT_SAFEARRAY *pRetVal
   ' =====================================================================================
   METHOD GetView <1610743809> ( _                      ' VTable offset = 32
     BYVAL technology AS LONG _                         ' __in ViewTechnology technology
   ) AS VARIANT                                         ' __retval_out VARIANT *pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __SystemIRootDesigner_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISelectionService
' IID = {297A65BE-5080-3F7F-AD19-B0D05D6F2327}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%SystemISelectionService_INTERFACE_DEFINED)
    %SystemISelectionService_INTERFACE_DEFINED = 1

INTERFACE SystemISelectionService $IID_SystemISelectionService

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET PrimarySelection <1610743808> ( _       ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *pRetVal
   ' =====================================================================================
   PROPERTY GET SelectionCount <1610743809> ( _         ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pRetVal
   ' =====================================================================================
   METHOD add_SelectionChanged <1610743810> ( _         ' VTable offset = 36
     BYVAL value AS IDispatch _                         ' __in _EventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD remove_SelectionChanged <1610743811> ( _      ' VTable offset = 40
     BYVAL value AS IDispatch _                         ' __in _EventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD add_SelectionChanging <1610743812> ( _        ' VTable offset = 44
     BYVAL value AS IDispatch _                         ' __in _EventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD remove_SelectionChanging <1610743813> ( _     ' VTable offset = 48
     BYVAL value AS IDispatch _                         ' __in _EventHandler *value
   )                                                    ' void
   ' =====================================================================================
   METHOD GetComponentSelected <1610743814> ( _         ' VTable offset = 52
     BYVAL component AS VARIANT _                       ' __in VARIANT component
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pRetVal
   ' =====================================================================================
   METHOD GetSelectedComponents <1610743815> ( _        ' VTable offset = 56
   ) AS SystemICollection                               ' __retval_out ICollection **pRetVal
   ' =====================================================================================
   METHOD SetSelectedComponents <1610743816> ( _        ' VTable offset = 60
     BYVAL Components AS SystemICollection _            ' __in ICollection *Components
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSelectedComponents_2 <1610743817> ( _      ' VTable offset = 64
     BYVAL Components AS SystemICollection _            ' __in ICollection *Components
   , BYVAL selectionType AS LONG _                      ' __in SelectionTypes selectionType
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __SystemISelectionService_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeDomProvider
' Interface name = _CodeDomProvider
' IID = {61059E8D-1DD2-3F4B-A4C5-D566B8968FFB}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeDomProvider_INTERFACE_DEFINED)
'    %SystemCodeDomProvider_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeDomProvider $IID__SystemCodeDomProvider

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeDomProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = TypeConverter
' Interface name = _TypeConverter
' IID = {05241989-96C5-3BF9-AB9B-37E261C1B8F8}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemTypeConverter_INTERFACE_DEFINED)
'    %SystemTypeConverter_INTERFACE_DEFINED = 1

'INTERFACE SystemTypeConverter $IID__SystemTypeConverter

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemTypeConverter_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeTypeMember
' Interface name = _CodeTypeMember
' IID = {8068AE1D-26CB-3DB6-97CD-ED83DE116C5A}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeTypeMember_INTERFACE_DEFINED)
'    %SystemCodeTypeMember_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeTypeMember $IID__SystemCodeTypeMember

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeTypeMember_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeArgumentReferenceExpression
' Interface name = _CodeArgumentReferenceExpression
' IID = {A52B85C6-5370-35C9-A04A-04A92013862C}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeArgumentReferenceExpression_INTERFACE_DEFINED)
'    %SystemCodeArgumentReferenceExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeArgumentReferenceExpression $IID__SystemCodeArgumentReferenceExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeArgumentReferenceExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeExpression
' Interface name = _CodeExpression
' IID = {AD377794-864F-3421-9FB8-C684BBC1BC02}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeExpression_INTERFACE_DEFINED)
'    %SystemCodeExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeExpression $IID__SystemCodeExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeArrayCreateExpression
' Interface name = _CodeArrayCreateExpression
' IID = {F7955E55-7F3B-3277-AA0C-F62AA615676D}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeArrayCreateExpression_INTERFACE_DEFINED)
'    %SystemCodeArrayCreateExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeArrayCreateExpression $IID__SystemCodeArrayCreateExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeArrayCreateExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeTypeReference
' Interface name = _CodeTypeReference
' IID = {B6D972C6-022B-3F91-9655-E288E9D32C55}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeTypeReference_INTERFACE_DEFINED)
'    %SystemCodeTypeReference_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeTypeReference $IID__SystemCodeTypeReference

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeTypeReference_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeExpressionCollection
' Interface name = _CodeExpressionCollection
' IID = {AF72CC74-2275-362A-9141-A4A79D596F39}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeExpressionCollection_INTERFACE_DEFINED)
'    %SystemCodeExpressionCollection_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeExpressionCollection $IID__SystemCodeExpressionCollection

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeExpressionCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeArrayIndexerExpression
' Interface name = _CodeArrayIndexerExpression
' IID = {732748F5-5256-327B-A7E5-2000B07F21B3}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeArrayIndexerExpression_INTERFACE_DEFINED)
'    %SystemCodeArrayIndexerExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeArrayIndexerExpression $IID__SystemCodeArrayIndexerExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeArrayIndexerExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeAssignStatement
' Interface name = _CodeAssignStatement
' IID = {E2024DE0-DC21-305D-8761-6C31F2177FB0}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeAssignStatement_INTERFACE_DEFINED)
'    %SystemCodeAssignStatement_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeAssignStatement $IID__SystemCodeAssignStatement

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeAssignStatement_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeStatement
' Interface name = _CodeStatement
' IID = {B125774D-EF66-382B-878D-2D916999B0D2}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeStatement_INTERFACE_DEFINED)
'    %SystemCodeStatement_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeStatement $IID__SystemCodeStatement

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeStatement_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeAttachEventStatement
' Interface name = _CodeAttachEventStatement
' IID = {F7BC47E9-706C-3AA7-B1BA-8AB95188FA11}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeAttachEventStatement_INTERFACE_DEFINED)
'    %SystemCodeAttachEventStatement_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeAttachEventStatement $IID__SystemCodeAttachEventStatement

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeAttachEventStatement_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeEventReferenceExpression
' Interface name = _CodeEventReferenceExpression
' IID = {35872687-5A11-34D7-85AB-865830A3BDEE}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeEventReferenceExpression_INTERFACE_DEFINED)
'    %SystemCodeEventReferenceExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeEventReferenceExpression $IID__SystemCodeEventReferenceExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeEventReferenceExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeAttributeArgument
' Interface name = _CodeAttributeArgument
' IID = {02EFD952-FF8C-3B72-8C33-739A506D53D9}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeAttributeArgument_INTERFACE_DEFINED)
'    %SystemCodeAttributeArgument_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeAttributeArgument $IID__SystemCodeAttributeArgument

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeAttributeArgument_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeAttributeArgumentCollection
' Interface name = _CodeAttributeArgumentCollection
' IID = {FE84E484-A7EC-3D15-B5E2-EDC2DE2DB42E}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeAttributeArgumentCollection_INTERFACE_DEFINED)
'    %SystemCodeAttributeArgumentCollection_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeAttributeArgumentCollection $IID__SystemCodeAttributeArgumentCollection

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeAttributeArgumentCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeAttributeDeclaration
' Interface name = _CodeAttributeDeclaration
' IID = {EF72D021-2C6D-3E33-9442-574BFD6E0871}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeAttributeDeclaration_INTERFACE_DEFINED)
'    %SystemCodeAttributeDeclaration_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeAttributeDeclaration $IID__SystemCodeAttributeDeclaration

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeAttributeDeclaration_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeAttributeDeclarationCollection
' Interface name = _CodeAttributeDeclarationCollection
' IID = {7E9ACA22-637C-3F88-A931-AAF36A4F9A6B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeAttributeDeclarationCollection_INTERFACE_DEFINED)
'    %SystemCodeAttributeDeclarationCollection_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeAttributeDeclarationCollection $IID__SystemCodeAttributeDeclarationCollection

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeAttributeDeclarationCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeBaseReferenceExpression
' Interface name = _CodeBaseReferenceExpression
' IID = {45E29CA6-670A-3B13-9557-4E5903056BF3}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeBaseReferenceExpression_INTERFACE_DEFINED)
'    %SystemCodeBaseReferenceExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeBaseReferenceExpression $IID__SystemCodeBaseReferenceExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeBaseReferenceExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeBinaryOperatorExpression
' Interface name = _CodeBinaryOperatorExpression
' IID = {A22929C9-D301-3F5B-98B7-844FDBA1DEDF}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeBinaryOperatorExpression_INTERFACE_DEFINED)
'    %SystemCodeBinaryOperatorExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeBinaryOperatorExpression $IID__SystemCodeBinaryOperatorExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeBinaryOperatorExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeCastExpression
' Interface name = _CodeCastExpression
' IID = {90BED8ED-21E3-31FE-8F02-C929BA4FB0AC}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeCastExpression_INTERFACE_DEFINED)
'    %SystemCodeCastExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeCastExpression $IID__SystemCodeCastExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeCastExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeCatchClause
' Interface name = _CodeCatchClause
' IID = {609C7788-BDB0-364C-92E3-FC16AC613430}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeCatchClause_INTERFACE_DEFINED)
'    %SystemCodeCatchClause_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeCatchClause $IID__SystemCodeCatchClause

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeCatchClause_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeStatementCollection
' Interface name = _CodeStatementCollection
' IID = {4B9A5032-4B8C-3DE6-997C-C38B4B3AF26A}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeStatementCollection_INTERFACE_DEFINED)
'    %SystemCodeStatementCollection_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeStatementCollection $IID__SystemCodeStatementCollection

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeStatementCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeCatchClauseCollection
' Interface name = _CodeCatchClauseCollection
' IID = {FF5E1CD9-0478-34A4-9B9C-7C80BCB1A725}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeCatchClauseCollection_INTERFACE_DEFINED)
'    %SystemCodeCatchClauseCollection_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeCatchClauseCollection $IID__SystemCodeCatchClauseCollection

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeCatchClauseCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeChecksumPragma
' Interface name = _CodeChecksumPragma
' IID = {7EB20114-E822-358C-BDAB-DCF9E5090F23}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeChecksumPragma_INTERFACE_DEFINED)
'    %SystemCodeChecksumPragma_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeChecksumPragma $IID__SystemCodeChecksumPragma

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeChecksumPragma_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeDirective
' Interface name = _CodeDirective
' IID = {767E752E-2315-35CF-9652-7FC46AE870D3}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeDirective_INTERFACE_DEFINED)
'    %SystemCodeDirective_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeDirective $IID__SystemCodeDirective

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeDirective_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeComment
' Interface name = _CodeComment
' IID = {C94F39B3-436F-3711-9CB0-91C6299B62A2}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeComment_INTERFACE_DEFINED)
'    %SystemCodeComment_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeComment $IID__SystemCodeComment

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeComment_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeObject
' Interface name = _CodeObject
' IID = {EE499EFD-22E2-3740-A64A-2AB010099C01}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeObject_INTERFACE_DEFINED)
'    %SystemCodeObject_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeObject $IID__SystemCodeObject

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeObject_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeCommentStatement
' Interface name = _CodeCommentStatement
' IID = {0C13F8B9-F2E0-3918-A33E-3E491BDC529E}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeCommentStatement_INTERFACE_DEFINED)
'    %SystemCodeCommentStatement_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeCommentStatement $IID__SystemCodeCommentStatement

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeCommentStatement_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeCommentStatementCollection
' Interface name = _CodeCommentStatementCollection
' IID = {E34CEB72-8F86-333D-AEDA-069221DF6A1A}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeCommentStatementCollection_INTERFACE_DEFINED)
'    %SystemCodeCommentStatementCollection_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeCommentStatementCollection $IID__SystemCodeCommentStatementCollection

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeCommentStatementCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeCompileUnit
' Interface name = _CodeCompileUnit
' IID = {6F20C263-AF67-380F-A482-9A21F7599748}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeCompileUnit_INTERFACE_DEFINED)
'    %SystemCodeCompileUnit_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeCompileUnit $IID__SystemCodeCompileUnit

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeCompileUnit_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeNamespaceCollection
' Interface name = _CodeNamespaceCollection
' IID = {F5E54F16-ADE3-3B5D-8B05-1F9803557905}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeNamespaceCollection_INTERFACE_DEFINED)
'    %SystemCodeNamespaceCollection_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeNamespaceCollection $IID__SystemCodeNamespaceCollection

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeNamespaceCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeDirectiveCollection
' Interface name = _CodeDirectiveCollection
' IID = {EEFBDD27-4904-3E90-ACFC-624164CB45DD}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeDirectiveCollection_INTERFACE_DEFINED)
'    %SystemCodeDirectiveCollection_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeDirectiveCollection $IID__SystemCodeDirectiveCollection

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeDirectiveCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeConditionStatement
' Interface name = _CodeConditionStatement
' IID = {69904B31-5FB5-39BF-83B0-5DDFA1F26D71}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeConditionStatement_INTERFACE_DEFINED)
'    %SystemCodeConditionStatement_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeConditionStatement $IID__SystemCodeConditionStatement

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeConditionStatement_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeConstructor
' Interface name = _CodeConstructor
' IID = {5A33C771-806E-337D-AE1F-66B523FC49BF}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeConstructor_INTERFACE_DEFINED)
'    %SystemCodeConstructor_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeConstructor $IID__SystemCodeConstructor

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeConstructor_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeMemberMethod
' Interface name = _CodeMemberMethod
' IID = {95C2EE26-4247-3DDC-8056-97353F10DE8F}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeMemberMethod_INTERFACE_DEFINED)
'    %SystemCodeMemberMethod_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeMemberMethod $IID__SystemCodeMemberMethod

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeMemberMethod_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeDefaultValueExpression
' Interface name = _CodeDefaultValueExpression
' IID = {EA9E1DD2-EF9A-3570-AE1A-2F625F594C3B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeDefaultValueExpression_INTERFACE_DEFINED)
'    %SystemCodeDefaultValueExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeDefaultValueExpression $IID__SystemCodeDefaultValueExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeDefaultValueExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeDelegateCreateExpression
' Interface name = _CodeDelegateCreateExpression
' IID = {D14E12C1-E1D1-3B74-A3AF-021A5A268FBE}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeDelegateCreateExpression_INTERFACE_DEFINED)
'    %SystemCodeDelegateCreateExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeDelegateCreateExpression $IID__SystemCodeDelegateCreateExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeDelegateCreateExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeDelegateInvokeExpression
' Interface name = _CodeDelegateInvokeExpression
' IID = {6F6C3482-8900-36EA-B621-943534E82C73}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeDelegateInvokeExpression_INTERFACE_DEFINED)
'    %SystemCodeDelegateInvokeExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeDelegateInvokeExpression $IID__SystemCodeDelegateInvokeExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeDelegateInvokeExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeDirectionExpression
' Interface name = _CodeDirectionExpression
' IID = {11EDAF3B-144E-32C8-8BE0-81D40A950656}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeDirectionExpression_INTERFACE_DEFINED)
'    %SystemCodeDirectionExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeDirectionExpression $IID__SystemCodeDirectionExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeDirectionExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeEntryPointMethod
' Interface name = _CodeEntryPointMethod
' IID = {7CD4EF19-27EB-399E-8ED2-C6647A99C03E}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeEntryPointMethod_INTERFACE_DEFINED)
'    %SystemCodeEntryPointMethod_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeEntryPointMethod $IID__SystemCodeEntryPointMethod

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeEntryPointMethod_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeExpressionStatement
' Interface name = _CodeExpressionStatement
' IID = {CEA240AF-60C5-3C69-9DA1-DA3F9A6D7B3C}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeExpressionStatement_INTERFACE_DEFINED)
'    %SystemCodeExpressionStatement_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeExpressionStatement $IID__SystemCodeExpressionStatement

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeExpressionStatement_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeFieldReferenceExpression
' Interface name = _CodeFieldReferenceExpression
' IID = {82D57B2B-C639-32A0-89B4-62A0C29DD64E}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeFieldReferenceExpression_INTERFACE_DEFINED)
'    %SystemCodeFieldReferenceExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeFieldReferenceExpression $IID__SystemCodeFieldReferenceExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeFieldReferenceExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeGotoStatement
' Interface name = _CodeGotoStatement
' IID = {8F1BAED9-52EC-3545-9CF0-6ED71A76A5CA}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeGotoStatement_INTERFACE_DEFINED)
'    %SystemCodeGotoStatement_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeGotoStatement $IID__SystemCodeGotoStatement

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeGotoStatement_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeIndexerExpression
' Interface name = _CodeIndexerExpression
' IID = {C92C323F-8601-34D4-A2D6-F5E2653DB456}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeIndexerExpression_INTERFACE_DEFINED)
'    %SystemCodeIndexerExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeIndexerExpression $IID__SystemCodeIndexerExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeIndexerExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeIterationStatement
' Interface name = _CodeIterationStatement
' IID = {B16F7137-C0E7-3ECF-9652-FB1EA947E44E}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeIterationStatement_INTERFACE_DEFINED)
'    %SystemCodeIterationStatement_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeIterationStatement $IID__SystemCodeIterationStatement

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeIterationStatement_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeLabeledStatement
' Interface name = _CodeLabeledStatement
' IID = {56699CCA-FD8D-3AD2-9643-149BAD87FD60}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeLabeledStatement_INTERFACE_DEFINED)
'    %SystemCodeLabeledStatement_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeLabeledStatement $IID__SystemCodeLabeledStatement

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeLabeledStatement_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeLinePragma
' Interface name = _CodeLinePragma
' IID = {1B52DED6-92F3-3B4F-851C-AB1F647582A3}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeLinePragma_INTERFACE_DEFINED)
'    %SystemCodeLinePragma_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeLinePragma $IID__SystemCodeLinePragma

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeLinePragma_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeMemberEvent
' Interface name = _CodeMemberEvent
' IID = {E1A7EA9F-5D43-3FA9-AFBC-9A2BFDA84B65}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeMemberEvent_INTERFACE_DEFINED)
'    %SystemCodeMemberEvent_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeMemberEvent $IID__SystemCodeMemberEvent

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeMemberEvent_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeTypeReferenceCollection
' Interface name = _CodeTypeReferenceCollection
' IID = {68A04561-D0A0-3EEB-B904-462DC4EB5531}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeTypeReferenceCollection_INTERFACE_DEFINED)
'    %SystemCodeTypeReferenceCollection_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeTypeReferenceCollection $IID__SystemCodeTypeReferenceCollection

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeTypeReferenceCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeMemberField
' Interface name = _CodeMemberField
' IID = {EEF50D17-7AA6-3E14-96C6-DD90FE5BAA1E}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeMemberField_INTERFACE_DEFINED)
'    %SystemCodeMemberField_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeMemberField $IID__SystemCodeMemberField

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeMemberField_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeParameterDeclarationExpressionCollection
' Interface name = _CodeParameterDeclarationExpressionCollection
' IID = {05192769-7D6A-3C8C-94C2-DFA668F61088}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeParameterDeclarationExpressionCollection_INTERFACE_DEFINED)
'    %SystemCodeParameterDeclarationExpressionCollection_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeParameterDeclarationExpressionCollection $IID__SystemCodeParameterDeclarationExpressionCollection

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeParameterDeclarationExpressionCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeTypeParameterCollection
' Interface name = _CodeTypeParameterCollection
' IID = {6E814F1F-C349-3766-B55D-87C9B0232B20}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeTypeParameterCollection_INTERFACE_DEFINED)
'    %SystemCodeTypeParameterCollection_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeTypeParameterCollection $IID__SystemCodeTypeParameterCollection

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeTypeParameterCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeMemberProperty
' Interface name = _CodeMemberProperty
' IID = {802E2ACC-A7F8-3CA9-9114-F49998BEBE6E}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeMemberProperty_INTERFACE_DEFINED)
'    %SystemCodeMemberProperty_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeMemberProperty $IID__SystemCodeMemberProperty

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeMemberProperty_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeMethodInvokeExpression
' Interface name = _CodeMethodInvokeExpression
' IID = {FFE1F142-85CF-3353-8512-EE73775E9C4C}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeMethodInvokeExpression_INTERFACE_DEFINED)
'    %SystemCodeMethodInvokeExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeMethodInvokeExpression $IID__SystemCodeMethodInvokeExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeMethodInvokeExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeMethodReferenceExpression
' Interface name = _CodeMethodReferenceExpression
' IID = {CBDF02F4-A9F4-33C0-8B24-275008890DCB}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeMethodReferenceExpression_INTERFACE_DEFINED)
'    %SystemCodeMethodReferenceExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeMethodReferenceExpression $IID__SystemCodeMethodReferenceExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeMethodReferenceExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeMethodReturnStatement
' Interface name = _CodeMethodReturnStatement
' IID = {851D821B-1E0C-3E91-832D-BA593523F566}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeMethodReturnStatement_INTERFACE_DEFINED)
'    %SystemCodeMethodReturnStatement_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeMethodReturnStatement $IID__SystemCodeMethodReturnStatement

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeMethodReturnStatement_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeNamespace
' Interface name = _CodeNamespace
' IID = {31ED1DCB-C007-3F96-8809-4D5E3540A7C1}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeNamespace_INTERFACE_DEFINED)
'    %SystemCodeNamespace_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeNamespace $IID__SystemCodeNamespace

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeNamespace_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeTypeDeclarationCollection
' Interface name = _CodeTypeDeclarationCollection
' IID = {BE0ECED3-5F0D-310A-B352-7D1ADF28F8EC}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeTypeDeclarationCollection_INTERFACE_DEFINED)
'    %SystemCodeTypeDeclarationCollection_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeTypeDeclarationCollection $IID__SystemCodeTypeDeclarationCollection

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeTypeDeclarationCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeNamespaceImportCollection
' Interface name = _CodeNamespaceImportCollection
' IID = {4C545457-76D7-3C56-B277-6A9E86D1046F}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeNamespaceImportCollection_INTERFACE_DEFINED)
'    %SystemCodeNamespaceImportCollection_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeNamespaceImportCollection $IID__SystemCodeNamespaceImportCollection

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeNamespaceImportCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeNamespaceImport
' Interface name = _CodeNamespaceImport
' IID = {34418787-726B-3E74-AEED-C01397FC707D}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeNamespaceImport_INTERFACE_DEFINED)
'    %SystemCodeNamespaceImport_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeNamespaceImport $IID__SystemCodeNamespaceImport

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeNamespaceImport_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeObjectCreateExpression
' Interface name = _CodeObjectCreateExpression
' IID = {CFE5E5E9-745F-348B-A7E6-38A46D1A20E0}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeObjectCreateExpression_INTERFACE_DEFINED)
'    %SystemCodeObjectCreateExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeObjectCreateExpression $IID__SystemCodeObjectCreateExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeObjectCreateExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeParameterDeclarationExpression
' Interface name = _CodeParameterDeclarationExpression
' IID = {EE96565B-2B1A-33C6-BA07-B63158F1C8C4}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeParameterDeclarationExpression_INTERFACE_DEFINED)
'    %SystemCodeParameterDeclarationExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeParameterDeclarationExpression $IID__SystemCodeParameterDeclarationExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeParameterDeclarationExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodePrimitiveExpression
' Interface name = _CodePrimitiveExpression
' IID = {175BB49A-4CBE-38B3-8C6C-1B0145EDABB7}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodePrimitiveExpression_INTERFACE_DEFINED)
'    %SystemCodePrimitiveExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodePrimitiveExpression $IID__SystemCodePrimitiveExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodePrimitiveExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodePropertyReferenceExpression
' Interface name = _CodePropertyReferenceExpression
' IID = {F8D64802-F9B7-3095-A641-D31E6E9F87B1}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodePropertyReferenceExpression_INTERFACE_DEFINED)
'    %SystemCodePropertyReferenceExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodePropertyReferenceExpression $IID__SystemCodePropertyReferenceExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodePropertyReferenceExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodePropertySetValueReferenceExpression
' Interface name = _CodePropertySetValueReferenceExpression
' IID = {2EE13FA1-8A02-3573-9AC9-4FEBD2CEAB45}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodePropertySetValueReferenceExpression_INTERFACE_DEFINED)
'    %SystemCodePropertySetValueReferenceExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodePropertySetValueReferenceExpression $IID__SystemCodePropertySetValueReferenceExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodePropertySetValueReferenceExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeRegionDirective
' Interface name = _CodeRegionDirective
' IID = {26AE5CC6-CCFD-3906-8B68-16E5EEFABB10}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeRegionDirective_INTERFACE_DEFINED)
'    %SystemCodeRegionDirective_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeRegionDirective $IID__SystemCodeRegionDirective

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeRegionDirective_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeRemoveEventStatement
' Interface name = _CodeRemoveEventStatement
' IID = {853BC437-CA6E-375D-BCBB-818E917D9691}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeRemoveEventStatement_INTERFACE_DEFINED)
'    %SystemCodeRemoveEventStatement_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeRemoveEventStatement $IID__SystemCodeRemoveEventStatement

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeRemoveEventStatement_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeSnippetCompileUnit
' Interface name = _CodeSnippetCompileUnit
' IID = {C7D34CF6-CF82-38B0-BF67-EB36DA63AE6E}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeSnippetCompileUnit_INTERFACE_DEFINED)
'    %SystemCodeSnippetCompileUnit_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeSnippetCompileUnit $IID__SystemCodeSnippetCompileUnit

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeSnippetCompileUnit_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeSnippetExpression
' Interface name = _CodeSnippetExpression
' IID = {9F3E3CD1-8082-31E9-851C-3E177E56A87B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeSnippetExpression_INTERFACE_DEFINED)
'    %SystemCodeSnippetExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeSnippetExpression $IID__SystemCodeSnippetExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeSnippetExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeSnippetStatement
' Interface name = _CodeSnippetStatement
' IID = {B4B00613-C48B-3FA9-B8F6-A527EC6F21C3}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeSnippetStatement_INTERFACE_DEFINED)
'    %SystemCodeSnippetStatement_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeSnippetStatement $IID__SystemCodeSnippetStatement

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeSnippetStatement_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeSnippetTypeMember
' Interface name = _CodeSnippetTypeMember
' IID = {575BF8D0-7A9D-39EB-81F9-AA2BEBA890FA}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeSnippetTypeMember_INTERFACE_DEFINED)
'    %SystemCodeSnippetTypeMember_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeSnippetTypeMember $IID__SystemCodeSnippetTypeMember

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeSnippetTypeMember_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeThisReferenceExpression
' Interface name = _CodeThisReferenceExpression
' IID = {3B4A1A6B-8E65-355D-B93A-E6AB753B2401}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeThisReferenceExpression_INTERFACE_DEFINED)
'    %SystemCodeThisReferenceExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeThisReferenceExpression $IID__SystemCodeThisReferenceExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeThisReferenceExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeThrowExceptionStatement
' Interface name = _CodeThrowExceptionStatement
' IID = {12350E95-6F4E-30F0-9343-72F1C64380A0}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeThrowExceptionStatement_INTERFACE_DEFINED)
'    %SystemCodeThrowExceptionStatement_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeThrowExceptionStatement $IID__SystemCodeThrowExceptionStatement

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeThrowExceptionStatement_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeTryCatchFinallyStatement
' Interface name = _CodeTryCatchFinallyStatement
' IID = {8FD0F76A-29BF-3982-8335-C9B44ABF31C3}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeTryCatchFinallyStatement_INTERFACE_DEFINED)
'    %SystemCodeTryCatchFinallyStatement_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeTryCatchFinallyStatement $IID__SystemCodeTryCatchFinallyStatement

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeTryCatchFinallyStatement_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeTypeConstructor
' Interface name = _CodeTypeConstructor
' IID = {261AD877-0F22-33DE-9A3A-31F5DA424B30}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeTypeConstructor_INTERFACE_DEFINED)
'    %SystemCodeTypeConstructor_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeTypeConstructor $IID__SystemCodeTypeConstructor

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeTypeConstructor_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeTypeDeclaration
' Interface name = _CodeTypeDeclaration
' IID = {7AA363E1-FA53-31EB-BE4A-1EB4838264F3}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeTypeDeclaration_INTERFACE_DEFINED)
'    %SystemCodeTypeDeclaration_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeTypeDeclaration $IID__SystemCodeTypeDeclaration

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeTypeDeclaration_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeTypeMemberCollection
' Interface name = _CodeTypeMemberCollection
' IID = {F943231E-6192-33A0-9CA3-D6ED0E4F323D}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeTypeMemberCollection_INTERFACE_DEFINED)
'    %SystemCodeTypeMemberCollection_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeTypeMemberCollection $IID__SystemCodeTypeMemberCollection

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeTypeMemberCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeTypeDelegate
' Interface name = _CodeTypeDelegate
' IID = {455090AB-5C44-3F4F-8EED-CCC90A3112B5}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeTypeDelegate_INTERFACE_DEFINED)
'    %SystemCodeTypeDelegate_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeTypeDelegate $IID__SystemCodeTypeDelegate

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeTypeDelegate_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeTypeOfExpression
' Interface name = _CodeTypeOfExpression
' IID = {12CBCE8E-75FF-312F-81B9-7FBC6212090B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeTypeOfExpression_INTERFACE_DEFINED)
'    %SystemCodeTypeOfExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeTypeOfExpression $IID__SystemCodeTypeOfExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeTypeOfExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeTypeParameter
' Interface name = _CodeTypeParameter
' IID = {B6ED2127-296F-3B31-AEB5-E2101E98D746}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeTypeParameter_INTERFACE_DEFINED)
'    %SystemCodeTypeParameter_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeTypeParameter $IID__SystemCodeTypeParameter

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeTypeParameter_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeTypeReferenceExpression
' Interface name = _CodeTypeReferenceExpression
' IID = {726BB04D-2C4C-3E3D-A01A-31448DB063DD}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeTypeReferenceExpression_INTERFACE_DEFINED)
'    %SystemCodeTypeReferenceExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeTypeReferenceExpression $IID__SystemCodeTypeReferenceExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeTypeReferenceExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeVariableDeclarationStatement
' Interface name = _CodeVariableDeclarationStatement
' IID = {4192A87C-5C57-3879-8624-AF5CA2ED9EB2}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeVariableDeclarationStatement_INTERFACE_DEFINED)
'    %SystemCodeVariableDeclarationStatement_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeVariableDeclarationStatement $IID__SystemCodeVariableDeclarationStatement

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeVariableDeclarationStatement_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CodeVariableReferenceExpression
' Interface name = _CodeVariableReferenceExpression
' IID = {54B54936-A71C-3A45-B982-2C484E7BCF86}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCodeVariableReferenceExpression_INTERFACE_DEFINED)
'    %SystemCodeVariableReferenceExpression_INTERFACE_DEFINED = 1

'INTERFACE SystemCodeVariableReferenceExpression $IID__SystemCodeVariableReferenceExpression

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCodeVariableReferenceExpression_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = component
' Interface name = _Component
' IID = {06565C0F-C465-37DE-896F-9864BC0BFC96}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemComponent_INTERFACE_DEFINED)
'    %SystemComponent_INTERFACE_DEFINED = 1

'INTERFACE SystemComponent $IID__SystemComponent

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemComponent_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = AttributeCollection
' Interface name = _AttributeCollection
' IID = {6F971E04-B06A-3DD0-B6F5-622826693454}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemAttributeCollection_INTERFACE_DEFINED)
'    %SystemAttributeCollection_INTERFACE_DEFINED = 1

'INTERFACE SystemAttributeCollection $IID__SystemAttributeCollection

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemAttributeCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = PropertyDescriptor
' Interface name = _PropertyDescriptor
' IID = {FE5060F8-212F-3A4F-8FA8-DB2E14588C49}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemPropertyDescriptor_INTERFACE_DEFINED)
'    %SystemPropertyDescriptor_INTERFACE_DEFINED = 1

'INTERFACE SystemPropertyDescriptor $IID__SystemPropertyDescriptor

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemPropertyDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = ComponentCollection
' Interface name = _ComponentCollection
' IID = {42F00C62-F454-3A38-AF9E-35D4E2BDFDAC}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemComponentCollection_INTERFACE_DEFINED)
'    %SystemComponentCollection_INTERFACE_DEFINED = 1

'INTERFACE SystemComponentCollection $IID__SystemComponentCollection

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemComponentCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = EventDescriptor
' Interface name = _EventDescriptor
' IID = {95B6A563-4A39-37A2-91D7-04B8ECDD1B66}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemEventDescriptor_INTERFACE_DEFINED)
'    %SystemEventDescriptor_INTERFACE_DEFINED = 1

'INTERFACE SystemEventDescriptor $IID__SystemEventDescriptor

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemEventDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = EventDescriptorCollection
' Interface name = _EventDescriptorCollection
' IID = {4C933253-83F2-35B6-961A-0780FF1BAF7C}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemEventDescriptorCollection_INTERFACE_DEFINED)
'    %SystemEventDescriptorCollection_INTERFACE_DEFINED = 1

'INTERFACE SystemEventDescriptorCollection $IID__SystemEventDescriptorCollection

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemEventDescriptorCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = MemberDescriptor
' Interface name = _MemberDescriptor
' IID = {F55EFA91-812E-3C6E-998F-3598E93FB8A7}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemMemberDescriptor_INTERFACE_DEFINED)
'    %SystemMemberDescriptor_INTERFACE_DEFINED = 1

'INTERFACE SystemMemberDescriptor $IID__SystemMemberDescriptor

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemMemberDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = MarshalByValueComponent
' Interface name = _MarshalByValueComponent
' IID = {35F38044-2017-3E05-BA83-1B87CC0D49C7}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemMarshalByValueComponent_INTERFACE_DEFINED)
'    %SystemMarshalByValueComponent_INTERFACE_DEFINED = 1

'INTERFACE SystemMarshalByValueComponent $IID__SystemMarshalByValueComponent

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemMarshalByValueComponent_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = CommandID
' Interface name = _CommandID
' IID = {FC50598B-2406-33D2-BA9A-CFBEA52BC05A}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemCommandID_INTERFACE_DEFINED)
'    %SystemCommandID_INTERFACE_DEFINED = 1

'INTERFACE SystemCommandID $IID__SystemCommandID

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemCommandID_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = ComponentChangedEventArgs
' Interface name = _ComponentChangedEventArgs
' IID = {A8FEF1C6-D434-3686-A4DE-B68E8EABB509}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemComponentChangedEventArgs_INTERFACE_DEFINED)
'    %SystemComponentChangedEventArgs_INTERFACE_DEFINED = 1

'INTERFACE SystemComponentChangedEventArgs $IID__SystemComponentChangedEventArgs

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemComponentChangedEventArgs_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = ComponentChangedEventHandler
' Interface name = _ComponentChangedEventHandler
' IID = {0451C390-1F90-341D-9278-B9FF2636D67D}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemComponentChangedEventHandler_INTERFACE_DEFINED)
'    %SystemComponentChangedEventHandler_INTERFACE_DEFINED = 1

'INTERFACE SystemComponentChangedEventHandler $IID__SystemComponentChangedEventHandler

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemComponentChangedEventHandler_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = ComponentChangingEventArgs
' Interface name = _ComponentChangingEventArgs
' IID = {B78CBAA3-37DF-31C9-ABD2-CDCB1A7FBA9F}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemComponentChangingEventArgs_INTERFACE_DEFINED)
'    %SystemComponentChangingEventArgs_INTERFACE_DEFINED = 1

'INTERFACE SystemComponentChangingEventArgs $IID__SystemComponentChangingEventArgs

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemComponentChangingEventArgs_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = ComponentChangingEventHandler
' Interface name = _ComponentChangingEventHandler
' IID = {7F8C2DA3-D337-334F-92E9-87BE9BDC6070}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemComponentChangingEventHandler_INTERFACE_DEFINED)
'    %SystemComponentChangingEventHandler_INTERFACE_DEFINED = 1

'INTERFACE SystemComponentChangingEventHandler $IID__SystemComponentChangingEventHandler

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemComponentChangingEventHandler_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = ComponentEventArgs
' Interface name = _ComponentEventArgs
' IID = {438E8DCF-6875-305F-8CA5-40DBB15782A6}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemComponentEventArgs_INTERFACE_DEFINED)
'    %SystemComponentEventArgs_INTERFACE_DEFINED = 1

'INTERFACE SystemComponentEventArgs $IID__SystemComponentEventArgs

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemComponentEventArgs_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = ComponentEventHandler
' Interface name = _ComponentEventHandler
' IID = {290B355D-80D3-3AFA-96AB-B4D395729374}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemComponentEventHandler_INTERFACE_DEFINED)
'    %SystemComponentEventHandler_INTERFACE_DEFINED = 1

'INTERFACE SystemComponentEventHandler $IID__SystemComponentEventHandler

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemComponentEventHandler_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = ComponentRenameEventArgs
' Interface name = _ComponentRenameEventArgs
' IID = {DA5D7739-9522-3E28-9AB7-7C2D7D27C63A}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemComponentRenameEventArgs_INTERFACE_DEFINED)
'    %SystemComponentRenameEventArgs_INTERFACE_DEFINED = 1

'INTERFACE SystemComponentRenameEventArgs $IID__SystemComponentRenameEventArgs

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemComponentRenameEventArgs_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = ComponentRenameEventHandler
' Interface name = _ComponentRenameEventHandler
' IID = {BA2DF049-DA87-3BD1-97B0-7904B59ADF7E}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemComponentRenameEventHandler_INTERFACE_DEFINED)
'    %SystemComponentRenameEventHandler_INTERFACE_DEFINED = 1

'INTERFACE SystemComponentRenameEventHandler $IID__SystemComponentRenameEventHandler

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemComponentRenameEventHandler_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = DesignerTransactionCloseEventArgs
' Interface name = _DesignerTransactionCloseEventArgs
' IID = {3924A637-C2C4-3558-945F-279B5AC39ED9}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemDesignerTransactionCloseEventArgs_INTERFACE_DEFINED)
'    %SystemDesignerTransactionCloseEventArgs_INTERFACE_DEFINED = 1

'INTERFACE SystemDesignerTransactionCloseEventArgs $IID__SystemDesignerTransactionCloseEventArgs

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemDesignerTransactionCloseEventArgs_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = DesignerTransactionCloseEventHandler
' Interface name = _DesignerTransactionCloseEventHandler
' IID = {4543D155-EE6A-3529-BC8D-CF0E866B6B0B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemDesignerTransactionCloseEventHandler_INTERFACE_DEFINED)
'    %SystemDesignerTransactionCloseEventHandler_INTERFACE_DEFINED = 1

'INTERFACE SystemDesignerTransactionCloseEventHandler $IID__SystemDesignerTransactionCloseEventHandler

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemDesignerTransactionCloseEventHandler_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = DesignerVerb
' Interface name = _DesignerVerb
' IID = {7C41B90E-52FB-3E54-8B03-EBE0BF172C84}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemDesignerVerb_INTERFACE_DEFINED)
'    %SystemDesignerVerb_INTERFACE_DEFINED = 1

'INTERFACE SystemDesignerVerb $IID__SystemDesignerVerb

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemDesignerVerb_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = MenuCommand
' Interface name = _MenuCommand
' IID = {1FF238CE-6190-3750-A34F-05F02B7315A6}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemMenuCommand_INTERFACE_DEFINED)
'    %SystemMenuCommand_INTERFACE_DEFINED = 1

'INTERFACE SystemMenuCommand $IID__SystemMenuCommand

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemMenuCommand_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = DesignerVerbCollection
' Interface name = _DesignerVerbCollection
' IID = {AC3BDDA4-25B8-3321-A1C0-7C37BBF2DDED}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemDesignerVerbCollection_INTERFACE_DEFINED)
'    %SystemDesignerVerbCollection_INTERFACE_DEFINED = 1

'INTERFACE SystemDesignerVerbCollection $IID__SystemDesignerVerbCollection

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemDesignerVerbCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = ServiceCreatorCallback
' Interface name = _ServiceCreatorCallback
' IID = {BE380BEC-79F2-3876-B510-FA2FE43B7EB7}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemServiceCreatorCallback_INTERFACE_DEFINED)
'    %SystemServiceCreatorCallback_INTERFACE_DEFINED = 1

'INTERFACE SystemServiceCreatorCallback $IID__SystemServiceCreatorCallback

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemServiceCreatorCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = DesignerLoader
' Interface name = _DesignerLoader
' IID = {43BE964C-1B4A-3D1F-9D94-8185A1E6CB7B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemDesignerLoader_INTERFACE_DEFINED)
'    %SystemDesignerLoader_INTERFACE_DEFINED = 1

'INTERFACE SystemDesignerLoader $IID__SystemDesignerLoader

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemDesignerLoader_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = PerformanceCounterManager
' Interface name = _PerformanceCounterManager
' IID = {A9809E7D-42F8-3284-82CF-AB5F863A29AA}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemPerformanceCounterManager_INTERFACE_DEFINED)
'    %SystemPerformanceCounterManager_INTERFACE_DEFINED = 1

'INTERFACE SystemPerformanceCounterManager $IID__SystemPerformanceCounterManager

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemPerformanceCounterManager_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = WebHeaderCollection
' Interface name = _WebHeaderCollection
' IID = {B97E84F2-FAB2-340D-8D49-2AC85CF5C0EC}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemWebHeaderCollection_INTERFACE_DEFINED)
'    %SystemWebHeaderCollection_INTERFACE_DEFINED = 1

'INTERFACE SystemWebHeaderCollection $IID__SystemWebHeaderCollection

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemWebHeaderCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = WebClient
' Interface name = _WebClient
' IID = {85B4A627-7552-3AA6-8A1C-A213C5788FEC}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemWebClient_INTERFACE_DEFINED)
'    %SystemWebClient_INTERFACE_DEFINED = 1

'INTERFACE SystemWebClient $IID__SystemWebClient

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemWebClient_INTERFACE_DEFINED__ */

' ########################################################################################
' CoClass name = StandardOleMarshalObject
' Interface name = _StandardOleMarshalObject
' IID = {05F3D6C7-D4D1-37EB-AC35-63347B838A23}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%SystemStandardOleMarshalObject_INTERFACE_DEFINED)
'    %SystemStandardOleMarshalObject_INTERFACE_DEFINED = 1

'INTERFACE SystemStandardOleMarshalObject $IID__SystemStandardOleMarshalObject

'   INHERIT IDispatch

'END INTERFACE

'#ENDIF   ' /* __SystemStandardOleMarshalObject_INTERFACE_DEFINED__ */
