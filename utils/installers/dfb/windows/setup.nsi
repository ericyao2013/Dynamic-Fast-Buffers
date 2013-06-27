# Auto-generated by EclipseNSIS Script Wizard
# Jun 20, 2013 10:40:30 AM

Name "Dynamic Fast Buffers"

# General Symbol Definitions
!define REGKEY "SOFTWARE\$(^Name)"
!define VERSION 0.1
!define COMPANY eProsima
!define URL www.eprosima.com

# MUI Symbol Definitions
!define MUI_ICON "${NSISDIR}\Contrib\Graphics\Icons\modern-install.ico"
!define MUI_FINISHPAGE_NOAUTOCLOSE
!define MUI_FINISHPAGE_SHOWREADME $INSTDIR\README.html
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\modern-uninstall.ico"
!define MUI_UNFINISHPAGE_NOAUTOCLOSE

# Included files
!include Sections.nsh
!include MUI2.nsh
!include EnvVarUpdate.nsh

# Installer pages
!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_LICENSE ..\..\..\..\DYNAMIC_FAST_BUFFERS_LICENSE.txt
!define MUI_PAGE_CUSTOMFUNCTION_LEAVE ComponentsPageLeave
!insertmacro MUI_PAGE_COMPONENTS
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES

# Installer languages
!insertmacro MUI_LANGUAGE English

# Installer attributes
OutFile eProsima_Dynamic_Fast_Buffers-0.1.exe
InstallDir "$PROGRAMFILES\eProsima\Dynamic Fast Buffers"
CRCCheck on
XPStyle on
ShowInstDetails show
VIProductVersion 0.1.0.0
VIAddVersionKey /LANG=${LANG_ENGLISH} ProductName "Dynamic Fast Buffers"
VIAddVersionKey /LANG=${LANG_ENGLISH} ProductVersion "${VERSION}"
VIAddVersionKey /LANG=${LANG_ENGLISH} CompanyName "${COMPANY}"
VIAddVersionKey /LANG=${LANG_ENGLISH} CompanyWebsite "${URL}"
VIAddVersionKey /LANG=${LANG_ENGLISH} FileVersion "${VERSION}"
VIAddVersionKey /LANG=${LANG_ENGLISH} FileDescription ""
VIAddVersionKey /LANG=${LANG_ENGLISH} LegalCopyright ""
InstallDirRegKey HKLM "${REGKEY}" Path
ShowUninstDetails show

# Installer sections
Section "Main Files" SEC0000
SectionIn RO
    SetOutPath $INSTDIR\doc\html
    SetOverwrite on
    File /r ..\..\..\..\doc\html\*
    SetOutPath $INSTDIR\doc\pdf
    File /r ..\..\..\..\doc\pdf\*
    SetOutPath $INSTDIR\examples
    File /r ..\..\..\..\examples\*
    SetOutPath $INSTDIR\include
    File /r ..\..\..\..\include\*
    SetOutPath $INSTDIR
    File ..\..\..\..\DYNAMIC_FAST_BUFFERS_LICENSE.txt
    File ..\..\..\..\LGPLv3_LICENSE.txt
    File ..\..\..\..\README.html
    WriteRegStr HKLM "${REGKEY}\Components" "Main Files" 1
SectionEnd

SectionGroup /e Libraries SECGRP0000
    Section "x64 libraries" SEC0001
        SetOutPath $INSTDIR\lib\x64Win64VS2010
        SetOverwrite on
        File /r ..\..\..\..\lib\x64Win64VS2010\*
        WriteRegStr HKLM "${REGKEY}\Components" "x64 libraries" 1
    SectionEnd

    Section "i86 libraries" SEC0002
        SetOutPath $INSTDIR\lib\i86Win32VS2010
        SetOverwrite on
        File /r ..\..\..\..\lib\i86Win32VS2010\*
        WriteRegStr HKLM "${REGKEY}\Components" "i86 libraries" 1
    SectionEnd
SectionGroupEnd

SectionGroup "Environment variables" SECGRP0001
    Section "x64 libraries location" SEC0003
       ${EnvVarUpdate} $0 "PATH" "A" "HKLM" "$INSTDIR\lib\x64Win64VS2010"
       WriteRegStr HKLM "${REGKEY}\Components" "x64 libraries location" 1
    SectionEnd
    Section "i86 libraries location" SEC0004
       ${EnvVarUpdate} $0 "PATH" "A" "HKLM" "$INSTDIR\lib\i86Win32VS2010"
       WriteRegStr HKLM "${REGKEY}\Components" "i86 libraries location" 1
    SectionEnd
SectionGroupEnd

Section -post SEC0006
    WriteRegStr HKLM "${REGKEY}" Path $INSTDIR
    SetOutPath $INSTDIR
    WriteUninstaller $INSTDIR\uninstall.exe
    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" DisplayName "$(^Name)"
    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" DisplayVersion "${VERSION}"
    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" Publisher "${COMPANY}"
    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" URLInfoAbout "${URL}"
    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" DisplayIcon $INSTDIR\uninstall.exe
    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" UninstallString $INSTDIR\uninstall.exe
    WriteRegDWORD HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" NoModify 1
    WriteRegDWORD HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" NoRepair 1
SectionEnd

