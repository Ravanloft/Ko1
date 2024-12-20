#pragma once

class CMagicType4Set : public OdbcRecordset
{
public:
	CMagicType4Set(OdbcConnection* dbConnection, Magictype4Array* pMap)
		: OdbcRecordset(dbConnection), m_pMap(pMap) {}

	virtual tstring GetTableName() { return _T("MAGIC_TYPE4"); }
	virtual tstring GetColumns() { return _T("iNum, BuffType, Radius, Duration, AttackSpeed, Speed, AC, ACPct, Attack, MagicAttack, MaxHP, MaxHPPct, MaxMP, MaxMPPct, Str, Sta, Dex, Intel, Cha, FireR, ColdR, LightningR, MagicR, DiseaseR, PoisonR, ExpPct, SpecialAmount, HitRate, AvoidRate"); }
	virtual bool Fetch()
	{
		_MAGIC_TYPE4* pData = new _MAGIC_TYPE4;

		_dbCommand->FetchUInt32(1, pData->iNum);
		_dbCommand->FetchByte(2, pData->bBuffType);
		_dbCommand->FetchByte(3, pData->bRadius);
		_dbCommand->FetchUInt16(4, pData->sDuration);
		_dbCommand->FetchByte(5, pData->bAttackSpeed);
		_dbCommand->FetchByte(6, pData->bSpeed);
		_dbCommand->FetchInt16(7, pData->sAC);
		_dbCommand->FetchUInt16(8, pData->sACPct);
		_dbCommand->FetchByte(9, pData->bAttack);
		_dbCommand->FetchByte(10, pData->bMagicAttack);
		_dbCommand->FetchUInt16(11, pData->sMaxHP);
		_dbCommand->FetchUInt16(12, pData->sMaxHPPct);
		_dbCommand->FetchUInt16(13, pData->sMaxMP);
		_dbCommand->FetchUInt16(14, pData->sMaxMPPct);
		_dbCommand->FetchSByte(15, pData->bStr);
		_dbCommand->FetchSByte(16, pData->bSta);
		_dbCommand->FetchSByte(17, pData->bDex);
		_dbCommand->FetchSByte(18, pData->bIntel);
		_dbCommand->FetchSByte(19, pData->bCha);
		_dbCommand->FetchByte(20, pData->bFireR);
		_dbCommand->FetchByte(21, pData->bColdR);
		_dbCommand->FetchByte(22, pData->bLightningR);
		_dbCommand->FetchByte(23, pData->bMagicR);
		_dbCommand->FetchByte(24, pData->bDiseaseR);
		_dbCommand->FetchByte(25, pData->bPoisonR);
		_dbCommand->FetchUInt16(26, pData->sExpPct);
		_dbCommand->FetchUInt16(27, pData->sSpecialAmount);
		_dbCommand->FetchByte(28, pData->bHitRate);
		_dbCommand->FetchUInt16(29, pData->sAvoidRate);

		// Determine if the skill is a buff or a debuff.
		pData->bIsBuff = CMagicProcess::IsBuff(pData);

		if (!m_pMap->PutData(pData->iNum, pData))
			delete pData;

		
		return true;
	}

	Magictype4Array* m_pMap;
};