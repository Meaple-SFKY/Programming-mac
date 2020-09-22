#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "StdAfx.h"
#include "Staff.h"

static STAFF_INFO StaffInfo[STAFF_NUM_MAX];		//职员信息
static unsigned int StaffNum = 0;				//职员信息数

//获取职员信息
int GetStaffInfo()
{
	FILE *fp = NULL;
	unsigned int fileSize = 0;
	unsigned int num = 0;

	memset(StaffInfo, 0, STAFF_NUM_MAX*sizeof(STAFF_INFO));

	fp = fopen(STAFF_FILE_PATH, "rb");	//打开文件
	if (NULL == fp)
	{
		strcpy(StaffInfo[0].szID, "admin");
		strcpy(StaffInfo[0].szPwd, "admin");
		StaffNum++;
		SetStaffInfo();
		return -1;
	}

	fseek(fp, 0, SEEK_END);				//移向文件尾
	fileSize = ftell(fp);				//计算文件大小
	fseek(fp, 0, SEEK_SET);				//移向文件头
	num = fileSize / sizeof(STAFF_INFO);//计算读出来的职员信息个数
	StaffNum = num;

	fread(StaffInfo, sizeof(STAFF_INFO), StaffNum, fp);	//读入文件

	if (NULL != fp)
	{
		fclose(fp);
	}

	return 0;
}

//设置职员信息
int SetStaffInfo()
{
	FILE *fp = NULL;

	fp = fopen(STAFF_FILE_PATH, "wb");	//打开文件
	if (NULL == fp)
	{
		return -1;
	}

	fwrite(StaffInfo, sizeof(STAFF_INFO), StaffNum, fp);	//写入文件

	if (NULL != fp)
	{
		fclose(fp);
	}

	return 0;
}

//查询职员信息
int QueryStaffInfo(char *pID, char *pPwd)
{
	unsigned int loop = 0;
	
	if (NULL == pID || NULL == pPwd)
		return -1;
	
	for (loop=0; loop<StaffNum; loop++)
	{
		if (strcmp(pID, StaffInfo[loop].szID) == 0)				//找到用户名
		{
			if (strcmp(pPwd, StaffInfo[loop].szPwd) == 0)		//密码匹配成功
			{
				return 0;
			}
		}
	}

	return -1;
}

//新增职员信息
int AddStaffInfo(char *pID, char *pPwd)
{
	if (NULL == pID || NULL == pPwd)
		return -1;

	if (StaffNum == STAFF_NUM_MAX)	//最大个数已经满了
		return -2;

	strcpy(StaffInfo[StaffNum].szID, pID);
	strcpy(StaffInfo[StaffNum].szPwd, pPwd);
	StaffNum++;

	SetStaffInfo();

	return 0;
}