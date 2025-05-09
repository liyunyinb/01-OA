



#include <list>
#include "../../domain/vo/ba_act_type/BaActTypeVO.h"
#include "../../domain/query/ba_act_type/BaActTypeQuery.h"
#include "../../domain/do/ba_act_type/BaActTypeDO.h"
#include "../../domain/dto/ba_act_type/BaActTypeDTO.h"

/**
 * ��ҵ���ͷ�����
 */

class BaActTypeService
{
public:
    // ��ҳ��ѯ��ҵ����
    BaActTypeListPageDTO::Wrapper listAll(const BaActTypeQuery::Wrapper& query);
    // ͨ��ID��ѯ������ҵ����
    BaActTypeDTO::Wrapper getById(uint64_t id);
    // �����ҵ����
    uint64_t saveData(const BaActTypeAddDTO::Wrapper& dto);
    // ������ҵ����
    bool updateData(const BaActTypeDTO::Wrapper& dto);
    // ɾ����ҵ����
    bool removeData(const std::string id);

    //
    std::list<BaActTypeDO> listAll();

    //������id�洢
    uint64_t saveData_noid(const std::vector<std::vector<std::string>>& dto);

};