package com.zeroone.star.message.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

/**
 * <p>
 * 描述：Swagger配置
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@ComponentScan({"com.zeroone.star.project.components.sms.aliyun",
"com.zeroone.star.project.components.mail"})
@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig {
    @Bean
    Docket messageApi() {
        return SwaggerCore.defaultDocketBuilder("消息服务", "com.zeroone.star.message.controller", "message");
    }
}
