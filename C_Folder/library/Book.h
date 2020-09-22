#ifndef __BOOK_H_
#define __BOOK_H_

#define BOOK_FILE_PATH	"./book.txt"	//存储书本信息的文件路径
#define BOOK_NUM_MAX	1024			//书本信息最大数量
#define BOOK_NAME_lEN	64				//书名长度
#define BOOK_AUTHOR_LEN	32				//作者名长度
#define BOOK_PUB_LEN	128				//出版社名长度

typedef struct __book_info
{
	unsigned int nID;					//书号
	char szName[BOOK_NAME_lEN+1];		//书名
	char szAuthor[BOOK_AUTHOR_LEN+1];	//作者名
	char szPub[BOOK_PUB_LEN+1];			//出版社名
	bool bState;						//借出状态
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