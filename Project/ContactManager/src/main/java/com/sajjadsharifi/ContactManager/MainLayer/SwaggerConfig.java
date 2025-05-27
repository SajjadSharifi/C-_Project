package com.sajjadsharifi.ContactManager.MainLayer;

import io.swagger.v3.oas.models.OpenAPI;
import io.swagger.v3.oas.models.info.Info;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class SwaggerConfig {
    @Bean
    public OpenAPI customOpenAPI() {
        return new OpenAPI()
                .info(new Info()
                        .title("PhoneBook Api 😎")
                        .version("1.0")
                        .description("Sajjad_Sharifi_Panah And Mohammad_Hossein_Noroozi"));
    }
}
