#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "StdAfx.h"
#include "Book.h"

static BOOK_INFO BookInfo[BOOK_NUM_MAX];	//书本信息
static unsigned int BookNum = 0;			//书本数
static unsigned int BookSerial = 0;			//书本最大编号

//获取书本信息
int GetBookInfo()
{
	FILE *fp = NULL;
	unsigned int fileSize = 0;
	unsigned int num = 0;
	
	memset(BookInfo, 0, BOOK_NUM_MAX*sizeof(BOOK_INFO));
	
	fp = fopen(BOOK_FILE_PATH, "rb");	//打开文件
	if (NULL == fp)
	{
		return -1;
	}
	
	fseek(fp, 0, SEEK_END);				//移向文件尾
	fileSize = ftell(fp);				//计算文件大小
	fseek(fp, 0, SEEK_SET);				//移向文件头
	num = fileSize / sizeof(BOOK_INFO);//计算读出来的书本信息个数
	BookNum = num;
	
	fread(BookInfo, sizeof(BOOK_INFO), BookNum, fp);	//读入文件
	BookSerial = BookInfo[BookNum-1].nID;
	
	if (NULL != fp)
	{
		fclose(fp);
	}
	
	return 0;
}

//设置书本信息
int SetBookInfo()
{
	FILE *fp = NULL;
	
	fp = fopen(BOOK_FILE_PATH, "wb");	//打开文件
	if (NULL == fp)
	{
		return -1;
	}
	
	fwrite(BookInfo, sizeof(BOOK_INFO), BookNum, fp);	//写入文件
	
	if (NULL != fp)
	{
		fclose(fp);
	}
	
	return 0;
}

//添加书本
int AddBookInfo(char *pName, char *pAuthor, char *pPub)
{
	if (NULL == pName || NULL == pAuthor || NULL == pPub)
		return -1;

	if (BookNum == BOOK_NUM_MAX)		//书本满了
		return -2;

	BookInfo[BookNum].nID = BookSerial+1;
	strcpy(BookInfo[BookNum].szName, pName);
	strcpy(BookInfo[BookNum].szAuthor, pAuthor);
	strcpy(BookInfo[BookNum].szPub, pPub);
	BookInfo[BookNum].bState = true;
	BookNum++;
	BookSerial++;

	SetBookInfo();

	return 0;
}

//删除指定ID的书本信息
int DelBookInfo(unsigned int nID)
{
	unsigned int loop = 0;
	int sign = -1;
	
	for (loop=0; loop<BookNum; loop++)
	{
		if (BookInfo[loop].nID == nID)	//找到这本书
		{
			sign = loop;
			break;
		}
	}

	if (-1 != sign)			//进行删除
	{
		for (loop=sign; loop<BookNum; loop++)
		{
			if (loop+1 == BookNum)							//最后一本清空
				memset(&(BookInfo[loop]), 0, sizeof(BOOK_INFO));
			else											//后面的每本递进
			{
				BookInfo[loop] = BookInfo[loop+1];
			}
		}
		BookNum--;
		SetBookInfo();

		return 0;
	}
	else					//没找到
		return -1;
}

//修改指定ID的书本信息
int ChangeBookInfo(unsigned int nID, char *pName, char *pAuthor, char *pPub)
{
	unsigned int loop = 0;

	if (NULL == pName || NULL == pAuthor || NULL == pPub)
	{
		return -1;
	}

	for (loop=0; loop<BookNum; loop++)
	{
		if (BookInfo[loop].nID == nID)	//找到书本
		{
			strcpy(BookInfo[loop].szName, pName);
			strcpy(BookInfo[loop].szAuthor, pAuthor);
			strcpy(BookInfo[loop].szPub, pPub);
			SetBookInfo();
			return 0;
		}
	}

	return -2;
}

//借出
int LoanBook(unsigned int nID)
{
	unsigned int loop = 0;

	for (loop=0; loop<BookNum; loop++)
	{
		if (BookInfo[loop].nID == nID)	//找到书本
		{
			if (BookInfo[loop].bState == true)		//在馆
			{
				BookInfo[loop].bState = false;
				SetBookInfo();
				return 0;
			}
			else									//已借出
				return -1;
		}
	}

	return -2;
}

//还入
int GiveBackBook(unsigned int nID)
{
	unsigned int loop = 0;
	
	for (loop=0; loop<BookNum; loop++)
	{
		if (BookInfo[loop].nID == nID)	//找到书本
		{
			if (BookInfo[loop].bState == false)		//借出
			{
				BookInfo[loop].bState = true;
				SetBookInfo();
				return 0;
			}
			else									//已在馆
				return -1;
		}
	}
	
	return -2;
}

//查询所有书本
int QueryBookInfo(BOOK_INFO *pInfo, unsigned int *pNum)
{
	unsigned int loop = 0;
	
	if (NULL == pInfo || NULL == pNum)
	{
		return -1;
	}
	
	for (loop=0; loop<BookNum; loop++)
	{
		pInfo[loop] = BookInfo[loop];
		
	}
	*pNum = BookNum;
	
	return 0;
}

//根据ID查询书本
int QueryBookInfoByID(unsigned int nID, BOOK_INFO *pInfo, unsigned int *pNum)
{
	unsigned int loop = 0;

	if (NULL == pInfo || NULL == pNum)
	{
		return -1;
	}

	*pNum = 0;
	
	for (loop=0; loop<BookNum; loop++)
	{
		if (BookInfo[loop].nID == nID)	//找到书本
		{
			pInfo[*pNum] = BookInfo[loop];
			*pNum = (*pNum) + 1;
		}
	}

	return 0;
}

//根据书名查询书本
int QueryBookInfoByName(char *pName, BOOK_INFO *pInfo, unsigned int *pNum)
{
	unsigned int loop = 0;
	
	if (NULL == pName || NULL == pInfo || NULL == pNum)
	{
		return -1;
	}
	
	*pNum = 0;
	
	for (loop=0; loop<BookNum; loop++)
	{
		if (strstr(BookInfo[loop].szName, pName) != 0)	//找到书本
		{
			pInfo[*pNum] = BookInfo[loop];
			*pNum = (*pNum) + 1;
		}
	}

	return 0;
}

//根据作者名查询书本
int QueryBookInfoByAuthor(char *pAuthor, BOOK_INFO *pInfo, unsigned int *pNum)
{
	unsigned int loop = 0;
	
	if (NULL == pAuthor || NULL == pInfo || NULL == pNum)
	{
		return -1;
	}
	
	*pNum = 0;
	
	for (loop=0; loop<BookNum; loop++)
	{
		if (strstr(BookInfo[loop].szAuthor, pAuthor) != 0)	//找到书本
		{
			pInfo[*pNum] = BookInfo[loop];
			*pNum = (*pNum) + 1;
		}
	}
	
	return 0;
}

//根据出版社查询书本
int QueryBookInfoByPub(char *pPub, BOOK_INFO *pInfo, unsigned int *pNum)
{
	unsigned int loop = 0;
	
	if (NULL == pPub || NULL == pInfo || NULL == pNum)
	{
		return -1;
	}
	
	*pNum = 0;
	
	for (loop=0; loop<BookNum; loop++)
	{
		if (strstr(BookInfo[loop].szPub, pPub) != 0)	//找到书本
		{
			pInfo[*pNum] = BookInfo[loop];
			*pNum = (*pNum) + 1;
		}
	}
	
	return 0;
}