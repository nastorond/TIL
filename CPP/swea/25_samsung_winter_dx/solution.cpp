#define MAX_N 1000
#define MAX_M 20

#include <vector>

struct Result {
	int y, x;
};

/**
 * @brief 보물상자의 개수, 원본, 90도, 180도, 270도 회전시킨 조각지도
 */
struct STPiecesMap 
{
	int treasureNum; 				// 조각지도 당 보물지도 개수
	vector<vector<int>> piece0;		// 조각지도 원본
	vector<vector<int>> piece90;	// 90도 회전시킨 조각지도
	vector<vector<int>> piece180;	// 180도 회전시킨 조각지도
	vector<vector<int>> piece270;	// 270도 회전시킨 조각지도

	/**
	 * @brief 상자의 개수를 최초 0개로 선언하여 생성합니다
	 */
	STPiecesMap () : treasureNum(0), piece0(), piece0(), piece90(), piece180(), piece270() {}

	/**
	 * @brief 각 조각 지도 당 몇개의 보물을 포함하고 있는지 갯수를 파악합니다
	 * @param maxLen 조각 지도 한변의 길이
	 */
	void getTreasureNum(int maxLen)
	{	
		int tmp = 0;
		for (int i=0; i<maxLen, i++) 
		{
			for (int j=0; j<maxLen, j++) 
			{
				tmp += piece0[i][j];
			}
		}
		treasureNum = tmp;
	}

	/**
	 * @brief 원본 조각지도를 기준으로 90 도 회전시킨 조각지도를 저장해줍니다.
	 * @param maxLen 조각 지도 한변의 길이
	 */
	void rotate90(int maxLen)
	{
		piece90.resize(maxLen, vector<int>(maxLen, 0));
		for (int i=0; i<maxLen, i++) 
		{
			for (int j=0; j<maxLen, j++) 
			{
				piece90[j][maxLen-1-i] = piece0[i][j];
			}
		}
	}

	/**
	 * @brief 원본 조각지도를 기준으로 180도 회전시킨 조각지도를 저장합니다
	 * @param maxLen 조각 지도 한변의 길이
	 * 구현의 편의성을 위해 90도에서 90도를 추가적으로 회전시키는 형태로 구현합니다.
	 */
	void rotate180(int maxLen)
	{
		piece180.resize(maxLen, vector<int>(maxLen, 0));
		for (int i=0; i<maxLen, i++) 
		{
			for (int j=0; j<maxLen, j++) 
			{
				piece180[j][maxLen-1-i] = piece90[i][j];
			}
		}
	}

	/**
	 * @brief 원본 조각지도를 기준으로 2700도 회전시킨 조각지도를 저장합니다
	 * @param maxLen 조각 지도 한변의 길이
	 * 구현의 편의성을 위해 180도에서 90도를 추가적으로 회전시키는 형태로 구현합니다.
	 */
	void rotate270(int maxLen)
	{
		piece180.resize(maxLen, vector<int>(maxLen, 0));
		for (int i=0; i<maxLen, i++) 
		{
			for (int j=0; j<maxLen, j++) 
			{
				piece270[j][maxLen-1-i] = piece180[i][j];
			}
		}
	}

	/**
	 * @brief 해당 구조체의 원하는 변수들을 채워주는 init 함수 입니다.
	 * @param maxLen 조각 지도 한변의 길이
	 */
	void stInit (int maxLen)
	{
		getTreasureNum(maxLen);
		rotate90(maxLen);
		rotate180(maxLen);
		rotate270(maxLen);
	}
}

vector<vector<int>> fld;						// 전체 지도
vector<vector<int>> countingFld					// 특정 위치부터 보물 상자의 개수를 세놓은 지도
int fieldMax;									// 전체 지도 중 탐색해야 할 사각형 한변의 길이
int piecesMax;									// 조각 지도 한변의 길이

/**
 * @brief 해당 범위의 보물상자의 개수를 확인합니다
 * @param x 시작점의 x 좌표
 * @param y 시작점의 y 좌표
 */
void checkingTreasure (int x, int y)
{
	int tmpNum = 0;								// 보물 상자 카운팅 변수
	for (int i=0; i<piecesMax; i++)
	{
		for (int j=0; j<piecesMax; j++)
		{
			tmpNum += fld[x + i][y + j];
		}
	}
	countingFld[i][j] = tmpNum;					// 보물 상자 개수 표기
}

void init(int N, int M, int Map[MAX_N][MAX_N])
{	
    fld.resize(N, vector<int>(N, 0));			// 전체 지도를 초기화
	countingFld.resize(N, vector<int>(N, 0))	// 카운팅 지도 초기화
    piecesMax = M;								// 조각지도 한 변의 길이 전역 저장
	fieldMax = N - M;							// 탐색 해야할 범위 지정

	for (int i=0; i<N; i++)
	{
		for (int j=0; j<N; j++) 
		{
			fld[i][j] = Map[i][j];				// 보물 위치 표기
		}
	}

	for (int i=0; i<fieldMax; i++)
	{
		for (int j=0; j<fieldMax; j++)
		{
			checkingTreasure(i, j);				// 각 범위 당 보물상자 개수 카운팅
		}
	}
}

Result findTreasureChest(int Pieces[MAX_M][MAX_M])
{
	Result res;

	STPiecesMap stPiece;						// 조각지도 구조체 선언
	stPiece.stInit(piecesMax);					// 구조체 초기화

	for (int i=0; i<fieldMax; i++)
	{
		for (int j=0; j<fieldMax; j++)
		{	
			// 범위의 보물의 개수가 조각지도의 보물 개수보다 적으면 확인하지 않음
			if (countingFld[i][j] < stPiece.treasureNum) continue;
			/**
			 * @todo 각 위치에 대해 검사를 하는 함수를 만들고 숫자쌍으로 return 해주는 함수 만들기, 불만족시 pair<-1, -1> return
			 */
		}
	}

	res.y = res.x = 0;
	return res;
}