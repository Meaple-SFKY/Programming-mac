#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "StdAfx.h"
#include "Book.h"

static BOOK_INFO BookInfo[BOOK_NUM_MAX];	//�鱾��Ϣ
static unsigned int BookNum = 0;			//�鱾��
static unsigned int BookSerial = 0;			//�鱾�����

//��ȡ�鱾��Ϣ
int GetBookInfo()
{
	FILE *fp = NULL;
	unsigned int fileSize = 0;
	unsigned int num = 0;
	
	memset(BookInfo, 0, BOOK_NUM_MAX*sizeof(BOOK_INFO));
	
	fp = fopen(BOOK_FILE_PATH, "rb");	//���ļ�
	if (NULL == fp)
	{
		return -1;
	}
	
	fseek(fp, 0, SEEK_END);				//�����ļ�β
	fileSize = ftell(fp);				//�����ļ���С
	fseek(fp, 0, SEEK_SET);				//�����ļ�ͷ
	num = fileSize / sizeof(BOOK_INFO);//������������鱾��Ϣ����
	BookNum = num;
	
	fread(BookInfo, sizeof(BOOK_INFO), BookNum, fp);	//�����ļ�
	BookSerial = BookInfo[BookNum-1].nID;
	
	if (NULL != fp)
	{
		fclose(fp);
	}
	
	return 0;
}

//�����鱾��Ϣ
int SetBookInfo()
{
	FILE *fp = NULL;
	
	fp = fopen(BOOK_FILE_PATH, "wb");	//���ļ�
	if (NULL == fp)
	{
		return -1;
	}
	
	fwrite(BookInfo, sizeof(BOOK_INFO), BookNum, fp);	//д���ļ�
	
	if (NULL != fp)
	{
		fclose(fp);
	}
	
	return 0;
}

//����鱾
int AddBookInfo(char *pName, char *pAuthor, char *pPub)
{
	if (NULL == pName || NULL == pAuthor || NULL == pPub)
		return -1;

	if (BookNum == BOOK_NUM_MAX)		//�鱾����
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

//ɾ��ָ��ID���鱾��Ϣ
int DelBookInfo(unsigned int nID)
{
	unsigned int loop = 0;
	int sign = -1;
	
	for (loop=0; loop<BookNum; loop++)
	{
		if (BookInfo[loop].nID == nID)	//�ҵ��Ȿ��
		{
			sign = loop;
			break;
		}
	}

	if (-1 != sign)			//����ɾ��
	{
		for (loop=sign; loop<BookNum; loop++)
		{
			if (loop+1 == BookNum)							//���һ�����
				memset(&(BookInfo[loop]), 0, sizeof(BOOK_INFO));
			else											//�����ÿ���ݽ�
			{
				BookInfo[loop] = BookInfo[loop+1];
			}
		}
		BookNum--;
		SetBookInfo();

		return 0;
	}
	else					//û�ҵ�
		return -1;
}

//�޸�ָ��ID���鱾��Ϣ
int ChangeBookInfo(unsigned int nID, char *pName, char *pAuthor, char *pPub)
{
	unsigned int loop = 0;

	if (NULL == pName || NULL == pAuthor || NULL == pPub)
	{
		return -1;
	}

	for (loop=0; loop<BookNum; loop++)
	{
		if (BookInfo[loop].nID == nID)	//�ҵ��鱾
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

//���
int LoanBook(unsigned int nID)
{
	unsigned int loop = 0;

	for (loop=0; loop<BookNum; loop++)
	{
		if (BookInfo[loop].nID == nID)	//�ҵ��鱾
		{
			if (BookInfo[loop].bState == true)		//�ڹ�
			{
				BookInfo[loop].bState = false;
				SetBookInfo();
				return 0;
			}
			else									//�ѽ��
				return -1;
		}
	}

	return -2;
}

//����
int GiveBackBook(unsigned int nID)
{
	unsigned int loop = 0;
	
	for (loop=0; loop<BookNum; loop++)
	{
		if (BookInfo[loop].nID == nID)	//�ҵ��鱾
		{
			if (BookInfo[loop].bState == false)		//���
			{
				BookInfo[loop].bState = true;
				SetBookInfo();
				return 0;
			}
			else									//���ڹ�
				return -1;
		}
	}
	
	return -2;
}

//��ѯ�����鱾
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

//����ID��ѯ�鱾
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
		if (BookInfo[loop].nID == nID)	//�ҵ��鱾
		{
			pInfo[*pNum] = BookInfo[loop];
			*pNum = (*pNum) + 1;
		}
	}

	return 0;
}

//����������ѯ�鱾
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
		if (strstr(BookInfo[loop].szName, pName) != 0)	//�ҵ��鱾
		{
			pInfo[*pNum] = BookInfo[loop];
			*pNum = (*pNum) + 1;
		}
	}

	return 0;
}

//������������ѯ�鱾
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
		if (strstr(BookInfo[loop].szAuthor, pAuthor) != 0)	//�ҵ��鱾
		{
			pInfo[*pNum] = BookInfo[loop];
			*pNum = (*pNum) + 1;
		}
	}
	
	return 0;
}

//���ݳ������ѯ�鱾
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
		if (strstr(BookInfo[loop].szPub, pPub) != 0)	//�ҵ��鱾
		{
			pInfo[*pNum] = BookInfo[loop];
			*pNum = (*pNum) + 1;
		}
	}
	
	return 0;
}