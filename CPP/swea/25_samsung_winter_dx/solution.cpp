#define MAX_N 1000
#define MAX_M 20

#include <iostream>
#include <vector>

using namespace std;

struct Result {
	int y, x;
};

/**
 * @brief 보물상자의 개수, 원본, 90도, 180도, 270도 회전시킨 조각지도
 */
struct STPiecesMap 
{
	int iTreasureNum; 				// 조각지도 당 보물지도 개수
	pair<int, int> piiStandard0;	// 최초 기준점
	pair<int, int> piiStandard90;	// 90도 회전시킨 기준점
	pair<int, int> piiStandard180;	// 180도 회전시킨 기준점
	pair<int, int> piiStandard270;	// 270도 회전시킨 기준점
	vector<vector<int> > piece0;	// 조각지도 원본
	vector<vector<int> > piece90;	// 90도 회전시킨 조각지도
	vector<vector<int> > piece180;	// 180도 회전시킨 조각지도
	vector<vector<int> > piece270;	// 270도 회전시킨 조각지도

	/**
	 * @brief 상자의 개수를 최초 0개로 선언하여 생성합니다
	 */
	STPiecesMap () : iTreasureNum(0), piiStandard0(), piiStandard90(), piiStandard180(), piiStandard270(), piece0(), piece90(), piece180(), piece270() {}

	/**
	 * @brief 각 조각 지도 당 몇개의 보물을 포함하고 있는지 갯수를 파악합니다. 기준점을 탐색하여 저장합니다.
	 * @param maxLen 조각 지도 한변의 길이
	 */
	void getiTreasureNum(int maxLen)
	{	
		int iTmp = 0;
		for (int i=0; i<maxLen; i++) 
		{
			for (int j=0; j<maxLen; j++) 
			{
				iTmp += piece0[i][j];
				if (piece0[i][j] == 9)
				{
					piiStandard0 = make_pair(i, j);
					piece0[i][j] = 1;
				}
			}
		}
		iTreasureNum = iTmp;
	}

	/**
	 * @brief 원본 조각지도를 기준으로 90 도 회전시킨 조각지도를 저장해줍니다. 기준점 또한 설정해줍니다.
	 * @param maxLen 조각 지도 한변의 길이
	 */
	void rotate90(int maxLen)
	{
		piece90.resize(maxLen, vector<int>(maxLen, 0));
		for (int i=0; i<maxLen; i++) 
		{
			for (int j=0; j<maxLen; j++) 
			{
				piece90[j][maxLen-1-i] = piece0[i][j];
			}
		}
		piiStandard90 = make_pair(piiStandard0.second, maxLen - 1 - piiStandard0.first);
	}

	/**
	 * @brief 원본 조각지도를 기준으로 180도 회전시킨 조각지도를 저장합니다
	 * @param maxLen 조각 지도 한변의 길이
	 * 구현의 편의성을 위해 90도에서 90도를 추가적으로 회전시키는 형태로 구현합니다.
	 */
	void rotate180(int maxLen)
	{
		piece180.resize(maxLen, vector<int>(maxLen, 0));
		for (int i=0; i<maxLen; i++) 
		{
			for (int j=0; j<maxLen; j++) 
			{
				piece180[j][maxLen-1-i] = piece90[i][j];
			}
		}
		piiStandard180 = make_pair(piiStandard90.second, maxLen - 1 - piiStandard90.first);
	}

	/**
	 * @brief 원본 조각지도를 기준으로 2700도 회전시킨 조각지도를 저장합니다
	 * @param maxLen 조각 지도 한변의 길이
	 * 구현의 편의성을 위해 180도에서 90도를 추가적으로 회전시키는 형태로 구현합니다.
	 */
	void rotate270(int maxLen)
	{
		piece270.resize(maxLen, vector<int>(maxLen, 0));
		for (int i=0; i<maxLen; i++) 
		{
			for (int j=0; j<maxLen; j++) 
			{
				piece270[j][maxLen-1-i] = piece180[i][j];
			}
		}
		piiStandard270 = make_pair(piiStandard180.second, maxLen - 1 - piiStandard180.first);
	}

	/**
	 * @brief 해당 구조체의 원하는 변수들을 채워주는 init 함수 입니다.
	 * @param maxLen 조각 지도 한변의 길이
	 */
	void stInit (int maxLen)
	{
		getiTreasureNum(maxLen);
		rotate90(maxLen);
		rotate180(maxLen);
		rotate270(maxLen);
	}
};

vector<vector<int> > fld;						// 전체 지도
vector<vector<int> > countingFld;				// 특정 위치부터 보물 상자의 개수를 세놓은 지도
int iFieldMax;									// 전체 지도 중 탐색해야 할 사각형 한변의 길이
int iPiecesMax;									// 조각 지도 한변의 길이

/**
 * @brief 시작점을 기준으로 조각지도와 일치하는지 탐색합니다
 * @param x 시작 기준점 x
 * @param y 시작 기준점 y
 * @param iTreasureNum 해당 조각지도가 가지고 있는 보물의 개수
 * @param vvTmpMap 원본과 맞춰볼 조각 지도
 * @return 일치하면 True 아니면 False
 */
