/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#include "AttriService.h"
#include "dao/companyattributes/AttriInfoDAO.h"
#include "domain/dto/companyattributes/AttriInfoDTO.h"


// ɾ��
bool AttriService::removeData(vector<string> id) {
	AttriInfoDAO dao;
	for (const auto & i : id) {
		if (dao.deleteById(i) != 1) {
			return false;
		}
	}
	return true;
}


// ������ҵ���ԵĲ�ѯ�����׼����һ�����뵽execl�ĵ���
vector<std::vector<std::string>> AttriService::getData() {
	AttriInfoDAO dao;
	std::list<AttriInfoDO> AttriList = dao.getAllAttri();//��ѯ��ȡ����
	vector<std::vector<std::string>> resault_data;
	stringstream ss;

	for (auto index : AttriList)
	{
		std::vector<std::string> row;
		vector<string> tmpList = { index.getID() ,index.getCreateName() ,index.getCreateBy() ,index.getCreateDate(),
								   index.getSysorgCode(),index.getSysCompanyCode(),index.getTypeCode(),index.getTypeNames()};
		for (auto count : tmpList) {
			ss.clear();
			ss << count;
			row.push_back(ss.str());
			ss.str("");
		}
		
		resault_data.push_back(row);
	}
	return resault_data;
}

// ���ϴ�����ҵ���Ա��浽���ݿ�
uint64_t AttriService::saveData(const AttriInfoJsonDTO::Wrapper& dto) {
	// ��װDO����
	AttriInfoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,CreateName,creadename,CreateBy,createby,SysorgCode,sysorgcode,SysCompanyCode,syscompanycode,TypeCode, typecodes, TypeNames, typenames);
	AttriInfoDAO dao;
	// ִ���������
	return dao.insert(data);
}
