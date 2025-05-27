package com.sajjadsharifi.ContactManager.MainLayer.Controllers;

import com.fasterxml.jackson.annotation.JsonValue;
import com.sajjadsharifi.ContactManager.DataLayer.Models.Contact;
import com.sajjadsharifi.ContactManager.DataLayer.Repositories.ContactRepository;
import com.sajjadsharifi.ContactManager.MainLayer.DTOs.ContactDto;
import com.sajjadsharifi.ContactManager.MainLayer.DTOs.RequestContactDto;
import io.swagger.v3.oas.annotations.Operation;
import io.swagger.v3.oas.annotations.responses.ApiResponse;
import io.swagger.v3.oas.annotations.tags.Tag;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import org.springframework.http.*;
import org.springframework.web.server.ResponseStatusException;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

@RestController
@RequestMapping("/")
@Tag(name = "User Management", description = "Endpoints for managing users")
public class HomeController {

    private final ContactRepository contactRepository;

    @Autowired
    public HomeController(ContactRepository contactService) {
        this.contactRepository = contactService;
    }


    @GetMapping
    @Operation(summary = "Get All Users", description = "Return all Users")
    @ApiResponse(responseCode = "200", description = "Worked")
    @ApiResponse(responseCode = "404", description = "Not Worked")
    public ResponseEntity<List<ContactDto>> GetAll() throws IOException {
        var contacts = contactRepository.GetAll();

       List<ContactDto>  contactDtos = new ArrayList<>();
        for (var contact : contacts ){
            ContactDto dto = new ContactDto();
            dto.id = contact.Id;
            dto.PersonName = contact.PersonName;
            dto.CreatedAt = contact.CratedAt;
            dto.Description = contact.Descriptions;
            dto.PhoneNumber = contact.PhoneNumber;
            dto.CreatedAt = contact.CratedAt;
            dto.UpdatedAt = contact.UpdatedAt;
            contactDtos.add(dto);
        }

        return ResponseEntity.ok(contactDtos);
    }

    @Operation(summary = "Get User By Id", description = "Return User if found")
    @ApiResponse(responseCode = "200", description = "Worked")
    @ApiResponse(responseCode = "404", description = "Not Worked")
    @GetMapping("/{id}")
    public ResponseEntity<ContactDto> GetById(@PathVariable int id){
        var contact = contactRepository.FindById(id);
        if(contact == null){
          throw new ResponseStatusException(HttpStatus.NOT_FOUND, "Contact not found with id: " + id);
        }

        ContactDto dto = new ContactDto();
        dto.id = contact.Id;
        dto.PersonName = contact.PersonName;
        dto.CreatedAt = contact.CratedAt;
        dto.Description = contact.Descriptions;
        dto.PhoneNumber = contact.PhoneNumber;
        dto.CreatedAt = contact.CratedAt;
        dto.UpdatedAt = contact.UpdatedAt;
        return ResponseEntity.ok(dto);
    }

    @Operation(summary = "Create")
    @ApiResponse(responseCode = "200", description = "Worked")
    @ApiResponse(responseCode = "404", description = "Not Worked")
    @PostMapping("/create")
    public ResponseEntity<Boolean> Create(@RequestBody RequestContactDto dto){
        try{
            Contact contact = new Contact();
            contact.PhoneNumber = dto.PhoneNumber;
            contact.PersonName = dto.PersonName;
            contact.Descriptions = dto.Description;

            contactRepository.Create(contact);
            return ResponseEntity.ok(true);
        }catch (Exception exception){
            exception.printStackTrace();
            return ResponseEntity.ok(false);
        }

    }

    @Operation(summary = "Update")
    @ApiResponse(responseCode = "200", description = "Worked")
    @ApiResponse(responseCode = "404", description = "Not Worked")
    @PutMapping("/put/{id}")
    public ResponseEntity<Boolean> Put(@PathVariable int id, @RequestBody RequestContactDto dto){
        var contact = contactRepository.FindById(id);
        if(contact == null){
            return ResponseEntity.ok(null);
        }
        contact.PersonName = dto.PersonName;
        contact.PhoneNumber = dto.PhoneNumber;
        contact.Descriptions = dto.Description;
        if(contactRepository.Update(id,contact)){
            return ResponseEntity.ok(true);
        }
        return ResponseEntity.ok(false);
    }

    @Operation(summary = "Delete User")
    @ApiResponse(responseCode = "200", description = "Worked")
    @ApiResponse(responseCode = "404", description = "Not Worked")
    @DeleteMapping("/delete/{id}")
    public ResponseEntity<Boolean> Delete(@PathVariable int id){
        var contact = contactRepository.FindById(id);
        if(contact == null){
            return ResponseEntity.ok(null);
        }
        if(contactRepository.Delete(id)){
            return ResponseEntity.ok(true);
        }
        return ResponseEntity.ok(false);
    }
}

