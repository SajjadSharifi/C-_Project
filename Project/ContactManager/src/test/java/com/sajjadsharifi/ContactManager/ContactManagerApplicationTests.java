package com.sajjadsharifi.ContactManager;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.SQLException;

import static org.junit.jupiter.api.Assertions.assertTrue;

@SpringBootTest
class ContactManagerApplicationTests {

	@Test
	void contextLoads() {
	}

	@Autowired
	private DataSource dataSource;

	@Test
	void testConnection() throws SQLException {
		try (Connection connection = dataSource.getConnection()) {
			assertTrue(connection.isValid(1000));
			System.out.println("Connection successful to: " +
					connection.getMetaData().getDatabaseProductName());
		}
	}
}
