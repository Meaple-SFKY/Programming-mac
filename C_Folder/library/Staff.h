#ifndef __STAFF_H_ 
#define __STAFF_H_

#define STAFF_FILE_PATH	"./staff.txt"	//�洢ְԱ��Ϣ���ļ�·��
#define STAFF_NUM_MAX	1024			//�洢ְԱ��Ϣ�������
#define STAFF_ID_lEN	8				//ID����
#define STAFF_PWD_LEN	8				//���볤��

//ְԱ�ṹ��
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