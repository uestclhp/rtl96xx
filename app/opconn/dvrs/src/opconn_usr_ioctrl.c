
#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <sys/types.h>

//#include <LINUX/opconn_ioctl.h>
#include <sys/ioctl.h>
#include "opconn_hw_reg.h"
#include "opconn_ioctl.h"
#include "mc_control.h"
#if 1
int opconnfd;
#define OPL_OPCONN_DEVICE_NAME "/dev/opl_dal_driver"


int open_opconn_drv(void)
{
  opconnfd = open(OPL_OPCONN_DEVICE_NAME, O_RDWR|O_SYNC );
  if(opconnfd < 0){
    printf("open the %s device failed\n",OPL_OPCONN_DEVICE_NAME);
    return -1;
  }
  return 0;
}


int close_opconn_drv(void)
{
  int status = 0;
  if(opconnfd > 0){
    close(opconnfd);
  }
  return status;
}
#endif

OPL_STATUS dalPonMacIdSet( UINT8 * mac )
{
	OPL_STATUS ret;
	dalponmacidset_params_t params;
    memcpy(params.mac, mac, MAC_LENGTH);

	ret = ioctl( opconnfd, IOC_DALPONMACIDSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonMacIdGet( UINT8 * mac )
{
	OPL_STATUS ret;
	dalponmacidget_params_t params;


	ret = ioctl( opconnfd, IOC_DALPONMACIDGET, &params );
	if ( ret )
	{
		return ret;
	}

    memcpy(mac,params.mac, MAC_LENGTH);

	return ret;
}

OPL_STATUS dalPonPhyFecModeSet( UINT32 mode )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONPHYFECMODESET, mode );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonPhyFecModeGet( UINT32 * mode )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONPHYFECMODEGET, mode );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonPhyTripleChuningModeSet( UINT32 mode )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONPHYTRIPLECHUNINGMODESET, mode );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonPhyTripleChuningModeGet( UINT32 * mode )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONPHYTRIPLECHUNINGMODEGET, mode );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonPhyAesModeSet( UINT32 mode )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONPHYAESMODESET, mode );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonPhyAesModeGet( UINT32 * mode )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONPHYAESMODEGET, mode );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonLaserOnCntSet( UINT32 count )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONLASERONCNTSET, count );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonLaserOnCntGet( UINT32 * count )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONLASERONCNTGET, count );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonLaserOffCntSet( UINT32 count )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONLASEROFFCNTSET, count );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonLaserOffCntGet( UINT32 * count )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONLASEROFFCNTGET, count );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonSyncTimeGet( UINT32 * count )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONSYNCTIMEGET, count );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonLlidGet( UINT32 * llid )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONLLIDGET, llid );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonSerdesDelayCntSet( UINT32 count )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONSERDESDELAYCNTSET, count );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonSerdesDelayCntGet( UINT32 * count )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONSERDESDELAYCNTGET, count );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonSecurityModeSet( UINT32 channel, UINT32 mode )
{
	OPL_STATUS ret;
	dalponsecuritymodeset_params_t params;

	params.channel = channel;
	params.mode = mode;

	ret = ioctl( opconnfd, IOC_DALPONSECURITYMODESET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonSecurityModeGet( UINT32 channel, UINT32 * mode )
{
	OPL_STATUS ret;
	dalponsecuritymodeget_params_t params;

	params.channel = channel;

	ret = ioctl( opconnfd, IOC_DALPONSECURITYMODEGET, &params );
	if ( ret )
	{
		return ret;
	}

	*mode = params.mode;

	return ret;
}

OPL_STATUS dalPonSecurityAesModeSet( UINT32 channel, UINT32 mode )
{
	OPL_STATUS ret;
	dalponsecurityaesmodeset_params_t params;

	params.channel = channel;
	params.mode = mode;

	ret = ioctl( opconnfd, IOC_DALPONSECURITYAESMODESET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonSecurityAesModeGet( UINT32 channel, UINT32 * mode )
{
	OPL_STATUS ret;
	dalponsecurityaesmodeget_params_t params;

	params.channel = channel;

	ret = ioctl( opconnfd, IOC_DALPONSECURITYAESMODEGET, &params );
	if ( ret )
	{
		return ret;
	}

	*mode = params.mode;

	return ret;
}

OPL_STATUS dalPonUnicastTripleChurningKeyGet( UINT8 keyIndex, UINT8 * keyBuff )
{
	OPL_STATUS ret;
	dalponunicasttriplechurningkeyget_params_t params;

	params.keyIndex = keyIndex;
	params.keyBuff = keyBuff;
	
	ret = ioctl( opconnfd, IOC_DALPONUNICASTTRIPLECHURNINGKEYGET, &params );
	if ( ret )
	{
		return ret;
	}

	return ret;
}

OPL_STATUS dalPonScbTripleChurningKeySet( UINT8 keyIndex, UINT8 * keyBuff )
{
	OPL_STATUS ret;
	dalponscbtriplechurningkeyset_params_t params;

	params.keyIndex = keyIndex;
	params.keyBuff = keyBuff;

	ret = ioctl( opconnfd, IOC_DALPONSCBTRIPLECHURNINGKEYSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonUnicastAesKeyGet( UINT8 keyIndex, UINT8 * keyBuff, UINT8 mode )
{
	OPL_STATUS ret;
	dalponunicastaeskeyget_params_t params;

	params.keyIndex = keyIndex;
	params.mode = mode;
	params.keyBuff = keyBuff;

	ret = ioctl( opconnfd, IOC_DALPONUNICASTAESKEYGET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonScbAesKeySet( UINT8 keyIndex, UINT8 * keyBuff, UINT8 mode )
{
	OPL_STATUS ret;
	dalponscbaeskeyset_params_t params;

	params.keyIndex = keyIndex;
	params.keyBuff = keyBuff;
	params.mode = mode;

	ret = ioctl( opconnfd, IOC_DALPONSCBAESKEYSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonTripleChurningModeGet( UINT8 * mode )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONTRIPLECHURNINGMODEGET, mode );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonTripleChurningModeSet( UINT8 mode )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONTRIPLECHURNINGMODESET, mode );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonMpcpDbaAgentConfigAllSet( UINT32 cpRptStaMode, UINT32 cpMergeRptSendMode, UINT32 cpRptSendMode, UINT32 cpPktInitTimerCfg, UINT32 cpDeltaTxNormalNoFecTime, UINT32 cpTxMpcpNoFecTime )
{
	OPL_STATUS ret;
	dalponmpcpdbaagentconfigallset_params_t params;

	params.cpRptStaMode = cpRptStaMode;
	params.cpMergeRptSendMode = cpMergeRptSendMode;
	params.cpRptSendMode = cpRptSendMode;
	params.cpPktInitTimerCfg = cpPktInitTimerCfg;
	params.cpDeltaTxNormalNoFecTime = cpDeltaTxNormalNoFecTime;
	params.cpTxMpcpNoFecTime = cpTxMpcpNoFecTime;

	ret = ioctl( opconnfd, IOC_DALPONMPCPDBAAGENTCONFIGALLSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonMpcpDbaAgentConfigAllGet( UINT32 * cpRptStaMode, UINT32 * cpMergeRptSendMode, UINT32 * cpRptSendMode, UINT32 * cpPktInitTimerCfg, UINT32 * cpDeltaTxNormalNoFecTime, UINT32 * cpTxMpcpNoFecTime )
{
	OPL_STATUS ret;
	dalponmpcpdbaagentconfigallget_params_t params;


	ret = ioctl( opconnfd, IOC_DALPONMPCPDBAAGENTCONFIGALLGET, &params );
	if ( ret )
	{
		return ret;
	}

	*cpRptStaMode = params.cpRptStaMode;
	*cpMergeRptSendMode = params.cpMergeRptSendMode;
	*cpRptSendMode = params.cpRptSendMode;
	*cpPktInitTimerCfg = params.cpPktInitTimerCfg;
	*cpDeltaTxNormalNoFecTime = params.cpDeltaTxNormalNoFecTime;
	*cpTxMpcpNoFecTime = params.cpTxMpcpNoFecTime;

	return ret;
}

OPL_STATUS dalPonDelayConfigAllSet( UINT8 cpTxDlyEn, UINT8 cpSyncEn, UINT16 cpRptsentDelt, UINT16 cpTxDly )
{
	OPL_STATUS ret;
	dalpondelayconfigallset_params_t params;

	params.cpTxDlyEn = cpTxDlyEn;
	params.cpSyncEn = cpSyncEn;
	params.cpRptsentDelt = cpRptsentDelt;
	params.cpTxDly = cpTxDly;

	ret = ioctl( opconnfd, IOC_DALPONDELAYCONFIGALLSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonDelayConfigAllGet( UINT32 * cpTxDlyEn, UINT32 * cpSyncEn, UINT32 * cpRptsentDelt, UINT32 * cpTxDly )
{
	OPL_STATUS ret;
	dalpondelayconfigallget_params_t params;


	ret = ioctl( opconnfd, IOC_DALPONDELAYCONFIGALLGET, &params );
	if ( ret )
	{
		return ret;
	}

	*cpTxDlyEn = params.cpTxDlyEn;
	*cpSyncEn = params.cpSyncEn;
	*cpRptsentDelt = params.cpRptsentDelt;
	*cpTxDly = params.cpTxDly;

	return ret;
}

OPL_STATUS dalPonMpcpStatusGet( DAL_PON_STATUS_t * ponStatus )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONMPCPSTATUSGET, ponStatus );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonOamFinishedSet( UINT32 oamFinished )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONOAMFINISHEDSET, oamFinished );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonMpcpFsmHoldOverCtrlSet( UINT32 enable )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONMPCPFSMHOLDOVERCTRLSET, enable );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonMpcpFsmHoldOverCtrlGet( UINT32 * enable )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONMPCPFSMHOLDOVERCTRLGET, enable );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonMpcpFsmHoldOverTimeSet( UINT32 holdTime )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONMPCPFSMHOLDOVERTIMESET, holdTime );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPonMpcpFsmHoldOverTimeGet( UINT32 * holdTime )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONMPCPFSMHOLDOVERTIMEGET, holdTime );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsTblEntryAdd( CLASSIFY_MASK_ENTRY_t * pMaskEntry, CLASSIFY_RULE_ENTRY_t * pRuleEntry, UINT16 * pCruleID, opl_cls_hwtbl_t * pClshwtbl )
{
	OPL_STATUS ret;
	dalclstblentryadd_params_t params;

	params.pMaskEntry = pMaskEntry;
	params.pRuleEntry = pRuleEntry;
	params.pClshwtbl = pClshwtbl;

	ret = ioctl( opconnfd, IOC_DALCLSTBLENTRYADD, &params );
	if ( ret )
	{
		return ret;
	}

	*pCruleID = params.pCruleID;
	//*pClshwtbl = params.pClshwtbl;

	return ret;
}

OPL_STATUS dalClsTblEntryDel( CLASSIFY_MASK_ENTRY_t * pMaskEntry, CLASSIFY_RULE_ENTRY_t * pRuleEntry, UINT16 * pCruleID )
{
	OPL_STATUS ret;
	dalclstblentrydel_params_t params;

	params.pMaskEntry = pMaskEntry;
	params.pRuleEntry = pRuleEntry;

	ret = ioctl( opconnfd, IOC_DALCLSTBLENTRYDEL, &params );
	if ( ret )
	{
		return ret;
	}

	*pCruleID = params.pCruleID;

	return ret;
}

OPL_STATUS dalClsMaskTblWr( CLASSIFY_MASK_ENTRY_t * pMask, UINT8 maskID )
{
	OPL_STATUS ret;
	dalclsmasktblwr_params_t params;
	
	params.pMask = pMask;
	params.maskID = maskID;

	ret = ioctl( opconnfd, IOC_DALCLSMASKTBLWR, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsRuleTblWr( CLASSIFY_RULE_ENTRY_t * pRule, UINT16 ruleID )
{
	OPL_STATUS ret;
	dalclsruletblwr_params_t params;

	//memcpy(&params.pRule ,pRule,sizeof(CLASSIFY_RULE_ENTRY_t));
	params.pRule = pRule;
	params.ruleID = ruleID;

	ret = ioctl( opconnfd, IOC_DALCLSRULETBLWR, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsAddrTblWr( UINT16 address, UINT16 offset, UINT16 ruleId )
{
	OPL_STATUS ret;
	dalclsaddrtblwr_params_t params;

	params.address = address;
	params.offset = offset;
	params.ruleId = ruleId;

	ret = ioctl( opconnfd, IOC_DALCLSADDRTBLWR, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsMaskHwWr( CLASSIFY_MASK_ENTRY_t * pMask, UINT8 maskID )
{
	OPL_STATUS ret;
	dalclsmaskhwwr_params_t params;

	params.pMask = pMask;
	params.maskID = maskID;

	ret = ioctl( opconnfd, IOC_DALCLSMASKHWWR, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsRuleHwWr( CLASSIFY_RULE_ENTRY_t * pRule, UINT16 ruleID )
{
	OPL_STATUS ret;
	dalclsrulehwwr_params_t params;

	params.pRule = pRule;
	params.ruleID = ruleID;

	ret = ioctl( opconnfd, IOC_DALCLSRULEHWWR, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsAddrHwWr( UINT16 address, UINT16 offset, UINT16 ruleId )
{
	OPL_STATUS ret;
	dalclsaddrhwwr_params_t params;

	params.address = address;
	params.offset = offset;
	params.ruleId = ruleId;

	ret = ioctl( opconnfd, IOC_DALCLSADDRHWWR, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsRuleTblRd( CLASSIFY_RULE_ENTRY_t * pRule, UINT16 ruleID, UINT8 tblType )
{
	OPL_STATUS ret;
	dalclsruletblrd_params_t params;
	
	params.pRule = pRule;
	params.ruleID = ruleID;
	params.tblType = tblType;

	ret = ioctl( opconnfd, IOC_DALCLSRULETBLRD, &params );
	if ( ret )
	{
		return ret;
	}

	return ret;
}

OPL_STATUS dalClsAddrTblRd( UINT16 address, UINT16 offset, UINT16 * pRuleId, UINT8 tblType )
{
	OPL_STATUS ret;
	dalclsaddrtblrd_params_t params;

	params.address = address;
	params.offset = offset;
	params.tblType = tblType;

	ret = ioctl( opconnfd, IOC_DALCLSADDRTBLRD, &params );
	if ( ret )
	{
		return ret;
	}

	*pRuleId = params.pRuleId;

	return ret;
}

OPL_STATUS dalClsEntrySet( CLASSIFY_PARAMETER_t * pMaskRulePar, UINT16 * pCruleID, opl_cls_hwtbl_t * pCmaskID )
{
	OPL_STATUS ret;
	dalclsentryset_params_t params;

	//memcpy(&params.pMaskRulePar,pMaskRulePar,sizeof(CLASSIFY_PARAMETER_t));
	params.pMaskRulePar = pMaskRulePar;

	ret = ioctl( opconnfd, IOC_DALCLSENTRYSET, &params );
	if ( ret )
	{
		return ret;
	}

	*pCruleID = params.pCruleID;
	*pCmaskID = params.pCmaskID;

	return ret;
}

OPL_STATUS dalClsEntryMove( CLASSIFY_PARAMETER_t * pRulePar, UINT16 * pCruleID )
{
	OPL_STATUS ret;
	dalclsentrymove_params_t params;

	params.pRulePar = pRulePar;

	ret = ioctl( opconnfd, IOC_DALCLSENTRYMOVE, &params );
	if ( ret )
	{
		return ret;
	}

	*pCruleID = params.pCruleID;

	return ret;
}

OPL_STATUS dalClsInit(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALCLSINIT, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsTranActSet( UINT16 classRuleID, UINT8 actValue )
{
	OPL_STATUS ret;
	dalclstranactset_params_t params;

	params.classRuleID = classRuleID;
	params.actValue = actValue;

	ret = ioctl( opconnfd, IOC_DALCLSTRANACTSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsRmkActSet( UINT16 classRuleID, UINT8 rmkactVal )
{
	OPL_STATUS ret;
	dalclsrmkactset_params_t params;

	params.classRuleID = classRuleID;
	params.rmkactVal = rmkactVal;

	ret = ioctl( opconnfd, IOC_DALCLSRMKACTSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsRmkCosSet( UINT16 classRuleID, UINT8 cosValue )
{
	OPL_STATUS ret;
	dalclsrmkcosset_params_t params;

	params.classRuleID = classRuleID;
	params.cosValue = cosValue;

	ret = ioctl( opconnfd, IOC_DALCLSRMKCOSSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsRmkIcosSet( UINT16 classRuleID, UINT8 iCosVal )
{
	OPL_STATUS ret;
	dalclsrmkicosset_params_t params;

	params.classRuleID = classRuleID;
	params.iCosVal = iCosVal;

	ret = ioctl( opconnfd, IOC_DALCLSRMKICOSSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsRmkVidSet( UINT16 classRuleID, UINT16 rmkVid )
{
	OPL_STATUS ret;
	dalclsrmkvidset_params_t params;

	params.classRuleID = classRuleID;
	params.rmkVid = rmkVid;

	ret = ioctl( opconnfd, IOC_DALCLSRMKVIDSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsRmkVidActSet(UINT16 classRuleID,UINT8 rmkVidAct,UINT16 rmkVid)
{
	OPL_STATUS ret;
	dalClsRmkVidActSet_params_t params;

	params.classRuleID = classRuleID;
	params.rmkVidAct = rmkVidAct;
	params.rmkVid = rmkVid;

	ret = ioctl( opconnfd, IOC_DALCLSRMKVIDACTSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}


OPL_STATUS dalClsEgressPortCfg( UINT16 classItemID, UINT8 pktType, UINT8 portID, UINT8 eMask, UINT8 bEnable )
{
	OPL_STATUS ret;
	dalclsegressportcfg_params_t params;

	params.classItemID = classItemID;
	params.pktType = pktType;
	params.portID = portID;
	params.eMask = eMask;
	params.bEnable = bEnable;

	ret = ioctl( opconnfd, IOC_DALCLSEGRESSPORTCFG, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsIngressPortCfg( UINT16 classItemID, UINT8 pktType, UINT8 portID, UINT8 iMask, UINT8 bEnable )
{
	OPL_STATUS ret;
	dalclsingressportcfg_params_t params;

	params.classItemID = classItemID;
	params.pktType = pktType;
	/* QINQ*/
	params.portID = portID;
	params.iMask = iMask;
	params.bEnable = bEnable;

	ret = ioctl( opconnfd, IOC_DALCLSINGRESSPORTCFG, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsTranActCfg( UINT16 classItemID, UINT8 pktType, UINT8 actValue )
{
	OPL_STATUS ret;
	dalclstranactcfg_params_t params;

	params.classItemID = classItemID;
	params.pktType = pktType;
	params.actValue = actValue;

	ret = ioctl( opconnfd, IOC_DALCLSTRANACTCFG, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsRmkActCfg( UINT16 classItemID, UINT8 pktType, UINT8 rmkActVal )
{
	OPL_STATUS ret;
	dalclsrmkactcfg_params_t params;

	params.classItemID = classItemID;
	params.pktType = pktType;
	params.rmkActVal = rmkActVal;

	ret = ioctl( opconnfd, IOC_DALCLSRMKACTCFG, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsRmkCosCfg( UINT16 classItemID, UINT8 pktType, UINT8 cosValue )
{
	OPL_STATUS ret;
	dalclsrmkcoscfg_params_t params;

	params.classItemID = classItemID;
	params.pktType = pktType;
	params.cosValue = cosValue;

	ret = ioctl( opconnfd, IOC_DALCLSRMKCOSCFG, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsRmkIcosCfg( UINT16 classItemID, UINT8 pktType, UINT8 iCosValue )
{
	OPL_STATUS ret;
	dalclsrmkicoscfg_params_t params;

	params.classItemID = classItemID;
	params.pktType = pktType;
	params.iCosValue = iCosValue;

	ret = ioctl( opconnfd, IOC_DALCLSRMKICOSCFG, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsRmkVidCfg( UINT16 classItemID, UINT8 pktType, UINT16 rmkVid )
{
	OPL_STATUS ret;
	dalclsrmkvidcfg_params_t params;

	params.classItemID = classItemID;
	params.pktType = pktType;
	params.rmkVid = rmkVid;

	ret = ioctl( opconnfd, IOC_DALCLSRMKVIDCFG, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}



OPL_STATUS dalClsMaskPrioCfg( UINT16 classItemID, UINT8 pktType, UINT8 maskPrio )
{
	OPL_STATUS ret;
	dalclsmaskpriocfg_params_t params;

	params.classItemID = classItemID;
	params.pktType = pktType;
	params.maskPrio = maskPrio;

	ret = ioctl( opconnfd, IOC_DALCLSMASKPRIOCFG, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsDestMacAddrCfg( UINT16 classItemID, UINT8 pktType, INT8 * pDestMac, INT8 * pUsrMask, UINT8 bEnable )
{
	OPL_STATUS ret;
	dalclsdestmacaddrcfg_params_t params;

	params.classItemID = classItemID;
	params.pktType = pktType;
	memcpy(params.pDestMac, pDestMac,sizeof(MAC_LENGTH));
	memcpy(params.pUsrMask ,pUsrMask,sizeof(MAC_LENGTH));
	params.bEnable = bEnable;

	ret = ioctl( opconnfd, IOC_DALCLSDESTMACADDRCFG, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsSrcMacAddrCfg( UINT16 classItemID, UINT8 pktType, INT8 * pSrcMac, INT8 * pUsrMask, UINT8 bEnable )
{
	OPL_STATUS ret;
	dalclssrcmacaddrcfg_params_t params;

	params.classItemID = classItemID;
	params.pktType = pktType;
	memcpy(params.pSrcMac ,pSrcMac,sizeof(MAC_LENGTH));
	memcpy(params.pUsrMask ,pUsrMask,sizeof(MAC_LENGTH));
	params.bEnable = bEnable;

	ret = ioctl( opconnfd, IOC_DALCLSSRCMACADDRCFG, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsFirstCosCfg( UINT16 classItemID, UINT8 pktType, UINT8 cosVal, UINT8 usrMask, UINT8 bEnable )
{
	OPL_STATUS ret;
	dalclsfirstcoscfg_params_t params;

	params.classItemID = classItemID;
	params.pktType = pktType;
	params.cosVal = cosVal;
	params.usrMask = usrMask;
	params.bEnable = bEnable;

	ret = ioctl( opconnfd, IOC_DALCLSFIRSTCOSCFG, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsFirstVidCfg( UINT16 classItemID, UINT8 pktType, UINT16 vlanID, UINT16 usrMask, UINT8 bEnable )
{
	OPL_STATUS ret;
	dalclsfirstvidcfg_params_t params;

	params.classItemID = classItemID;
	params.pktType = pktType;
	params.vlanID = vlanID;
	params.usrMask = usrMask;
	params.bEnable = bEnable;

	ret = ioctl( opconnfd, IOC_DALCLSFIRSTVIDCFG, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsTypeLenCfg( UINT16 classItemID, UINT8 pktType, UINT16 typeLen, UINT16 usrMask, UINT8 bEnable )
{
	OPL_STATUS ret;
	dalclstypelencfg_params_t params;

	params.classItemID = classItemID;
	params.pktType = pktType;
	params.typeLen = typeLen;
	params.usrMask = usrMask;
	params.bEnable = bEnable;

	ret = ioctl( opconnfd, IOC_DALCLSTYPELENCFG, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsDestIpCfg( UINT16 classItemID, UINT8 pktType, INT8 * pDestIp, INT8 * pUsrMask, UINT8 bEnable )
{
	OPL_STATUS ret;
	dalclsdestipcfg_params_t params;

	params.classItemID = classItemID;
	params.pktType = pktType;
	memcpy(params.pDestIp ,pDestIp,IPVERSION4_LENGTH);
	memcpy(params.pUsrMask ,pUsrMask,IPVERSION4_LENGTH);
	params.bEnable = bEnable;

	ret = ioctl( opconnfd, IOC_DALCLSDESTIPCFG, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsSrcIpCfg( UINT16 classItemID, UINT8 pktType, INT8 * pSrcIp, INT8 * pUsrMask, UINT8 bEnable )
{
	OPL_STATUS ret;
	dalclssrcipcfg_params_t params;

	params.classItemID = classItemID;
	params.pktType = pktType;
	memcpy(params.pSrcIp,pSrcIp ,IPVERSION4_LENGTH);
	memcpy(params.pUsrMask,pUsrMask,IPVERSION4_LENGTH) ;
	params.bEnable = bEnable;

	ret = ioctl( opconnfd, IOC_DALCLSSRCIPCFG, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsIpTypeCfg( UINT16 classItemID, UINT8 pktType, UINT8 ipType, UINT8 usrMask, UINT8 bEnable )
{
	OPL_STATUS ret;
	dalclsiptypecfg_params_t params;

	params.classItemID = classItemID;
	params.pktType = pktType;
	params.ipType = ipType;
	params.usrMask = usrMask;
	params.bEnable = bEnable;

	ret = ioctl( opconnfd, IOC_DALCLSIPTYPECFG, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsIpTosCfg( UINT16 classItemID, UINT8 pktType, UINT8 ipTos, UINT8 usrMask, UINT8 bEnable )
{
	OPL_STATUS ret;
	dalclsiptoscfg_params_t params;

	params.classItemID = classItemID;
	params.pktType = pktType;
	params.ipTos = ipTos;
	params.usrMask = usrMask;
	params.bEnable = bEnable;

	ret = ioctl( opconnfd, IOC_DALCLSIPTOSCFG, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsL4DestPortCfg( UINT16 classItemID, UINT8 pktType, UINT16 L4DestPortID, UINT16 usrMask, UINT8 bEnable )
{
	OPL_STATUS ret;
	dalclsl4destportcfg_params_t params;

	params.classItemID = classItemID;
	params.pktType = pktType;
	params.L4DestPortID = L4DestPortID;
	params.usrMask = usrMask;
	params.bEnable = bEnable;

	ret = ioctl( opconnfd, IOC_DALCLSL4DESTPORTCFG, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsL4SrcPortCfg( UINT16 classItemID, UINT8 pktType, UINT16 L4SrcPortID, UINT16 usrMask, UINT8 bEnable )
{
	OPL_STATUS ret;
	dalclsl4srcportcfg_params_t params;

	params.classItemID = classItemID;
	params.pktType = pktType;
	params.L4SrcPortID = L4SrcPortID;
	params.usrMask = usrMask;
	params.bEnable = bEnable;

	ret = ioctl( opconnfd, IOC_DALCLSL4SRCPORTCFG, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

#if 1/*wfxu*/

OPL_STATUS dalClsRuleEntryShow( UINT16 startId, UINT16 endId, UINT8 mode )
{
	OPL_STATUS ret;
	dalclsruleentryshow_params_t params;

	params.startId = startId;
	params.endId = endId;
	params.mode = mode;

	ret = ioctl( opconnfd, IOC_DALCLSRULEENTRYSHOW, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsMaskEntryShow(UINT16 startId, UINT16 endId, UINT8 mode )
{
	OPL_STATUS ret;
	dalclsmaskentryshow_params_t params;

	params.startId = startId;
	params.endId = endId;
	params.mode = mode;

	ret = ioctl( opconnfd, IOC_DALCLSMASKENTRYSHOW, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}


OPL_STATUS dalClsAddrEntryShow(UINT16 startId, UINT16 endId, UINT8 mode )
{
	OPL_STATUS ret;
	dalclsaddrentryshow_params_t params;

	params.startId = startId;
	params.endId = endId;
	params.mode = mode;

	ret = ioctl( opconnfd, IOC_DALCLSADDRENTRYSHOW, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsCfgShow(UINT16 usFirstItem,UINT16 usLastItem)
{
	OPL_STATUS ret;
	dalclscfgshow_params_t params;

	params.usFirstItem = usFirstItem;
	params.usLastItem = usLastItem;

	ret = ioctl( opconnfd, IOC_DALCLSCFGSHOW, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

#endif
OPL_STATUS dalClsRuleDel( UINT16 classItemID )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALCLSRULEDEL, classItemID );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsConvertPara( CLASSIFY_ITEM_t * pClassItemInfo, CLS_CONFIG_INFO_t * stClassCfg, UINT8 pktType )
{
	OPL_STATUS ret;
	dalclsconvertpara_params_t params;

	params.pClassItemInfo = pClassItemInfo;
	params.stClassCfg = stClassCfg;	
	params.pktType = pktType;

	ret = ioctl( opconnfd, IOC_DALCLSCONVERTPARA, &params );
	if ( ret )
	{
		return ret;
	}

	return ret;
}

OPL_STATUS dalClsCtcInit(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALCLSCTCINIT, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsRuleCtcAdd( CLS_CONFIG_INFO_t * stClassCfg, UINT16 * ruleId )
{
	OPL_STATUS ret;
	dalclsrulectcadd_params_t params;

	params.stClassCfg = stClassCfg;
	
	ret = ioctl( opconnfd, IOC_DALCLSRULECTCADD, &params );
	if ( ret )
	{
		return ret;
	}

	*ruleId = params.ruleId  ;

	return ret;
}

OPL_STATUS dalClsRuleCtcDel( CLS_CONFIG_INFO_t * stClassCfg, UINT16 * ruleId )
{
	OPL_STATUS ret;
	dalclsrulectcdel_params_t params;

	params.stClassCfg = stClassCfg;

	ret = ioctl( opconnfd, IOC_DALCLSRULECTCDEL, &params );
	if ( ret )
	{
		return ret;
	}

	*ruleId = params.ruleId;

	return ret;
}

OPL_STATUS dalClsRuleCtcClear(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALCLSRULECTCCLEAR, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalExClsDelEntry( UINT32 ruleIndex )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALEXCLSDELENTRY, ruleIndex );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsIpVersionCfg(UINT16 classItemID,
                           UINT8 pktType,
                           UINT8 ipVersion,
                           UINT8 usrMask,
                           UINT8 bEnable) 
{
	OPL_STATUS ret;
	dalClsIpVersionCfg_params_t params;

	params.classItemID = classItemID;
	params.pktType = pktType;
	params.ipVersion = ipVersion;
	params.usrMask = usrMask;
	params.bEnable = bEnable;

	ret = ioctl( opconnfd, IOC_DALCLSIPVERSIONCFG, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsFirstTpidCfg(UINT16 classItemID,
                           UINT8 pktType,
                           UINT16 firsttpid,
                           UINT16 usrMask,
                           UINT8 bEnable)
{
	OPL_STATUS ret;
	dalClsFirstTpidCfg_params_t params;

	params.classItemID = classItemID;
	params.pktType = pktType;
	params.firsttpid = firsttpid;
	params.usrMask = usrMask;
	params.bEnable = bEnable;

	ret = ioctl( opconnfd, IOC_DALCLSFIRSTTPIDCFG, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsValidEntryGet(UINT16 *puiClsId)
{
    OPL_STATUS ret;

    //ret = ioctl( opconnfd, IOC_DALVOIPCLSRULECTCADD, puiClsId );
    ret = ioctl( opconnfd, IOC_DALCLSVALIDENTRYGET, puiClsId );

    return ret;
}

OPL_STATUS dalVoipClsRuleCtcAdd( CLS_CONFIG_INFO_t * stClassCfg, UINT16 * ruleId )
{
	OPL_STATUS ret;
	dalvoipclsrulectcadd_params_t params;

	params.stClassCfg = stClassCfg;

	ret = ioctl( opconnfd, IOC_DALVOIPCLSRULECTCADD, &params );
	if ( ret )
	{
		return ret;
	}

	*ruleId = params.ruleId;

	return ret;
}


OPL_STATUS dalChipReset(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALCHIPRESET, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalDemonInit(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALDEMONINIT, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlAgeTimeSet( UINT32 ageingTime )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALARLAGETIMESET, ageingTime );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlAgeTimeGet( UINT32 * ageingTime )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALARLAGETIMEGET, ageingTime );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlMacAdd( UINT8 portNum, UINT8 * macAddress, UINT16 vlanIndex )
{
	OPL_STATUS ret;
	dalarlmacadd_params_t params;

	params.portNum = portNum;
	memcpy(params.macAddress , macAddress, MAC_LENGTH);
	params.vlanIndex = vlanIndex;

	ret = ioctl( opconnfd, IOC_DALARLMACADD, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlMacDel( UINT8 portNum, UINT8 * macAddress, UINT16 vlanIndex )
{
	OPL_STATUS ret;
	dalarlmacdel_params_t params;

	params.portNum = portNum;
	memcpy(params.macAddress , macAddress, MAC_LENGTH);
	params.vlanIndex = vlanIndex;

	ret = ioctl( opconnfd, IOC_DALARLMACDEL, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlMacRemove( UINT8 * macAddress, UINT16 vlanIndex )
{
	OPL_STATUS ret;
	dalarlmacremove_params_t params;

	memcpy(params.macAddress , macAddress, MAC_LENGTH);
	params.vlanIndex = vlanIndex;

	ret = ioctl( opconnfd, IOC_DALARLMACREMOVE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlFlushDynamic(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALARLFLUSHDYNAMIC, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlFlushAll(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALARLFLUSHALL, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlLearnEnSet( UINT8 enable )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALARLLEARNENSET, enable );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlLearnEnGet( UINT8 * enable )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALARLLEARNENGET, enable );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlSoftLearnEnSet( UINT8 enable )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALARLSOFTLEARNENSET, enable );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlSoftLearnEnGet( UINT8 * enable )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALARLSOFTLEARNENGET, enable );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlAgeEnableSet( UINT8 enable )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALARLAGEENABLESET, enable );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlAgeEnableGet( UINT8 * enable )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALARLAGEENABLEGET, enable );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlMacNumLimitSet( UINT32 portID, UINT8 enable, UINT32 num )
{
	OPL_STATUS ret;
	dalarlmacnumlimitset_params_t params;

	params.portID = portID;
	params.enable = enable;
	params.num = num;

	ret = ioctl( opconnfd, IOC_DALARLMACNUMLIMITSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlMultiPortMacAdd( UINT32 uiPortNum, UINT32 * auiPortlist, UINT8 * aucMacAddress, UINT16 usVlanId )
{
	OPL_STATUS ret;
	dalarlmultiportmacadd_params_t params;

	params.uiPortNum = uiPortNum;
	params.auiPortlist = *auiPortlist;
	memcpy(params.aucMacAddress , aucMacAddress, MAC_LENGTH);
	params.usVlanId = usVlanId;

	ret = ioctl( opconnfd, IOC_DALARLMULTIPORTMACADD, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlMultiPortMacDel( UINT32 uiPortNum, UINT32 * auiPortlist, UINT8 * aucMacAddress, UINT16 usVlanId )
{
	OPL_STATUS ret;
	dalarlmultiportmacdel_params_t params;

	params.uiPortNum = uiPortNum;
	params.auiPortlist = *auiPortlist;
	memcpy(params.aucMacAddress , aucMacAddress, MAC_LENGTH);
	params.usVlanId = usVlanId;

	ret = ioctl( opconnfd, IOC_DALARLMULTIPORTMACDEL, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlMacEntryFind( UINT8 * aucMacAddress, UINT16 usVlanId, FDB_MAC_ENTRY_INFO_S * pstMacEntryInfo, OPL_BOOL * pbFind )
{
	OPL_STATUS ret;
	dalarlmacentryfind_params_t params;

	memcpy(params.aucMacAddress , aucMacAddress, MAC_LENGTH);
	params.usVlanId = usVlanId;
	params.pstMacEntryInfo = pstMacEntryInfo;

	ret = ioctl( opconnfd, IOC_DALARLMACENTRYFIND, &params );
	if ( ret )
	{
		return ret;
	}

	//*pstMacEntryInfo = params.pstMacEntryInfo;
	*pbFind = params.pbFind;

	return ret;
}

OPL_STATUS dalArlMacEntryTraverse( UINT32 * puiStartMacEntryId, FDB_MAC_ENTRY_INFO_S * pstMacEntryInfo, OPL_BOOL * pbFind )
{
	OPL_STATUS ret;
	dalarlmacentrytraverse_params_t params;

	params.puiStartMacEntryId = *puiStartMacEntryId;
	params.pstMacEntryInfo = pstMacEntryInfo ;

	ret = ioctl( opconnfd, IOC_DALARLMACENTRYTRAVERSE, &params );
	if ( ret )
	{
		return ret;
	}

	//*pstMacEntryInfo = params.pstMacEntryInfo;
	*pbFind = params.pbFind;

	return ret;
}

OPL_STATUS dalArlMacEntryShowOne( INT32 lFd, UINT8 * aucMacAddress, UINT16 usType, UINT32 uiPortNum, UINT32 * auiPortlist )
{
	OPL_STATUS ret;
	dalarlmacentryshowone_params_t params;

	params.lFd = lFd;
	memcpy(params.aucMacAddress , aucMacAddress, MAC_LENGTH);
	params.usType = usType;
	params.uiPortNum = uiPortNum;
	params.auiPortlist = *auiPortlist;

	ret = ioctl( opconnfd, IOC_DALARLMACENTRYSHOWONE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlMacEntryShowAll( INT32 lFd, UINT16 usType, UINT32 uiPortNum, UINT32 * auiPortlist )
{
	OPL_STATUS ret;
	dalarlmacentryshowall_params_t params;

	params.lFd = lFd;
	params.usType = usType;
	params.uiPortNum = uiPortNum;
	params.auiPortlist = *auiPortlist;

	ret = ioctl( opconnfd, IOC_DALARLMACENTRYSHOWALL, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMulticastInit(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALMULTICASTINIT, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

#if defined(ONU_4PORT_AR8327)
OPL_STATUS dalMulticastVlanAddPort( UINT8 portNum, UINT16 vlanId, UINT32 tag )
{
	OPL_STATUS ret;
	dalmulticastvlanaddport_params_t params;

	params.portNum = portNum;
	params.vlanId = vlanId;
	params.tag = tag;

#else
OPL_STATUS dalMulticastVlanAddPort( UINT8 portNum, UINT16 vlanId )
{
	OPL_STATUS ret;
	dalmulticastvlanaddport_params_t params;

	params.portNum = portNum;
	params.vlanId = vlanId;
#endif
	ret = ioctl( opconnfd, IOC_DALMULTICASTVLANADDPORT, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMulticastVlanDelPort( UINT8 portNum, UINT16 vlanId )
{
	OPL_STATUS ret;
	dalmulticastvlandelport_params_t params;

	params.portNum = portNum;
	params.vlanId = vlanId;

	ret = ioctl( opconnfd, IOC_DALMULTICASTVLANDELPORT, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMulticastVlanTagStripe( UINT8 portNum, UINT8 enable )
{
	OPL_STATUS ret;
	dalmulticastvlantagstripe_params_t params;

	params.portNum = portNum;
	params.enable = enable;

	ret = ioctl( opconnfd, IOC_DALMULTICASTVLANTAGSTRIPE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMulticastArlAddPort( UINT8 portNum, UINT8 * macAddr )
{
	OPL_STATUS ret;
	dalmulticastarladdport_params_t params;

	params.portNum = portNum;
	memcpy(params.macAddr , macAddr, MAC_LENGTH);

	ret = ioctl( opconnfd, IOC_DALMULTICASTARLADDPORT, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMulticastArlPortDel( UINT8 portNum, UINT8 * macAddr )
{
	OPL_STATUS ret;
	dalmulticastarlportdel_params_t params;

	params.portNum = portNum;
	memcpy(params.macAddr , macAddr, MAC_LENGTH);

	ret = ioctl( opconnfd, IOC_DALMULTICASTARLPORTDEL, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMulticastArlVlanAdd( UINT8 portNum, UINT16 vlanId, UINT8 * macAddr )
{
	OPL_STATUS ret;
	dalmulticastarlvlanadd_params_t params;

	params.portNum = portNum;
	params.vlanId = vlanId;
	memcpy(params.macAddr , macAddr, MAC_LENGTH);

	ret = ioctl( opconnfd, IOC_DALMULTICASTARLVLANADD, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMulticastArlVlanDel( UINT8 portNum, UINT16 vlanId, UINT8 * macAddr )
{
	OPL_STATUS ret;
	dalmulticastarlvlandel_params_t params;

	params.portNum = portNum;
	params.vlanId = vlanId;
	memcpy(params.macAddr , macAddr, MAC_LENGTH);

	ret = ioctl( opconnfd, IOC_DALMULTICASTARLVLANDEL, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMulticastArlTabFlush(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALMULTICASTARLTABFLUSH, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMulticastPortVlanMacAdd( UINT8 portNum, UINT16 vlanId, UINT8 * macAddr, OPL_BOOL fuzzy )
{
/* Begin Modified*/
#ifndef CTC_MULTICAST_SURPORT    
	OPL_STATUS ret;
	dalmulticastportvlanmacadd_params_t params;

	params.portNum = portNum;
	params.vlanId = vlanId;
	memcpy(params.macAddr , macAddr, MAC_LENGTH);
	params.fuzzy = fuzzy;
   
	ret = ioctl( opconnfd, IOC_DALMULTICASTPORTVLANMACADD, &params );
	if ( ret )
	{
		return ret;
	}
#else
{
    extern INT32 DRV_AddPort2McastAddr(UINT32 uiLPort, UINT32 uiVlan, UINT8 aucMac [6]);
    INT32 ret;
    #if 0
    printf("\n%s adds port %d to mc-mac atu %02X%02X-%02X%02X-%02X%02X.\n",__FUNCTION__,
             portNum,macAddr[0],macAddr[1],macAddr[2],macAddr[3],
             macAddr[4],macAddr[5]);
    #endif
    ret = DRV_AddPort2McastAddr(portNum, vlanId, macAddr);
    if (0 != ret)
    {
        mc_printf("\nfunc:%s failed to set mc mac.\n",__FUNCTION__);
        return OPL_ERROR;
    }
}
#endif
/* End   Modified*/ 

	return OPL_OK;
}

OPL_STATUS dalMulticastPortVlanMacDel( UINT8 portNum, UINT16 vlanId, UINT8 * macAddr, OPL_BOOL fuzzy )
{
/* Begin Modified*/
#ifndef CTC_MULTICAST_SURPORT
	OPL_STATUS ret;
	dalmulticastportvlanmacdel_params_t params;

	params.portNum = portNum;
	params.vlanId = vlanId;
	memcpy(params.macAddr , macAddr, MAC_LENGTH);
	params.fuzzy = fuzzy;

	ret = ioctl( opconnfd, IOC_DALMULTICASTPORTVLANMACDEL, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
#else
{
    extern INT32 DRV_DelPortFromMcastAddr(UINT32 uiLPort, UINT32 uiVlan, UINT8 aucMac[6]);
    INT32 ret;
    //printf("\nfunc:%s,line:%d\n",__FUNCTION__,__LINE__);
    ret = DRV_DelPortFromMcastAddr(portNum, vlanId, macAddr);
    if (0 != ret)
    {
        mc_printf("\nfunc:%s failed to delete port from mc mac.\n",__FUNCTION__);
        return OPL_ERROR;
    }
}
#endif
/* End   Modified of porting */
}

OPL_STATUS dalMulticastPortVlanIpAdd( UINT8 portNum, UINT16 vlanId, UINT32 ip )
{
	OPL_STATUS ret;
	dalmulticastportvlanipadd_params_t params;

	params.portNum = portNum;
	params.vlanId = vlanId;
	params.ip = ip;

	ret = ioctl( opconnfd, IOC_DALMULTICASTPORTVLANIPADD, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMulticastPortVlanIpDel( UINT8 portNum, UINT16 vlanId, UINT32 ip )
{
	OPL_STATUS ret;
	dalmulticastportvlanipdel_params_t params;

	params.portNum = portNum;
	params.vlanId = vlanId;
	params.ip = ip;

	ret = ioctl( opconnfd, IOC_DALMULTICASTPORTVLANIPDEL, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMulticastRuleDelAll(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALMULTICASTRULEDELALL, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMulticastDataFilterAdd(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALMULTICASTDATAFILTERADD, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMulticastDataFilterDel(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALMULTICASTDATAFILTERDEL, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMulticastNumofRuleGet( UINT16 * numOfRule )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALMULTICASTNUMOFRULEGET, numOfRule );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPortNumIsInvalid( UINT8 portId )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPORTNUMISINVALID, portId );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPortSpecificDuplexRead( UINT8 portId, UINT32 * duplex )
{
	OPL_STATUS ret;
	dalportspecificduplexread_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALPORTSPECIFICDUPLEXREAD, &params );
	if ( ret )
	{
		return ret;
	}

	*duplex = params.duplex;

	return ret;
}

OPL_STATUS dalPhySpecificAutonegRead( UINT8 portId, UINT32 * state )
{
	OPL_STATUS ret;
	dalphyspecificautonegread_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALPHYSPECIFICAUTONEGREAD, &params );
	if ( ret )
	{
		return ret;
	}

	*state = params.state;

	return ret;
}

OPL_STATUS dalPortSpecificSpeedRead( UINT8 portId, UINT32 * portSpeed )
{
	OPL_STATUS ret;
	dalportspecificspeedread_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALPORTSPECIFICSPEEDREAD, &params );
	if ( ret )
	{
		return ret;
	}

	*portSpeed = params.portSpeed;

	return ret;
}

OPL_STATUS dalPortStateGet( UINT8 portId, UINT8 * status )
{
	OPL_STATUS ret;
	dalportstateget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALPORTSTATEGET, &params );
	if ( ret )
	{
		return ret;
	}

	*status = params.status;

	return ret;
}

OPL_STATUS dalPortSpeedSet( UINT8 portId, UINT32 portSpeed )
{
	OPL_STATUS ret;
	dalportspeedset_params_t params;

	params.portId = portId;
	params.portSpeed = portSpeed;

	ret = ioctl( opconnfd, IOC_DALPORTSPEEDSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPortSpeedGet( UINT8 portId, UINT32 * portSpeed )
{
	OPL_STATUS ret;
	dalportspeedget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALPORTSPEEDGET, &params );
	if ( ret )
	{
		return ret;
	}

	*portSpeed = params.portSpeed;

	return ret;
}

OPL_STATUS dalPortDuplexSet( UINT8 portId, UINT32 duplex )
{
	OPL_STATUS ret;
	dalportduplexset_params_t params;

	params.portId = portId;
	params.duplex = duplex;

	ret = ioctl( opconnfd, IOC_DALPORTDUPLEXSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPortDuplexGet( UINT8 portId, UINT32 * duplex )
{
	OPL_STATUS ret;
	dalportduplexget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALPORTDUPLEXGET, &params );
	if ( ret )
	{
		return ret;
	}

	*duplex = params.duplex;

	return ret;
}

OPL_STATUS dalPortFlowcontrolSet( UINT8 portId, UINT8 enable )
{
	OPL_STATUS ret;
	dalportflowcontrolset_params_t params;

	params.portId = portId;
	params.enable = enable;

	ret = ioctl( opconnfd, IOC_DALPORTFLOWCONTROLSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPortFlowcontrolGet( UINT8 portId, UINT8 * enable )
{
	OPL_STATUS ret;
	dalportflowcontrolget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALPORTFLOWCONTROLGET, &params );
	if ( ret )
	{
		return ret;
	}

	*enable = params.enable;

	return ret;
}

OPL_STATUS dalPortLoopbackSet( UINT8 portId, UINT8 enable )
{
	OPL_STATUS ret;
	dalportloopbackset_params_t params;

	params.portId = portId;
	params.enable = enable;

	ret = ioctl( opconnfd, IOC_DALPORTLOOPBACKSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPortUsPolicingEnableSet( UINT8 portId, UINT8 enable )
{
	OPL_STATUS ret;
	dalportuspolicingenableset_params_t params;

	params.portId = portId;
	params.enable = enable;

	ret = ioctl( opconnfd, IOC_DALPORTUSPOLICINGENABLESET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPortUsPolicingCirSet( UINT8 portId, UINT32 cir )
{
	OPL_STATUS ret;
	dalportuspolicingcirset_params_t params;

	params.portId = portId;
	params.cir = cir;

	ret = ioctl( opconnfd, IOC_DALPORTUSPOLICINGCIRSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPortUsPolicingCirGet( UINT8 portId, UINT32 * cir )
{
	OPL_STATUS ret;
	dalportuspolicingcirget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALPORTUSPOLICINGCIRGET, &params );
	if ( ret )
	{
		return ret;
	}

	*cir = params.cir;

	return ret;
}

OPL_STATUS dalPortUsPolicingCbsSet( UINT8 portId, UINT32 cbs )
{
	OPL_STATUS ret;
	dalportuspolicingcbsset_params_t params;

	params.portId = portId;
	params.cbs = cbs;

	ret = ioctl( opconnfd, IOC_DALPORTUSPOLICINGCBSSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPortUsPolicingCbsGet( UINT8 portId, UINT32 * cbs )
{
	OPL_STATUS ret;
	dalportuspolicingcbsget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALPORTUSPOLICINGCBSGET, &params );
	if ( ret )
	{
		return ret;
	}

	*cbs = params.cbs;

	return ret;
}

OPL_STATUS dalPortUsPolicingEbsSet( UINT8 portId, UINT32 ebs )
{
	OPL_STATUS ret;
	dalportuspolicingebsset_params_t params;

	params.portId = portId;
	params.ebs = ebs;

	ret = ioctl( opconnfd, IOC_DALPORTUSPOLICINGEBSSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPortUsPolicingEbsGet( UINT8 portId, UINT32 * ebs )
{
	OPL_STATUS ret;
	dalportuspolicingebsget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALPORTUSPOLICINGEBSGET, &params );
	if ( ret )
	{
		return ret;
	}

	*ebs = params.ebs;

	return ret;
}

OPL_STATUS dalPortUsPolicingSet( UINT8 portId, UINT8 enable, UINT32 cir, UINT32 cbs, UINT32 ebs )
{
	OPL_STATUS ret;
	dalportuspolicingset_params_t params;

	params.portId = portId;
	params.enable = enable;
	params.cir = cir;
	params.cbs = cbs;
	params.ebs = ebs;

	ret = ioctl( opconnfd, IOC_DALPORTUSPOLICINGSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPortUsPolicingGet( UINT8 portId, UINT8 * enable, UINT32 * cir, UINT32 * cbs, UINT32 * ebs )
{
	OPL_STATUS ret;
	dalportuspolicingget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALPORTUSPOLICINGGET, &params );
	if ( ret )
	{
		return ret;
	}

	*enable = params.enable;
	*cir = params.cir;
	*cbs = params.cbs;
	*ebs = params.ebs;

	return ret;
}

OPL_STATUS dalPortDsPolicingEnableSet( UINT8 portId, UINT8 enable )
{
	OPL_STATUS ret;
	dalportdspolicingenableset_params_t params;

	params.portId = portId;
	params.enable = enable;

	ret = ioctl( opconnfd, IOC_DALPORTDSPOLICINGENABLESET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPortDsPolicingEnableGet( UINT8 portId, UINT8 * enable )
{
	OPL_STATUS ret;
	dalportdspolicingenableget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALPORTDSPOLICINGENABLEGET, &params );
	if ( ret )
	{
		return ret;
	}

	*enable = params.enable;

	return ret;
}

OPL_STATUS dalPortDsPolicingCirSet( UINT8 portId, UINT32 cir )
{
	OPL_STATUS ret;
	dalportdspolicingcirset_params_t params;

	params.portId = portId;
	params.cir = cir;

	ret = ioctl( opconnfd, IOC_DALPORTDSPOLICINGCIRSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPortDsPolicingCirGet( UINT8 portId, UINT32 * cir )
{
	OPL_STATUS ret;
	dalportdspolicingcirget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALPORTDSPOLICINGCIRGET, &params );
	if ( ret )
	{
		return ret;
	}

	*cir = params.cir;

	return ret;
}

OPL_STATUS dalPortDsPolicingPirSet( UINT8 portId, UINT32 pir )
{
	OPL_STATUS ret;
	dalportdspolicingpirset_params_t params;

	params.portId = portId;
	params.pir = pir;

	ret = ioctl( opconnfd, IOC_DALPORTDSPOLICINGPIRSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPortDsPolicingPirGet( UINT8 portId, UINT32 * pir )
{
	OPL_STATUS ret;
	dalportdspolicingpirget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALPORTDSPOLICINGPIRGET, &params );
	if ( ret )
	{
		return ret;
	}

	*pir = params.pir;

	return ret;
}

OPL_STATUS dalPortDsPolicingSet( UINT8 portId, UINT8 enable, UINT32 cir, UINT32 pir )
{
	OPL_STATUS ret;
	dalportdspolicingset_params_t params;

	params.portId = portId;
	params.enable = enable;
	params.cir = cir;
	params.pir = pir;

	ret = ioctl( opconnfd, IOC_DALPORTDSPOLICINGSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPortDsPolicingGet( UINT8 portId, UINT8 * enable, UINT32 * cir, UINT32 * pir )
{
	OPL_STATUS ret;
	dalportdspolicingget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALPORTDSPOLICINGGET, &params );
	if ( ret )
	{
		return ret;
	}

	*enable = params.enable;
	*cir = params.cir;
	*pir = params.pir;

	return ret;
}

OPL_STATUS dalPhyAdminStateGet( UINT8 portId, UINT32 * state )
{
	OPL_STATUS ret;
	dalphyadminstateget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALPHYADMINSTATEGET, &params );
	if ( ret )
	{
		return ret;
	}

	*state = params.state;

	return ret;
}

OPL_STATUS dalPhyAdminControlSet( UINT8 portId,UINT32 state )
{
	OPL_STATUS ret;

	dalphyadmincontrolset_params_t params;
	
	params.portId = portId;
	params.state = state;

	ret = ioctl( opconnfd, IOC_DALPHYADMINCONTROLSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPhyAutonegAdminStateGet( UINT8 portId, UINT32 * state )
{
	OPL_STATUS ret;
	dalphyautonegadminstateget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALPHYAUTONEGADMINSTATEGET, &params );
	if ( ret )
	{
		return ret;
	}

	*state = params.state;

	return ret;
}

OPL_STATUS dalPhyAutonegEnableSet( UINT8 portId,UINT32 enable )
{
	OPL_STATUS ret;
	dalphyautonegenableset_params_t params;
	
	params.portId = portId;
	params.state= enable;

	ret = ioctl( opconnfd, IOC_DALPHYAUTONEGENABLESET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPhyAutonegRestart( UINT8 portId )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPHYAUTONEGRESTART, portId );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPortInit(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPORTINIT, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalRstpModeSet( IN OPL_BOOL bEnable )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALRSTPMODESET, bEnable );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalRstpPortStateGet( IN UINT32 ulPortId, OUT UINT8 * pucPortState )
{
	OPL_STATUS ret;
	dalrstpportstateget_params_t params;

	params.ulPortId = ulPortId;

	ret = ioctl( opconnfd, IOC_DALRSTPPORTSTATEGET, &params );
	if ( ret )
	{
		return ret;
	}

	*pucPortState = params.pucPortState;

	return ret;
}

OPL_STATUS dalRstpPortStateSet( IN UINT32 ulPortId, IN UINT8 ucPortState )
{
	OPL_STATUS ret;
	dalrstpportstateset_params_t params;

	params.ulPortId = ulPortId;
	params.ucPortState = ucPortState;

	ret = ioctl( opconnfd, IOC_DALRSTPPORTSTATESET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalRstpPortMacFlush( UINT32 ulPortid, BOOL_T bOnlyThisPort )
{
	OPL_STATUS ret;
	dalrstpportmacflush_params_t params;

	params.ulPortid = ulPortid;
	params.bOnlyThisPort = bOnlyThisPort;

	ret = ioctl( opconnfd, IOC_DALRSTPPORTMACFLUSH, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalStormClsRuleAdd( UINT32 stormLimitType, UP_DOWN_STREAM_e streamType )
{
	OPL_STATUS ret;
	dalstormclsruleadd_params_t params;

	params.stormLimitType = stormLimitType;
	params.streamType = streamType;

	ret = ioctl( opconnfd, IOC_DALSTORMCLSRULEADD, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalStormClsRuleDel( UINT32 stormLimitType, UP_DOWN_STREAM_e streamType )
{
	OPL_STATUS ret;
	dalstormclsruledel_params_t params;

	params.stormLimitType = stormLimitType;
	params.streamType = streamType;

	ret = ioctl( opconnfd, IOC_DALSTORMCLSRULEDEL, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalStormCtrlFrameSet( UINT32 portId, UINT32 stormLimitType, UINT32 limitEnable )
{
	OPL_STATUS ret;
	dalstormctrlframeset_params_t params;

	params.portId = portId;
	params.stormLimitType = stormLimitType;
	params.limitEnable = limitEnable;

	ret = ioctl( opconnfd, IOC_DALSTORMCTRLFRAMESET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalStormCtrlFrameGet( UINT32 portId, UINT32 stormLimitType, UINT32 * limitEnable )
{
	OPL_STATUS ret;
	dalstormctrlframeget_params_t params;

	params.portId = portId;
	params.stormLimitType = stormLimitType;

	ret = ioctl( opconnfd, IOC_DALSTORMCTRLFRAMEGET, &params );
	if ( ret )
	{
		return ret;
	}

	*limitEnable = params.limitEnable;

	return ret;
}

OPL_STATUS dalStormCtrlRateSet( UINT32 portId, UINT32 rateLimit )
{
	OPL_STATUS ret;
	dalstormctrlrateset_params_t params;

	params.portId = portId;
	params.rateLimit = rateLimit;

	ret = ioctl( opconnfd, IOC_DALSTORMCTRLRATESET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalStormCtrlRateGet( UINT32 portId, UINT32 * rateLimit )
{
	OPL_STATUS ret;
	dalstormctrlrateget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALSTORMCTRLRATEGET, &params );
	if ( ret )
	{
		return ret;
	}

	*rateLimit = params.rateLimit;

	return ret;
}

OPL_STATUS oplVerStrGet( UINT8 * pString )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_OPLVERSTRGET, pString );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

#if 0
OPL_STATUS oplVerNumGet( FLOAT32 * verNum )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_OPLVERNUMGET, verNum );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS oplVerShow(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_OPLVERSHOW, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}
#endif

OPL_STATUS dalVttModeSet( UINT8 mode, UINT32 portId )
{
	OPL_STATUS ret;
	dalvttmodeset_params_t params;

	params.mode = mode;
	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALVTTMODESET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalVttModeGet( UINT8 * mode, UINT32 portId )
{
	OPL_STATUS ret;
	dalvttmodeget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALVTTMODEGET, &params );
	if ( ret )
	{
		return ret;
	}

	*mode = params.mode;

	return ret;
}

OPL_STATUS dalVttTpidSet( UINT16 tpid, UINT32 portId )
{
	OPL_STATUS ret;
	dalvtttpidset_params_t params;

	params.tpid = tpid;
	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALVTTTPIDSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalVttTpidGet( UINT16 * tpid, UINT32 portId )
{
	OPL_STATUS ret;
	dalvtttpidget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALVTTTPIDGET, &params );
	if ( ret )
	{
		return ret;
	}

	*tpid = params.tpid;

	return ret;
}

OPL_STATUS dalVttVidSet( UINT16 pvid, UINT32 portId )
{
	OPL_STATUS ret;
	dalvttvidset_params_t params;

	params.pvid = pvid;
	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALVTTVIDSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalVttVidGet( UINT16 * pvid, UINT32 portId )
{
	OPL_STATUS ret;
	dalvttvidget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALVTTVIDGET, &params );
	if ( ret )
	{
		return ret;
	}

	*pvid = params.pvid;

	return ret;
}

OPL_STATUS dalVttDefaultPriSet( UINT8 etherPri, UINT32 portId )
{
	OPL_STATUS ret;
	dalvttdefaultpriset_params_t params;

	params.etherPri = etherPri;
	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALVTTDEFAULTPRISET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalVttDefaultPriGet( UINT8 * etherPri, UINT32 portId )
{
	OPL_STATUS ret;
	dalvttdefaultpriget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALVTTDEFAULTPRIGET, &params );
	if ( ret )
	{
		return ret;
	}

	*etherPri = params.etherPri;

	return ret;
}

OPL_STATUS dalVttTagEntryAdd( UINT8 pStrip, UINT8 gStrip, UINT32 cVlan, UINT32 sVlan, UINT32 portId, UINT32 * pEntryIndex, UINT8 type )
{
	OPL_STATUS ret;
	dalvtttagentryadd_params_t params;

	params.pStrip = pStrip;
	params.gStrip = gStrip;
	params.cVlan = cVlan;
	params.sVlan = sVlan;
	params.portId = portId;
	params.type = type;

	ret = ioctl( opconnfd, IOC_DALVTTTAGENTRYADD, &params );
	if ( ret )
	{
		return ret;
	}

	*pEntryIndex = params.pEntryIndex;

	return ret;
}

OPL_STATUS dalVttTagEntryGet( UINT8 ValidRecordIndex, UINT32 * cVlan, UINT32 * sVlan, UINT32 portId )
{
	OPL_STATUS ret;
	dalvtttagentryget_params_t params;

	params.ValidRecordIndex = ValidRecordIndex;
	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALVTTTAGENTRYGET, &params );
	if ( ret )
	{
		return ret;
	}

	*cVlan = params.cVlan;
	*sVlan = params.sVlan;

	return ret;
}

OPL_STATUS dalVttTagEntryDel( UINT8 pStrip, UINT8 gStrip, UINT32 cVlan, UINT32 sVlan, UINT32 portId, UINT32 * pEntryIndex, UINT8 type )
{
	OPL_STATUS ret;
	dalvtttagentrydel_params_t params;

	params.pStrip = pStrip;
	params.gStrip = gStrip;
	params.cVlan = cVlan;
	params.sVlan = sVlan;
	params.portId = portId;
	params.type = type;

	ret = ioctl( opconnfd, IOC_DALVTTTAGENTRYDEL, &params );
	if ( ret )
	{
		return ret;
	}

	*pEntryIndex = params.pEntryIndex;

	return ret;
}

OPL_STATUS dalVttNumOfRecordGet( UINT8 * numOfRecords, UINT32 portId )
{
	OPL_STATUS ret;
	dalvttnumofrecordget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALVTTNUMOFRECORDGET, &params );
	if ( ret )
	{
		return ret;
	}

	*numOfRecords = params.numOfRecords;

	return ret;
}

OPL_STATUS dalVttMulticastEntryAdd( UINT8 pStrip, UINT8 gStrip, UINT32 cVlan, UINT32 sVlan, UINT32 portId )
{
	OPL_STATUS ret;
	dalvttmulticastentryadd_params_t params;

	params.pStrip = pStrip;
	params.gStrip = gStrip;
	params.cVlan = cVlan;
	params.sVlan = sVlan;
	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALVTTMULTICASTENTRYADD, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalVttMulticastEntryDel( UINT8 pStrip, UINT8 gStrip, UINT32 cVlan, UINT32 sVlan, UINT32 portId )
{
	OPL_STATUS ret;
	dalvttmulticastentrydel_params_t params;

	params.pStrip = pStrip;
	params.gStrip = gStrip;
	params.cVlan = cVlan;
	params.sVlan = sVlan;
	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALVTTMULTICASTENTRYDEL, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalVttMulticastStripEnable( UINT8 portId, UINT32 enable )
{
	OPL_STATUS ret;
	dalvttmulticaststripenable_params_t params;

	params.portId = portId;
	params.enable = enable;

	ret = ioctl( opconnfd, IOC_DALVTTMULTICASTSTRIPENABLE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalVttMulticastInit( UINT8 portId )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALVTTMULTICASTINIT, portId );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalVttMulticastNumOfRecordGet( UINT8 * numOfRecords )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALVTTMULTICASTNUMOFRECORDGET, numOfRecords );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalVttInit(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALVTTINIT, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}


OPL_STATUS tmGeShaperEnableHwWrite( UINT8 stream, UINT8 enable )
{
	OPL_STATUS ret;
	tmgeshaperenablehwwrite_params_t params;

	params.stream = stream;
	params.enable = enable;

	ret = ioctl( opconnfd, IOC_TMGESHAPERENABLEHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS tmGeShaperEnableHwRead( UINT8 stream, UINT8 * enable )
{
	OPL_STATUS ret;
	tmgeshaperenablehwread_params_t params;

	params.stream = stream;

	ret = ioctl( opconnfd, IOC_TMGESHAPERENABLEHWREAD, &params );
	if ( ret )
	{
		return ret;
	}

	*enable = params.enable;

	return ret;
}

OPL_STATUS tmQueueShaperEnableHwWrite( UINT8 stream, UINT8 Qid, UINT8 enable )
{
	OPL_STATUS ret;
	tmqueueshaperenablehwwrite_params_t params;

	params.stream = stream;
	params.Qid = Qid;
	params.enable = enable;

	ret = ioctl( opconnfd, IOC_TMQUEUESHAPERENABLEHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS tmQueueShaperEnableHwRead( UINT8 stream, UINT8 Qid, UINT8 * enable )
{
	OPL_STATUS ret;
	tmqueueshaperenablehwread_params_t params;

	params.stream = stream;
	params.Qid = Qid;

	ret = ioctl( opconnfd, IOC_TMQUEUESHAPERENABLEHWREAD, &params );
	if ( ret )
	{
		return ret;
	}

	*enable = params.enable;

	return ret;
}

OPL_STATUS tmQueuePriHwWrite( UINT8 stream, UINT8 Qid, UINT8 priority )
{
	OPL_STATUS ret;
	tmqueueprihwwrite_params_t params;

	params.stream = stream;
	params.Qid = Qid;
	params.priority = priority;

	ret = ioctl( opconnfd, IOC_TMQUEUEPRIHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS tmQueuePriHwRead( UINT8 stream, UINT8 Qid, UINT8 * priority )
{
	OPL_STATUS ret;
	tmqueueprihwread_params_t params;

	params.stream = stream;
	params.Qid = Qid;

	ret = ioctl( opconnfd, IOC_TMQUEUEPRIHWREAD, &params );
	if ( ret )
	{
		return ret;
	}

	*priority = params.priority;

	return ret;
}

OPL_STATUS tmQueueWeightHwWrite( UINT8 stream, UINT8 Qid, UINT32 weight )
{
	OPL_STATUS ret;
	tmqueueweighthwwrite_params_t params;

	params.stream = stream;
	params.Qid = Qid;
	params.weight = weight;

	ret = ioctl( opconnfd, IOC_TMQUEUEWEIGHTHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS tmQueueWeightHwRead( UINT8 stream, UINT8 Qid, UINT32 * weight )
{
	OPL_STATUS ret;
	tmqueueweighthwread_params_t params;

	params.stream = stream;
	params.Qid = Qid;

	ret = ioctl( opconnfd, IOC_TMQUEUEWEIGHTHWREAD, &params );
	if ( ret )
	{
		return ret;
	}

	*weight = params.weight;

	return ret;
}

OPL_STATUS tmGeCirHwWrite( UINT8 stream, UINT32 geCir )
{
	OPL_STATUS ret;
	tmgecirhwwrite_params_t params;

	params.stream = stream;
	params.geCir = geCir;

	ret = ioctl( opconnfd, IOC_TMGECIRHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS tmGeCirHwRead( UINT8 stream, UINT32 * geCir )
{
	OPL_STATUS ret;
	tmgecirhwread_params_t params;

	params.stream = stream;

	ret = ioctl( opconnfd, IOC_TMGECIRHWREAD, &params );
	if ( ret )
	{
		return ret;
	}

	*geCir = params.geCir;

	return ret;
}

OPL_STATUS tmGeCbsHwWrite( UINT8 stream, UINT32 geCbs )
{
	OPL_STATUS ret;
	tmgecbshwwrite_params_t params;

	params.stream = stream;
	params.geCbs = geCbs;

	ret = ioctl( opconnfd, IOC_TMGECBSHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS tmGeCbsHwRead( UINT8 stream, UINT32 * geCbs )
{
	OPL_STATUS ret;
	tmgecbshwread_params_t params;

	params.stream = stream;

	ret = ioctl( opconnfd, IOC_TMGECBSHWREAD, &params );
	if ( ret )
	{
		return ret;
	}

	*geCbs = params.geCbs;

	return ret;
}

OPL_STATUS tmCosIcosMapHwWrite( UINT8 stream, UINT8 cos, UINT8 icos )
{
	OPL_STATUS ret;
	tmcosicosmaphwwrite_params_t params;

	params.stream = stream;
	params.cos = cos;
	params.icos = icos;

	ret = ioctl( opconnfd, IOC_TMCOSICOSMAPHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS tmCosIcosMapHwRead( UINT8 stream, UINT8 cos, UINT8 * icos )
{
	OPL_STATUS ret;
	tmcosicosmaphwread_params_t params;

	params.stream = stream;
	params.cos = cos;

	ret = ioctl( opconnfd, IOC_TMCOSICOSMAPHWREAD, &params );
	if ( ret )
	{
		return ret;
	}

	*icos = params.icos;

	return ret;
}

OPL_STATUS tmQueueCbsHwWrite( UINT8 stream, UINT8 Qid, UINT32 cbs )
{
	OPL_STATUS ret;
	tmqueuecbshwwrite_params_t params;

	params.stream = stream;
	params.Qid = Qid;
	params.cbs = cbs;

	ret = ioctl( opconnfd, IOC_TMQUEUECBSHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS tmQueueCbsHwRead( UINT8 stream, UINT8 Qid, UINT32 * cbs )
{
	OPL_STATUS ret;
	tmqueuecbshwread_params_t params;

	params.stream = stream;
	params.Qid = Qid;

	ret = ioctl( opconnfd, IOC_TMQUEUECBSHWREAD, &params );
	if ( ret )
	{
		return ret;
	}

	*cbs = params.cbs;

	return ret;
}

OPL_STATUS tmQueueCirHwWrite( UINT8 stream, UINT8 Qid, UINT32 cir )
{
	OPL_STATUS ret;
	tmqueuecirhwwrite_params_t params;

	params.stream = stream;
	params.Qid = Qid;
	params.cir = cir;

	ret = ioctl( opconnfd, IOC_TMQUEUECIRHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS tmQueueCirHwRead( UINT8 stream, UINT8 Qid, UINT32 * cir )
{
	OPL_STATUS ret;
	tmqueuecirhwread_params_t params;

	params.stream = stream;
	params.Qid = Qid;

	ret = ioctl( opconnfd, IOC_TMQUEUECIRHWREAD, &params );
	if ( ret )
	{
		return ret;
	}

	*cir = params.cir;

	return ret;
}

OPL_STATUS tmWredCfgSet( UINT8 stream, UINT8 queueId, UINT8 type, UINT32 value )
{
	OPL_STATUS ret;
	tmwredcfgset_params_t params;

	params.stream = stream;
	params.queueId = queueId;
	params.value = value;

	ret = ioctl( opconnfd, IOC_TMWREDCFGSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS tmWredEnableHwWrite( UINT8 stream, UINT8 queueId, UINT32 enable )
{
	OPL_STATUS ret;
	tmwredenablehwwrite_params_t params;

	params.stream = stream;
	params.queueId = queueId;
	params.enable = enable;

	ret = ioctl( opconnfd, IOC_TMWREDENABLEHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS tmWredEnableHwRead( UINT8 stream, UINT8 queueId, UINT32 * enable )
{
	OPL_STATUS ret;
	tmwredenablehwread_params_t params;

	params.stream = stream;
	params.queueId = queueId;

	ret = ioctl( opconnfd, IOC_TMWREDENABLEHWREAD, &params );
	if ( ret )
	{
		return ret;
	}

	*enable = params.enable;

	return ret;
}

OPL_STATUS tmUsShaperTabDirectHwWrite( UINT32 entryId, UINT32 cir, UINT32 cbs )
{
	OPL_STATUS ret;
	tmusshapertabdirecthwwrite_params_t params;

	params.entryId = entryId;
	params.cir = cir;
	params.cbs = cbs;

	ret = ioctl( opconnfd, IOC_TMUSSHAPERTABDIRECTHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS tmUsWredTabDirectHwWrite( UINT32 entryId, UINT32 weight, UINT32 minth, UINT32 maxth )
{
	OPL_STATUS ret;
	tmuswredtabdirecthwwrite_params_t params;

	params.entryId = entryId;
	params.weight = weight;
	params.minth = minth;
	params.maxth = maxth;

	ret = ioctl( opconnfd, IOC_TMUSWREDTABDIRECTHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS tmDsWredTabDirectHwWrite( UINT32 entryId, UINT32 weight, UINT32 minth, UINT32 maxth )
{
	OPL_STATUS ret;
	tmdswredtabdirecthwwrite_params_t params;

	params.entryId = entryId;
	params.weight = weight;
	params.minth = minth;
	params.maxth = maxth;

	ret = ioctl( opconnfd, IOC_TMDSWREDTABDIRECTHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS tmDsShaperTabDirectHwWrite( UINT32 entryId, UINT32 cir, UINT32 cbs )
{
	OPL_STATUS ret;
	tmdsshapertabdirecthwwrite_params_t params;

	params.entryId = entryId;
	params.cir = cir;
	params.cbs = cbs;

	ret = ioctl( opconnfd, IOC_TMDSSHAPERTABDIRECTHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS tmQueueMaxCellNumHwWrite( UINT8 stream, UINT8 Qid, UINT16 maxCellNum )
{
	OPL_STATUS ret;
	tmqueuemaxcellnumhwwrite_params_t params;

	params.stream = stream;
	params.Qid = Qid;
	params.maxCellNum = maxCellNum;

	ret = ioctl( opconnfd, IOC_TMQUEUEMAXCELLNUMHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS tmWredCfgGet( UINT8 stream, UINT8 queueId, UINT8 type, UINT32 * value )
{
	OPL_STATUS ret;
	tmwredcfgget_params_t params;

	params.stream = stream;
	params.queueId = queueId;
	params.type = type;

	ret = ioctl( opconnfd, IOC_TMWREDCFGGET, &params );
	if ( ret )
	{
		return ret;
	}

	*value = params.value;

	return ret;
}

OPL_STATUS tmMaxpUsWredTabDirectHwWrite( UINT32 entryId, UINT8 c1, UINT32 weight, UINT32 minth, UINT32 maxth )
{
	OPL_STATUS ret;
	tmdswredtabdirecthwwrite_params_t params;

	params.entryId = entryId;
	params.c1 = c1;
	params.weight = weight;
	params.minth = minth;
	params.maxth = maxth;

	ret = ioctl( opconnfd, IOC_TMMAXPUSWREDTABDIRECTHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS tmMaxpDsWredTabDirectHwWrite( UINT32 entryId, UINT8 c1, UINT32 weight, UINT32 minth, UINT32 maxth )
{
	OPL_STATUS ret;
	tmdswredtabdirecthwwrite_params_t params;

	params.entryId = entryId;
	params.c1 = c1;	
	params.weight = weight;
	params.minth = minth;
	params.maxth = maxth;

	ret = ioctl( opconnfd, IOC_TMMAXPDSWREDTABDIRECTHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS tmQueueShaperCirEnableHwWrite(UINT8 stream,UINT8 Qid,UINT8 enable)
{
	OPL_STATUS ret;
	tmqueueshapercirenablehwwrite_params_t params;

	params.stream = stream;
	params.Qid = Qid;
	params.enable = enable;

	ret = ioctl( opconnfd, IOC_TMQUEUESHAPERCIRENABLEHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS tmUsShaperTabPirDirectHwWrite(UINT32 entryId,UINT32 pir,UINT32 pbs)
{
	OPL_STATUS ret;
	tmusshapertabpirdirecthwwrite_params_t params;

	params.entryId = entryId;
	params.pir = pir;
	params.pbs = pbs;

	ret = ioctl( opconnfd, IOC_TMUSSHAPERTABPIRDIRECTHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}


OPL_STATUS tmQueueMaxPktNumHwWrite(UINT8 stream,UINT8 Qid,UINT16 maxPktNum)
{
	OPL_STATUS ret;
	tmqueuemaxpktNumhwwrite_params_t params;

	params.stream = stream;
	params.Qid = Qid;
	params.maxPktNum = maxPktNum;

	ret = ioctl( opconnfd, IOC_TMQUEUEMAXPKTNUMHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}


OPL_STATUS tmUsShaperTabCirDirectHwWrite(UINT32 entryId,UINT32 cir,UINT32 cbs)
{
	OPL_STATUS ret;
	tmusshapertabcirdirecthwwrite_params_t params;

	params.entryId = entryId;
	params.cir = cir;
	params.cbs = cbs;

	ret = ioctl( opconnfd, IOC_TMUSSHAPERTABCIRDIRECTHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS tmQueueShaperPirEnableHwWrite(UINT8 stream,UINT8 Qid,UINT8 enable)
{
	OPL_STATUS ret;
	tmqueueshaperpirenablehwwrite_params_t params;

	params.stream = stream;
	params.Qid = Qid;
	params.enable = enable;

	ret = ioctl( opconnfd, IOC_TMQUEUESHAPERPIRENABLEHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS tmCellNumInQueueHwRead(UINT8 stream,UINT8  Qid,UINT32 *numOfCell)
{
	OPL_STATUS ret;
	tmcellnuminqueuehwread_params_t params;

	params.stream = stream;
	params.Qid= Qid;
	
	ret = ioctl( opconnfd, IOC_TMCELLNUMINQUEUEHWREAD, &params );
	if ( ret )
	{
		return ret;
	}

	*numOfCell = params.numOfCell;

	return ret;
}


OPL_STATUS phySpeedHwWrite( UINT32 phySpeedMode )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_PHYSPEEDHWWRITE, phySpeedMode );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS phySpeedHwRead( PHY_SPEED_MODE_e * phySpeedMode )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_PHYSPEEDHWREAD, phySpeedMode );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS phyDuplexHwWrite( PHY_DUPLEX_MODE_e phyDuplexMode )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_PHYDUPLEXHWWRITE, phyDuplexMode );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS phyDuplexHwRead( PHY_DUPLEX_MODE_e * phyDuplexMode )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_PHYDUPLEXHWREAD, phyDuplexMode );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS phyAutoNegHwWrite( UINT8 enable )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_PHYAUTONEGHWWRITE, enable );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS phyAutoNegHwRead( UINT8 * enable )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_PHYAUTONEGHWREAD, enable );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS phyRestartAutoNeg(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_PHYRESTARTAUTONEG, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS phyLoopbackEnableHwWrite( UINT8 enable )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_PHYLOOPBACKENABLEHWWRITE, enable );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS phyLoopbackEnableHwRead( UINT8 * enable )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_PHYLOOPBACKENABLEHWREAD, enable );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS phyReset(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_PHYRESET, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS phyPowerDown( UINT8 enable )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_PHYPOWERDOWN, enable );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS phyLinkStatusHwRead( UINT8 * linkStatus )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_PHYLINKSTATUSHWREAD, linkStatus );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS phyFlowControlEnHwWrite( UINT8 enable )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_PHYFLOWCONTROLENHWWRITE, enable );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS phySpecificAutoRead( UINT32 * phyAutonegDone )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_PHYSPECIFICAUTOREAD, phyAutonegDone );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS phySpecificSpeedRead( PHY_SPEED_MODE_e * phySpeed )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_PHYSPECIFICSPEEDREAD, phySpeed );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS phySpecificDuplexRead( PHY_DUPLEX_MODE_e * phyDuplex )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_PHYSPECIFICDUPLEXREAD, phyDuplex );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS oplRegRead( UINT32 regAddr, UINT32 * regVal )
{
	OPL_STATUS ret;
	oplregread_params_t params;

	params.regAddr = regAddr;

	ret = ioctl( opconnfd, IOC_OPLREGREAD, &params );
	if ( ret )
	{
		return ret;
	}

	*regVal = params.regVal;

	return ret;
}

OPL_STATUS oplRegWrite( UINT32 regAddr, UINT32 regVal )
{
	OPL_STATUS ret;
	oplregwrite_params_t params;

	params.regAddr = regAddr;
	params.regVal = regVal;

	ret = ioctl( opconnfd, IOC_OPLREGWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS oplRegFieldRead( UINT32 regAddr, UINT16 fieldOffset, UINT16 fieldWidth, UINT32 * data0 )
{
	OPL_STATUS ret;
	oplregfieldread_params_t params;

	params.regAddr = regAddr;
	params.fieldOffset = fieldOffset;
	params.fieldWidth = fieldWidth;

	ret = ioctl( opconnfd, IOC_OPLREGFIELDREAD, &params );
	if ( ret )
	{
		return ret;
	}

	*data0 = params.data0;

	return ret;
}

OPL_STATUS oplRegFieldWrite( UINT32 regAddr, UINT16 fieldOffset, UINT16 fieldWidth, UINT32 data0 )
{
	OPL_STATUS ret;
	oplregfieldwrite_params_t params;

	params.regAddr = regAddr;
	params.fieldOffset = fieldOffset;
	params.fieldWidth = fieldWidth;
	params.data0 = data0;

	ret = ioctl( opconnfd, IOC_OPLREGFIELDWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS oplTabRead( OPCONN_TAB_e region, UINT32 startId, UINT32 num, UINT32 * pVal )
{
	OPL_STATUS ret;
	opltabread_params_t params;

	params.region = region;
	params.startId = startId;
	params.num = num;
	params.pVal = pVal;
	ret = ioctl( opconnfd, IOC_OPLTABREAD, &params );
	if ( ret )
	{
		return ret;
	}

	//*pVal = params.pVal;

	return ret;
}

OPL_STATUS oplTabWrite( OPCONN_TAB_e region, UINT32 startId, UINT32 num, UINT32 * pVal )
{
	OPL_STATUS ret;
	opltabwrite_params_t params;

	params.region = region;
	params.startId = startId;
	params.num = num;
	params.pVal = pVal;

	ret = ioctl( opconnfd, IOC_OPLTABWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS mdioRegisterRead( UINT8 deviceAddr, UINT8 regAddr, UINT16 * data0 )
{
	OPL_STATUS ret;
	mdioregisterread_params_t params;

	params.deviceAddr = deviceAddr;
	params.regAddr = regAddr;

	ret = ioctl( opconnfd, IOC_MDIOREGISTERREAD, &params );
	if ( ret )
	{
		return ret;
	}

	*data0 = params.data0;

	return ret;
}

OPL_STATUS mdioRegisterWrite( UINT8 deviceAddr, UINT8 regAddr, UINT16 data0 )
{
	OPL_STATUS ret;
	mdioregisterwrite_params_t params;

	params.deviceAddr = deviceAddr;
	params.regAddr = regAddr;
	params.data0 = data0;

	ret = ioctl( opconnfd, IOC_MDIOREGISTERWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS mdioRegisterFieldRead( UINT8 deviceAddr, UINT8 regAddr, UINT8 offset, UINT8 width, UINT16 * data0 )
{
	OPL_STATUS ret;
	mdioregisterfieldread_params_t params;

	params.deviceAddr = deviceAddr;
	params.regAddr = regAddr;
	params.offset = offset;
	params.width = width;

	ret = ioctl( opconnfd, IOC_MDIOREGISTERFIELDREAD, &params );
	if ( ret )
	{
		return ret;
	}

	*data0 = params.data0;

	return ret;
}

OPL_STATUS mdioRegisterFieldWrite( UINT8 deviceAddr, UINT8 regAddr, UINT8 offset, UINT8 width,UINT16 data0 )
{
	OPL_STATUS ret;
	mdioregisterfieldwrite_params_t params;

	params.deviceAddr = deviceAddr;
	params.regAddr = regAddr;
	params.offset = offset;
	params.data0 = data0;

	ret = ioctl( opconnfd, IOC_MDIOREGISTERFIELDWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS mdioRegisterInit(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_MDIOREGISTERINIT, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}


OPL_STATUS chipReset(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_CHIPRESET, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS chipAttrGet( UINT8 type, UINT32 * value )
{
	OPL_STATUS ret;
	chipattrget_params_t params;

	params.type = type;

	ret = ioctl( opconnfd, IOC_CHIPATTRGET, &params );
	if ( ret )
	{
		return ret;
	}

	*value = params.value;

	return ret;
}

OPL_STATUS chipInit(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_CHIPINIT, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS linkListEnable(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_LINKLISTENABLE, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS respinInit(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_RESPININIT, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS gmacInit(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_GMACINIT, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS pmacInit(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_PMACINIT, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsDelEntry( UINT32 ruleid )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALCLSDELENTRY, ruleid );
	if ( ret )
	{
		return ret;
	}


	return ret;
}



OPL_STATUS dalVttVlanAggDel( UINT16 egressPort, UINT16 targetVlan, UINT16 aggedVlan, UINT8 * aggedMac )
{
	OPL_STATUS ret;
	dalvttvlanaggdel_params_t params;

	params.egressPort = egressPort;
	params.targetVlan = targetVlan;
	params.aggedVlan = aggedVlan;
	memcpy(params.aggedMac ,aggedMac ,MAC_LENGTH);

	ret = ioctl( opconnfd, IOC_DALVTTVLANAGGDEL, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalVttVlanAggAdd( UINT16 portId, UINT16 sVlan, UINT16 cVlan, UINT8 * aggedMac, UINT16 * ruleId )
{
	OPL_STATUS ret;
	dalvttvlanaggadd_params_t params;

	params.portId = portId;
	params.sVlan = sVlan;
	params.cVlan = cVlan;
	memcpy(params.aggedMac ,aggedMac ,MAC_LENGTH);

	ret = ioctl( opconnfd, IOC_DALVTTVLANAGGADD, &params );
	if ( ret )
	{
		return ret;
	}

	*ruleId = params.ruleId;

	return ret;
}

OPL_STATUS brgRsvMacCtrlHwRead( UINT8 macNum, UINT8 * icos, UINT8 * macCtl )
{
	OPL_STATUS ret;
	brgrsvmacctrlhwread_params_t params;

	params.macNum = macNum;

	ret = ioctl( opconnfd, IOC_BRGRSVMACCTRLHWREAD, &params );
	if ( ret )
	{
		return ret;
	}

	*icos = params.icos;
	*macCtl = params.macCtl;

	return ret;
}

OPL_STATUS brgRsvMacCtrlHwWrite( UINT8 macNum, UINT8 icos, UINT8 macCtl )
{
	OPL_STATUS ret;
	brgrsvmacctrlhwwrite_params_t params;

	params.macNum = macNum;
	params.icos = icos;
	params.macCtl = macCtl;

	ret = ioctl( opconnfd, IOC_BRGRSVMACCTRLHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMulticastEnable(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALMULTICASTENABLE, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMulticastDisable(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALMULTICASTDISABLE, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}



int i2cInit( int i2cMode, int intMode, UINT8 slvAddr, int nRate )
{
	int ret;
	i2cinit_params_t params;

	params.i2cMode = i2cMode;
	params.intMode = intMode;
	params.slvAddr = slvAddr;
	params.nRate = nRate;

	ret = ioctl( opconnfd, IOC_I2CINIT, &params );

	return ret;
}

int i2cReadRandom( UINT8 slvAddr, UINT8 staRegAddr, UINT32 nByte, UINT8 * pDataBuf )
{
	int ret;
	i2creadrandom_params_t params;

	#define MAX_I2C_SIZE 32
	
	if ( nByte > MAX_I2C_SIZE)
	{
	    return OPL_ERROR;
	}
	
	params.slvAddr = slvAddr;
	params.staRegAddr = staRegAddr;
	params.nByte = nByte;
	memset(params.pDataBuf, 0, MAX_I2C_SIZE);

	ret = ioctl( opconnfd, IOC_I2CREADRANDOM, &params );
	memcpy(pDataBuf, params.pDataBuf, nByte);

	return ret;
}

OPL_STATUS dalOnuClsRuleCtcAdd( opl_acl_list_t * oamcls )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALONUCLSRULECTCADD, oamcls );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalOnuClsRuleCtcChange( opl_acl_list_t * oamcls, UINT16 newmask )
{
	OPL_STATUS ret;
	dalonuclsrulectcchange_params_t params;

	params.oamcls = oamcls;
	params.newmask = newmask;

	ret = ioctl( opconnfd, IOC_DALONUCLSRULECTCCHANGE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalOnuClsRuleCtcDel( opl_acl_list_t * oamcls )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALONUCLSRULECTCDEL, oamcls );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalVoipClsDelEntry( UINT32 ruleid )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALVOIPCLSDELENTRY, ruleid );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClaCfgCheck( CLS_CONFIG_INFO_t * stClassCfg, UINT16 * ruleId )
{
	OPL_STATUS ret;
	dalclacfgcheck_params_t params;

	params.stClassCfg = stClassCfg;

	ret = ioctl( opconnfd, IOC_DALCLACFGCHECK, &params );
	if ( ret )
	{
		return ret;
	}

	*ruleId = params.ruleId;

	return ret;
}

OPL_STATUS dalPortPvidSet( UINT8 portId, UINT16 pvid )
{
	OPL_STATUS ret;
	dalportpvidset_params_t params;

	params.portId = portId;
	params.pvid = pvid;

	ret = ioctl( opconnfd, IOC_DALPORTPVIDSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPortPvidGet( UINT8 portId, UINT16 * pvid )
{
	OPL_STATUS ret;
	dalportpvidget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALPORTPVIDGET, &params );
	if ( ret )
	{
		return ret;
	}

	*pvid = params.pvid;

	return ret;
}

OPL_STATUS dalPortVlanModeSet( UINT8 portId, UINT8 mode )
{
	OPL_STATUS ret;
	dalportvlanmodeset_params_t params;

	params.portId = portId;
	params.mode = mode;

	ret = ioctl( opconnfd, IOC_DALPORTVLANMODESET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPortVlanModeGet( UINT8 portId, UINT8 * mode )
{
	OPL_STATUS ret;
	dalportvlanmodeget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALPORTVLANMODEGET, &params );
	if ( ret )
	{
		return ret;
	}

	*mode = params.mode;

	return ret;
}

OPL_STATUS dalPortDefaultPriSet( UINT8 portId, UINT8 defaultPri )
{
	OPL_STATUS ret;
	dalportdefaultpriset_params_t params;

	params.portId = portId;
	params.defaultPri = defaultPri;

	ret = ioctl( opconnfd, IOC_DALPORTDEFAULTPRISET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalTrunkEntryAdd( UINT8 portId, UINT32 vlanId )
{
	OPL_STATUS ret;
	daltrunkentryadd_params_t params;

	params.portId = portId;
	params.vlanId = vlanId;

	ret = ioctl( opconnfd, IOC_DALTRUNKENTRYADD, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalTrunkEntryDel( UINT8 portId, UINT32 vlanId )
{
	OPL_STATUS ret;
	daltrunkentrydel_params_t params;

	params.portId = portId;
	params.vlanId = vlanId;

	ret = ioctl( opconnfd, IOC_DALTRUNKENTRYDEL, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalTrunkEntryValueGet( UINT8 portId, UINT16 entryIndex, UINT16 * pVlanId )
{
	OPL_STATUS ret;
	daltrunkentryvalueget_params_t params;

	params.portId = portId;
	params.entryIndex = entryIndex;

	ret = ioctl( opconnfd, IOC_DALTRUNKENTRYVALUEGET, &params );
	if ( ret )
	{
		return ret;
	}

	*pVlanId = params.pVlanId;

	return ret;
}

OPL_STATUS dalTrunkEntryNumGet( UINT8 portId, UINT32 * pNum )
{
	OPL_STATUS ret;
	daltrunkentrynumget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALTRUNKENTRYNUMGET, &params );
	if ( ret )
	{
		return ret;
	}

	*pNum = params.pNum;

	return ret;
}

OPL_STATUS dalTrunkEntryClear( UINT8 portId )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALTRUNKENTRYCLEAR, portId );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalCreateVlanID( UINT16 vid )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALCREATEVLANID, vid );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalFlushVlanAll(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALFLUSHVLANALL, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalSetLocalSwitch( UINT8 lport, UINT8 enable )
{
	OPL_STATUS ret;
	dalsetlocalswitch_params_t params;

	params.lport = lport;
	params.enable = enable;

	ret = ioctl( opconnfd, IOC_DALSETLOCALSWITCH, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalClsRmkActGet( UINT16 classItemID, UINT8 pktType, UINT8 * rmkActVal )
{
	OPL_STATUS ret;
	dalclsrmkactget_params_t params;

	params.classItemID = classItemID;
	params.pktType = pktType;

	ret = ioctl( opconnfd, IOC_DALCLSRMKACTGET, &params );
	if ( ret )
	{
		return ret;
	}

	*rmkActVal = params.rmkActVal;

	return ret;
}

OPL_STATUS dalPonInit(  )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONINIT, 0 );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalDbaQueueThresholdSet( UINT8 qSetNum, UINT8 qNum, UINT16 thresholdVal )
{
	OPL_STATUS ret;
	daldbaqueuethresholdset_params_t params;

	params.qSetNum = qSetNum;
	params.qNum = qNum;
	params.thresholdVal = thresholdVal;

	ret = ioctl( opconnfd, IOC_DALDBAQUEUETHRESHOLDSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalDbaQueueThresholdGet( UINT8 qSetNum, UINT8 qNum,UINT16 * thresholdVal )
{
	OPL_STATUS ret;
	daldbaqueuethresholdget_params_t params;

	params.qSetNum = qSetNum;
	params.qNum = qNum;	

	ret = ioctl( opconnfd, IOC_DALDBAQUEUETHRESHOLDGET, &params );
	if ( ret )
	{
		return ret;
	}

	*thresholdVal = params.thresholdVal;

	return ret;
}

OPL_STATUS dalDbaReportModeSet( UINT32 mode )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALDBAREPORTMODESET, mode );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalDbaReportModeGet( UINT32 * mode )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALDBAREPORTMODEGET, mode );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalOnuMtuSet( UINT32 mtuSize )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALONUMTUSET, mtuSize );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalOnuMtuGet( UINT32 * mtuSize )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALONUMTUGET, mtuSize );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalOnuPonLoopbackConfig( UINT32 uniorscb, UINT32 enable )
{
	OPL_STATUS ret;
	dalonuponloopbackconfig_params_t params;

	params.uniorscb = uniorscb;
	params.enable = enable;

	ret = ioctl( opconnfd, IOC_DALONUPONLOOPBACKCONFIG, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalOnuPonTxPolarityConfig( UINT32 loworhigh )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALONUPONTXPOLARITYCONFIG, loworhigh );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS brgUsrDefineRsvMacHwWrite( UINT8 num, UINT8 * mac )
{
	OPL_STATUS ret;
	brgusrdefinersvmachwwrite_params_t params;

	params.num = num;
	memcpy(params.mac , mac, MAC_LENGTH);

	ret = ioctl( opconnfd, IOC_BRGUSRDEFINERSVMACHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS brgUsrDefineRsvMacHwRead( UINT8 num, UINT8 * mac )
{
	OPL_STATUS ret;
	brgusrdefinersvmachwread_params_t params;

	params.num = num;

	ret = ioctl( opconnfd, IOC_BRGUSRDEFINERSVMACHWREAD, &params );
	if ( ret )
	{
		return ret;
	}
	memcpy(mac , params.mac, MAC_LENGTH);
	
	return ret;
}

OPL_STATUS brgUsrDefineRsvMacCtrlHwWrite( UINT8 macNum, UINT8 icos, UINT8 macCtl )
{
	OPL_STATUS ret;
	brgusrdefinersvmacctrlhwwrite_params_t params;

	params.macNum = macNum;
	params.icos = icos;
	params.macCtl = macCtl;

	ret = ioctl( opconnfd, IOC_BRGUSRDEFINERSVMACCTRLHWWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS brgUsrDefineRsvMacCtrlHwRead( UINT8 macNum, UINT8 * icos, UINT8 * macCtl )
{
	OPL_STATUS ret;
	brgusrdefinersvmacctrlhwread_params_t params;

	params.macNum = macNum;

	ret = ioctl( opconnfd, IOC_BRGUSRDEFINERSVMACCTRLHWREAD, &params );
	if ( ret )
	{
		return ret;
	}

	*icos = params.icos;
	*macCtl = params.macCtl;

	return ret;
}

OPL_STATUS dalPONPortStatisticsGet1( ONU_PON_Port_Statistics_Get_1_t * ponStats )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONPORTSTATISTICSGET1, ponStats );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPONPortStatisticsGet2( ONU_PON_Port_Statistics_Get_2_t * ponStats )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPONPORTSTATISTICSGET2, ponStats );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPortFluxStatisticsCounterGet( ONU_Port_Flux_Statistics_Counter_t * portStats )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALPORTFLUXSTATISTICSCOUNTERGET, portStats );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalCounterGet( unsigned int moduleBit, OPL_CNT_t * oplCounter, unsigned int start, unsigned int num )
{
	OPL_STATUS ret;
	dalcounterget_params_t params;

	params.moduleBit = moduleBit;
	params.start = start;
	params.num = num;
	params.oplCounter = oplCounter;

	ret = ioctl( opconnfd, IOC_DALCOUNTERGET, &params );
	if ( ret )
	{
		return ret;
	}

	return ret;
}

OPL_STATUS dalCounterEnable( unsigned int moduleBitmap )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALCOUNTERENABLE, moduleBitmap );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalCounterEnableGet( unsigned int * moduleBitmap )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALCOUNTERENABLEGET, moduleBitmap );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalCounterClear( unsigned int moduleBitmap )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALCOUNTERCLEAR, moduleBitmap );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalVttNumExistGet(UINT32 *num)
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALVTTNUMEXISTGET, num );
	if ( ret )
	{
		return ret;
	}


	return ret;

}
OPL_STATUS dalVlanQinQModeSet( unsigned char mode )
{
	OPL_STATUS ret;

	ret = ioctl( opconnfd, IOC_DALVLANQINQMODESET, mode );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalVlanQinQBaseAdd( unsigned short vlan,unsigned short remarkPri,unsigned short insertPri )
{
	OPL_STATUS ret;
	dalvlanqinqbaseadd_params_t params;

	params.vlan = vlan;
	params.remarkPri = remarkPri;
	params.insertPri = insertPri;


	ret = ioctl( opconnfd, IOC_DALVLANQINQBASEADD, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalVlanQinQBaseDel( unsigned short vlan,unsigned short remarkPri,unsigned short insertPri  )
{
	OPL_STATUS ret;
	dalvlanqinqbasedel_params_t params;

	params.vlan = vlan;
	params.remarkPri = remarkPri;
	params.insertPri = insertPri;

	ret = ioctl( opconnfd, IOC_DALVLANQINQBASEDEL, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalVlanTransparentAdd( unsigned short vlan )
{
	OPL_STATUS ret;

	ret = ioctl( opconnfd, IOC_DALVLANTRANSPARENTADD, vlan );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalVlanTransparentDel( unsigned short vlan )
{
	OPL_STATUS ret;

	ret = ioctl( opconnfd, IOC_DALVLANTRANSPARENTDEL, vlan );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalVlanQinQFlexibleAdd( unsigned short svlan, unsigned short cvlan,unsigned short sPriority )
{
	OPL_STATUS ret;
	dalvlanqinqflexibleadd_params_t params;
	
	params.cvlan = cvlan;
	params.svlan = svlan;
	params.sPriority = sPriority;

	ret = ioctl( opconnfd, IOC_DALVLANQINQFLEXIBLEADD, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalVlanQinQFlexibleDel( unsigned short svlan, unsigned short cvlan,unsigned short sPriority )
{
	OPL_STATUS ret;
	dalvlanqinqflexibledel_params_t params;

	params.cvlan = cvlan;
	params.svlan = svlan;
	params.sPriority = sPriority;

	ret = ioctl( opconnfd, IOC_DALVLANQINQFLEXIBLEDEL, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlDiscardMacAdd( UINT8 * macAddress )
{
	OPL_STATUS ret;

	dalarldiscardmacadd_params_t params;
    memcpy(params.mac, macAddress, MAC_LENGTH);

	ret = ioctl( opconnfd, IOC_DALARLDISCARDMACADD, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlDiscardMacDel( UINT8 * macAddress )
{
	OPL_STATUS ret;

	dalarldiscardmacdel_params_t params;
    memcpy(params.mac, macAddress, MAC_LENGTH);

	ret = ioctl( opconnfd, IOC_DALARLDISCARDMACDEL, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalAclRstpAdd( UINT8 flg )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALACLRSTPADD, flg );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMulticastVlanCreate( UINT16 vlanId )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALMULTICASTVLANCREATE, vlanId );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMulticastVlanDelete( UINT16 vlanId )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALMULTICASTVLANDELETE, vlanId );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalAclClsFindName( CLS_CONFIG_INFO_t * stClassCfg, UINT8 * name )
{
	OPL_STATUS ret;
	dalaclclsfindname_params_t params;

	params.stClassCfg = stClassCfg;
	memcpy(params.name ,name,sizeof(name));

	ret = ioctl( opconnfd, IOC_DALACLCLSFINDNAME, &params );
	if ( ret )
	{
		return ret;
	}

	return ret;
}

OPL_STATUS dalArlFlushAllByPort( UINT8 portId )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALARLFLUSHALLBYPORT, portId );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalPortLearnEnableSet( UINT8 portId, UINT32 enable )
{
	OPL_STATUS ret;
	dalportlearnenableset_params_t params;

	params.portId = portId;
	params.enable = enable;

	ret = ioctl( opconnfd, IOC_DALPORTLEARNENABLESET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlMacMove( UINT32 port, UINT32 toPort )
{
	OPL_STATUS ret;
	dalarlmacmove_params_t params;

	params.port = port;
	params.toPort = toPort;

	ret = ioctl( opconnfd, IOC_DALARLMACMOVE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlMacFilterAdd( UINT8 portId, UINT16 vlanId, UINT8 * macAddress )
{
	OPL_STATUS ret;
	dalarlmacfilteradd_params_t params;

	params.portId = portId;
	params.vlanId = vlanId;
    memcpy(params.macAddress, macAddress, MAC_LENGTH);

	ret = ioctl( opconnfd, IOC_DALARLMACFILTERADD, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlMacFilterDel( UINT8 portId, UINT16 vlanId, UINT8 * macAddress )
{
	OPL_STATUS ret;
	dalarlmacfilterdel_params_t params;

	params.portId = portId;
	params.vlanId = vlanId;
    memcpy(params.macAddress, macAddress, MAC_LENGTH);

	ret = ioctl( opconnfd, IOC_DALARLMACFILTERDEL, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlMacDlfFilterEn( UINT8 portId, UINT8 enable )
{
	OPL_STATUS ret;
	dalarlmacdlffilteren_params_t params;

	params.portId = portId;
	params.enable = enable;

	ret = ioctl( opconnfd, IOC_DALARLMACDLFFILTEREN, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArlMacPortLockDropEn( UINT8 portId, UINT8 enable )
{
	OPL_STATUS ret;
	dalarlmacportlockdropen_params_t params;

	params.portId = portId;
	params.enable = enable;

	ret = ioctl( opconnfd, IOC_DALARLMACPORTLOCKDROPEN, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMirPortSet( UINT8 portId )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALMIRPORTSET, portId );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMirPortGet( UINT8 * portId )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALMIRPORTGET, portId );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMirIngPortSet( UINT8 portId, UINT32 enable )
{
	OPL_STATUS ret;
	dalmiringportset_params_t params;

	params.portId = portId;
	params.enable = enable;

	ret = ioctl( opconnfd, IOC_DALMIRINGPORTSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMirIngPortGet( UINT8 portId, UINT32 * enable )
{
	OPL_STATUS ret;
	dalmiringportget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALMIRINGPORTGET, &params );
	if ( ret )
	{
		return ret;
	}

	*enable = params.enable;

	return ret;
}

OPL_STATUS dalMirEgPortSet( UINT8 portId, UINT32 enable )
{
	OPL_STATUS ret;
	dalmiregportset_params_t params;

	params.portId = portId;
	params.enable = enable;

	ret = ioctl( opconnfd, IOC_DALMIREGPORTSET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMirEgPortGet( UINT8 portId, UINT32 * enable )
{
	OPL_STATUS ret;
	dalmiregportget_params_t params;

	params.portId = portId;

	ret = ioctl( opconnfd, IOC_DALMIREGPORTGET, &params );
	if ( ret )
	{
		return ret;
	}

	*enable = params.enable;

	return ret;
}

OPL_STATUS dalDeleteVlanID( UINT16 vid )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALDELETEVLANID, vid );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalAddVlanPort( UINT8 portId, UINT16 vid, VLAN_EGRESS_TYPE_E type )
{
	OPL_STATUS ret;
	daladdvlanport_params_t params;

	params.portId = portId;
	params.vid = vid;
	params.type = type;

	ret = ioctl( opconnfd, IOC_DALADDVLANPORT, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMoveVlanPort( UINT8 portId, UINT16 vid )
{
	OPL_STATUS ret;
	dalmovevlanport_params_t params;

	params.portId = portId;
	params.vid = vid;

	ret = ioctl( opconnfd, IOC_DALMOVEVLANPORT, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalMibGet( UINT8 portId, void * mib )
{
	OPL_STATUS ret;
	dalmibget_params_t params;

	params.portId = portId;
	params.mib = mib;

	ret = ioctl( opconnfd, IOC_DALMIBGET, &params );
	if ( ret )
	{
		return ret;
	}

	return ret;
}

OPL_STATUS isis_phy_get( UINT32 dev_id, UINT32 phy_addr, UINT32 reg, UINT16 * value )
{
	OPL_STATUS ret;
	isis_phy_get_params_t params;

	params.dev_id = dev_id;
	params.phy_addr = phy_addr;
	params.reg = reg;

	ret = ioctl( opconnfd, IOC_ISIS_PHY_GET, &params );
	if ( ret )
	{
		return ret;
	}

	*value = params.value;

	return ret;
}

OPL_STATUS isis_phy_set( UINT32 dev_id, UINT32 phy_addr, UINT32 reg, UINT16 value )
{
	OPL_STATUS ret;
	isis_phy_set_params_t params;

	params.dev_id = dev_id;
	params.phy_addr = phy_addr;
	params.reg = reg;
	params.value = value;

	ret = ioctl( opconnfd, IOC_ISIS_PHY_SET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS isis_reg_get( UINT32 dev_id, UINT32 reg_addr,UINT8  * value, UINT32 value_len )
{
	OPL_STATUS ret;
	isis_reg_get_params_t params;

	params.dev_id = dev_id;
	params.reg_addr = reg_addr;
	params.value = value;
	params.value_len = value_len;

	ret = ioctl( opconnfd, IOC_ISIS_REG_GET, &params );
	if ( ret )
	{
		return ret;
	}

	return ret;
}

OPL_STATUS isis_reg_set( UINT32 dev_id, UINT32 reg_addr, UINT8 * value, UINT32 value_len )
{
	OPL_STATUS ret;
	isis_reg_set_params_t params;

	params.dev_id = dev_id;
	params.reg_addr = reg_addr;
	params.value = value;
	params.value_len = value_len;

	ret = ioctl( opconnfd, IOC_ISIS_REG_SET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS isis_reg_field_get( UINT32 dev_id, UINT32 reg_addr, UINT32 bit_offset, UINT32 field_len, UINT8 * value, UINT32 value_len )
{
	OPL_STATUS ret;
	isis_reg_field_get_params_t params;

	params.dev_id = dev_id;
	params.reg_addr = reg_addr;
	params.bit_offset = bit_offset;
	params.field_len = field_len;
	params.value = value;
	params.value_len = value_len;

	ret = ioctl( opconnfd, IOC_ISIS_REG_FIELD_GET, &params );
	if ( ret )
	{
		return ret;
	}

	return ret;
}

OPL_STATUS isis_reg_field_set( UINT32 dev_id, UINT32 reg_addr, UINT32 bit_offset, UINT32 field_len, const UINT8 * value, UINT32 value_len )
{
	OPL_STATUS ret;
	isis_reg_field_set_params_t params;

	params.dev_id = dev_id;
	params.reg_addr = reg_addr;
	params.bit_offset = bit_offset;
	params.field_len = field_len;
	params.value = value;
	params.value_len = value_len;

	ret = ioctl( opconnfd, IOC_ISIS_REG_FIELD_SET, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS isis_acl_rule_dump( UINT32 dev_id )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_ISIS_ACL_RULE_DUMP, dev_id );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS isis_acl_list_dump( UINT32 dev_id )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_ISIS_ACL_LIST_DUMP, dev_id );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS atheros_show_cnt( UINT32 port_id )
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_ATHEROS_SHOW_CNT, port_id );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS dalArVttShow(UINT32 portId)
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALARVTTSHOW, portId );
	if ( ret )
	{
		return ret;
	}


	return ret;

}

OPL_STATUS dalVlanShow(UINT32	vid)
{
	OPL_STATUS ret;


	ret = ioctl( opconnfd, IOC_DALVLANSHOW, vid );
	if ( ret )
	{
		return ret;
	}


	return ret;

}
/* Begin Added */
/*****************************************************************************
    Func Name: MdioSwGlobalRegRead
 Date Created: 2012/4/17 
       Author: 
  Description: Read global register's value in switch.
        Input: UINT32 regAddr   
                UINT32 * regVal  
       Output: 
       Return: 
      Caution: 
------------------------------------------------------------------------------
  Modification History                                                      
  DATE        NAME             DESCRIPTION                                  
  --------------------------------------------------------------------------
                                                                            
*****************************************************************************/
OPL_STATUS MdioSwGlobalRegRead(UINT32 regAddr, UINT32 * regVal )
{
	OPL_STATUS ret = OPL_OK;
	swmdioregisterread_params_t params;

    params.deviceAddr = 0;
	params.regAddr    = regAddr;
    params.data0      = 0;
#if 1
	ret = ioctl( opconnfd, IOC_SWMDIORGLBREGREAD, &params );
	if ( ret )
	{
		return ret;
	}
#else
    printf("\nrd reg:0x%04X, val:0x%04X, id:0x%08X, rstid:0x%08X\n",params.regAddr,*regVal,
           (IOC_SWMDIORGLBREGREAD), (IOC_CHIPRESET));
#endif
	*regVal = params.data0;

	return ret;
}

/*****************************************************************************
    Func Name: MdioSwGlobalRegWrite
 Date Created: 2012/4/17 
       Author: 
  Description: Write global register's value in switch.
        Input: UINT32 regAddr  
                UINT32 regVal   
       Output: 
       Return: 
      Caution: 
------------------------------------------------------------------------------
  Modification History                                                      
  DATE        NAME             DESCRIPTION                                  
  --------------------------------------------------------------------------
                                                                            
*****************************************************************************/
OPL_STATUS MdioSwGlobalRegWrite( UINT32 regAddr, UINT32 regVal )
{
	OPL_STATUS ret;
	swmdioregisterwrite_params_t params;

    params.deviceAddr = 0;
	params.regAddr    = regAddr;
	params.data0      = regVal;

    //printf("\nwr reg:0x%04X, val:0x%04X, id:0x%08X\n",params.regAddr,regVal,(IOC_SWMDIORGLBREGWRITE));
    
	ret = ioctl( opconnfd, IOC_SWMDIORGLBREGWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}

OPL_STATUS MdioSwPhyRegRead(UINT32 phyId, UINT32 regAddr, UINT32 * regVal )
{
	OPL_STATUS ret = OPL_OK;
	swmdiophyregread_params_t params;
    
    params.deviceAddr = 0;
    params.phyid      = phyId;
	params.regAddr    = regAddr;
    params.data0      = 0;

	ret = ioctl( opconnfd, IOC_SWMDIOPHYREAD, &params );
	if ( ret )
	{
		return ret;
	}

	*regVal = params.data0;

	return ret;
}

OPL_STATUS MdioSwPhyRegWrite(UINT32 phyId, UINT32 regAddr, UINT32 regVal)
{
	OPL_STATUS ret;
	swmdiophyregwrite_params_t params;

    params.deviceAddr = 0;
    params.phyid      = phyId;
	params.regAddr    = regAddr;
	params.data0      = regVal;

    //printf("\nwr reg:0x%04X, val:0x%04X, id:0x%08X\n",params.regAddr,regVal,(IOC_SWMDIORGLBREGWRITE));
    
	ret = ioctl( opconnfd, IOC_SWMDIOPHYWRITE, &params );
	if ( ret )
	{
		return ret;
	}


	return ret;
}
/* End   Added of porting */

/* Begin Added of qinq */
OPL_STATUS dalVttEntryTagAdd(UINT8 pon_strip_en,UINT8 ge_strip_en, UINT16 c_vid,UINT16 s_vid)
{
	OPL_STATUS ret;
	vttentrytag_params_t params;

    params.pon_strip_en = pon_strip_en;
    params.ge_strip_en = ge_strip_en;
	params.c_vid = c_vid;
    params.s_vid = s_vid;

	ret = ioctl( opconnfd, IOC_DALVTTENTRYTAGADD, &params );

	return ret;
}

OPL_STATUS dalQinqPvidSet(UINT32 uiPvid, UINT32 uiPriority)
{
	OPL_STATUS ret;
	qinqpvidset_params_t params;

	params.uiPvid = uiPvid;
	params.uiPriority = uiPriority;
	
	ret = ioctl( opconnfd, IOC_DALVTTQINQPVIDSET, &params );

	return ret;
}

OPL_STATUS dalQinqPvidReSet(UINT32 uiPvid, UINT32 uiPriority)
{
	OPL_STATUS ret;
	qinqpvidset_params_t params;

	params.uiPvid = uiPvid;
	params.uiPriority = uiPriority;
	
	ret = ioctl( opconnfd, IOC_DALVTTQINQPVIDRESET, &params );

	return ret;
}
/* End   Added of qinq */
#ifdef CONFIG_BOSA
OPL_STATUS dal25L90ImodSet(UINT32 uiModVal)
{
	OPL_STATUS ret;
	
	ret = ioctl( opconnfd, IOC_DALPON25L90IMODSET, &uiModVal );

	return ret;
}
OPL_STATUS dal25L90ApcSet(UINT32 uiApcVal)
{
	OPL_STATUS ret;
	
	ret = ioctl( opconnfd, IOC_DALPON25L90APCSET, &uiApcVal );

	return ret;

}
#endif
