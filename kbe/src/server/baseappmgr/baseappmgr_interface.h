/*
This source file is part of KBEngine
For the latest info, see http://www.kbengine.org/

Copyright (c) 2008-2012 KBEngine.

KBEngine is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

KBEngine is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
 
You should have received a copy of the GNU Lesser General Public License
along with KBEngine.  If not, see <http://www.gnu.org/licenses/>.
*/


#if defined(DEFINE_IN_INTERFACE)
	#undef KBE_BASEAPPMGR_INTERFACE_H
#endif


#ifndef KBE_BASEAPPMGR_INTERFACE_H
#define KBE_BASEAPPMGR_INTERFACE_H

// common include	
#if defined(BASEAPPMGR)
#include "baseappmgr.h"
#endif
#include "baseappmgr_interface_macros.h"
#include "network/interface_defs.h"
//#define NDEBUG
// windows include	
#if KBE_PLATFORM == PLATFORM_WIN32
#else
// linux include
#endif
	
namespace KBEngine{

/**
	BASEAPPMGR������Ϣ�ӿ��ڴ˶���
*/
NETWORK_INTERFACE_DECLARE_BEGIN(BaseappmgrInterface)
	// ĳappע���Լ��Ľӿڵ�ַ����app
	BASEAPPMGR_MESSAGE_DECLARE_ARGS11(onRegisterNewApp,						NETWORK_VARIABLE_MESSAGE,
									int32,									uid, 
									std::string,							username,
									COMPONENT_TYPE,							componentType, 
									COMPONENT_ID,							componentID, 
									COMPONENT_ORDER,						globalorderID,
									COMPONENT_ORDER,						grouporderID,
									uint32,									intaddr, 
									uint16,									intport,
									uint32,									extaddr, 
									uint16,									extport,
									std::string,							extaddrEx)

	// ĳapp��������look��
	BASEAPPMGR_MESSAGE_DECLARE_ARGS0(lookApp,								NETWORK_FIXED_MESSAGE)

	// ĳ��app����鿴��app����״̬��
	BASEAPPMGR_MESSAGE_DECLARE_ARGS0(queryLoad,								NETWORK_FIXED_MESSAGE)

	// ĳ��app��app��֪���ڻ״̬��
	BASEAPPMGR_MESSAGE_DECLARE_ARGS2(onAppActiveTick,						NETWORK_FIXED_MESSAGE,
									COMPONENT_TYPE,							componentType, 
									COMPONENT_ID,							componentID)

	// baseEntity���󴴽���һ���µ�space�С�
	BASEAPPMGR_MESSAGE_DECLARE_STREAM(reqCreateBaseAnywhere,				NETWORK_VARIABLE_MESSAGE)

	// baseEntity���󴴽���һ���µ�space�С�
	BASEAPPMGR_MESSAGE_DECLARE_STREAM(reqCreateBaseAnywhereFromDBID,		NETWORK_VARIABLE_MESSAGE)

	// ��Ϣת���� ��ĳ��app��ͨ����app����Ϣת����ĳ��app��	
	BASEAPPMGR_MESSAGE_DECLARE_STREAM(forwardMessage,						NETWORK_VARIABLE_MESSAGE)

	// ĳ��app��app��֪���ڻ״̬��
	BASEAPPMGR_MESSAGE_DECLARE_ARGS7(registerPendingAccountToBaseapp,		NETWORK_VARIABLE_MESSAGE,
									std::string,							loginName, 
									std::string,							accountName,
									std::string,							password,
									DBID,									entityDBID,
									uint32,									flags,
									uint64,									deadline,
									COMPONENT_TYPE,							componentType)

	// ��ȡ��baseapp�ĵ�ַ��
	BASEAPPMGR_MESSAGE_DECLARE_ARGS4(onPendingAccountGetBaseappAddr,		NETWORK_VARIABLE_MESSAGE,
									std::string,							loginName, 
									std::string,							accountName,
									std::string,							addr,
									uint16,									port)
									
	// һ���µ�¼���˺Ż�úϷ�����baseapp��Ȩ���� ������Ҫ���˺�ע���ָ����baseapp
	// ʹ�������ڴ�baseapp�ϵ�¼��
	BASEAPPMGR_MESSAGE_DECLARE_ARGS9(registerPendingAccountToBaseappAddr,	NETWORK_VARIABLE_MESSAGE,
									COMPONENT_ID,							componentID,
									std::string,							loginName, 
									std::string,							accountName,
									std::string,							password,
									ENTITY_ID,								entityID,
									DBID,									entityDBID,
									uint32,									flags,
									uint64,									deadline,
									COMPONENT_TYPE,							componentType)

	// ����رշ�����
	BASEAPPMGR_MESSAGE_DECLARE_STREAM(reqCloseServer,						NETWORK_VARIABLE_MESSAGE)

	// ����baseapp��Ϣ��
	BASEAPPMGR_MESSAGE_DECLARE_ARGS4(updateBaseapp,							NETWORK_FIXED_MESSAGE,
									COMPONENT_ID,							componentID,
									ENTITY_ID,								numBases,
									ENTITY_ID,								numProxices,
									float,									load)

	// �����ѯwatcher����
	BASEAPPMGR_MESSAGE_DECLARE_STREAM(queryWatcher,							NETWORK_VARIABLE_MESSAGE)

	// baseappͬ���Լ��ĳ�ʼ����Ϣ
	BASEAPPMGR_MESSAGE_DECLARE_ARGS2(onBaseappInitProgress,					NETWORK_FIXED_MESSAGE,
									COMPONENT_ID,							cid,
									float,									progress)

	// ��ʼprofile
	BASEAPPMGR_MESSAGE_DECLARE_STREAM(startProfile,							NETWORK_VARIABLE_MESSAGE)

	// ����ǿ��ɱ����ǰapp
	BASEAPPMGR_MESSAGE_DECLARE_STREAM(reqKillServer,						NETWORK_VARIABLE_MESSAGE)

NETWORK_INTERFACE_DECLARE_END()

#ifdef DEFINE_IN_INTERFACE
	#undef DEFINE_IN_INTERFACE
#endif

}
#endif