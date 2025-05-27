package com.sajjadsharifi.ContactManager.DataLayer.Repositories;

import com.sajjadsharifi.ContactManager.DataLayer.Models.Contact;

import java.util.List;

public interface IContactRepository{
    public List<Contact> GetAll();
    public Contact FindById(int id);
    public boolean Create(Contact contact);
    public boolean Update(int id, Contact contact);
    public boolean Delete(int id);
}
