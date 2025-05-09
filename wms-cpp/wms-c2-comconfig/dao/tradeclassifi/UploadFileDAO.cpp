/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/03/12 9:26:52

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
#include "stdafx.h"
#include "UploadFileDAO.h"
#include <sstream>
#include "../lib-common/src/id/UuidFacade.cpp"
#include <iomanip>

// ��execl�������������󣬲��뵽���ݿ���
uint64_t UploadFileDAO::insert(const UploadFileDO& iObj) {

	/*
	* 8
	id -- Ψһ��ʶ��
	create_name -- ������--����Ա
	create_by -- ��˭���� --- admin
	create_date -- ����ʱ��
	sys_org_code -- �������Ŵ���
	sys_company_code -- ������˾����
	com_type_code -- ��ҵ�������
	com_type_name -- ��ҵ��������
	*/

	// ׼��sql��� 
	string sql = "INSERT INTO `ba_classfl` (`id`, `create_name`, `create_by`,`create_date`,`sys_org_code`, `sys_company_code`, `classfl_code`, `classfl_name`) VALUES (?,?,?,?,?,?,?,?)";

	// ׼���ֶ�1��Ψһ��ʶ��	
	UuidFacade uf(1);
	string id = uf.genUuid();
	std::cout << uf.genUuid() << std::endl;

	// ׼������ʱ��
	using namespace std::chrono;
	auto now = system_clock::now(); // ��ȡ��ǰʱ���
	auto now_time_t = system_clock::to_time_t(now); // ת��Ϊ time_t
	std::tm now_tm = *std::localtime(&now_time_t); // ת��Ϊ tm �ṹ
	std::ostringstream oss; // ��ʽ��Ϊ�ַ�������ʽ��YYYY-MM-DD HH:MM:SS��
	oss << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S");
	std::cout << "Current Time: " << oss.str() << std::endl; // ��ӡʱ���ַ�

	// ����ִ�н��
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s", id, iObj.getCreateName(), iObj.getCreateBy(), oss.str(), iObj.getSysorgCode(), iObj.getSysCompanyCode(), iObj.getTypeCode(), iObj.getTypeNames());
}
