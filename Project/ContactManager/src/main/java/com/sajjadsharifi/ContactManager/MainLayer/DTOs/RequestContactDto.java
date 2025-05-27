package com.sajjadsharifi.ContactManager.MainLayer.DTOs;

import jakarta.validation.constraints.Size;

public class RequestContactDto {
    @Size(max = 50)
    public String PersonName;

    @Size(max = 11)
    public String PhoneNumber;

    @Size(max = 100)
    public String Description;
}
