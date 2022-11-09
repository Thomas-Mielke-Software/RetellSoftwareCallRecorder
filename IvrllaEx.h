//////////////////////////////////////////////////////////////////////////
// Include this file into your C++ application if you using IvrllaClass
//////////////////////////////////////////////////////////////////////////
#include "IvrllaClass.h"
#ifdef __cplusplus
extern "C" {
#endif
	//////////////////////////////////////////////////////////////////////////
	// Create and dispose instances
	//////////////////////////////////////////////////////////////////////////
	extern IVRLLA_CLASS_API IvrllaClass* createInstance();
	extern IVRLLA_CLASS_API void disposeInstance(IvrllaClass* pObject);
	//////////////////////////////////////////////////////////////////////////
	// Requests wrappers
	//////////////////////////////////////////////////////////////////////////
	extern IVRLLA_CLASS_API void destroyWrapper(
		IvrllaClass* pObject);
	extern IVRLLA_CLASS_API long connectToServerWrapper(
		IvrllaClass* pObject, 
		const char* serverName, 
		const char* serverPort, 
		const char* userName, 
		const char* password);

	extern IVRLLA_CLASS_API long IvrReqAlertWrapper(
		IvrllaClass* pObject, 
		long csid,
		const char* callid);

	extern IVRLLA_CLASS_API long IvrReqAcceptCallWrapper(
		IvrllaClass* pObject, 
		long csid,
		const char* callid);

	extern IVRLLA_CLASS_API char* IvrReqCreateCallWrapper(
		IvrllaClass* pObject, 
		long csid, 
		long direction, 
		const char* calledNumber, 
		const char* callingNumber, 
		long timeout,
		OUT char* callid);

	extern IVRLLA_CLASS_API char* IvrReqCreateCallExWrapper(
		IvrllaClass* pObject, 
		long csid, 
		long direction, 
		const char* calledNumber, 
		const char* callingNumber, 
		long timeout,
		OUT char* callid, 
		long informationElemnts);

	extern IVRLLA_CLASS_API long IvrReqJoinCallsWrapper(
		IvrllaClass* pObject, 
		long csid,
		const char* callid1, 
		const char* callid2);

	extern IVRLLA_CLASS_API long IvrReqDisjoinCallsWrapper(
		IvrllaClass* pObject, 
		long csid,
		const char* callid1, 
		const char* callid2);

	extern IVRLLA_CLASS_API long IvrReqDisconnectCallWrapper(
		IvrllaClass* pObject, 
		long csid,
		const char* callid, 
		long party,
		long reason);

	extern IVRLLA_CLASS_API long IvrReqPlayAudioMessageWrapper(
		IvrllaClass* pObject, 
		long csid,
		const char* callid, 
		long party, 
		long repeat, 
		const char* audioMessages);

	extern IVRLLA_CLASS_API long IvrReqPlayAudioMessageExWrapper(
		IvrllaClass* pObject, 
		long csid,
		const char* callid, 
		long uploadMode,
		long deleteFile, 
		long repeat, 
		const char* audioMessages);

	extern IVRLLA_CLASS_API long IvrReqPlayAudioMessageEx2Wrapper(
		IvrllaClass* pObject, 
		long csid,
		const char* callid, 
		long party,
		long uploadMode,
		long deleteFile, 
		long repeat, 
		long reservedInt1,
		long reservedInt2,
		const char* reservedString1,
		const char* reservedString2,
		const char* audioMessages);

	extern IVRLLA_CLASS_API long IvrReqStartLiveWrapper(
		IvrllaClass* pObject, 
		long csid,
		const char* callid, 
		long party);

	extern IVRLLA_CLASS_API long IvrReqStopLiveWrapper(
		IvrllaClass* pObject, 
		long csid,
		const char* callid, 
		long party);

	extern IVRLLA_CLASS_API long IvrReqPlayLiveWrapper(
		IvrllaClass* pObject, 
		long csid,
		const char* callid, 
		long party, 
		const char* samples,
		long size);

	extern IVRLLA_CLASS_API long IvrReqStopPlayingWrapper(
		IvrllaClass* pObject, 
		long csid,
		const char* callid, 
		long party);

	extern IVRLLA_CLASS_API long IvrReqRecordWrapper(
		IvrllaClass* pObject, 
		long csid,
		const char* callid, 
		long party, 
		long format);

	extern IVRLLA_CLASS_API long IvrReqStopRecordWrapper(
		IvrllaClass* pObject, 
		long csid,
		const char* callid, 
		long party, 
		long type);

	extern IVRLLA_CLASS_API long IvrReqRecordSegmentWrapper(
		IvrllaClass* pObject, 
		long csid,
		const char* callid, 
		long party, 
		const char* fileName, 
		long format);

	extern IVRLLA_CLASS_API long IvrReqStopRecordSegmentWrapper(
		IvrllaClass* pObject, 
		long csid,
		const char* callid);

	extern IVRLLA_CLASS_API long startStreamWrapper(
		IvrllaClass* pObject, 
		const char* callid,
		long party, 
		long format);

	extern IVRLLA_CLASS_API long IvrReqStopStreamWrapper(
		IvrllaClass* pObject, 
		long csid,
		const char* callid);

	extern IVRLLA_CLASS_API long updateCallWrapper(
		IvrllaClass*		pObject, 
		long		updateType, 
		long		direction, 
		long		csType, 
		long		timeStarted, 
		long		timeConnected, 
		long		timeEnd1, 
		long		timeEnded, 
		const char	*numCalling, 
		const char	*numCalled, 
		const char	*numExtension,
		OUT char	*callId);

	extern IVRLLA_CLASS_API long IvrReqUploadAudioMessageWrapper(
		IvrllaClass* pObject, 
		const char* audioMessageName, //callID
		const char* description, 
		const char* audioMessagePath, 
		long audioFormat, 
		long audioType);

	extern IVRLLA_CLASS_API long IvrReqDeleteAudioMessageWrapper(
		IvrllaClass* pObject, 
		const char* audioMessageName);

	extern IVRLLA_CLASS_API long IvrReqSetDtmfDetectionWrapper(
		IvrllaClass* pObject, 
		long csid,
		const char* callid,
		long party,
		long duration);

	extern IVRLLA_CLASS_API long IvrReqInvalidateCacheWrapper(
		IvrllaClass* pObject);

	extern IVRLLA_CLASS_API long setSenseObjectWrapper(
		IvrllaClass* pObject, 
		const char*	userName,
		const char*	objectName,
		long		op,
		const char*	object);

	extern IVRLLA_CLASS_API long getSenseObjectWrapper(
		IvrllaClass* pObject, 
		const char*	userName,
		const char*	objectName,
		long		op,
		const char*	object);

	extern IVRLLA_CLASS_API long IvrReqDownloadFirmwareWrapper(
		IvrllaClass* pObject, 
		long csid,
		long force,
		const char*	fileName);

	extern IVRLLA_CLASS_API long getSenseVersionWrapper(
		IvrllaClass* pObject, 
		OUT char* IvrLlaApiVersion);

	extern IVRLLA_CLASS_API long SystemParametersWrapper(
		IvrllaClass*			pObject, 
		long			opCode,
		long			reserved2,
		long			reserved3,
		long			reserved4,
		long			reserved5,
		long			reserved6,
		long			reserved7,
		long			reserved8,
		long			reserved9,
		long			reserved10,
		const char*		serialKey,			/* 64 */
		const char*		reservedString2,	/* 64 */
		const char*		reservedString3,	/* 64 */
		const char*		reservedString4,	/* 64 */
		const char*		filePath,	/* 128 */
		const char*		sysParams	/* 256 */ );

	extern IVRLLA_CLASS_API long UpdateWallBoardStateWrapper(
		IvrllaClass*		pObject, 
		long		active, 
		long		waiting,
		long		inbound,
		long		outbound,
		long		missed,
		long		averageWaitingTime,
		long		maxWaitingTime,
		long		reserved8,
		long		reserved9,
		long		reserved10,
		const char*	reservedString1,
		const char*	reservedString2,
		const char*	reservedString3,
		const char*	reservedString4,
		const char* reservedLongString1,
		const char* reservedLongString2);
	extern IVRLLA_CLASS_API long restoreWrapper(
		IvrllaClass* pObject, 
		const char* callid);
	//////////////////////////////////////////////////////////////////////////
	// Callbacks setters wrappers
	//////////////////////////////////////////////////////////////////////////
	extern IVRLLA_CLASS_API void set_alertingWrapper(IvrllaClass* pObject, Alerting callback);
	extern IVRLLA_CLASS_API void set_alertingExWrapper(IvrllaClass* pObject, AlertingEx callback);
	extern IVRLLA_CLASS_API void set_auditWrapper(IvrllaClass* pObject, Audit callback);
	extern IVRLLA_CLASS_API void set_progressingWrapper(IvrllaClass* pObject, Progressing callback);
	extern IVRLLA_CLASS_API void set_connectedWrapper(IvrllaClass* pObject, Connected callback);
	extern IVRLLA_CLASS_API void set_disconnectedWrapper(IvrllaClass* pObject, Disconnected callback);
	extern IVRLLA_CLASS_API void set_failedWrapper(IvrllaClass* pObject, Failed callback);
	extern IVRLLA_CLASS_API void set_errorWrapper(IvrllaClass* pObject, Error callback);
	extern IVRLLA_CLASS_API void set_errorExWrapper(IvrllaClass* pObject, ErrorEx callback);
	extern IVRLLA_CLASS_API void set_csStateChangedWrapper(IvrllaClass* pObject, CsStateChanged callback);
	extern IVRLLA_CLASS_API void set_csDescriptorWrapper(IvrllaClass* pObject, CsDescriptor callback);
	extern IVRLLA_CLASS_API void set_channelInfoWrapper(IvrllaClass* pObject, ChannelInfo callback);
	extern IVRLLA_CLASS_API void set_dtmfWrapper(IvrllaClass* pObject, DTMF callback);
	extern IVRLLA_CLASS_API void set_playEndedWrapper(IvrllaClass* pObject, PlayEnded callback);
	extern IVRLLA_CLASS_API void set_audioWrapper(IvrllaClass* pObject, Audio callback);
	extern IVRLLA_CLASS_API void set_confirmedWrapper(IvrllaClass* pObject, Confirmed callback);
	extern IVRLLA_CLASS_API void set_senseObjectWrapper(IvrllaClass* pObject, SenseObject callback);
	extern IVRLLA_CLASS_API void set_loginResponseWrapper(IvrllaClass* pObject, LoginResponse callback);
	extern IVRLLA_CLASS_API void set_versionInfoWrapper(IvrllaClass* pObject, VersionInfo callback);
	extern IVRLLA_CLASS_API void set_wallBoardStateWrapper(IvrllaClass* pObject, WallBoardState callback);
#ifdef __cplusplus
}
#endif
