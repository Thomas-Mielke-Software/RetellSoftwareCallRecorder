/*
* This file is part of Retell Software Call Recorder.
*
* Retell Software Call Recorder is free software: you can redistribute it
* and/or modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation, either version 3 of the License,
* or (at your option) any later version.
*
* Retell Software Call Recorder is distributed in the hope that it will be
* useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
* Public License for more details.
*
* You should have received a copy of the GNU General Public License along with
* Retell Software Call Recorder. If not, see <https://www.gnu.org/licenses/>. 
*/

#if !defined(__IVRLLA_H__)
#define __IVRLLA_H__

///////////////////////////////////////////////////////////////////////////////
// This file contains the declarations of the exported functions of the IVRLLA API.
///////////////////////////////////////////////////////////////////////////////

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the IVRLLA_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// IVRLLA_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef IVRLLA_EXPORTS
#define IVRLLA_API extern "C" __declspec(dllexport)
#else
#define IVRLLA_API
#endif

enum UploadFileMode {
	UPLOAD = 0,
	NO_UPLOAD = 1 };

enum DeleteFileMode {
	DELETE_FILE = 0,
	NO_DELETE_FILE = 1 };

enum AudioFormat {
	FMT_PCM_8KHZ_8BIT_MONO = 1,
	FMT_PCM_8KHZ_8BIT_STEREO = 2, 
	FMT_WMA = 4,
	FMT_WAV = 8 };

typedef enum _CS_TYPE { 
	CS_NONE		= 0x0,
	CS_BRI		= 0x1, 
	CS_PRI		= 0x2, 
	CS_ANALOG	= 0x3,
	CS_957		= 0x4,
	CS_VOIP		= 0x5,
} CS_TYPE;

enum CallParty 
{
	P_INTERNAL = 0,
	P_EXTERNAL = 1,
	P_BOTH = 2,
	P_ACTIVE = 3 
};

enum CallDirection 
{
	D_INCOMING = 1,			// Inbound call
	D_OUTGOING = 2,			// Outbound call
	D_INTERNAL = 3,			// Active mode call on TE.
	D_UNKNOWN = 4			// A call who's type can not be inferred
};


#define IN
#define OUT

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////

// Connection

IVRLLA_API 
long connectToServer(
	const char* serverName,
	const char* serverPort,
	const char* userName,
	const char* password);

IVRLLA_API 
void destroy();

//Directives:
IVRLLA_API 
long IvrReqAlert(
	long csid,
	const char* callid);

IVRLLA_API 
long IvrReqAcceptCall(
	long csid,
	const char* callid);

IVRLLA_API 
char* IvrReqCreateCall(
	long csid, 
	long direction, 
	const char* calledNumber, 
	const char* callingNumber, 
	long timeout,
	OUT char* callid);

IVRLLA_API 
char* IvrReqCreateCallEx(
   long csid, 
   long direction, 
   const char* calledNumber, 
   const char* callingNumber, 
   long timeout,
   OUT char* callid, 
   long informationElemnts);
#if 0
IVRLLA_API 
char* IvrReqCreateAndJoinCall(
	long csid,
	const char* callid, 
	char* newCallid, 
	long direction, 
	const char* calledNumber, 
	const char* callingNumber, 
	long timeout);
#endif
IVRLLA_API 
long IvrReqJoinCalls(
	long csid,
	const char* callid1, 
	const char* callid2);

IVRLLA_API 
long IvrReqDisjoinCalls(
	long csid,
	const char* callid1, 
	const char* callid2);

IVRLLA_API 
long IvrReqDisconnectCall(
	long csid,
	const char* callid, 
	long party,
	long reason);

IVRLLA_API 
long IvrReqPlayAudioMessage(
	long csid,
	const char* callid, 
	long party, 
	long repeat, 
	const char* audioMessages);

IVRLLA_API 
long IvrReqPlayAudioMessageEx(
	long csid,
	const char* callid, 
	long uploadMode,
	long deleteFile, 
	long repeat, 
	const char* audioMessages);

