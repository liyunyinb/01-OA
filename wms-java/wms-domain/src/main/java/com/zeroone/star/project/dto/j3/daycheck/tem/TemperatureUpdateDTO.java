package com.zeroone.star.project.dto.j3.daycheck.tem;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.time.LocalDateTime;
@ToString
@Getter
@Setter
@ApiModel("温度数据修改模型")
public class TemperatureUpdateDTO {
    @ApiModelProperty(value = "温度id" ,example = "123xxxxxx")
    private String id;

    @ApiModelProperty(value = "温度地点",example = "上海")
    private String wenduDd;

    @ApiModelProperty(value = "采集时间",example = "2025-12-03 12:10:55")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime wenduCjsj;

    @ApiModelProperty(value = "温度摄氏度",example = "10")
    private Double wenduZhi;

    @ApiModelProperty(value = "备注",example = "这是上海的温度")
    private String wenduBz;
}
