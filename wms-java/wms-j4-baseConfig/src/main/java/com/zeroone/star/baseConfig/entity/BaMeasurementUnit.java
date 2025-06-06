package com.zeroone.star.baseConfig.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.io.Serializable;
import java.util.Date;

/**
 * <p>
 *      mybatis plus 生成的计量单位实体类
 * </p>
 *
 * @author 1+5
 * @since 2025-02-25
 */
@Getter
@Setter
@TableName("ba_unit")
@ToString
public class BaMeasurementUnit implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(type = IdType.ASSIGN_UUID)
    private String id;

    /**
     * 创建人名称
     */
    private String createName;

    /**
     * 创建人登录名称
     */
    private String createBy;

    /**
     * 创建日期
     */
    private Date createDate;

    /**
     * 更新人名称
     */
    private String updateName;

    /**
     * 更新人登录名称
     */
    private String updateBy;

    /**
     * 更新日期
     */
    private Date updateDate;

    /**
     * 所属部门
     */
    private String sysOrgCode;

    /**
     * 所属公司
     */
    private String sysCompanyCode;

    /**
     * 单位代码
     */
    private String unitCode;

    /**
     * 单位名称
     */
    private String unitZhName;

    /**
     * 英文名称
     */
    private String unitEnName;

    /**
     * 国际度量衡换算值
     */
    private String unitChange;

    /**
     * 单位类型
     */
    private String unitType;

    /**
     * 停用
     */
    private String unitDel;


}
