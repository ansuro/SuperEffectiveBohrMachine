///////////////////////////////////////////////////////////////////////////////
// ModuleController.cpp
#include "TcPch.h"
#pragma hdrstop

#include "ModuleController.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
DEFINE_THIS_FILE()

///////////////////////////////////////////////////////////////////////////////
// CModuleController
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Collection of interfaces implemented by module CModuleController
BEGIN_INTERFACE_MAP(CModuleController)
	INTERFACE_ENTRY_ITCOMOBJECT()
	INTERFACE_ENTRY(IID_ITcADI, ITcADI)
	INTERFACE_ENTRY(IID_ITcWatchSource, ITcWatchSource)
///<AutoGeneratedContent id="InterfaceMap">
	INTERFACE_ENTRY(IID_ITcCyclic, ITcCyclic)
///</AutoGeneratedContent>
END_INTERFACE_MAP()


IMPLEMENT_ITCOMOBJECT(CModuleController)
IMPLEMENT_ITCOMOBJECT_SETSTATE_LOCKOP2(CModuleController)
IMPLEMENT_ITCADI(CModuleController)
IMPLEMENT_ITCWATCHSOURCE(CModuleController)


///////////////////////////////////////////////////////////////////////////////
// Set parameters of CModuleController 
BEGIN_SETOBJPARA_MAP(CModuleController)
	SETOBJPARA_DATAAREA_MAP()
///<AutoGeneratedContent id="SetObjectParameterMap">
	SETOBJPARA_VALUE(PID_TcTraceLevel, m_TraceLevelMax)
	SETOBJPARA_ITFPTR(PID_Ctx_TaskOid, m_spCyclicCaller)
	SETOBJPARA_ITFPTR(PID_ModuleControllerBohrmaschine, m_spBohrmaschine)
	SETOBJPARA_ITFPTR(PID_ModuleControllerTransportMaster, m_spTransportMaster)
	SETOBJPARA_ITFPTR(PID_ModuleControllerTransportSlave, m_spTransportSlave)
///</AutoGeneratedContent>
END_SETOBJPARA_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get parameters of CModuleController 
BEGIN_GETOBJPARA_MAP(CModuleController)
	GETOBJPARA_DATAAREA_MAP()
///<AutoGeneratedContent id="GetObjectParameterMap">
	GETOBJPARA_VALUE(PID_TcTraceLevel, m_TraceLevelMax)
	GETOBJPARA_ITFPTR(PID_Ctx_TaskOid, m_spCyclicCaller)
	GETOBJPARA_ITFPTR(PID_ModuleControllerBohrmaschine, m_spBohrmaschine)
	GETOBJPARA_ITFPTR(PID_ModuleControllerTransportMaster, m_spTransportMaster)
	GETOBJPARA_ITFPTR(PID_ModuleControllerTransportSlave, m_spTransportSlave)
///</AutoGeneratedContent>
END_GETOBJPARA_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get watch entries of CModuleController
BEGIN_OBJPARAWATCH_MAP(CModuleController)
	OBJPARAWATCH_DATAAREA_MAP()
///<AutoGeneratedContent id="ObjectParameterWatchMap">
///</AutoGeneratedContent>
END_OBJPARAWATCH_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get data area members of CModuleController
BEGIN_OBJDATAAREA_MAP(CModuleController)
///<AutoGeneratedContent id="ObjectDataAreaMap">
	OBJDATAAREA_VALUE(ADI_ModuleControllerInputs, m_Inputs)
	OBJDATAAREA_VALUE(ADI_ModuleControllerUIControls, m_UIControls)
	OBJDATAAREA_VALUE(ADI_ModuleControllerState, m_State)
///</AutoGeneratedContent>
END_OBJDATAAREA_MAP()


///////////////////////////////////////////////////////////////////////////////
CModuleController::CModuleController()
	: m_Trace(m_TraceLevelMax, m_spSrv)
{
///<AutoGeneratedContent id="MemberInitialization">
	m_TraceLevelMax = tlAlways;
	memset(&m_Inputs, 0, sizeof(m_Inputs));
	memset(&m_UIControls, 0, sizeof(m_UIControls));
	memset(&m_State, 0, sizeof(m_State));
///</AutoGeneratedContent>
}

///////////////////////////////////////////////////////////////////////////////
CModuleController::~CModuleController() 
{
}


///////////////////////////////////////////////////////////////////////////////
// State Transitions 
///////////////////////////////////////////////////////////////////////////////
IMPLEMENT_ITCOMOBJECT_SETOBJSTATE_IP_PI(CModuleController)