# Macro for selecting uninstaller sections
!macro SELECT_UNSECTION SECTION_NAME UNSECTION_ID
    Push $R0
    ReadRegStr $R0 HKLM "${REGKEY}\Components" "${SECTION_NAME}"
    StrCmp $R0 1 0 next${UNSECTION_ID}
    !insertmacro SelectSection "${UNSECTION_ID}"
    GoTo done${UNSECTION_ID}
next${UNSECTION_ID}:
    !insertmacro UnselectSection "${UNSECTION_ID}"
done${UNSECTION_ID}:
    Pop $R0
!macroend

# Uninstaller sections
Section /o "-un.i86 libraries" UNSEC0002
    RmDir /r /REBOOTOK $INSTDIR\lib\i86Win32VS2010
    DeleteRegValue HKLM "${REGKEY}\Components" "i86 libraries"
SectionEnd

Section /o "-un.x64 libraries" UNSEC0001
    RmDir /r /REBOOTOK $INSTDIR\lib\x64Win64VS2010
    DeleteRegValue HKLM "${REGKEY}\Components" "x64 libraries"
SectionEnd

Section /o "-un.Main Files" UNSEC0000
    Delete /REBOOTOK $INSTDIR\README.html
    Delete /REBOOTOK $INSTDIR\LGPLv3_LICENSE.txt
    Delete /REBOOTOK $INSTDIR\DYNAMIC_FAST_BUFFERS_LICENSE.txt
    RmDir /r /REBOOTOK $INSTDIR\include
    RmDir /r /REBOOTOK $INSTDIR\examples
    RmDir /r /REBOOTOK $INSTDIR\doc\pdf
    RmDir /r /REBOOTOK $INSTDIR\doc\html
    RmDir /r /REBOOTOK $INSTDIR\lib
    DeleteRegValue HKLM "${REGKEY}\Components" "Main Files"
SectionEnd

Section /o "-un.i86 libraries location" UNSEC0004
    DeleteRegValue HKLM "${REGKEY}\Components" "i86 libraries location"
SectionEnd

Section /o "-un.x64 libraries location" UNSEC0003
    DeleteRegValue HKLM "${REGKEY}\Components" "x64 libraries location"
SectionEnd

Section -un.post UNSEC0006
    DeleteRegKey HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)"
    Delete /REBOOTOK $INSTDIR\uninstall.exe
    DeleteRegValue HKLM "${REGKEY}" Path
    DeleteRegKey /IfEmpty HKLM "${REGKEY}\Components"
    DeleteRegKey /IfEmpty HKLM "${REGKEY}"
    RmDir /REBOOTOK $INSTDIR
SectionEnd

# Installer functions
Function .onInit
    InitPluginsDir
    Push $R1
    File /oname=$PLUGINSDIR\spltmp.jpg "$%EPROSIMADIR%\logo\eProsimaLogoAndNameFinal_wBorder_460.jpg"
    newadvsplash::show 1000 600 400 -1 "$PLUGINSDIR\spltmp.jpg"
    Pop $R1
    Pop $R1
FunctionEnd

Function ComponentsPageLeave
  ${Unless} ${SectionIsSelected} ${SEC0001}
  ${AndUnless} ${SectionIsSelected} ${SEC0002}
    MessageBox MB_OK|MB_ICONINFORMATION `Please select at least one library component.`
    Abort
  ${EndUnless}
FunctionEnd

# Uninstaller functions
Function un.onInit
    ReadRegStr $INSTDIR HKLM "${REGKEY}" Path
    !insertmacro SELECT_UNSECTION "Main Files" ${UNSEC0000}
    !insertmacro SELECT_UNSECTION "x64 libraries" ${UNSEC0001}
    !insertmacro SELECT_UNSECTION "i86 libraries" ${UNSEC0002}
    !insertmacro SELECT_UNSECTION "x64 libraries location" ${UNSEC0003}
    !insertmacro SELECT_UNSECTION "i86 libraries location" ${UNSEC0004}
FunctionEnd

# Section Descriptions
!insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
!insertmacro MUI_DESCRIPTION_TEXT ${SECGRP0000} $(SECGRP0000_DESC)
!insertmacro MUI_DESCRIPTION_TEXT ${SEC0001} $(SEC0001_DESC)
!insertmacro MUI_DESCRIPTION_TEXT ${SEC0002} $(SEC0002_DESC)
!insertmacro MUI_DESCRIPTION_TEXT ${SECGRP0001} $(SECGRP0001_DESC)
!insertmacro MUI_DESCRIPTION_TEXT ${SEC0003} $(SEC0003_DESC)
!insertmacro MUI_DESCRIPTION_TEXT ${SEC0003} $(SEC0004_DESC)
!insertmacro MUI_FUNCTION_DESCRIPTION_END

# Installer Language Strings
# TODO Update the Language Strings with the appropriate translations.

LangString SECGRP0000_DESC ${LANG_ENGLISH} "Select whether to install 32-bit or 64-bit libraries"
LangString SEC0001_DESC ${LANG_ENGLISH} "64-bit libraries"
LangString SEC0002_DESC ${LANG_ENGLISH} "32-bit libraries"
LangString SECGRP0001_DESC ${LANG_ENGLISH} "Select whether to set environment variables"
LangString SEC0003_DESC ${LANG_ENGLISH} "32-bit environment variable set"
LangString SEC0004_DESC ${LANG_ENGLISH} "64-bit environment variable set"