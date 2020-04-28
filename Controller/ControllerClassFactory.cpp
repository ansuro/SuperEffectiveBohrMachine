///////////////////////////////////////////////////////////////////////////////
// ControllerClassFactory.cpp
#include "TcPch.h"
#pragma hdrstop

#include "ControllerClassFactory.h"
#include "ControllerServices.h"
#include "ControllerVersion.h"
#include "ModuleController.h"

BEGIN_CLASS_MAP(CControllerClassFactory)
///<AutoGeneratedContent id="ClassMap">
	CLASS_ENTRY(CID_ControllerCModuleController, SRVNAME_CONTROLLER "!CModuleController", CModuleController)
///</AutoGeneratedContent>
END_CLASS_MAP()

CControllerClassFactory::CControllerClassFactory() : CObjClassFactory()
{
	TcDbgUnitSetImageName(TCDBG_UNIT_IMAGE_NAME(SRVNAME_CONTROLLER));
#if defined(TCDBG_UNIT_VERSION)
	TcDbgUnitSetVersion(TCDBG_UNIT_VERSION(Controller));
#endif //defined(TCDBG_UNIT_VERSION)
}

