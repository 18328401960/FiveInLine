# Microsoft Developer Studio Project File - Name="FiveInLine" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=FiveInLine - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "FiveInLine.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "FiveInLine.mak" CFG="FiveInLine - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "FiveInLine - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "FiveInLine - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "FiveInLine - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "FiveInLine - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "FiveInLine - Win32 Release"
# Name "FiveInLine - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ColorBtn.cpp
# End Source File
# Begin Source File

SOURCE=.\ColorStatic.cpp
# End Source File
# Begin Source File

SOURCE=.\FiveInLine.cpp
# End Source File
# Begin Source File

SOURCE=.\FiveInLine.rc
# End Source File
# Begin Source File

SOURCE=.\FiveInLineDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainGameDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ColorBtn.h
# End Source File
# Begin Source File

SOURCE=.\ColorStatic.h
# End Source File
# Begin Source File

SOURCE=.\FiveInLine.h
# End Source File
# Begin Source File

SOURCE=.\FiveInLineDlg.h
# End Source File
# Begin Source File

SOURCE=.\MainGameDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\114.bmp
# End Source File
# Begin Source File

SOURCE=.\res\115.bmp
# End Source File
# Begin Source File

SOURCE=.\res\116.bmp
# End Source File
# Begin Source File

SOURCE=.\res\117.bmp
# End Source File
# Begin Source File

SOURCE=.\res\119.bmp
# End Source File
# Begin Source File

SOURCE=.\res\123.bmp
# End Source File
# Begin Source File

SOURCE=.\res\124.BMP
# End Source File
# Begin Source File

SOURCE=.\res\125.bmp
# End Source File
# Begin Source File

SOURCE=.\res\126.BMP
# End Source File
# Begin Source File

SOURCE=.\res\128.bmp
# End Source File
# Begin Source File

SOURCE=.\res\129.bmp
# End Source File
# Begin Source File

SOURCE=.\res\131.bmp
# End Source File
# Begin Source File

SOURCE=.\res\132.bmp
# End Source File
# Begin Source File

SOURCE=.\res\background.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btn1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btn2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Document0000.cur
# End Source File
# Begin Source File

SOURCE=.\res\Document0005.cur
# End Source File
# Begin Source File

SOURCE=.\res\FiveInLine.ico
# End Source File
# Begin Source File

SOURCE=.\res\FiveInLine.rc2
# End Source File
# Begin Source File

SOURCE=".\res\flat-02.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\HAND.CUR
# End Source File
# Begin Source File

SOURCE=.\res\hand_v.cur
# End Source File
# Begin Source File

SOURCE=".\res\����1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\����2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\�˳���Ϸ1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\�˳���Ϸ2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\���ֹ�.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\���ֿ�.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\���¿�ʼ1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\���¿�ʼ2.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