///////////////////////////////////////////////////////////////////////////////
// State transition from PREOP to SAFEOP
//
// Initialize input parameters 
// Allocate memory
HRESULT CModuleController::SetObjStatePS(PTComInitDataHdr pInitData)
{
	m_Trace.Log(tlVerbose, FENTERA);
	HRESULT hr = S_OK;
	IMPLEMENT_ITCOMOBJECT_EVALUATE_INITDATA(pInitData);

	// TODO: Add initialization code

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from SAFEOP to OP
//
// Register with other TwinCAT objects
HRESULT CModuleController::SetObjStateSO()
{
	m_Trace.Log(tlVerbose, FENTERA);
	HRESULT hr = S_OK;

	// TODO: Add any additional initialization
	m_State.eZustand = Zustand::stopped;

	// If following call is successful the CycleUpdate method will be called, 
	// possibly even before method has been left.
	hr = FAILED(hr) ? hr : AddModuleToCaller(); 

	// Cleanup if transition failed at some stage
	if ( FAILED(hr) )
	{
		RemoveModuleFromCaller(); 
	}

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from OP to SAFEOP
HRESULT CModuleController::SetObjStateOS()
{
	m_Trace.Log(tlVerbose, FENTERA);

	HRESULT hr = S_OK;

	RemoveModuleFromCaller(); 

	// TODO: Add any additional deinitialization
	m_spBohrmaschine = NULL;
	m_spTransportMaster = NULL;
	m_spTransportSlave = NULL;

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from SAFEOP to PREOP
HRESULT CModuleController::SetObjStateSP()
{
	HRESULT hr = S_OK;
	m_Trace.Log(tlVerbose, FENTERA);

	// TODO: Add deinitialization code

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///<AutoGeneratedContent id="ImplementationOf_ITcCyclic">
HRESULT CModuleController::CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context)
{
	HRESULT hr = S_OK;

	// init interface pointers
	if (!initialized)
	{
		init();
	}
	else
	{
		loop();
	}
	

	return hr;
}
///</AutoGeneratedContent>

///////////////////////////////////////////////////////////////////////////////
HRESULT CModuleController::AddModuleToCaller()
{
	m_Trace.Log(tlVerbose, FENTERA);

	HRESULT hr = S_OK;
	if ( m_spCyclicCaller.HasOID() )
	{
		if ( SUCCEEDED_DBG(hr = m_spSrv->TcQuerySmartObjectInterface(m_spCyclicCaller)) )
		{
			if ( FAILED(hr = m_spCyclicCaller->AddModule(m_spCyclicCaller, THIS_CAST(ITcCyclic))) )
			{
				m_spCyclicCaller = NULL;
			}
		}
	}
	else
	{
		hr = ADS_E_INVALIDOBJID; 
		SUCCEEDED_DBGT(hr, "Invalid OID specified for caller task");
	}

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
VOID CModuleController::RemoveModuleFromCaller()
{
	m_Trace.Log(tlVerbose, FENTERA);

	if ( m_spCyclicCaller )
	{
		m_spCyclicCaller->RemoveModule(m_spCyclicCaller);
	}
	m_spCyclicCaller	= NULL;

	m_Trace.Log(tlVerbose, FLEAVEA);
}

void CModuleController::init()
{
	if (m_spBohrmaschine == NULL && m_Inputs.oidBohrmaschine != 0)
	{
		m_spBohrmaschine.SetOID(m_Inputs.oidBohrmaschine);
		m_spSrv->TcQuerySmartObjectInterface(m_spBohrmaschine);
	}

	if (m_spTransportMaster == NULL && m_Inputs.oidTransportA)
	{
		m_spTransportMaster.SetOID(m_Inputs.oidTransportA);
		m_spSrv->TcQuerySmartObjectInterface(m_spTransportMaster);
	}

	if (m_spTransportSlave == NULL && m_Inputs.oidTransportB)
	{
		m_spTransportSlave.SetOID(m_Inputs.oidTransportB);
		m_spSrv->TcQuerySmartObjectInterface(m_spTransportSlave);
	}

	initialized = m_spBohrmaschine != NULL && m_spTransportMaster != NULL && m_spTransportSlave != NULL;
}

/*
TODO morgen
- Zustand der Ger�te outputten und hier inputten (zum Testen ob alle gestoppt sind)
- ConfigStruct erstellen. Anlage erst startbar machen, nachdem g�ltige Konfig gesetzt wurde
- UI vorbereiten (Set Config, start, stop, Status / Zustand der einzelnen Ger�te)
*/

// statemachine loop
void CModuleController::loop()
{
	switch (m_State.eZustand)
	{
	case Zustand::started:
		this->started();
		break;

	case Zustand::starting:
		this->starting();
		break;

	case Zustand::stopped:
		this->stopped();
		break;

	case Zustand::stopping:
		this->stopping();
		break;

	default:
		break;
	}
}

/*
- auf UI-Stop lauschen -> alle Ger�te stoppen
*/
void CModuleController::started()
{
}

/*
- Transport A + B starten, Bohrer (Werkst�ckgr��e) konfigurieren
- in Zustand 'started' switchen
*/
void CModuleController::starting()
{
}

// auf UI-Start lauschen
void CModuleController::stopped()
{
}

/*
- alle Ger�te stoppen und auf deren Stop warten
- danach in Zustand 'Stopped' wechseln
*/
void CModuleController::stopping()
{
}