IVRLLA_API 
long IvrReqPlayAudioMessageEx2(
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

IVRLLA_API 
long IvrReqStartLive(
	long csid,
	const char* callid, 
	long party);

IVRLLA_API 
long IvrReqStopLive(
	long csid,
	const char* callid, 
	long party);

IVRLLA_API 
long IvrReqPlayLive(
	long csid,
	const char* callid, 
	long party, 
	const char* samples,
	long size);

IVRLLA_API 
long IvrReqStopPlaying(
	long csid,
	const char* callid, 
	long party);

IVRLLA_API 
long IvrReqRecord(
	long csid,
	const char* callid, 
	long party, 
	long format);

IVRLLA_API 
long IvrReqStopRecord(
	long csid,
	const char* callid, 
	long party, 
	long type);

IVRLLA_API 
long IvrReqRecordSegment(
	long csid,
	const char* callid, 
	long party, 
	const char* fileName, 
	long format);

IVRLLA_API 
long IvrReqStopRecordSegment(
	long csid,
	const char* callid);

IVRLLA_API 
long startStream(
	const char* callid,
	long party, 
	long format);

IVRLLA_API 
long IvrReqStopStream(
	long csid,
	const char* callid);

IVRLLA_API 
long updateCall(
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

IVRLLA_API 
long IvrReqUploadAudioMessage(
	const char* audioMessageName, //callID
	const char* description, 
	const char* audioMessagePath, 
	long audioFormat, 
	long audioType);

IVRLLA_API 
long IvrReqDeleteAudioMessage(
	const char* audioMessageName);

IVRLLA_API 
long IvrReqSetDtmfDetection(
	long csid,
	const char* callid,
	long party,
	long duration);

IVRLLA_API 
long IvrReqInvalidateCache();

IVRLLA_API 
long setSenseObject(
	const char*	userName,
	const char*	objectName,
	long		op,
	const char*	object);

IVRLLA_API 
long getSenseObject(
	const char*	userName,
	const char*	objectName,
	long		op,
	const char*	object);

IVRLLA_API 
long IvrReqDownloadFirmware(
	long csid,
	long force,
	const char*	fileName);

IVRLLA_API
long getSenseVersion(
	OUT char* IvrLlaApiVersion);

long setLoopbackMode();		// Not exported

IVRLLA_API
long SystemParameters(
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

IVRLLA_API
long UpdateWallBoardState(
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



// Callback typedefs
////////////////////////////
//Events:
typedef void (*Alerting)(
	const char*	callid, 
	long		direction,
	long		party,
	const char*	calledNumber, 
	const char*	callingNumber);

typedef void (*AlertingEx)(
	long		direction,
	long		party,
	long		sendingComplete, 
	long		csId,	
	long		auditType,
	long		signallingMode,
	long		reservedParam7,
	long		reservedParam8,
	long		reservedParam9,
	long		reservedParam10,
	const char* callId,
	const char* calledNumber,
	const char* callingNumber,
	const char* reservedString4,
	const char* reservedString5,
	const char* reservedString6
);

typedef void (*Audit)(
	const long		direction,
	const long		party,
	const long		sendingComplete, 
	const long		csid,
	const long		auditType,
	const long		reservedParam6,
	const long		reservedParam7,
	const long		reservedParam8,
	const long		reservedParam9,
	const long		reservedParam10,
	const char* 	callId,
	const char* 	calledNumber,
	const char* 	callingNumber,
	const char* 	reservedString4,
	const char* 	reservedString5,
	const char* 	reservedString6
	);

typedef void (*Progressing)(
	const char* callid, 
	long direction, 
	long party,
	const char* calledNumber, 
	const char* callingNumber);

typedef void (*Connected)(
	const char* callid, 
	long party,
	const char* connectedNumber);

typedef void (*Disconnected)(
	const char* callid, 
	long party,
	long reason);
	
typedef void (*Failed)(
	const char* callid, 
	long party,
	long tagname,
	long reason);
	
typedef void (*IVRError)(
	const char* callid, 
	long party,
	long reason);
	
typedef void (*ErrorEx)(
	long party,
	long reason,
	long csid,
	long state,
	long param5,
	long param6,
	const char* callid, 
	const char* string2);

typedef void (*CsStateChanged)(
	long csid, 
	long state);
	
typedef void (*CsDescriptor)(
	long		csid, 
	long		state,
	long		serial,
	long		deviceType,
	long		signallingMode,
	long		reserved3,
	long		reserved4,
	long		reserved5,
	long		reserved6,
	long		reserved7,
	const char*	reservedString1,
	const char*	reservedString2,
	const char*	reservedString3,
	const char*	reservedString4,
	const char* reservedLongString1,
	const char* reservedLongString2);

typedef void (*ChannelInfo)(
	const char*	callid,
	long		internalChannel, 
	long		externalChannel,
	long		internalPort,
	long		externalPort);

typedef void (*ChannelInfoEx)(
	const char*	callid,
	signed char		internalChannel,
	signed char		externalChannel,
	signed char		internalPort,
	signed char		externalPort);

typedef void (*DTMF)(
	const char* callid, 
	long party,
	const char* digits,
	bool completed);
	
typedef void (*PlayEnded)(
	const char* callid, 
	long party,
	long reason);
	
typedef void (*Audio)(
	const char* callid, 
	long party,
	long format,
	long dataSize,
	const char* data);
	
typedef void (*Confirmed)(
	long tagname);

typedef void (*SenseObject)(
	const char*	userName,
	const char*	objectName,
	long		op,
	const char*	object);

typedef void (*LoginResponse)(
	const char*	senseDBUser,
	const char*	senseDBPassword);

typedef void (*VersionInfo)(
	const char*	senseVersion);
	
typedef void (*WallBoardState)(
	 long			active, 
	 long			waiting,
	 long			inbound,
	 long			outbound,
	 long			missed,
	 long			averageWaitingTime,
	 long			maxWaitingTime,
	 long			reserved5,
	 long			reserved6,
	 long			reserved7,
	 const char*	reservedString1,
	 const char*	reservedString2,
	 const char*	reservedString3,
	 const char*	reservedString4,
	 const char* 	reservedLongString1,
	 const char* 	reservedLongString2);

// Callbacks setters
////////////////////
IVRLLA_API void set_alerting(Alerting callback);
IVRLLA_API void set_alertingEx(AlertingEx callback);
IVRLLA_API void set_audit(Audit callback);
IVRLLA_API void set_progressing(Progressing callback);
IVRLLA_API void set_connected(Connected callback);
IVRLLA_API void set_disconnected(Disconnected callback);
IVRLLA_API void set_failed(Failed callback);
IVRLLA_API void set_error(IVRError callback);
IVRLLA_API void set_errorEx(ErrorEx callback);
IVRLLA_API void set_csStateChanged(CsStateChanged callback);
IVRLLA_API void set_csDescriptor(CsDescriptor callback);
IVRLLA_API void set_channelInfo(ChannelInfo callback);
IVRLLA_API void set_dtmf(DTMF callback);
IVRLLA_API void set_playEnded(PlayEnded callback);
IVRLLA_API void set_audio(Audio callback);
IVRLLA_API void set_confirmed(Confirmed callback);
IVRLLA_API void set_senseObject(SenseObject callback);
IVRLLA_API void set_loginResponse(LoginResponse callback);
IVRLLA_API void set_versionInfo(VersionInfo callback);
IVRLLA_API void set_wallBoardState(WallBoardState callback);

#endif // __IVRLLA_H__

