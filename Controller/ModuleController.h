///////////////////////////////////////////////////////////////////////////////
// ModuleController.h
#pragma once

#include "ControllerInterfaces.h"

class CModuleController 
	: public ITComObject
	, public ITcADI
	, public ITcWatchSource
///<AutoGeneratedContent id="InheritanceList">
	, public ITcCyclic
///</AutoGeneratedContent>
{
public:
	DECLARE_IUNKNOWN()
	DECLARE_IPERSIST(CID_ControllerCModuleController)
	DECLARE_ITCOMOBJECT_LOCKOP()
	DECLARE_ITCADI()
	DECLARE_ITCWATCHSOURCE()
	DECLARE_OBJPARAWATCH_MAP()
	DECLARE_OBJDATAAREA_MAP()

	CModuleController();
	virtual	~CModuleController();


///<AutoGeneratedContent id="InterfaceMembers">
	// ITcCyclic
	virtual HRESULT TCOMAPI CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context);

///</AutoGeneratedContent>

protected:
	DECLARE_ITCOMOBJECT_SETSTATE();

	HRESULT AddModuleToCaller();
	VOID RemoveModuleFromCaller();

	// Tracing
	CTcTrace m_Trace;

///<AutoGeneratedContent id="Members">
	TcTraceLevel m_TraceLevelMax;
	ModuleControllerInputIPointers m_InputIPointers;
	ModuleControllerUIControls m_UIControls;
	ModuleControllerState m_State;
	ModuleControllerTransportA m_TransportA;
	ModuleControllerBohrmaschine m_Bohrmaschine;
	ModuleControllerTransportB m_TransportB;
	ITcCyclicCallerInfoPtr m_spCyclicCaller;
	I_BohrmaschinePtr m_spBohrmaschine;
	I_TransportPtr m_spTransportMaster;
	I_TransportSlavePtr m_spTransportSlave;
///</AutoGeneratedContent>

private:
	// interface pointer initialization
	bool initialized = false;		// interface pointer initialized?
	void init();

	// statemachine loops
	void loop();
	void started();
	void starting();
	void stopped();
	void stopping();
	void operatingLoop();

	// UI update
	void updateUI();
};
