#ifndef __BOOK_H_
#define __BOOK_H_

#define BOOK_FILE_PATH	"./book.txt"	//�洢�鱾��Ϣ���ļ�·��
#define BOOK_NUM_MAX	1024			//�鱾��Ϣ�������
#define BOOK_NAME_lEN	64				//��������
#define BOOK_AUTHOR_LEN	32				//����������
#define BOOK_PUB_LEN	128				//������������

typedef struct __book_info
{
	unsigned int nID;					//���
	char szName[BOOK_NAME_lEN+1];		//����
	char szAuthor[BOOK_AUTHOR_LEN+1];	//������
	char szPub[BOOK_PUB_LEN+1];			//��������
	bool bState;						//���״̬
}BOOK_INFO;

int GetBookInfo();
int SetBookInfo();
int AddBookInfo(char *pName, char *pAuthor, char *pPub);
int DelBookInfo(unsigned int nID);
int ChangeBookInfo(unsigned int nID, char *pName, char *pAuthor, char *pPub);
int LoanBook(unsigned int nID);
int GiveBackBook(unsigned int nID);
int QueryBookInfo(BOOK_INFO *pInfo, unsigned int *pNum);
int QueryBookInfoByID(unsigned int nID, BOOK_INFO *pInfo, unsigned int *pNum);
int QueryBookInfoByName(char *pName, BOOK_INFO *pInfo, unsigned int *pNum);
int QueryBookInfoByAuthor(char *pAuthor, BOOK_INFO *pInfo, unsigned int *pNum);
int QueryBookInfoByPub(char *pPub, BOOK_INFO *pInfo, unsigned int *pNum);

#endif	//__BOOK_H_