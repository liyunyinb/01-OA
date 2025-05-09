/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

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
#include "AttriInfoDAO.h"
#include "AttriInfoMapper.h"
#include <sstream>
#include "AttriInfoMapper.h"

int AttriInfoDAO::deleteById(string id) {
	string sql = "DELETE FROM `ba_com_type` WHERE `id`=?"; //����idɾ��
	return sqlSession->executeUpdate(sql, "%s", id);
}
// ��execl�������������󣬲��뵽���ݿ���
uint64_t AttriInfoDAO::insert(const AttriInfoDO& iObj) {
	
	/*
	* 8 
	id -- Ψһ��ʶ��
	create_name -- ������--����Ա
	create_by -- ��˭���� --- admin
	create_date -- ����ʱ��
	sys_org_code -- �������Ŵ���
	sys_company_code -- ������˾����
	com_type_code -- ��ҵ���Դ���
	com_type_name -- ��ҵ��������
	*/

	// ׼��sql��� 
	string sql = "INSERT INTO `ba_com_type` (`id`, `create_name`, `create_by`,`create_date`,`sys_org_code`, `sys_company_code`, `com_type_code`, `com_type_name`) VALUES (?,?,?,?,?,?,?,?)";
	//string sql = "INSERT INTO `ba_com_type` (`id`,`com_type_code`, `com_type_name`) VALUES (?,?,?)";

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
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s",id,iObj.getCreateName(),iObj.getCreateBy(),oss.str(),iObj.getSysorgCode(), iObj.getSysCompanyCode(), iObj.getTypeCode(), iObj.getTypeNames());
}

// ��ѯ���ݿ��е���Ϣ��׼�����뵽execl�ĵ���
std::list<AttriInfoDO> AttriInfoDAO::getAllAttri() {
	string sql = "SELECT `id`,`create_name`,`create_by`,`create_date`,`sys_org_code`,`sys_company_code`,`com_type_code`,`com_type_name` from `ba_com_type`";
	AttriInfoMapper mapper;
	return sqlSession->executeQuery<AttriInfoDO>(sql, mapper);
}
