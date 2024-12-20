#pragma once
class CKnightsCapeSet : public OdbcRecordset
{
public:
	CKnightsCapeSet(OdbcConnection * dbConnection, KnightsCapeArray * pMap)
		: OdbcRecordset(dbConnection), m_pMap(pMap) {}

	virtual tstring GetTableName() { return _T("KNIGHTS_CAPE"); }
	virtual tstring GetColumns() { return _T("sCapeIndex, nBuyPrice, byGrade, nBuyLoyalty, byRanking, Description, bType, bTicket"); }

	virtual bool Fetch()
	{
		_KNIGHTS_CAPE *pData = new _KNIGHTS_CAPE;

		_dbCommand->FetchUInt16(1, pData->sCapeIndex);
		_dbCommand->FetchUInt32(2, pData->nReqCoins);
		_dbCommand->FetchByte(3, pData->byGrade);
		_dbCommand->FetchUInt32(4, pData->nReqClanPoints);
		_dbCommand->FetchByte(5, pData->byRanking);
		_dbCommand->FetchString(6, pData->Description);
		_dbCommand->FetchByte(7, pData->Type);
		_dbCommand->FetchByte(8, pData->Ticket);

		if (!m_pMap->PutData(pData->sCapeIndex, pData))
			delete pData;

		
		return true;
	}

	KnightsCapeArray *m_pMap;
};