bool checkCanOpenTreasure(int x, int y, int& iTreasureNum, vector<vector<int> >& vvTmpMap)
{
	bool bRes = true;											// 결과 값, 초기값 true로 세팅
	int iCnt = iTreasureNum;									// 참조값을 복사해서 카운팅 합니다.

	for (int i=0; i<iFieldMax; i++)
	{
		for (int j=0; j<iFieldMax; j++)
		{
			if (fld[x + i][y + j] == 1 && vvTmpMap[i][j] == 1)	// 보물상자의 위치가 서로 일치하는 경우 1개씩 줄여줍니다.
			{
				iCnt--;
			}
		}
	}

	if (iCnt > 0)
	{
		bRes = false;											// 보물상자가 남는 경우 열 수 없으므로 false 로 설정
	}

	return bRes;
}

/**
 * @brief 4 종류의 조각지도를 각각 조사하고 맞는 조각지도가 있다면 해당 기준점을 리턴해줍니다.
 * @param x 시작점 x
 * @param y 시작점 y
 * @param stMap 탐색할 지도의 구조체
 * @return 일치하는 것이 있는 경우 해당 기준점을 리턴하고 아니라면 (-1, -1) 을 리턴합니다.
 */
pair<int, int> findFitPiece(int x, int y, STPiecesMap& stMap)
{
	pair<int, int> piiRes = make_pair(-1, -1);

	if (checkCanOpenTreasure(x, y, stMap.iTreasureNum, stMap.piece0))						// 해당 조각과 일치하는 문양을 가졌는지 확인하고 맞을경우 해당 기준점을 리턴합니다.
	{
		piiRes = make_pair(stMap.piiStandard0.first + x, stMap.piiStandard0.second + y);
	}
	else if (checkCanOpenTreasure(x, y, stMap.iTreasureNum, stMap.piece90))
	{
		piiRes = make_pair(stMap.piiStandard90.first + x, stMap.piiStandard90.second + y);
	}
	else if (checkCanOpenTreasure(x, y, stMap.iTreasureNum, stMap.piece180))
	{
		piiRes = make_pair(stMap.piiStandard180.first + x, stMap.piiStandard180.second + y);
	}
	else if (checkCanOpenTreasure(x, y, stMap.iTreasureNum, stMap.piece270))
	{
		piiRes = make_pair(stMap.piiStandard270.first + x, stMap.piiStandard270.second + y);
	}

	return piiRes;
}

/**
 * @brief 해당 범위의 보물상자의 개수를 확인합니다
 * @param x 시작점의 x 좌표
 * @param y 시작점의 y 좌표
 */
void checkingTreasure (int x, int y)
{
	int iTmpNum = 0;								// 보물 상자 카운팅 변수
	for (int i=0; i<iPiecesMax; i++)
	{
		for (int j=0; j<iPiecesMax; j++)
		{
			iTmpNum += fld[x + i][y + j];
		}
	}
	countingFld[x][y] = iTmpNum;					// 보물 상자 개수 표기
	return;
}

void init(int N, int M, int Map[MAX_N][MAX_N])
{	
    fld.resize(N, vector<int>(N, 0));				// 전체 지도를 초기화
	countingFld.resize(N, vector<int>(N, 0));		// 카운팅 지도 초기화
    iPiecesMax = M;									// 조각지도 한 변의 길이 전역 저장
	iFieldMax = N - M;								// 탐색 해야할 범위 지정

	for (int i=0; i<N; i++)
	{
		for (int j=0; j<N; j++) 
		{
			fld[i][j] = Map[i][j];					// 보물 위치 표기
		}
	}

	for (int i=0; i<iFieldMax; i++)
	{
		for (int j=0; j<iFieldMax; j++)
		{
			checkingTreasure(i, j);					// 각 범위 당 보물상자 개수 카운팅
		}
	}
}

Result findTreasureChest(int Pieces[MAX_M][MAX_M])
{
	Result res;

	STPiecesMap stPiece;							// 조각지도 구조체 선언

	stPiece.piece0.resize(iPiecesMax, vector<int>(iPiecesMax, 0));
	for (int i=0; i<iPiecesMax; i++) 
	{
		for (int j=0; j<iPiecesMax; j++)
		{
			stPiece.piece0[i][j] = Pieces[i][j];	// original 조각 구조체에 넣기
		}
	}	
	stPiece.stInit(iPiecesMax);						// 구조체 초기화

	for (int i=0; i<iFieldMax; i++)
	{
		for (int j=0; j<iFieldMax; j++)
		{
			// 범위의 보물의 개수가 조각지도의 보물 개수보다 적으면 확인하지 않습니다.
			if (countingFld[i][j] < stPiece.iTreasureNum) continue;

			pair<int, int> piiRes = findFitPiece(i, j, stPiece);

			// 일치하는 경우는 한개만 존재한다고 생각해도 된다 했으므로 한개 발견하면 종료합니다.
			// 답에서 요구하는 x, y 와 실제로 사용하는 x, y 가 반대이므로 반대로 리턴합니다.
			if (piiRes.first != -1 && piiRes.second != -1)
			{
				res.y = piiRes.first;
				res.x = piiRes.second;
				return res;
			}
		}
	}

	res.y = res.x = 0;
	return res;
}