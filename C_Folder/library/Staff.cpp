#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "StdAfx.h"
#include "Staff.h"

static STAFF_INFO StaffInfo[STAFF_NUM_MAX];		//ְԱ��Ϣ
static unsigned int StaffNum = 0;				//ְԱ��Ϣ��

//��ȡְԱ��Ϣ
int GetStaffInfo()
{
	FILE *fp = NULL;
	unsigned int fileSize = 0;
	unsigned int num = 0;

	memset(StaffInfo, 0, STAFF_NUM_MAX*sizeof(STAFF_INFO));

	fp = fopen(STAFF_FILE_PATH, "rb");	//���ļ�
	if (NULL == fp)
	{
		strcpy(StaffInfo[0].szID, "admin");
		strcpy(StaffInfo[0].szPwd, "admin");
		StaffNum++;
		SetStaffInfo();
		return -1;
	}

	fseek(fp, 0, SEEK_END);				//�����ļ�β
	fileSize = ftell(fp);				//�����ļ���С
	fseek(fp, 0, SEEK_SET);				//�����ļ�ͷ
	num = fileSize / sizeof(STAFF_INFO);//�����������ְԱ��Ϣ����
	StaffNum = num;

	fread(StaffInfo, sizeof(STAFF_INFO), StaffNum, fp);	//�����ļ�

	if (NULL != fp)
	{
		fclose(fp);
	}

	return 0;
}

//����ְԱ��Ϣ
int SetStaffInfo()
{
	FILE *fp = NULL;

	fp = fopen(STAFF_FILE_PATH, "wb");	//���ļ�
	if (NULL == fp)
	{
		return -1;
	}

	fwrite(StaffInfo, sizeof(STAFF_INFO), StaffNum, fp);	//д���ļ�

	if (NULL != fp)
	{
		fclose(fp);
	}

	return 0;
}

//��ѯְԱ��Ϣ
int QueryStaffInfo(char *pID, char *pPwd)
{
	unsigned int loop = 0;
	
	if (NULL == pID || NULL == pPwd)
		return -1;
	
	for (loop=0; loop<StaffNum; loop++)
	{
		if (strcmp(pID, StaffInfo[loop].szID) == 0)				//�ҵ��û���
		{
			if (strcmp(pPwd, StaffInfo[loop].szPwd) == 0)		//����ƥ��ɹ�
			{
				return 0;
			}
		}
	}

	return -1;
}

//����ְԱ��Ϣ
int AddStaffInfo(char *pID, char *pPwd)
{
	if (NULL == pID || NULL == pPwd)
		return -1;

	if (StaffNum == STAFF_NUM_MAX)	//�������Ѿ�����
		return -2;

	strcpy(StaffInfo[StaffNum].szID, pID);
	strcpy(StaffInfo[StaffNum].szPwd, pPwd);
	StaffNum++;

	SetStaffInfo();

	return 0;
}