#ifndef _TREEAREANAME_MAPPER_
#define _TREEAREANAME_MAPPER_
#include "tree/TreeNodeMapper.h"
#include "domain/do/areainfo/AreaInfoDO.h"
#include "domain/dto/areainfo/AreaInfoDTO.h"

class TreeAreaNameMapper : public TreeNodeMapper<AreaNameTreeDO>
{
public:
	shared_ptr<TreeNode> objectMapper(AreaNameTreeDO* source) const override
	{
		// ����������ݶ���
		auto res = make_shared<AreaNameTreeDTO>();
		// ����㼶�ṹ����ӳ��
		res->_id(source->getCid());
		res->_pid(source->getParentId());
		// ��չ����ӳ��
		res->id = source->getId();
		res->name = source->getCity_name();
		return res;
	}
};


#endif // !_TREEAREANAME_MAPPER_