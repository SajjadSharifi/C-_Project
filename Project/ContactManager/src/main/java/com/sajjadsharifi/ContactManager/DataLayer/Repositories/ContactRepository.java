package com.sajjadsharifi.ContactManager.DataLayer.Repositories;

import com.sajjadsharifi.ContactManager.DataLayer.Models.Contact;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;
import java.time.ZonedDateTime;
import javax.sql.DataSource;
import java.sql.*;
import java.util.*;


@Repository
public class ContactRepository implements IContactRepository {
    private final DataSource dataSource;
    @Autowired
    public  ContactRepository(DataSource dataSource){
        this.dataSource = dataSource;
    }

    @Override
    public List<Contact> GetAll() {
        String query = "Select * From Contact";
        try(Connection connection = dataSource.getConnection()){
            System.out.println("Sql Connected");
            Statement statement = connection.createStatement();
            var queryResult = statement.executeQuery(query);

            List<Contact> contacts = new ArrayList<>();
            while (queryResult.next()){
                Contact contact = new Contact();
                contact.Id = queryResult.getInt("Id");
                contact.PersonName = queryResult.getString("PersonName");
                contact.PhoneNumber = queryResult.getString("PhoneNumber");
                contact.Descriptions = queryResult.getString("Descriptions");
                contact.CratedAt = queryResult.getString("CreatedAt");
                contact.UpdatedAt = queryResult.getString("UpdatedAt");

                contacts.add(contact);
            }
            return contacts;
        }catch (Exception exception){
            exception.printStackTrace();
        }
        return List.of();
    }

    @Override
    public Contact FindById(int id) {
        String query = "Select * From Contact Where ? = Id";
        try(Connection connection = dataSource.getConnection() ){
            PreparedStatement statement = connection.prepareStatement(query);
            statement.setInt(1,id);
            ResultSet queryResult = statement.executeQuery();
            if(queryResult.next()){
                Contact contact = new Contact();
                contact.Id = queryResult.getInt("Id");
                contact.PersonName = queryResult.getString("PersonName");
                contact.PhoneNumber = queryResult.getString("PhoneNumber");
                contact.Descriptions = queryResult.getString("Descriptions");
                contact.CratedAt = queryResult.getString("CreatedAt");
                contact.UpdatedAt = queryResult.getString("UpdatedAt");
                return contact;
            }else {
                return null;
            }

        }catch (Exception exception){
            exception.printStackTrace();
        }

        return null;
    }

    @Override
    public boolean Create(Contact contact) {
        String query = "Insert Into Contact(PersonName,PhoneNumber,Descriptions,CreatedAt) " +
                "Values (?,?,?,?)";

        try(Connection connection = dataSource.getConnection() ){
            PreparedStatement statement = connection.prepareStatement(query);
            statement.setString(1,contact.PersonName);
            statement.setString(2,contact.PhoneNumber);
            statement.setString(3,contact.Descriptions);
            statement.setString(4,ZonedDateTime.now().toString());
            statement.addBatch();
            statement.executeBatch();
            return true;

        }catch (Exception exception){
            exception.printStackTrace();
            return false;
        }
    }

    @Override
    public boolean Update(int id, Contact contact) {
        var contactById = FindById(id);
        if(contactById == null){
            System.out.println("User NotFound");
            return false;
        }
        String query = "Update Contact " +
                "Set PersonName = ?, PhoneNumber = ?, Descriptions = ?, UpdatedAt = ? " +
                "Where Id = ?";
        try(Connection connection = dataSource.getConnection() ){
            PreparedStatement statement = connection.prepareStatement(query);
            statement.setString(1,contact.PersonName);
            statement.setString(2,contact.PhoneNumber);
            statement.setString(3,contact.Descriptions);
            statement.setString(4,ZonedDateTime.now().toString());
            statement.setInt(5,id);
            statement.addBatch();
            statement.executeBatch();
            return true;

        }catch (Exception exception){
            exception.printStackTrace();
            return false;
        }
    }

    @Override
    public boolean Delete(int id) {
        var contactById = FindById(id);
        if(contactById == null){
            System.out.println("User NotFound");
            return false;
        }

        String query = "Delete From Contact " +
                "Where Id = ?";
        try(Connection connection = dataSource.getConnection() ){
            PreparedStatement statement = connection.prepareStatement(query);
            statement.setInt(1,id);
            statement.execute();
            return true;

        }catch (Exception exception){
            exception.printStackTrace();
            return false;
        }
    }
}
