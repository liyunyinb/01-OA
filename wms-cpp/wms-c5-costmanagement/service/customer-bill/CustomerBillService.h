#ifndef _CUSTURMER_SERVICE_
#define _CUSTURMER_SERVICE_
#include <list>
#include "domain/vo/customer-bill/CustomerBillVO.h"
#include "domain/query/customer-bill/CustomerBillQuery.h"
#include "domain/dto/customer-bill/CustomerBillDTO.h"
#include "domain/do/public-do/DayCostDO.h"
#include "domain/vo/BaseJsonVO.h"
//#include "ApiController.h"
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class CustomerBillPageService
{
public:
	// ��ҳ��ѯ��������
	CustomerBillPageDTO::Wrapper listAll(const CustomerBillQuery::Wrapper& query);

};




class ExportService
{

private:
    // �� DayCostDO ��������ݰ�˳���ŵ� vector ��
    std::vector<std::string> convertDayCostDOToVector( DayCostDO& dayCost) {
        std::vector<std::string> row;
        row.push_back(dayCost.getId());
        row.push_back(dayCost.getCreateName());
        row.push_back(dayCost.getCreateBy());
        row.push_back(dayCost.getCreateDate());
        row.push_back(dayCost.getUpdateName());
        row.push_back(dayCost.getUpdateBy());
        row.push_back(dayCost.getUpdateDate());
        row.push_back(dayCost.getSysOrgCode());
        row.push_back(dayCost.getSysCompanyCode());
        row.push_back(dayCost.getCusCode());
        row.push_back(dayCost.getCusName());
        row.push_back(dayCost.getCostCode());
        row.push_back(dayCost.getCostName());
        row.push_back(dayCost.getCostDate());
        row.push_back(dayCost.getDayCostYj());
        row.push_back(dayCost.getDayCostBhs());
        row.push_back(dayCost.getDayCostSe());
        row.push_back(dayCost.getDayCostHsj());
        row.push_back(dayCost.getCostOri());
        row.push_back(dayCost.getBeiZhu());
        row.push_back(dayCost.getCostSta());
        row.push_back(dayCost.getCostSl());
        row.push_back(dayCost.getCostUnit());
        row.push_back(dayCost.getCostJs());
        return row;
    }


public:
	// ͨ��ID��ѯ��������
	oatpp::String getById(oatpp::String id);

};






class periodService
{

private:
    // �� DayCostDO ��������ݰ�˳���ŵ� vector ��
    std::vector<std::string> convertDayCostDOToVector(const DayCostDO& dayCost) {
        std::vector<std::string> row;
        row.push_back(dayCost.getId());
        row.push_back(dayCost.getCreateName());
        row.push_back(dayCost.getCreateBy());
        row.push_back(dayCost.getCreateDate());
        row.push_back(dayCost.getUpdateName());
        row.push_back(dayCost.getUpdateBy());
        row.push_back(dayCost.getUpdateDate());
        row.push_back(dayCost.getSysOrgCode());
        row.push_back(dayCost.getSysCompanyCode());
        row.push_back(dayCost.getCusCode());
        row.push_back(dayCost.getCusName());
        row.push_back(dayCost.getCostCode());
        row.push_back(dayCost.getCostName());
        row.push_back(dayCost.getCostDate());
        row.push_back(dayCost.getDayCostYj());
        row.push_back(dayCost.getDayCostBhs());
        row.push_back(dayCost.getDayCostSe());
        row.push_back(dayCost.getDayCostHsj());
        row.push_back(dayCost.getCostOri());
        row.push_back(dayCost.getBeiZhu());
        row.push_back(dayCost.getCostSta());
        row.push_back(dayCost.getCostSl());
        row.push_back(dayCost.getCostUnit());
        row.push_back(dayCost.getCostJs());
        return row;
    }


public:
    // ͨ��ID��ѯ��������
    oatpp::String getBydate(const PeriodQuery::Wrapper& file);

};

#endif // !_CUSTURMER_SERVICE_

