#ifndef __STAFF_H_ 
#define __STAFF_H_

#define STAFF_FILE_PATH	"./staff.txt"	//存储职员信息的文件路径
#define STAFF_NUM_MAX	1024			//存储职员信息最大数量
#define STAFF_ID_lEN	8				//ID长度
#define STAFF_PWD_LEN	8				//密码长度

//职员结构体
typedef struct __staff_info_
{
	char szID[STAFF_ID_lEN+1];
	char szPwd[STAFF_PWD_LEN+1];
}STAFF_INFO;

int GetStaffInfo();
int SetStaffInfo();
int QueryStaffInfo(char *pID, char *pPwd);
int AddStaffInfo(char *pID, char *pPwd);

#endif	//__STAFF_H_