#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: tutu
 @Date: 2025/02/23 12:36:48

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
#ifndef _PLC_DTO_
#define _PLC_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * PLC�������ݶ��󣬰���Ҫ��ʾ��������
 */
class PlcBaseDto : public oatpp::DTO
{
	DTO_INIT(PlcBaseDto, DTO);
	// PLCIP
	API_DTO_FIELD_DEFAULT(String, plc_ip, "PLCIP");
	// PLC�˿�
	API_DTO_FIELD_DEFAULT(String, plc_port, ZH_WORDS_GETTER("plc.file.plcport"));
	// PLC�ͺ�
	API_DTO_FIELD_DEFAULT(String, plc_type, ZH_WORDS_GETTER("plc.file.plctype"));
	//ָ�ע
	API_DTO_FIELD_DEFAULT(String, com_remark, ZH_WORDS_GETTER("plc.file.remark"));
	// ָ����
	API_DTO_FIELD_DEFAULT(String, com_no, ZH_WORDS_GETTER("plc.file.number"));
};

/**
 * PLC�������ݶ�������add
 */
class PlcAddDTO : public PlcBaseDto
{
	DTO_INIT(PlcAddDTO, PlcBaseDto);
	//ִ��ʱ��
	API_DTO_FIELD_DEFAULT(String, com_time, ZH_WORDS_GETTER("plc.file.time"));
	//ִ��˳��
	API_DTO_FIELD_DEFAULT(String, com_seq, ZH_WORDS_GETTER("plc.file.seq"));
	//ָ�
	API_DTO_FIELD_DEFAULT(String, com_cons, ZH_WORDS_GETTER("plc.file.insset"));
	//����1
	API_DTO_FIELD_DEFAULT(String, remark1, ZH_WORDS_GETTER("plc.file.standby"));
	//��������1
	API_DTO_FIELD_DEFAULT(String, query01, ZH_WORDS_GETTER("plc.file.sys1"));
	//��������2
	API_DTO_FIELD_DEFAULT(String, query02, ZH_WORDS_GETTER("plc.file.sys2"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, setp_time, ZH_WORDS_GETTER("plc.file.steptime"));
	//����
	API_DTO_FIELD_DEFAULT(String, setp_num, ZH_WORDS_GETTER("plc.file.step"));
};

/**
 * ������Ϣ��ID�����ڷ�ҳ��ѯ
 */
class PlcListDTO : public PlcBaseDto
{
	DTO_INIT(PlcListDTO, PlcBaseDto);
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("plc.file.id"));
};

/**
 * PLC�б��ҳ���ݶ���
 */
class PlcListPageDTO : public PageDTO<PlcListDTO::Wrapper>
{
	DTO_INIT(PlcListPageDTO, PageDTO<PlcListDTO::Wrapper>);
};
//�������ݴ�ID�������޸�����
class PlcdetailDTO : public PlcAddDTO
{
	DTO_INIT(PlcdetailDTO, PlcAddDTO);
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("plc.file.id"));
};
#include OATPP_CODEGEN_END(DTO)
#endif 