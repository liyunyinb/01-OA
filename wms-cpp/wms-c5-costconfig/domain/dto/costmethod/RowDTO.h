//#pragma once
//#ifndef _ROW_LIST_DTO_
//#define _ROW_LIST_DTO_
//#include "oatpp/core/macro/codegen.hpp"
//#include "oatpp/core/Types.hpp"
//
//#include OATPP_CODEGEN_BEGIN(DTO)
//
///**
// * �����������б��ʵ��
// */
//template <class T>
//class RowListDTO : public oatpp::DTO
//{
//    // ��ʼ��
//    DTO_INIT(RowListDTO, DTO);
//
//    /**
//     * �����б�
//     */
//    DTO_FIELD(List<T>, rows) = {};
//    DTO_FIELD_INFO(rows) {
//#ifndef LINUX
//        info->description = u8"�����б�";
//#else
//        info->description = "data list";
//#endif
//    }
//
//public:
//    // ���һ������
//    void addData(T one) {
//        this->rows->push_back(one);
//    }
//};
//
//#include OATPP_CODEGEN_END(DTO)
//#endif // !_ROW_LIST_DTO_