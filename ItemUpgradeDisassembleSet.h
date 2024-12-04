#pragma once

class CItemUpgradeDisassembleSet : public OdbcRecordset
{
public:
	CItemUpgradeDisassembleSet(OdbcConnection* dbConnection, ItemUpgradeDisassembleArray* pMap)
		: OdbcRecordset(dbConnection), m_pMap(pMap) {}

	virtual tstring GetTableName() { return _T("ITEM_UPGRADE_DISASSEMBLE"); }
	virtual tstring GetColumns() { return _T("nOritinType, nOriginItem, nReqNoah, nGiveItem "); }

	virtual bool Fetch()
	{
		_ITEM_UPGRADE_DISASSEMBLE* pData = new _ITEM_UPGRADE_DISASSEMBLE;

		_dbCommand->FetchInt32(1, pData->bOriginType);
		_dbCommand->FetchUInt32(2, pData->sOriginItem);
		_dbCommand->FetchUInt32(3, pData->nReqNoah);
		_dbCommand->FetchInt32(4, pData->nGiveItem);

		if (!m_pMap->PutData(m_pMap->GetSize(), pData))
			delete pData;


		return true;
	}

	ItemUpgradeDisassembleArray* m_pMap;
};