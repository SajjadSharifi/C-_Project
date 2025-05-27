package com.sajjadsharifi.ContactManager.DataLayer.Models;

import jakarta.persistence.*;
import lombok.*;

@Entity
@Getter @Setter
@Table(name = "Contact")
@AllArgsConstructor
@NoArgsConstructor
public class Contact {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "Id")
    public int Id;

    @Column(name = "PersonName")
    public String PersonName;

    @Column(name = "PhoneNumber")
    public String PhoneNumber;

    @Column(name = "Descriptions")
    public String Descriptions;

    @Column(name = "CreatedAt")
    public String CratedAt;

    @Column(name = "UpdatedAt")
    public String UpdatedAt;

}
