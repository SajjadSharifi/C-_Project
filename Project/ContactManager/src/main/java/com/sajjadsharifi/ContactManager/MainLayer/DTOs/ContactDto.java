package com.sajjadsharifi.ContactManager.MainLayer.DTOs;

import jakarta.validation.constraints.Size;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class ContactDto {
    public int id;

    @Size(max = 50)
    public String PersonName;

    @Size(max = 11)
    public String PhoneNumber;

    @Size(max = 100)
    public String Description;

    @Size(max = 50)
    public String CreatedAt;

    @Size(max = 50)
    public String UpdatedAt;
}

