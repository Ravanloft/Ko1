#pragma once

class CMonsterBossTable : public OdbcRecordset
{
public:
	CMonsterBossTable(OdbcConnection* dbConnection, MonsterBossArray* pMap)
		: OdbcRecordset(dbConnection), m_pMap(pMap) {}

	virtual tstring GetTableName() { return _T("K_BOSSPOS"); }
	virtual tstring GetColumns() { return _T("Num,NpcID,strName, Zone, Posx1, Posz1, Posx2, Posz2, Posx3, Posz3, Posx4, Posz4, RegTime"); }

	virtual bool Fetch()
	{
		_MONSTER_BOSS_TABLE* pData = new _MONSTER_BOSS_TABLE;
		
		_dbCommand->FetchUInt16(1, pData->TrapNumber);
		_dbCommand->FetchUInt32(2, pData->iNpcID);
		_dbCommand->FetchString(3, pData->ZoneName);
		_dbCommand->FetchUInt16(4, pData->ZoneID);
		_dbCommand->FetchUInt32(5, pData->iPosX[0]);
		_dbCommand->FetchUInt32(6, pData->iPosZ[0]);
		_dbCommand->FetchUInt32(7, pData->iPosX[1]);
		_dbCommand->FetchUInt32(8, pData->iPosZ[1]);
		_dbCommand->FetchUInt32(9, pData->iPosX[2]);
		_dbCommand->FetchUInt32(10, pData->iPosZ[2]);
		_dbCommand->FetchUInt32(11, pData->iPosX[3]);
		_dbCommand->FetchUInt32(12, pData->iPosZ[3]);
		_dbCommand->FetchUInt32(13, pData->RegTime);

		if (!m_pMap->PutData(pData->TrapNumber, pData))
			delete pData;
		

		return true;
	}

	MonsterBossArray* m_pMap;
};